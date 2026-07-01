# UT AP Final Project

A C++11 Advanced Programming final project that implements a small Netflix-style film marketplace. The project combines an in-memory domain model, a command parser from the first phase of the assignment, and a lightweight HTTP server with Bootstrap-based HTML pages.

The codebase is preserved as a legacy educational project from around 2019. This README documents how the project is structured, how to build and run it, and what behavior is implemented.

## Table of contents

- [Project overview](#project-overview)
- [Features](#features)
- [Tech stack](#tech-stack)
- [Repository layout](#repository-layout)
- [Build and run](#build-and-run)
- [Using the web UI](#using-the-web-ui)
- [Command model](#command-model)
- [Business rules](#business-rules)
- [Architecture](#architecture)
- [Legacy notes](#legacy-notes)

## Project overview

The application models a film distribution platform with two main user roles:

- **Customer**: can sign up, add money, browse films, buy films, rate purchased films, comment on purchased films, and receive notifications.
- **Publisher**: can sign up as a publisher, post films, delete owned films, receive revenue, reply to comments, manage followers, and receive notifications when users interact with their films.

Runtime data is stored in memory. There is no database or persistence layer, so all users, films, purchases, comments, ratings, and messages are reset when the process stops.

## Features

- User registration and login
- Customer and publisher roles
- Film publishing with name, year, length, price, summary, and director
- Film search and filtering
- Film detail pages
- Wallet charging and purchase flow
- Rating system with average film scores
- Comment and reply model
- Publisher revenue calculation
- Follow and notification model in the command layer
- Recommendation system based on shared buyers between films
- Custom HTTP server and template renderer
- Static Bootstrap pages for the web interface

## Tech stack

- C++11
- GNU Make
- POSIX sockets for the custom HTTP server
- Custom request, response, route, and template utilities
- Bootstrap 4.3.1 loaded from CDN in the HTML pages

## Repository layout

```text
.
|-- makefile                 # Build rules for the executable
|-- src/                     # Application domain, handlers, and entry point
|   |-- Core.*               # Main application state and business operations
|   |-- User.*               # Base user behavior and customer-like behavior
|   |-- Publisher.*          # Publisher-specific behavior
|   |-- Film.*               # Film model, scores, comments, buyers
|   |-- Comment.*            # Comment and reply model
|   |-- Message.*            # Notification message model
|   |-- Film_Graph.*         # Film recommendation graph
|   |-- Money_Handler.*      # Purchase revenue split rules
|   |-- Input_Handler.*      # Legacy command-line parser
|   |-- Parameter_Handler.*  # Request and command parameter validation
|   |-- Web_Service.*        # Web route registration
|   `-- Web_Handlers.*       # HTTP request handlers
|-- server/                  # Minimal HTTP server and route implementation
|-- utils/                   # Request, response, template, and utility code
|-- static/                  # HTML pages and image assets
|-- template/                # Extra template/static assets
|-- BUILD_DIR/               # Generated object files, if already built
`-- final_phase1.out         # Built executable, if already built
```

## Build and run

### Requirements

- A Unix-like environment
- `g++`
- `make`

The server uses POSIX socket headers such as `netinet/in.h`, `sys/socket.h`, and `unistd.h`, so it is intended for Linux or a compatible Unix-like system.

### Build

From the repository root:

```bash
make
```

This creates the executable:

```text
final_phase1.out
```

### Run

Run the executable from the repository root so relative paths such as `static/home.html` resolve correctly:

```bash
./final_phase1.out
```

Then open:

```text
http://localhost:5000
```

Stop the server with `Ctrl+C`.

### Clean generated files

```bash
make clean
```

The clean target removes generated build files such as `BUILD_DIR`, `.template`, object files, and `.out` files.

## Using the web UI

The current entry point starts the HTTP server on port `5000`.

| Route | Method | Purpose |
| --- | --- | --- |
| `/` | GET | Landing/login page |
| `/signup` | GET | Signup form |
| `/signup` | POST | Create a customer or publisher account |
| `/login` | GET | Login form |
| `/login` | POST | Login with username and password |
| `/homepage` | GET | Browse and filter available films |
| `/postfilm` | GET | Publisher film creation form |
| `/postfilm` | POST | Publish a new film |
| `/profile` | GET | Purchased films and wallet charge form |
| `/charge` | POST | Add money to the current account |
| `/getfilm` | GET | Film details, buy/rate actions, recommendations |
| `/buyfilm` | POST | Buy a film |
| `/ratefilm` | POST | Rate a purchased film |
| `/deletefilm` | POST | Delete a publisher-owned film |
| `/logout` | POST | Logout and return to guest state |

Typical flow:

1. Open `http://localhost:5000`.
2. Create a publisher account.
3. Publish one or more films from `PostFilm`.
4. Logout and create a customer account.
5. Charge the customer account from the profile page.
6. Browse films, open details, buy a film, and rate it.

## Command model

The project still contains the original command-oriented service layer in `Input_Handler` and `Core`. The current `main.cpp` starts the web server first, and the server loop blocks, so the interactive command loop is not normally reached during a web run. The command model is still useful for understanding the domain operations.

General command shape:

```text
<METHOD> <command> ? <key> <value> <key> <value> ...
```

Common examples:

```text
POST signup ? email user@example.com username alice password 1234 age 21
POST signup ? email pub@example.com username studio password 1234 age 30 publisher true
POST login ? username alice password 1234
POST logout ?

POST films ? name Matrix year 1999 length 136 price 50 summary SciFi director Wachowski
GET films ? director Wachowski
GET films ? min_year 1990 max_year 2000
GET films ? film_id 1

POST money ? amount 100
POST buy ? film_id 1
POST rate ? film_id 1 score 9
POST comments ? film_id 1 content Great

GET purchased ? director Wachowski
GET published ? min_rate 5
POST followers ? user_id 2
GET followers ?
GET notifications ?
GET notifications read ? limit 5
```

Implemented command names include:

- `signup`
- `login`
- `logout`
- `films`
- `put_films`
- `delete_films`
- `published`
- `purchased`
- `followers`
- `money`
- `buy`
- `rate`
- `comments`
- `replies`
- `delete_comments`
- `notifications`

The command layer prints one of these simple status/error messages:

- `OK`
- `Bad Request`
- `Permission Denied`
- `Not Found`

## Business rules

- Guests can sign up or log in. Most film, wallet, and notification actions require an authenticated user.
- Publishers can publish films and delete only films they own.
- Users can buy films when they have enough money.
- Users can rate or comment on a film only after buying it.
- Film scores are calculated as the average of submitted ratings.
- Purchases generate publisher revenue and platform revenue.
- Notifications are created for follow events, new publisher films, film purchases, ratings, comments, and replies.
- Recommendations are based on co-purchase relationships between films.

## Architecture

### Core domain

`Core` owns the application state:

- registered users
- films
- current user session
- platform account money
- parameter parser
- recommendation graph

Most user-facing operations eventually call into `Core`, including signup, login, publishing, buying, rating, commenting, searching, and notifications.

### Users and publishers

`User` represents the base account behavior. Customer behavior is handled through this base class. `Publisher` extends `User` with:

- published films
- followers
- comment reply and delete operations
- reserved publisher revenue
- follower notifications for newly published films

### Films, comments, and messages

`Film` stores metadata, average rating, comments, buyers, and publisher ownership. `Comment` stores comment text, sender, and publisher replies. `Message` stores notification content and unread/read state.

### Money flow

`Money_Handler` handles purchase settlement. When a film is bought, the buyer pays the film price and the publisher receives a percentage based on the film score:

| Film score | Publisher share | Platform share |
| --- | ---: | ---: |
| `< 5` | 80% | 20% |
| `>= 5` and `< 8` | 90% | 10% |
| `>= 8` | 95% | 5% |

### Recommendations

`Film_Graph` builds an adjacency matrix between films. Edge weights are based on how many buyers of one film also bought another film. Film detail pages use this graph to show up to four recommended films that the current user has not already bought.

### HTTP layer

The HTTP stack is implemented inside `server/` and `utils/`:

- `Server` listens on port `5000`
- `Route` matches method and path
- `Request` parses query/body parameters
- `Response` formats status, headers, cookies, and body
- `TemplateParser` renders the HTML templates with C++ snippets and context values

`Web_Service` wires routes to handlers in `Web_Handlers`.

## Legacy notes

This repository is an old educational project, so a few behaviors are intentionally documented rather than hidden:

- Data is in memory only; restarting the process resets everything.
- The server port is hard-coded to `5000`.
- The process must be run from the repository root because static files are referenced by relative paths.
- Authentication is session-like and minimal; it is not production security.
- Some generated artifacts are present in the repository, including `BUILD_DIR` and `final_phase1.out`.
- The web server loop blocks before the legacy command loop in `main.cpp`.
- The HTML pages use Bootstrap from a CDN, so the pages may appear unstyled without network access.
- There is no automated test suite in this repository.
- The code uses older C++ ownership patterns with raw pointers.

## Status

Archived university project. Useful as a snapshot of a C++ AP final assignment with object-oriented modeling, manual HTTP handling, templates, and a small recommendation algorithm.

#include "Web_Service.h"

using namespace std;

Web_Service::Web_Service(Core* ccore)
{
  try
  {
    server.my_core = ccore;
    server.setNotFoundErrPage("static/404.html");
    server.post("/signup" , new SignupHandler());
    server.get("/signup" , new ShowPage("static/signup.html"));
    server.post("/login", new LoginHandler());
    server.get("/login", new ShowPage("static/login.html"));
    server.get("/homepage", new HomepageHandler("static/homepage.html"));
    server.get("/postfilm", new ShowPage("static/postfilm.html"));
    server.post("/postfilm", new PostfilmHandler());
    server.post("/logout", new LogoutHandler());
    server.post("/deletefilm", new DeleteHandler());
    server.get("/profile", new ProfileHandler("static/profile.html"));
    server.post("/charge", new ChargeHandler());
    server.get("/getfilm", new GetfilmHandler("static/getfilm.html"));
    server.post("/buyfilm", new BuyHandler());
    server.post("/ratefilm", new RateHandler());
    server.get("/", new ShowPage("static/home.html"));

  }
  catch (Server::Exception e)
  {
    cerr << e.getMessage() << endl;
  }
  catch(exception& ex)
  {
    cerr<<ex.what()<<endl;
  }
}

void Web_Service::run()
{
  try
  {
    server.run();
  }
  catch (Server::Exception e)
  {
    cerr << e.getMessage() << endl;
  }
}


#include "Web_Handlers.h"

using namespace std;

/*Response *RandomNumberHandler::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  string body;
  body += "<!DOCTYPE html>";
  body += "<html>";
  body += "<body style=\"text-align: center;\">";
  body += "<h1>AP HTTP</h1>";
  body += "<p>";
  body += "a random number in [1, 10] is: ";
  body += to_string(rand() % 10 + 1);
  body += "</p>";
  body += "<p>";
  body += "SeddionId: ";
  body += req->getSessionId();
  body += "</p>";
  body += "</body>";
  body += "</html>";
  res->setBody(body);
  return res;
}*/

Response* SignupHandler::callback(Request* req)
{
  map< string, string > user_info;
  if (req->getBodyParam("password") != req->getBodyParam("confirmpassword"))
  {
    throw Server::Exception("Password doesn't match");
  }
  //user_info["sessionid"] = md5(req->getBodyParam("Username"));
  user_info["username"] = req->getBodyParam("username");
  user_info["password"] = req->getBodyParam("password");
  user_info["email"] = req->getBodyParam("email");
  user_info["age"] = req->getBodyParam("age");
  if (req->getBodyParam("type-publisher") == "on")
  {
    user_info["publisher"] = "true";
  }
  my_core->sign_up(user_info);
  Response *res = Response::redirect("/homepage");
  res->setSessionId(req->getBodyParam("username"));
  my_core->cout_users();
  return res;
}

Response *LoginHandler::callback(Request *req) 
{
  map<string, string> user_info;
  //user_info["sessionid"] = md5(req->getBodyParam("Username"));
  user_info["username"] = req->getBodyParam("username");
  user_info["password"] = req->getBodyParam("password");
  my_core->login(user_info);
  Response *res = Response::redirect("/homepage");
  res->setSessionId(req->getBodyParam("username"));
  return res;
}

Response* LogoutHandler::callback(Request* req)
{
  my_core->logout();
  Response *res = Response::redirect("/");
  res->setSessionId("");
  return res;
}


Response* PostfilmHandler::callback(Request* req)
{
  map<string,string> film_parameter;
  film_parameter["name"] = req->getBodyParam("name");
  film_parameter["price"] = req->getBodyParam("price");
  film_parameter["year"] = req->getBodyParam("year");
  film_parameter["length"] = req->getBodyParam("length");
  film_parameter["summary"] = req->getBodyParam("summary");
  film_parameter["director"] = req->getBodyParam("director");
  my_core->add_film(film_parameter);
  Response *res = Response::redirect("/homepage");
  return res;
}

HomepageHandler::HomepageHandler(string filePath) : TemplateHandler(filePath) 
{
}


map<string,string> HomepageHandler::handle(Request* req)
{
  map<string,string> context;
  map<string, string> filter;
  filter["name"] = req->getQueryParam("Name");
  if (req->getQueryParam("Min_rate") != "")
  {
    filter["min_rate"] = req->getQueryParam("Min_rate");
  }
  if (req->getQueryParam("Min_year") != "")
  {
    filter["min_year"] = req->getQueryParam("Min_year");
  }
  if (req->getQueryParam("Max_year") != "")
  {
    filter["max_year"] = req->getQueryParam("Max_year");
  }
  if (req->getQueryParam("Price") != "")
  {
    filter["price"] = req->getQueryParam("Price");
  }
  filter["summary"] = req->getQueryParam("Summary");
  filter["director"] = req->getQueryParam("Director");
  my_core->get_search_films(filter);
  context = my_core->get_home_page_films();
  context["money"] = to_string(my_core->right_now_user->get_money());
  if(my_core->right_now_user->get_my_type() == PUBLISHER)
  {
    context["ispublisher"] = "true";
  }
  if (my_core->right_now_user->get_my_type() == CUSTOMER )
  {
    context["ispublisher"] = "false";
  }

  cout << "-------" << endl;
  cout << "context is:" << endl;
  for (auto it = context.begin(); it != context.end(); it++)
  {
    cout << "first: " << it->first << "  second is: " << it->second << endl;
  }
  cout << "-------" << endl;


  return context;
}

Response* DeleteHandler::callback(Request* req)
{
  cout << "it's del" << endl;
  map<string,string> _parameter;
  _parameter["film_id"] = req->getBodyParam("film_id");
  my_core->delete_film(_parameter);
  Response *res = Response::redirect("/homepage");
  return res;
}

ProfileHandler::ProfileHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> ProfileHandler::handle(Request *req)
{
  map<string, string> context;
  map<string, string> filter;
  filter["name"] = req->getQueryParam("Name");
  if (req->getQueryParam("Min_rate") != "")
  {
    filter["min_rate"] = req->getQueryParam("Min_rate");
  }
  if (req->getQueryParam("Min_year") != "")
  {
    filter["min_year"] = req->getQueryParam("Min_year");
  }
  if (req->getQueryParam("Max_year") != "")
  {
    filter["max_year"] = req->getQueryParam("Max_year");
  }
  if (req->getQueryParam("Price") != "")
  {
    filter["price"] = req->getQueryParam("Price");
  }
  filter["summary"] = req->getQueryParam("Summary");
  filter["director"] = req->getQueryParam("Director");
  my_core->purchased_film(filter);
  context = my_core->get_home_page_films();
  context["money"] = to_string(my_core->right_now_user->get_money());
  if (my_core->right_now_user->get_my_type() == PUBLISHER)
  {
    context["ispublisher"] = "true";
  }
  if (my_core->right_now_user->get_my_type() == CUSTOMER)
  {
    context["ispublisher"] = "false";
  }

  cout << "-------" << endl;
  cout << "context is:" << endl;
  for (auto it = context.begin(); it != context.end(); it++)
  {
    cout << "first: " << it->first << "  second is: " << it->second << endl;
  }
  cout << "-------" << endl;

  return context;
}

Response *ChargeHandler::callback(Request *req)
{
  if(my_core->right_now_user->get_my_type() == PUBLISHER)
  {
    my_core->receive_money_from_core();
  }
  map<string,string> _parameter;
  _parameter["amount"] = req->getBodyParam("amount");
  my_core->adding_money(_parameter);
  Response *res = Response::redirect("/profile");
  return res;
}

GetfilmHandler::GetfilmHandler(string filePath) : TemplateHandler(filePath)
{
}

map<string, string> GetfilmHandler::handle(Request *req)
{
  map<string, string> context;
  map<string, string> _parameter;
  _parameter["film_id"] = req->getQueryParam("film_id");
  cout << "film id is:" << req->getQueryParam("film_id") <<endl;
  my_core->get_search_films(_parameter);
  context = my_core -> get_home_page_films();
  context["money"] = to_string(my_core->right_now_user->get_money());
  if (my_core->right_now_user->get_my_type() == PUBLISHER)
  {
    context["ispublisher"] = "true";
  }
  if (my_core->right_now_user->get_my_type() == CUSTOMER)
  {
    context["ispublisher"] = "false";
  }
  cout << "-------" << endl;
  cout << "context is:" << endl;
  for (auto it = context.begin(); it != context.end(); it++)
  {
    cout << "first: " << it->first << "  second is: " << it->second << endl;
  }
  cout << "-------" << endl;
  return context;
}

Response *BuyHandler::callback(Request *req)
{
  cout<<"it's buy"<<endl;
  map<string,string> _parameter;
  _parameter["film_id"] = req->getBodyParam("film_id");
  my_core->buying_film(_parameter);
  cout << my_core -> right_now_user ->get_money () << endl;
  Response *res = Response::redirect("/homepage");
  return res;
}

Response *RateHandler::callback(Request *req)
{
  string rate = "";
  if (req->getBodyParam("Rate") != "")
  {
    rate = req->getBodyParam("Rate");
  }
  map<string , string > _parameter;
  _parameter["film_id"] = req->getBodyParam("film_id");
  _parameter["score"] = rate;
  my_core->add_score(_parameter);
  Response *res = Response::redirect("/homepage");
  return res;
}
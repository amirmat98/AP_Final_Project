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

Response *UploadHandler::callback(Request *req) {
  string name = req->getBodyParam("file_name");
  string file = req->getBodyParam("file");
  cout << name << " (" << file.size() << "B):\n" << file << endl;
  Response *res = Response::redirect("/");
  return res;
}

ColorHandler::ColorHandler(string filePath) : TemplateHandler(filePath) {}

map<string, string> ColorHandler::handle(Request *req) {
  map<string, string> context;
  string newName = "I am " + req->getQueryParam("name");
  context["name"] = newName;
  context["color"] = req->getQueryParam("color");
  return context;
}

#include "Web_Service.h"

using namespace std;

Web_Service::Web_Service(Core* core)
{
  netflix_core = core;
  try
  {
    server.my_core = netflix_core;
    server.setNotFoundErrPage("static/404.html");
    server.post("/login", new LoginHandler());
    server.post("/up", new UploadHandler());
    server.get("/login", new ShowPage("static/logincss.html"));
    server.get("/up", new ShowPage("static/upload_form.html"));
    server.get("/rand", new RandomNumberHandler());
    server.get("/home.png", new ShowImage("static/home.png"));
    server.get("/", new ShowPage("static/home.html"));
    server.get("/colors", new ColorHandler("template/colors.html"));
  }
  catch (Server::Exception e)
  {
    cerr << e.getMessage() << endl;
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


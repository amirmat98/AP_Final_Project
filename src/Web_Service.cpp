#include "Web_Service.h"

using namespace std;

Web_Service::Web_Service(Core* ccore)
{
  try
  {
    server.my_core = ccore;
    server.setNotFoundErrPage("static/404.html");
    server.get("/login", new ShowPage("static/logincss.html"));
    server.post("/login", new LoginHandler());
    server.get("/up", new ShowPage("static/upload_form.html"));
    server.post("/up", new UploadHandler());
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


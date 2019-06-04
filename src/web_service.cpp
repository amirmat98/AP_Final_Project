#include "web_service.h"

using namespace std;

web_service::web_service()
{
  try
  {
    MyServer server;
    server.setNotFoundErrPage("static/404.html");
    server.get("/login", new ShowPage("static/logincss.html"));
    server.post("/login", new LoginHandler());
    server.get("/up", new ShowPage("static/upload_form.html"));
    server.post("/up", new UploadHandler());
    server.get("/rand", new RandomNumberHandler());
    server.get("/home.png", new ShowImage("static/home.png"));
    server.get("/", new ShowPage("static/home.html"));
    server.get("/colors", new ColorHandler("template/colors.html"));
    server.run();
  }
  catch (Server::Exception e)
  {
    cerr << e.getMessage() << endl;
  }
}


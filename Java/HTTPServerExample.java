import com.sun.net.httpserver.*;
import java.io.*;
import java.net.InetSocketAddress;

public class HTTPServerExample {

  public static void main(String[] args) throws IOException {
      HttpServer server = HttpServer.create(new InetSocketAddress(8500), 0);
      HttpContext context = server.createContext("/");
      context.setHandler(HTTPServerExample::handleRequest);
      server.start();
  }

  private static void handleRequest(HttpExchange exchange) throws IOException {
      String response = "Hello world";
      exchange.sendResponseHeaders(200, response.getBytes().length);//response code and length
      OutputStream os = exchange.getResponseBody();
      os.write(response.getBytes());
      os.close();
  }
}
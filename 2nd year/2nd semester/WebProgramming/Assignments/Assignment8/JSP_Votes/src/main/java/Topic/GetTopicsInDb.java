package Topic;

import Auth.AuthManager;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "GetTopicsInDbServlet")
public class GetTopicsInDb extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        System.out.println("Wooorks bois");
        //request.setAttribute("message", "hello there");
        PrintWriter out = response.getWriter();
        response.setContentType("text/html");
        out.write("<H1>Hello from a Servlet</h2>");
        out.close();

        // !!!!!!!!!!!!!!!!!
        // DOESN'T WORK
        // DELETE THIS
        // !!!!!!!!!!!!!!!!!
    }
}

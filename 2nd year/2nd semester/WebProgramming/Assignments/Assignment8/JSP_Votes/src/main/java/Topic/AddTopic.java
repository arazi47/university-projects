package Topic;

import Auth.AuthManager;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "AddTopicServlet")
public class AddTopic extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String title = req.getParameter("topictitle");
        String text = req.getParameter("topictext");

        AuthManager.addTopicToDatabase(title, text, req.getSession().getAttribute("username").toString());

        resp.sendRedirect("/Gradle___Votes___ro_ubb_1_0_SNAPSHOT_war/loggedin.jsp");
    }
}

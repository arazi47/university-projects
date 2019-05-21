package Topic;

import Auth.AuthManager;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "AddReplyServlet")
public class AddReply extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String replyText = req.getParameter("replytext");

        String threadTitle = req.getSession().getAttribute("threadtitle").toString();
        String username = req.getSession().getAttribute("username").toString();
        AuthManager.addReplyToDatabase(threadTitle, username, replyText);

        String threadUrl = "/Gradle___Votes___ro_ubb_1_0_SNAPSHOT_war/loggedin.jsp?thread=" + threadTitle;
        resp.sendRedirect(threadUrl);
    }
}

package Auth;

import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet(name = "LoginServlet")
public class Login extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        // Encrypt the password
        //String encryptedPassword = AuthManager.encrypt(password);

        // If the login data is valid -> log the user in
        if(AuthManager.validUserLogin(username, password)) {
            loginUser(req.getSession(), username);
            resp.sendRedirect("/Gradle___Votes___ro_ubb_1_0_SNAPSHOT_war/loggedin.jsp");
            return;
        }

        // Redirect the user to "/"
        resp.sendRedirect("/Gradle___Votes___ro_ubb_1_0_SNAPSHOT_war/index.jsp?error=MailOrPasswordIncorrect");
    }

    public static void loginUser(HttpSession session, String username) {
        session.setAttribute("username", username);
    }
}

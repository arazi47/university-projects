package Auth;

import DB.DBManager;

//import javax.jws.WebService;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class AuthManager {
    public static int getUserIdByMail(String mail){
        try{
            String sql = "select * from Users where userEmail = '" + mail + "';";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement( sql );
            ResultSet resultSet = stmt.executeQuery();

            while(resultSet.next()){
                return resultSet.getInt( 1 );
            }
            return 0;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return 0;
    }

    public static String getUserNameById(Integer id) {
        try {
            String sql = "select * from Users where id = " + id + ";";
            PreparedStatement statement = DBManager.getConnection().prepareStatement( sql );
            ResultSet resultSet = statement.executeQuery();

            while (resultSet.next()) {
                return resultSet.getString( 3 );
            }
            return "";
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "";
    }

    public static Boolean validUserLogin(String username, String encryptedPassword) {
        try {
            String sql = "SELECT * FROM administrator WHERE username = '" + username + "'";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            ResultSet results = stmt.executeQuery();

            while(results.next()) {
                return true;
            }
            return false;

        } catch(SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    public static void addUserToDataBase(String mail, String name, String encryptedPassword) {
        String sql = "INSERT INTO Users(userEmail, userName, userPassword) VALUES ('" + mail + "','" + name + "','" + encryptedPassword + "');";
        System.out.println( sql );
        // Execute the query
        try {
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            stmt.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static Boolean isMailUnique(String mail) {
        try {
            String sql = "SELECT * FROM Users where userEmail = '" + mail +"';";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            ResultSet results = stmt.executeQuery();

            while(results.next()) {
                return false;
            }
            return true;

        } catch(SQLException e) {
            e.printStackTrace();
        }

        return false;
    }

    public static String encrypt(String passwordToHash) {
        String generatedPassword = null;
        try {
            // Create MessageDigest instance for MD5
            MessageDigest md = MessageDigest.getInstance("MD5");
            //Add password bytes to digest
            md.update(passwordToHash.getBytes());
            //Get the hash's bytes
            byte[] bytes = md.digest();
            //This bytes[] has bytes in decimal format;
            //Convert it to hexadecimal format
            StringBuilder sb = new StringBuilder();
            for(int i=0; i< bytes.length ;i++)
            {
                sb.append(Integer.toString((bytes[i] & 0xff) + 0x100, 16).substring(1));
            }
            //Get complete hashed password in hex format
            generatedPassword = sb.toString();
        }
        catch (NoSuchAlgorithmException e)
        {
            e.printStackTrace();
        }
        return generatedPassword;
    }

    public static void addTopicToDatabase(String title, String text, String author) {
        String sql = "INSERT INTO topics VALUES ('" + title + "', '" + text + "', '" + author + "')";
        //System.out.println(sql);
        // Execute the query
        try {
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            stmt.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static String getAllTopicsFromDbInHTML() {
        String output = "";
        try {
            String sql = "SELECT * FROM topics";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            ResultSet results = stmt.executeQuery();

            while(results.next()) {
                String topicTitle = results.getString("title");
                String topicText = results.getString("text");
                String author = results.getString("author");
                output += "<a href=\"?thread=" + topicTitle + "\" class=\"list-group-item active\"><h4 class=\"list-group-item-heading\">" + "<b>" + author + "</b> posted: " + topicTitle + "</h4><p class=\"list-group-item-text\">" + topicText + "</p></a><br>";
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return output;
    }

    public static String getTopicWithName(String title) {
        String output = "";
        try {
            String sql = "SELECT * FROM topics WHERE title = '" + title + "'";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            ResultSet results = stmt.executeQuery();

            while(results.next()) {
                String topicTitle = results.getString("title");
                String topicText = results.getString("text");
                String author = results.getString("author");
                output += "<a href=\"?thread=" + topicTitle + "\" class=\"list-group-item active\"><h4 class=\"list-group-item-heading\">" + "<b>" + author + "</b> posted: " + topicTitle + "</h4><p class=\"list-group-item-text\">" + topicText + "</p></a><br>";
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return output;
    }

    public static String getRepliesFromTopic(String topicTitle, String currentUsername) {
        String output = "";
        try {
            String sql = "SELECT * FROM replies WHERE threadname = '" + topicTitle + "'";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            ResultSet results = stmt.executeQuery();

            while(results.next()) {
                String replyText = results.getString("reply");
                String replyAuthor = results.getString("author");
                //output += "<a href=\"?thread=" + topicTitle + "\" class=\"list-group-item active\"><h4 class=\"list-group-item-heading\">" + "<b>" + author + "</b> posted: " + topicTitle + "</h4><p class=\"list-group-item-text\">" + topicText + "</p></a><br>";
                //output += "<p><b>" + replyAuthor + "</b> replied: " + replyText + "</p><form action=\"${pageContext.request.contextPath}/DeleteReplyServlet\" method=\"post><button type=\"submit\" class=\"btn btn-small\">Delete</button></form><br>";
                output += "<p><b>" + replyAuthor + "</b> replied: " + replyText + "</p>";

                //System.out.println("AAAA " + replyAuthor + " _----- BBB " + currentUsername);

                if (replyAuthor.equals(currentUsername))
                    output += "<button type=\"button\" class=\"btn btn-primary btn-small\" onclick=\"location.href='loggedin.jsp?deletereply=" + replyText + "'\">Delete</button>";

                output += "<br>";
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return output;
    }

    public static void addReplyToDatabase(String threadTitle, String username, String replyText) {
        String sql = "INSERT INTO replies VALUES ('" + threadTitle + "', '" + username + "', '" + replyText + "')";
        //System.out.println(sql);
        // Execute the query
        try {
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            stmt.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static void deleteReply(String replyText) {
        replyText = replyText.replaceAll("\\s+$", "");
        String sql = "DELETE FROM replies WHERE reply = '" + replyText + "'";
        System.out.println(sql);
        try {
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            stmt.execute();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static boolean validDeleteReply(String replyToDelete, String currentUsername) {
        try {
            String sql = "SELECT author FROM replies WHERE reply = '" + replyToDelete + "'";
            PreparedStatement stmt = DBManager.getConnection().prepareStatement(sql);
            ResultSet results = stmt.executeQuery();

            while(results.next()) {
                return results.getString("author").equals(currentUsername);
            }
        } catch(SQLException e) {
            e.printStackTrace();
        }

        return false;
    }
}

<%@ page import="java.util.Random" %>
<%@ page import="Auth.AuthManager" %><%--
  Created by IntelliJ IDEA.
  User: admin
  Date: 5/19/2019
  Time: 10:10 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <%
        //String test = "<b><u>bold and underlined</u></b>";
        //pageContext.setAttribute("test", test);

        // get all topics from db
        String output = AuthManager.getAllTopicsFromDbInHTML();
        pageContext.setAttribute("output", output);

    %>

    ${output}
</body>
</html>

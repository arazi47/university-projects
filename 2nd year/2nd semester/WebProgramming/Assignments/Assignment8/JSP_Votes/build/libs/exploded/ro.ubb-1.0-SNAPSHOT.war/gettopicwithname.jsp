<%@ page import="Auth.AuthManager" %><%--
  Created by IntelliJ IDEA.
  User: admin
  Date: 5/19/2019
  Time: 2:41 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Reply to topic</title>
</head>
<body>
<%
    String output = AuthManager.getTopicWithName(request.getParameter("thread"));
    pageContext.setAttribute("output", output);

    String replies = AuthManager.getRepliesFromTopic(request.getParameter("thread"), session.getAttribute("username").toString());
    pageContext.setAttribute("replies", replies);

    session.setAttribute("threadtitle", request.getParameter("thread"));

%>

${output}
${replies}
</body>
</html>

<%@ page import="Auth.AuthManager" %><%--
  Created by IntelliJ IDEA.
  User: admin
  Date: 5/18/2019
  Time: 4:53 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Forum home</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>


    <script src="http://code.jquery.com/jquery-latest.min.js"></script>
    <script>
        $(document).ready(function() {
            $.get('GetTopicsInDb', function() {
                console.log("Called doGet()");
            });
        });
    </script>

</head>
<body>

<button type="button" class="btn btn-primary btn-block" onclick="location.href='loggedin.jsp'">Home</button>
<br><br>

<%
    if (request.getParameter("deletereply") != null) {
        //System.out.println("USERNAME IS IS IS " + session.getAttribute("username"));
        if (AuthManager.validDeleteReply(request.getParameter("deletereply"), session.getAttribute("username").toString()))
            AuthManager.deleteReply(request.getParameter("deletereply"));
    }
%>

<%
    if(request.getParameter( "thread" ) == null) {
        // Set the current thread title that we're viewing
        // So when we delete a reply, we get redirected back to the same page
        //session.setAttribute("currentthreadtitle", request.getParameter("thread"));
%>

<div class="container">
    <form action="${pageContext.request.contextPath}/AddTopicServlet" method="post">
        <div id="loginForm" class="form-group">
            <input type="text" name="topictitle" id="inputTopicTitle" placeholder="Title">
        </div>
        <div class="form-group">
            <input type="text" name="topictext" id="topictext" placeholder="Text">
        </div>
        <button type="submit" class="btn btn-primary">Add topic</button>
    </form>

    <jsp:include page="/gettopicsindb.jsp" />

</div>
<%
    } else {
%>

<jsp:include page="/gettopicwithname.jsp" />

<form action="${pageContext.request.contextPath}/AddReplyServlet" method="post">
    <div id="addReplyForm" class="form-group">
        <input type="text" name="replytext" id="inputReplyText" placeholder="Text">
    </div>
    <button type="submit" class="btn btn-primary">Submit reply</button>
</form>

<%
    }
%>

    <!--

    <button type="button" id="addtopicbtn" class="btn btn-primary" data-toggle="modal" data-target="#myModal">Add topic</button>
<div id="myModal" class="modal fade" role="dialog">
    <div class="modal-dialog">
        <div class="modal-content">
            <div class="modal-header">
                <h4 class="modal-title">Add topic</h4>
                <button type="button" class="close" data-dismiss="modal">&times;</button>
            </div>
            <form action="${pageContext.request.contextPath}/AddTopicServlet" method="post">
            <div class="modal-body">
                <input type="text" id="topictitle" placeholder="Title">
                <br><br>
                <input type="text" id="topicdesc" placeholder="Description">
            </div>
            <div class="modal-footer">
                <button type="submit" class="btn btn-primary" id="savetopicbtn" data-dismiss="modal" onclick="saveTask()">Add</button>
                <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
            </div>
            </form>
        </div>
    </div>
</div>
   -->

<br>
<br>
<div id="topiclistdiv" class="list-group list-group-item-mine"></div>

</div>
</body>
</html>

<script>
    function saveTask() {
        topicTitle = document.getElementById("topictitle").value;
        topicText = document.getElementById("topictext").value

        topicList = document.getElementById("topiclistdiv");
        topicList.innerHTML += "<a href=\"#\" class=\"list-group-item active\"><h4 class=\"list-group-item-heading\">" + topicTitle + "</h4><p class=\"list-group-item-text\">" + topicText + "</p></a>";
    }
</script>
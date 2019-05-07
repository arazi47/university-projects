<?php
// USED IN adminhome.php

session_start();

$servername = "localhost";
$username = "root";
$password = "root1234";
$dbname = "weblab7";

$db = mysqli_connect($servername, $username, $password, $dbname);

if (isset($_POST['submit_update_entry'])) {
    $id = mysqli_real_escape_string($db, $_POST['id']);
    $email = mysqli_real_escape_string($db, $_POST['email']);
    $title = mysqli_real_escape_string($db, $_POST['title']);
    $comment = mysqli_real_escape_string($db, $_POST['comment']);

    $curr_date = date_create()->format('Y-m-d');
    //$query = "INSERT INTO guestbook (author_email, title, description, posted_on) VALUES ('$email', '$title', '$comment', '$curr_date')";

    $query = "UPDATE guestbook SET author_email = '$email', title = '$title', description = '$comment', posted_on = '$curr_date' WHERE id = '$id'";

    //$query = "INSERT INTO guestbook (author_email, title, description, posted_on) VALUES ('emailaici', 'titluaici', 'commaici', '01-09-01')";
    //$query = "INSERT INTO Administrator (username) VALUES ('hi')";

    mysqli_query($db, $query);
    header('location: adminhome.php');
}

if (isset($_POST['submit_delete_entry'])) {
    $id = mysqli_real_escape_string($db, $_POST['id']);
    //$email = mysqli_real_escape_string($db, $_POST['email']);
    //$title = mysqli_real_escape_string($db, $_POST['title']);
    //$comment = mysqli_real_escape_string($db, $_POST['comment']);

    //$curr_date = date_create()->format('Y-m-d');
    //$query = "INSERT INTO guestbook (author_email, title, description, posted_on) VALUES ('$email', '$title', '$comment', '$curr_date')";

    //$query = "UPDATE guestbook SET author_email = '$email', title = '$title', description = '$comment', posted_on = '$curr_date' WHERE id = '$id'";

    //$query = "INSERT INTO guestbook (author_email, title, description, posted_on) VALUES ('emailaici', 'titluaici', 'commaici', '01-09-01')";
    //$query = "INSERT INTO Administrator (username) VALUES ('hi')";

    $query = "DELETE FROM guestbook WHERE id = '$id'";

    mysqli_query($db, $query);
    header('location: adminhome.php');
}

//echo '<script>console.log("ASD")</script>';
?>
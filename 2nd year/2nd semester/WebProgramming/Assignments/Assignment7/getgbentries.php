<?php
// get all guest book entries without pagination
// used in adminhome.php

// session already started error
//session_start();

$servername = "localhost";
$username = "root";
$password = "root1234";
$dbname = "weblab7";

$db = mysqli_connect($servername, $username, $password, $dbname);

//if (isset($_POST['submit_add_entry'])) {
    //$email = mysqli_real_escape_string($db, $_POST['email']);
    //$title = mysqli_real_escape_string($db, $_POST['title']);
    //$comment = mysqli_real_escape_string($db, $_POST['comment']);

    //$curr_date = date_create()->format('Y-m-d');
    //$query = "INSERT INTO guestbook (author_email, title, description, posted_on) VALUES ('$email', '$title', '$comment', '$curr_date')";

    $query = "SELECT * FROM guestbook";
    $result = mysqli_query($db, $query);

    echo "<table id=\"gbentries-table\" border = \"1\">
<tr>
<th>ID</th>
<th>Author's Email</th>
<th>Title</th>
<th>Description</th>
<th>Posted on</th>
</tr>";
while($row = mysqli_fetch_array($result)) {
    echo "<tr>";
    echo "<td>" . $row['id'] . "</td>";
    echo "<td>" . $row['author_email'] . "</td>";
    echo "<td>" . $row['title'] . "</td>";
    echo "<td>" . $row['description'] . "</td>";
    echo "<td>" . $row['posted_on'] . "</td>";
    echo "</tr>";
}
echo "</table>";

echo '<script>function addRowHandlers() {
    var table = document.getElementById("gbentries-table");
    var rows = table.getElementsByTagName("tr");
    alert("piii");
    for (i = 1; i < rows.length; i++) {
        var row = table.rows[i];
        row.onclick = function(myrow){
                          return function() { 
                             var cell = myrow.getElementsByTagName("td")[0];
                             var id = cell.innerHTML;
                             alert("id:" + id);
                      };
                  }(row);
    }
}</script>';

    //$query = "INSERT INTO guestbook (author_email, title, description, posted_on) VALUES ('emailaici', 'titluaici', 'commaici', '01-09-01')";
    //$query = "INSERT INTO Administrator (username) VALUES ('hi')";

    //mysqli_query($db, $query);
    //header('location: guesthome.php');
//}

//if ($_POST['authors-select'] == "All"){
//echo '<script>console.log("ASD")</script>';}
?>
<?php

        if (isset($_GET['pageno'])) {
            $pageno = $_GET['pageno'];
        } else {
            $pageno = 1;
        }
        $no_of_records_per_page = 4; // number of guest book entries
        $offset = ($pageno-1) * $no_of_records_per_page;

        $conn=mysqli_connect("localhost","root","root1234","weblab7");
        // Check connection
        if (mysqli_connect_errno()){
            echo "Failed to connect to MySQL: " . mysqli_connect_error();
            die();
        }

        $total_pages_sql = "SELECT COUNT(*) FROM guestbook";
        $result = mysqli_query($conn,$total_pages_sql);
        $total_rows = mysqli_fetch_array($result)[0];
        $total_pages = ceil($total_rows / $no_of_records_per_page);

        $sql = "SELECT * FROM guestbook LIMIT $offset, $no_of_records_per_page";
        $res_data = mysqli_query($conn,$sql);
		echo "<table border = \"1\">
<tr>
<th>Author's Email</th>
<th>Title</th>
<th>Description</th>
<th>Posted on</th>
</tr>";
while($row = mysqli_fetch_array($res_data)) {
    echo "<tr>";
    echo "<td>" . $row['author_email'] . "</td>";
    echo "<td>" . $row['title'] . "</td>";
    echo "<td>" . $row['description'] . "</td>";
    echo "<td>" . $row['posted_on'] . "</td>";
    echo "</tr>";
}
echo "</table>";

        mysqli_close($conn);
    ?>
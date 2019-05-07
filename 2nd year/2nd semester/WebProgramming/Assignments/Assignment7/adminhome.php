<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Admin</title>
	<meta name="viewport" content="width=device-width, initial-scale=1">

	<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
	<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
	<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>

	<link rel="stylesheet" type="text/css" media="screen" href="main.css">
	<script type="text/javascript" src="main.js"></script>
</head>
<body>
	<button type="button" class="btn btn-primary btn-block" onclick="location.href='index.html'">Home</button>
	<p class="font-weight-normal">Admin home</p>

	<select id="authors-select">
		<option>All</option>
	</select>

	<p>Filter by author:</p>
	<?php include('getauthorsinselect.php'); ?>
	<br>
	<br>
	<?php include('getgbentries.php'); ?>

	<p class="font-weight-normal">Modify info:</p>

<form action="updategbentry.php" method="post">
	<div id="update-gbentry-div">
		<input id="id-input" type="text" name="id" placeholder="ID" readonly>
		<br>
		<input id="email-input" type="text" name="email" placeholder="E-mail">
		<br>
		<input id="title-input" type="text" name="title" placeholder="Title">
		<br>
		<input id="comment-input" type="text" name="comment" placeholder="Comment">
		<br>
		<button id="update-gbentry-button" type="submit" name="submit_update_entry" class="btn btn-primary btn-small">Save changes</button>
		<button id="delete-gbentry-button" type="submit" name="submit_delete_entry" class="btn btn-primary btn-small">Delete entry</button>
	</div>
</form>
</body>
</html>

USE weblab7;

DROP TABLE IF EXISTS GuestBook;
CREATE TABLE GuestBook(
	id INT PRIMARY KEY IDENTITY(1, 1),
	author_email VARCHAR(50),
	title VARCHAR(50),
	COMMENT VARCHAR(255),
	posted_on DATE
);

DROP TABLE IF EXISTS Administrator;
CREATE TABLE Administrator(
	id INT PRIMARY KEY IDENTITY(1, 1),
	username VARCHAR(20),
);

-- mysql:
DROP TABLE IF EXISTS GuestBook;
CREATE TABLE GuestBook (
	id INT NOT NULL AUTO_INCREMENT,
	author_email VARCHAR(50),
	title VARCHAR(50),
	description VARCHAR(255),
	posted_on DATE,
	PRIMARY KEY (id)
	);

DROP TABLE IF EXISTS Administrator;
CREATE TABLE Administrator (
	id INT NOT NULL AUTO_INCREMENT,
	username VARCHAR(20),
	PRIMARY KEY (id)
	);

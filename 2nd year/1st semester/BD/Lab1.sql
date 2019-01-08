USE master
GO
DROP DATABASE IF EXISTS TeaShop;
GO

CREATE DATABASE TeaShop;
GO
USE TeaShop;

CREATE TABLE tea_type (
type_id INT PRIMARY KEY IDENTITY,
name VARCHAR(50),
no_of_teas INT NOT NULL
);

CREATE TABLE tea (
tea_id INT PRIMARY KEY,
name VARCHAR(50) NOT NULL,
price INT CHECK(price > 0 AND price < 40),
type_id INT FOREIGN KEY REFERENCES tea_type(type_id)
)

CREATE TABLE flavor (
fid INT PRIMARY KEY,
name VARCHAR(50) DEFAULT 'Mint',
effect INT
)

CREATE TABLE tea_flavor (
tea_id INT FOREIGN KEY REFERENCES tea(tea_id),
flavor_id INT FOREIGN KEY REFERENCES flavor(fid),
no_of_flavors INT,
CONSTRAINT pk_tea_flavor PRIMARY KEY(tea_id, flavor_id)
)

CREATE TABLE barcode (
id INT FOREIGN KEY REFERENCES tea(tea_id),
no_of_lines INT,
CONSTRAINT pk_B PRIMARY KEY(id)
)
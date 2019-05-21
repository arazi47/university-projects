USE deadlocktestdb;
GO

DROP TABLE IF EXISTS Table1
CREATE TABLE Table1 (
	id INT IDENTITY,
	name VARCHAR(20),
	somestr VARCHAR(20)
);

DROP TABLE IF EXISTS Table2
CREATE TABLE Table2 (
	id INT IDENTITY,
	name VARCHAR(20),
	someint INT
);

INSERT INTO Table1(name, somestr) VALUES ('name1', 'testval');
INSERT INTO Table2(name, someint) VALUES ('name2', 10); 

SELECT * FROM Table1
SELECT * FROM Table2

GO

-- Deadlock part 1
CREATE OR ALTER PROCEDURE deadlock1
AS
BEGIN TRANSACTION;
UPDATE Table1 SET somestr = 'updateval' WHERE name = 'name1';
WAITFOR DELAY '00:00:10';
UPDATE Table2 SET someint = 2 WHERE name = 'name2';
COMMIT;
GO

-- Deadlock part 2
CREATE OR ALTER PROCEDURE deadlock2
AS
BEGIN TRANSACTION;
UPDATE Table2 SET someint = 2 WHERE name = 'name2';
WAITFOR DELAY '00:00:10';
UPDATE Table1 SET somestr = 'updateval' WHERE name = 'name1';
COMMIT;
GO

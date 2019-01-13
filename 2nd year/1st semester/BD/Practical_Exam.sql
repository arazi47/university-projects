USE MountainsDB

DROP TABLE IF EXISTS TouristMountains
DROP TABLE IF EXISTS Mountains
DROP TABLE IF EXISTS Hotels

DROP TABLE IF EXISTS Tourists
CREATE TABLE Tourists (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name VARCHAR(100),
	age INT,
	experience INT);

DROP TABLE IF EXISTS MountainAreas
CREATE TABLE MountainAreas (
	id INT PRIMARY KEY IDENTITY(1, 1),
	max_height INT);

CREATE TABLE Mountains (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name VARCHAR(100),
	height INT,
	maid INT FOREIGN KEY REFERENCES MountainAreas(id));


CREATE TABLE Hotels (
	id INT PRIMARY KEY IDENTITY(1, 1),
	stars INT,
	min_price INT,
	maid INT FOREIGN KEY REFERENCES MountainAreas(id));

CREATE TABLE TouristMountains (
	tid INT FOREIGN KEY REFERENCES Tourists(id),
	mid INT FOREIGN KEY REFERENCES Mountains(id),
	no_of_days INT,
	budget INT,
	PRIMARY KEY (tid, mid));

INSERT INTO Tourists VALUES ('n1', 10, 1), ('n2', 20, 5), ('n3', 25, 3), ('n4', 48, 9);
INSERT INTO MountainAreas VALUES (100), (500), (1000), (1500), (2000), (2500), (3000), (3500);
INSERT INTO Mountains VALUES ('m1', 1428, 1), ('m2', 2544, 2), ('m3', 8848, 3);
INSERT INTO Hotels VALUES (1, 400, 1), (2, 800, 2), (5, 1200, 3);
INSERT INTO TouristMountains VALUES (1, 1, 3, 500), (2, 1, 4, 1000), (3, 2, 7, 790), (4, 2, 5, 100); 

GO
CREATE OR ALTER PROCEDURE uspAddTouristToMountain (@tid INT, @mid INT, @days INT, @budget INT)
AS
	IF EXISTS (SELECT * FROM TouristMountains TM WHERE TM.tid = @tid AND TM.mid = @mid)
	BEGIN
		PRINT 'Cannot add!'
	END
	ELSE
	BEGIN
		INSERT INTO TouristMountains VALUES (@tid, @mid, @days, @budget);
		PRINT 'Added!'
	END
GO

SELECT * FROM TouristMountains

EXEC uspAddTouristToMountain 4, 2, 5, 100

GO
CREATE OR ALTER VIEW vHotelsWithMoreThanTwoStars
AS
	SELECT M.name, H.id
	FROM Mountains M, Hotels H
	WHERE M.maid = H.maid AND H.stars > 2
GO

SELECT * FROM vHotelsWithMoreThanTwoStars

GO
CREATE OR ALTER FUNCTION ufMountainsWithMaxTourists () RETURNS TABLE
	RETURN
		SELECT M.name, COUNT(M.name) total_tourists
		FROM Mountains M
		INNER JOIN TouristMountains TM ON TM.mid = M.id
		GROUP BY M.name
		HAVING COUNT(M.name) >= ALL (
			SELECT COUNT(*)
			FROM Mountains M
			INNER JOIN TouristMountains TM ON TM.mid = M.id
			GROUP BY M.name
		)
GO

SELECT * FROM ufMountainsWithMaxTourists()
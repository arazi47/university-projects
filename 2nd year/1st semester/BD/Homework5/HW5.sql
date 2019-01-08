use hw5db

DROP TABLE IF EXISTS TableA
CREATE TABLE TableA (
	aid INT PRIMARY KEY IDENTITY(1, 1),
	a2 INT UNIQUE,
	something VARCHAR(100)
)
INSERT INTO TableA VALUES (1, 'smth'), (2, 'other'), (3, 'this'), (199, 'that'), (177, 'and'), (12, 'the')

DROP TABLE IF EXISTS TableB
CREATE TABLE TableB (
	bid INT PRIMARY KEY IDENTITY(1, 1),
	b2 INT
)

INSERT INTO TableB VALUES (1), (-5), (-3), (2), (8), (199), (178)

DROP TABLE IF EXISTS TableC
CREATE TABLE TableC (
	cid INT PRIMARY KEY IDENTITY(1, 1),
	aid INT FOREIGN KEY REFERENCES TableA(aid),
	bid INT FOREIGN KEY REFERENCES TableB(bid),
	something VARCHAR(100)
)

INSERT INTO TableC VALUES (3, 2, 'smth'), (4, 7, 'smth2'), (5, 7, 'test3'), (6, 5, 'test4')

SELECT * FROM TableA
SELECT * FROM TableB
SELECT * FROM TableC

IF EXISTS (SELECT name FROM sys.indexes WHERE name = N'N_tableB_b2')
 DROP INDEX N_tableB_b2 ON TableB;
GO
-- Create a nonclustered index called N_tableB_b2 on the TableB table using the b2 column.
CREATE NONCLUSTERED INDEX N_tableB_b2 ON TableB(b2); 
GO

-- clustered index scan
SELECT * FROM TableA ORDER BY aid

-- non clustered index scan && key lookup
SELECT * FROM TableA ORDER BY a2

-- clustered index seek
SELECT a.aid FROM TableA a
INNER JOIN TableB b ON a.aid = b.bid

-- non clustered index seek
SELECT *
FROM TableA a
WHERE a2 = 5

-- b
SELECT *
FROM TableB b
WHERE b2 = 2

-- c
GO
CREATE VIEW testView
AS
	SELECT a.something --, b.b2, c.something
	FROM TableA a -- , TableB b, TableC c,
	INNER JOIN TableB b ON a.a2 = b.b2
	INNER JOIN TableC c on c.aid = a.aid
GO

-- uses N_tableB_2 
SELECT * FROM testView
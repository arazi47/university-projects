USE deadlocktestdb;
GO

SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
BEGIN TRAN;
SElECT * FROM Table1;
WAITFOR DELAY '00:00:05';
SELECT * FROM Table1;
COMMIT;

-- cleanup from part 1
DELETE FROM Table1 WHERE name = 'sometestname' AND somestr = 'someteststr';
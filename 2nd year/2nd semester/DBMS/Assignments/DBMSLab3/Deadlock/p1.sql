-- Deadlock part 1
--CREATE OR ALTER PROCEDURE deadlock1
--AS
BEGIN TRANSACTION;
UPDATE Table1 SET somestr = 'updateval' WHERE name = 'name1';
WAITFOR DELAY '00:00:03';
UPDATE Table2 SET someint = 2 WHERE name = 'name2';
COMMIT;
--GO

--EXEC deadlock1
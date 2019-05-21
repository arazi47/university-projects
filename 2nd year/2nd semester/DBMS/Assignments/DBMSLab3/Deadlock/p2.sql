-- Deadlock part 2
CREATE OR ALTER PROCEDURE deadlock2
AS
BEGIN TRANSACTION;
UPDATE Table2 SET someint = 2 WHERE name = 'name2';
WAITFOR DELAY '00:00:10';
UPDATE Table1 SET somestr = 'updateval' WHERE name = 'name1';
COMMIT;
GO

EXEC deadlock2

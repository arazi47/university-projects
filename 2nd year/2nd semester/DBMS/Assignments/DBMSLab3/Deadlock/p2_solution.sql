-- Deadlock part 2 solution

USE deadlocktestdb;
GO

SET deadlock_priority high

BEGIN TRANSACTION
UPDATE Table2 SET someint = 2 WHERE name = 'name2';
WAITFOR DELAY '00:00:03';
UPDATE Table1 SET somestr = 'updateval' WHERE name = 'name1';
COMMIT TRANSACTION;


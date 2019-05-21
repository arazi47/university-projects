USE deadlocktestdb;
GO

BEGIN TRAN;
WAITFOR DELAY '00:00:05';
INSERT INTO Table1 VALUES ('sometestname', 'someteststr');
COMMIT TRAN;

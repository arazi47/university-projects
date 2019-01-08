-- pk no fk = Profession
-- pk and fk = Achievement
-- 2 pks = TwoPKTable

use testTemaDb

CREATE TABLE Profession (
	id INT NOT NULL,
	CONSTRAINT PK_Profession PRIMARY KEY(id),
	--testfield INT
)

CREATE TABLE Achievement (
	id INT NOT NULL,
	CONSTRAINT PK_Achievement PRIMARY KEY(id),
	prof_id INT,
	FOREIGN KEY(prof_id) REFERENCES Profession(id),
)

CREATE TABLE TwoPKTable (
	id INT NOT NULL,
	pk2 INT NOT NULL,
	CONSTRAINT PK_TwoPKTable PRIMARY KEY (id, pk2),
	testfield INT
)

DELETE FROM TwoPKTable
INSERT INTO TwoPKTable VALUES (1, 1), (1, 2), (1, 3), (1, 4), (2, 1), (2, 2), (3, 1);

GO
CREATE VIEW ViewProfession
AS
	SELECT * FROM Profession
GO

CREATE VIEW ViewAchievement
AS
	SELECT * FROM Achievement
GO

CREATE VIEW ViewTwoPKTable
AS
SELECT * FROM TwoPKTable
GO

DELETE FROM Views
INSERT INTO Views VALUES ('ViewProfession'), ('ViewAchievement'), ('ViewTwoPKTable')


DELETE FROM Tables
INSERT INTO Tables VALUES ('Profession'), ('Achievement'), ('TwoPKTable')

DELETE FROM Tests
INSERT INTO Tests VALUES ('select_view'), ('insert_profession'), ('delete_profession'),
	('insert_achievement'), ('delete_achievement'),
	('insert_twopktable'), ('delete_twopktable') 

SELECT * FROM Tests
SELECT * FROM Tables
SELECT * FROM Views

DELETE FROM TestViews
INSERT INTO TestViews VALUES (1, 1)
INSERT INTO TestViews VALUES (1, 2)
INSERT INTO TestViews VALUES (1, 3)

INSERT INTO TestTables (TestId, TableID, NoOfRows, Position) VALUES (3, 1, 100, 1)
INSERT INTO TestTables (TestId, TableID, NoOfRows, Position) VALUES (5, 2, 100, 2)
INSERT INTO TestTables (TestId, TableID, NoOfRows, Position) VALUES (7, 3, 100, 3)

SELECT * FROM TestTables

-- before test delete prev tests
delete from TestRunViews
delete from TestRuns
delete from TestRunTables

INSERT INTO Profession VALUES (1)
GO
CREATE OR ALTER PROC deleteProfession
AS
  DELETE FROM Profession WHERE id > 1
GO

SELECT * FROM TestTables

GO
CREATE OR ALTER PROC insertProfession
AS
	DECLARE @Index INT = 1
	 DECLARE @NoOfRows INT
	 SELECT @NoOfRows = NoOfRows FROM TestTables WHERE TestId = 3
	 
	WHILE @index <= @NoOfRows
    BEGIN
      INSERT INTO Profession VALUES (@index + 1)
      SET @index = @Index + 1
    END
GO

--
GO
CREATE OR ALTER PROC deleteAchievement
AS
  DELETE FROM Achievement
GO

GO
CREATE OR ALTER PROC insertAchievement
AS
	DECLARE @Index INT = 0
	 DECLARE @NoOfRows INT
	 SELECT @NoOfRows = NoOfRows FROM TestTables WHERE TestId = 5
	 
	WHILE @index < @NoOfRows
    BEGIN
      INSERT INTO Achievement VALUES (@index + 1, 1)
      SET @index = @Index + 1
    END
GO

--
GO
CREATE OR ALTER PROC deleteTwoPKTable
AS
  DELETE FROM TwoPKTable 
GO

GO
CREATE OR ALTER PROC insertTwoPKTable
AS
	DECLARE @Index INT = 0
	 DECLARE @NoOfRows INT
	 SELECT @NoOfRows = NoOfRows FROM TestTables WHERE TestId = 7
	 
	WHILE @index < @NoOfRows
    BEGIN
      INSERT INTO TwoPKTable VALUES (@index + 1, @index + 1, 3)
      SET @index = @Index + 1
    END
GO

--------
select * from Views
create or alter PROC TestRunView
as
  begin
    DECLARE @startTime1 DATETIME;
    DECLARE @endTime1 DATETIME;
    DECLARE @startTime2 DATETIME;
    DECLARE @endTime2 DATETIME;
    DECLARE @startTime3 DATETIME;
    DECLARE @endTime3 DATETIME;

    SET @startTime1 = GETDATE();
    EXEC ('select * from viewProfession');
    PRINT 'select * from viewProfession';
    SET @endTime1 = GETDATE();

    INSERT INTO TestRuns VALUES ('test_view', @startTime1, @endTime1)
    INSERT INTO TestRunViews(TestRunID, ViewID, StartAt, EndAt) values (@@IDENTITY, 4, @startTime1, @endTime1);

    SET @startTime2 = GETDATE();
    EXEC ('select * from viewAchievement');
    PRINT 'select * from viewAchievement';
    SET @endTime2 = GETDATE();
    INSERT INTO TestRuns VALUES ('test_view2', @startTime2, @endTime2)
    INSERT INTO TestRunViews(TestRunID, ViewID, StartAt, EndAt) values (@@identity, 5, @startTime2, @endTime2);

    SET @startTime3 = GETDATE();
    EXEC ('select * from viewTwoPKTable');
    PRINT 'select * from viewTwoPKTable';
    SET @endTime3 = GETDATE();
    INSERT INTO TestRuns VALUES ('test_view3', @startTime3, @endTime3)
    INSERT INTO TestRunViews(TestRunID, ViewID, StartAt, EndAt) values (@@identity, 6, @startTime3, @endTime3);
  end
GO
exec TestRunView

select * FROM TestRuns

GO
--drop proc TestRunInsertRemove
CREATE OR ALTER PROC TestRunInsertRemove
  AS
    begin
      DECLARE @startTime1 DATETIME;
      DECLARE @endTime1 DATETIME;

      DECLARE @startTime2 DATETIME;
      DECLARE @endTime2 DATETIME;

      DECLARE @startTime3 DATETIME;
      DECLARE @endTime3 DATETIME;

      DECLARE @startTime4 DATETIME;
      DECLARE @endTime4 DATETIME;

	  DECLARE @startTime5 DATETIME;
      DECLARE @endTime5 DATETIME;

	  DECLARE @startTime6 DATETIME;
      DECLARE @endTime6 DATETIME;

      SET @startTime1 = GETDATE()
      EXEC insertProfession
      PRINT ('exec insertProfession')
      SET @endTime1 = GETDATE()
      INSERT INTO TestRuns VALUES ('test_insert_profession', @startTime1, @endTime1)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 1, @startTime1, @endTime1)

      SET @startTime2 = GETDATE()
      EXEC deleteProfession
      PRINT ('exec deleteProfession')
      SET @endTime2 = GETDATE()
      INSERT INTO TestRuns VALUES ('test_delete_profession', @startTime2, @endTime2)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 1, @startTime1, @endTime1)

      SET @startTime3 = GETDATE()
      exec insertAchievement
      print ('exec insertAchievement')
      SET @endTime3 = GETDATE()
      INSERT INTO TestRuns values ('test_insert_achievement', @startTime3, @endTime3)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 2, @startTime3, @endTime3)

      SET @startTime4 = GETDATE()
      exec deleteAchievement
      print ('exec deleteAchievement')
      SET @endTime4 = GETDATE()
      INSERT INTO TestRuns values ('test_delete_achievement', @startTime4, @endTime4)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 2, @startTime4, @endTime4)
	  
      SET @startTime5 = GETDATE()
      exec insertTwoPKTable
      print ('exec insertTwoPKTable')
      SET @endTime5 = GETDATE()
      INSERT INTO TestRuns values ('test_insert_twopktable', @startTime5, @endTime5)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 3, @startTime5, @endTime5)

      SET @startTime6 = GETDATE()
      exec deleteTwoPKTable
      print ('exec deleteTwoPKTable')
      SET @endTime6 = GETDATE()
      INSERT INTO TestRuns values ('test_delete_twopktable', @startTime6, @endTime6)
      INSERT INTO TestRunTables VALUES (@@IDENTITY, 3, @startTime6, @endTime6)

    end
  GO
exec TestRunView
exec TestRunInsertRemove

select * from TestRuns
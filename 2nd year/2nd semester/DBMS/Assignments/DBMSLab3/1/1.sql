-- create a stored procedure that inserts data in tables that are in a m:n relationship;
-- if one insert fails, all the operations performed by the procedure must be rolled back (grade 3);

USE WoWCharacters2
GO

CREATE OR ALTER PROCEDURE uspAddCommunity (@commName VARCHAR(50))
AS
	SET NOCOUNT ON;
	BEGIN TRAN
		BEGIN TRY
			IF EXISTS (SELECT * FROM Community C WHERE C.name = @commName)
			BEGIN
				RAISERROR('Invalid community name', 14, 1)
			END

			INSERT INTO Community VALUES (@commName);
			COMMIT TRAN
		END TRY
	BEGIN CATCH
		ROLLBACK tran
		print 'Transaction rollbacked'
	END CATCH
GO

CREATE OR ALTER PROCEDURE uspAddCommunityMember (@playerId INT, @communityId INT)
AS
	SET NOCOUNT ON;

	BEGIN TRAN
		BEGIN TRY
			IF NOT EXISTS (SELECT * FROM Player P WHERE P.id = @playerId)
			BEGIN
				 RAISERROR('Invalid player id', 14, 1)
			END
	
			IF NOT EXISTS (SELECT * FROM Community C WHERE C.id = @communityId)
			BEGIN
				RAISERROR('Invalid comm id', 14, 1)
			END
	
			IF EXISTS (SELECT * FROM Community_Members C WHERE C.player_id = @playerId AND C.community_id = @communityId)
			BEGIN
				RAISERROR('Player already in community', 14, 1)
			END

				INSERT INTO Community_Members VALUES (@playerId, @communityId);
				print 'Added!'
				COMMIT TRAN
		END TRY

		BEGIN CATCH
			ROLLBACK TRAN
			print 'Transaction rollbacked'
		END CATCH
GO

-- 1) execute only the first command, it executes correctly
-- 2) execute both and watch it fail

SELECT * FROM Community

--EXEC uspAddCommunity 'The Drunken Sailors';
EXEC uspAddCommunityMember 2, 2;
EXEC uspAddCommunityMember 1, 1;

SELECT * FROM Community_Members

DELETE FROM Community_Members WHERE player_id = 2 AND community_id = 2

GO

CREATE OR ALTER PROCEDURE uspAddToMNRelationship
AS
	BEGIN TRAN
		BEGIN TRY
			EXEC uspAddCommunityMember 2, 2;
			EXEC uspAddCommunityMember 1, 1;
			COMMIT TRAN
		END TRY
		BEGIN CATCH
			ROLLBACK TRAN
			print 'Transaction rollbacked (uspAddToMNRelationship)'
		END CATCH
GO

EXEC uspAddToMNRelationship

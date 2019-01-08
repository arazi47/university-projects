-- Create communities
SET IDENTITY_INSERT Community ON

INSERT INTO Community(id, name) VALUES(1, 'The Drunken Sailors')
INSERT INTO Community(id, name) VALUES(2, 'A turtle made it to the water')
INSERT INTO Community(id, name) VALUES(3, 'Floyds')

SET IDENTITY_INSERT Community OFF


-- Create players
SET IDENTITY_INSERT Player ON


INSERT INTO Player(id, name, class)
VALUES (1, 'Shizzle', 1)

INSERT INTO Player(id, name, class)
VALUES (2, 'Arkade', 2)

INSERT INTO Player(id, name, class)
VALUES (3, 'Drood', 2)

INSERT INTO Player(id, name, class)
VALUES (4, 'Sixsixsix', 4)

INSERT INTO Player(id, name, class)
VALUES (5, 'Chaos', 3)

INSERT INTO Player(id, name, class)
VALUES (6, 'Prollyapally', 1)

-- Error
--INSERT INTO Player(id, name, class, prof_id, guild_id, quest_id)
--VALUES (7, 'Oopseroare', 2, 3, 4, 99)

SET IDENTITY_INSERT Player OFF


-- Assign players to communities
SET IDENTITY_INSERT Community_Members ON

INSERT INTO Community_Members(id, player_id, community_id)
VALUES (1, 1, 1)

INSERT INTO Community_Members(id, player_id, community_id)
VALUES (2, 1, 2)

INSERT INTO Community_Members(id, player_id, community_id)
VALUES (3, 1, 3)

INSERT INTO Community_Members(id, player_id, community_id)
VALUES (4, 2, 1)

INSERT INTO Community_Members(id, player_id, community_id)
VALUES (5, 2, 3)

INSERT INTO Community_Members(id, player_id, community_id)
VALUES  (6, 4, 3)

SET IDENTITY_INSERT Community_Members OFF


-- Create guilds
SET IDENTITY_INSERT Guild ON

INSERT INTO Guild(id, name, level, leader_id)
VALUES (1, 'Transcendental', 3, 1)

INSERT INTO Guild(id, name, level, leader_id)
VALUES (2, 'Amorphus', 13, 2)

INSERT INTO Guild(id, name, level, leader_id)
VALUES (3, 'Db bois', 7, 5)

SET IDENTITY_INSERT GUILD OFF


-- Create professions
SET IDENTITY_INSERT Profession ON

INSERT INTO Profession(id, name)
VALUES (1, 'Herbalism')

INSERT INTO Profession(id, name)
VALUES (2, 'Mining')

INSERT INTO Profession(id, name)
VALUES (3, 'Blacksmithing')

INSERT INTO Profession(id, name)
VALUES (4, 'Archeology')

INSERT INTO Profession(id, name)
VALUES (5, 'Alchemy')

SET IDENTITY_INSERT Profession OFF


-- Create items
SET IDENTITY_INSERT Item ON

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (1, 'Ashkandi, Greatstaff of the Devourer', 'It''s nice', 300, 600)

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (2, 'Shadowmourne', 'Yoyoyo', 200, 400)

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (3, 'Frostmourne', 'Hail to the king, baby!', 500, 800)

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (4, 'Shard of Azzinoth', 'Illidan''s thingy thing', 100, 230)

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (5, 'Green sword of deadly deathly ghostly ded', 'I like it, like it', 5, 8) 

SET IDENTITY_INSERT Item OFF


-- Create quests
SET IDENTITY_INSERT Quest ON

INSERT INTO Quest(id, name, text, xp_reward, gold_reward, item_id_reward)
VALUES (1, 'Welcome to the game', 'Welcome, welcome! We hope you have a good stay here!!!!!!!! ENJOY BOI', 1000, 200, 2)

INSERT INTO  Quest(id, name, text, xp_reward, gold_reward, item_id_reward)
VALUES (2, 'Rest and relaxation', 'Deliver some ca$h to Goldshire, pls pls pls. I''l let you keep some of it ;)', 2500, 50, 1)

SET IDENTITY_INSERT Quest OFF

-- Update players
UPDATE Player
SET name = 'Drizzle'
WHERE name = 'Shizzle'

UPDATE Player
SET prof_id = 1, guild_id = 1, quest_id = 2
WHERE id = 1

UPDATE Player
SET prof_id = 3, guild_id = 1, quest_id = 1
WHERE id = 2

UPDATE Player
SET prof_id = 4, guild_id = 1, quest_id = 2
WHERE id = 3


-- Update guilds
UPDATE Guild
SET level = 5
WHERE id = 1

UPDATE Guild
SET leader_id = 3
WHERE name like 'Amo%'

SELECT * FROM Guild


-- Update community
UPDATE Community
SET name = 'Mayweather Floyds'
WHERE id = 3


-- Add and delete two items
SET IDENTITY_INSERT Item ON

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (99, 'testname', 'testdesc', 333, 666)

INSERT INTO Item(id, name, description, min_dmg, max_dmg)
VALUES (199, 'testnamee', 'testdesc', 4444, 8888)

SET IDENTITY_INSERT Item OFF

DELETE FROM Item
WHERE id > 5


-- Add and delete two communities
SET IDENTITY_INSERT Community ON

INSERT INTO Community(id, name)
VALUES (99, 'testcomm1'), (991, 'test comm 2')

SET IDENTITY_INSERT Community OFF

DELETE FROM Community WHERE id BETWEEN 99 AND 991


-- a. 2 queries with the union operation; use UNION [ALL] and OR;
SELECT name FROM Player
UNION -- Distinct values
SELECT name FROM Guild

SELECT DISTINCT id FROM Item
UNION ALL -- All values
SELECT id FROM Quest


-- b. 2 queries with the intersection operation; use INTERSECT and IN;
SELECT id FROM Item
INTERSECT
SELECT id FROM Quest

SELECT id FROM Player
WHERE id IN (SELECT level FROM Guild)


-- c. 2 queries with the difference operation; use EXCEPT and NOT IN;

-- Selects player ids that are not guild masters
SELECT player.id
FROM Player
EXCEPT
SELECT Guild.leader_id
FROM Guild

SELECT Quest.name, Quest.item_id_reward
FROM Quest
WHERE Quest.item_id_reward NOT IN (1, 3)

-- Not needed for homework
-- Selects the name of guild leaders: Drizzle, Drood, Chaos
--SELECT Player.id FROM Player, Guild
--WHERE Player.id = Guild.leader_id


-- d. 4 queries with INNER JOIN, LEFT JOIN, RIGHT JOIN, and FULL JOIN;
-- one query will join at least 3 tables, while another one will join at least two many-to-many relationships;

-- Select player name & class, inner join for guild leaders
SELECT Player.name, Player.class
FROM Player
INNER JOIN Guild ON Guild.leader_id = Player.id

-- Select player, guild and profession info if profession id matches player id
-- left join if guild leader
SELECT Player.name, Player.class, Player.prof_id, Guild.leader_id, Guild.level, Profession.name
FROM Player
LEFT JOIN Profession ON Profession.id = Player.id
LEFT JOIN Guild ON Guild.leader_id = Player.id

-- select profession id and name on profession on profession id = player.profession id
SELECT Player.prof_id, Profession.name
FROM Player
RIGHT JOIN Profession ON Profession.id = Player.prof_id

-- Create another many to many relationship
CREATE TABLE Creature_Loot (
	id INT PRIMARY KEY IDENTITY(1, 1),
	creature_id INT,
	loot_id INT,
	FOREIGN KEY(creature_id) REFERENCES Creature(id),
	FOREIGN KEY(loot_id) REFERENCES Loot(id)
	);


SET IDENTITY_INSERT Creature ON
INSERT INTO Creature(id, name, level, xp_on_kill) VALUES(1, 'Dibolu47', 1337, 7331)
SET IDENTITY_INSERT Creature OFF 

SET IDENTITY_INSERT Loot ON
INSERT INTO Loot(id, creature_id, gold, item_id) VALUES (1,1,3,1)
SET IDENTITY_INSERT Loot OFF

SELECT DISTINCT Player.name, Community.name
FROM Player, Guild, Community_Members
FULL JOIN Community ON Community_Members.player_id = Community.id
FULL JOIN (
SELECT Loot.creature_id
FROM Creature_Loot
FULL JOIN Loot ON Creature_Loot.id = Loot.creature_id) T ON T.creature_id <= Community.id


-- e. 2 queries using the IN operator to introduce a subquery in the WHERE clause;
-- in at least one query, the subquery should include a subquery in its own WHERE clause;

-- Selects the name and class from Player if their ID matches Quest ID.
SELECT name, class
FROM Player
WHERE id IN (SELECT id FROM Quest) -- there are only 2 quests, so only 2 players will show up

-- only 2 quests exist
-- so only first 2 guilds will show up
-- Select top 1 guild info that matches the a player id that matches a quest id
SELECT TOP 1 id, name, level
FROM Guild
WHERE id IN (SELECT id FROM Player WHERE id IN (SELECT id FROM Quest))


-- f. 2 queries using the EXISTS operator to introduce a subquery in the WHERE clause;
-- selects player name if player has a profession and prof id >= 4
SELECT Player.name
FROM Player
WHERE EXISTS (SELECT Player.prof_id FROM Player WHERE Player.prof_id >= 4)

-- selects item name and description where
-- player id matches item id and item id is 2 or 3
SELECT Item.name, Item.description
FROM Item
WHERE EXISTS (SELECT Player.id FROM Player WHERE Player.id = Item.id AND Item.id IN (2, 3))


-- g. 2 queries with a subquery in the FROM clause;
SELECT DISTINCT p.name
FROM Player p JOIN Player p2 ON (p.guild_id = p2.guild_id)

SELECT iname, idesc
FROM (SELECT Item.id, MIN(Item.min_dmg) mindmg, MAX(Item.max_dmg) maxdmg, MIN(Item.name) iname, MIN(Item.description) idesc FROM Item GROUP BY Item.id) AS item_result


-- h. 4 queries with the GROUP BY clause, 3 of which also contain the HAVING clause;
-- 2 of the latter will also have a subquery in the HAVING clause; use the aggregation operators: COUNT, SUM, AVG, MIN, MAX;

-- MIN(name)/MAX(name) -> alphabetically
SELECT TOP 2 MAX(name), guild_id
FROM Player
GROUP BY guild_id

SELECT MAX(name), id
FROM Guild
GROUP BY id
HAVING SUM(id) > 1

SELECT MAX(name) max_name, MIN(prof_id) min_prof_id, MIN(id) min_id
FROM Player
GROUP BY prof_id
HAVING prof_id IN (SELECT id FROM Guild)

SELECT MAX(name) min_name, MIN(description)
FROM Item
GROUP BY id
HAVING MIN(id) < ALL(SELECT AVG(min_dmg) FROM Item)


-- i. 4 queries using ANY and ALL to introduce a subquery in the WHERE clause;
-- 2 of them should be rewritten with aggregation operators, while the other 2 should also be expressed with [NOT] IN.

-- select min_dmg if min_dmg > any player id
SELECT min_dmg
FROM Item
WHERE min_dmg > ANY(SELECT id FROM Player)
ORDER BY min_dmg

-- rewritten with aggregation operator
SELECT DISTINCT min_dmg
FROM Item, Player
WHERE min_dmg > Player.id
ORDER BY min_dmg


SELECT id, name, text, xp_reward
FROM Quest
WHERE xp_reward > ALL(SELECT id FROM Community)

-- rewritten with aggregation operator
-- quest info where xp_reward > maximum community id
SELECT Quest.id, Quest.name, text, xp_reward
FROM Quest, (SELECT MAX(Community.id) mcid FROM Community) mcidresult
WHERE xp_reward > mcid


-- select max dmg if max_dmg > any guild id
SELECT max_dmg
FROM Item
WHERE max_dmg > ANY(SELECT id FROM Guild)
ORDER BY max_dmg

-- rewritten with NOT IN
SELECT max_dmg
FROM Item
WHERE max_dmg NOT IN (SELECT MIN(id) FROM Guild)
ORDER BY max_dmg


-- select player info if id = any guild ids
SELECT id, name, class
FROM Player
WHERE id = ANY(SELECT id FROM Guild)

-- rewritten with IN
SELECT id, name, class
FROM Player
WHERE id IN (SELECT id FROM Guild)

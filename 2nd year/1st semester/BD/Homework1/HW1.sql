CREATE DATABASE WoWCharacters2

CREATE TABLE Profession (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50)
	);

CREATE TABLE Player (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	class INT NOT NULL,
	prof_id INT,
	guild_id INT,
	FOREIGN KEY(prof_id) REFERENCES Profession(id),
	);

--ALTER TABLE Player ADD guild_id INT
--ALTER TABLE Player ADD CONSTRAINT fk_guild_id FOREIGN KEY(guild_id) REFERENCES Guild(id)

--ALTER TABLE Player ADD quest_id INT
--ALTER TABLE Player ADD CONSTRAINT fk_quest_id FOREIGN KEY(quest_id) REFERENCES Quest(id)

CREATE TABLE Community (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	--leader_id INT,
	--FOREIGN KEY(leader_id) REFERENCES Player(id)
	);

--ALTER TABLE Community DROP COLUMN leader_id

CREATE TABLE Guild (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	level INT,
	leader_id INT,
	FOREIGN KEY(leader_id) REFERENCES Player(id)
	);

CREATE TABLE Creature (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	level INT,
	xp_on_kill INT
	);

CREATE TABLE Loot (
	id INT PRIMARY KEY IDENTITY(1, 1),
	creature_id INT UNIQUE FOREIGN KEY REFERENCES Creature(id),
	gold INT,
	item_id INT,
	--FOREIGN KEY(creature_id) REFERENCES Creature(id),
	FOREIGN KEY(item_id) REFERENCES Item(id)
	);

CREATE TABLE Item (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	description VARCHAR(50),
	min_dmg INT,
	max_dmg INT
	);

CREATE TABLE Achievement (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	description VARCHAR(50),
	xp_reward INT,
	gold_reward INT,
	item_id_reward INT,
	FOREIGN KEY(item_id_reward) REFERENCES Item(id)
	);

CREATE TABLE Quest (
	id INT PRIMARY KEY IDENTITY(1, 1),
	name CHAR(50),
	text VARCHAR(100),
	xp_reward INT,
	gold_reward INT,
	item_id_reward INT,
	FOREIGN KEY(item_id_reward) REFERENCES Item(id)
	);
	
CREATE TABLE Community_Members (
	id INT PRIMARY KEY IDENTITY(1, 1),
	player_id INT,
	community_id INT,
	FOREIGN KEY(player_id) REFERENCES Player(id),
	FOREIGN KEY(community_id) REFERENCES Community(id)
	);

	
CREATE TABLE TwoPKTable (
	id INT NOT NULL,
	pk2 INT NOT NULL,
	CONSTRAINT PK_TwoPKTable PRIMARY KEY (id, pk2);
)

INSERT INTO TwoPKTable VALUES (1, 1), (1, 2), (1, 3), (1, 4), (2, 1), (2, 2), (3, 1);
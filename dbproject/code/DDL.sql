 DROP TABLE IF EXISTS proj_stock, proj_order_items, proj_orders, proj_admin, proj_login, proj_book, proj_author, proj_customer;


CREATE TABLE proj_customer
(
	firstname 		VARCHAR(15),
	lastname 		VARCHAR(20),
	address_street	VARCHAR(20),
	address_city		VARCHAR(20),
	address_state	VARCHAR(2), -- two leter postal abreviation. 
	address_zip		VARCHAR(5),
	phone			VARCHAR(12),
	email			VARCHAR(30),
	
	PRIMARY KEY (email)
) ENGINE = InnoDB;

CREATE TABLE proj_login
(
	email			VARCHAR(30),
	password_hash   VARCHAR(32),	
	
	PRIMARY KEY(email),	
	FOREIGN KEY (email) REFERENCES proj_customer (email)
) ENGINE = InnoDB;

CREATE TABLE proj_admin
(
	email			VARCHAR(30),

	FOREIGN KEY(email) REFERENCES proj_login(email)
) ENGINE = InnoDB;

CREATE TABLE proj_author
(
	author_ID		INT NOT NULL AUTO_INCREMENT,
	firstname		VARCHAR(30),
	lastname			VARCHAR(30),
	PRIMARY KEY(author_ID)
) ENGINE = InnoDB;

CREATE TABLE proj_book
(
	ISBN				VARCHAR(17) NOT NULL,
	TITLE			VARCHAR(50),
	author_ID		INT,
	num_pages		INT,
	publish_year 	VARCHAR(4),
	price			NUMERIC(7,2),
	
	PRIMARY KEY(ISBN),
	FOREIGN KEY(author_ID) REFERENCES proj_author(author_ID)
) Engine = InnoDB;

CREATE TABLE proj_stock
(
	ISBN				VARCHAR(17) NOT NULL,
	qty				INT,
	
	FOREIGN KEY(ISBN) REFERENCES proj_book(ISBN)
) Engine = InnoDB;

CREATE TABLE proj_orders
(
	order_ID			VARCHAR(12) NOT NULL,
	email			VARCHAR(30),
	order_date		TIMESTAMP,

	PRIMARY KEY(order_ID),	
	FOREIGN KEY(email) REFERENCES proj_customer(email)
) Engine = InnoDB;

CREATE TABLE proj_order_items
(
	order_ID			VARCHAR(12),
	ISBN				VARCHAR(17) NOT NULL,
	qty				INT,						-- how many books
	amt				NUMERIC(10,2),		-- amount paid for the books

	FOREIGN KEY(order_ID) REFERENCES proj_orders(order_ID),
	FOREIGN KEY(ISBN) REFERENCES proj_book(ISBN)
)	Engine = InnoDB;




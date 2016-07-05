--
-- Database: 'checkout'
-- Problem Written by Brian Yu
--

CREATE DATABASE IF NOT EXISTS checkout;
USE checkout;

CREATE TABLE IF NOT EXISTS members (
  id int(10) unsigned NOT NULL AUTO_INCREMENT,
  first_name varchar(127) NOT NULL,
  last_name varchar(127) NOT NULL,
  PRIMARY KEY (id)
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS authors (
  id int(10) unsigned NOT NULL AUTO_INCREMENT,
  first_name varchar(127) NOT NULL,
  last_name varchar(127) NOT NULL,
  PRIMARY KEY (id)
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS books (
  id int(10) unsigned NOT NULL AUTO_INCREMENT,
  isbn bigint(13) unsigned NOT NULL,
  title varchar(255) NOT NULL,
  author_id int(10) unsigned NOT NULL,
  PRIMARY KEY (id),
  FOREIGN KEY (author_id) REFERENCES authors(id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;

CREATE TABLE IF NOT EXISTS transactions (
  id int(10) unsigned NOT NULL AUTO_INCREMENT,
  borrower_id int(10) unsigned NOT NULL,
  book_id int(10) unsigned NOT NULL,
  borrow_date date,
  due_date date,
  returned boolean NOT NULL DEFAULT 0,
  PRIMARY KEY (id),
  FOREIGN KEY (borrower_id) REFERENCES members(id) ON DELETE RESTRICT ON UPDATE CASCADE,
  FOREIGN KEY (book_id) REFERENCES books(id) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB;

INSERT INTO `members` (first_name, last_name) VALUES('Arturo', 'Real');
INSERT INTO `members` (first_name, last_name) VALUES('Dan', 'Coffey');
INSERT INTO `members` (first_name, last_name) VALUES('Annie', 'Chen');
INSERT INTO `members` (first_name, last_name) VALUES('Brian', 'Yu');
INSERT INTO `members` (first_name, last_name) VALUES('Connor', 'Doyle');
INSERT INTO `members` (first_name, last_name) VALUES('Dan', 'Armendariz');
INSERT INTO `members` (first_name, last_name) VALUES('Davey', 'Proctor');
INSERT INTO `members` (first_name, last_name) VALUES('Miles', 'Fertel');
INSERT INTO `members` (first_name, last_name) VALUES('Noe', 'Miniel');
INSERT INTO `members` (first_name, last_name) VALUES('Doug', 'Lloyd');
INSERT INTO `members` (first_name, last_name) VALUES('Erin', 'Carvalho');
INSERT INTO `members` (first_name, last_name) VALUES('Hari', 'Anbarasu');
INSERT INTO `members` (first_name, last_name) VALUES('Stelios', 'Rousoglou');
INSERT INTO `members` (first_name, last_name) VALUES('Ian', 'Sexton');
INSERT INTO `members` (first_name, last_name) VALUES('Jack', 'Deschler');
INSERT INTO `members` (first_name, last_name) VALUES('Jacob', 'Lurye');
INSERT INTO `members` (first_name, last_name) VALUES('Lauren', 'Scully');
INSERT INTO `members` (first_name, last_name) VALUES('Marinda', 'Horan');
INSERT INTO `members` (first_name, last_name) VALUES('Melinda', 'Li');
INSERT INTO `members` (first_name, last_name) VALUES('Ramon', 'Galvan');
INSERT INTO `members` (first_name, last_name) VALUES('Christian', 'Saravia');
INSERT INTO `members` (first_name, last_name) VALUES('Colton', 'Ogden');
INSERT INTO `members` (first_name, last_name) VALUES('David', 'Malan');
INSERT INTO `members` (first_name, last_name) VALUES('Luke', 'Jackson');
INSERT INTO `members` (first_name, last_name) VALUES('Tobias', 'Buschel');
INSERT INTO `members` (first_name, last_name) VALUES('Anthony', 'Bau');

INSERT INTO `authors` (first_name, last_name) VALUES('J.K.', 'Rowling');
INSERT INTO `authors` (first_name, last_name) VALUES('John', 'Green');
INSERT INTO `authors` (first_name, last_name) VALUES('Sharon', 'Creech');
INSERT INTO `authors` (first_name, last_name) VALUES('Randy', 'Pausch');
INSERT INTO `authors` (first_name, last_name) VALUES('William', 'Shakespeare');
INSERT INTO `authors` (first_name, last_name) VALUES('Mark', 'Twain');
INSERT INTO `authors` (first_name, last_name) VALUES('Agatha', 'Christie');
INSERT INTO `authors` (first_name, last_name) VALUES('Suzanne', 'Collins');
INSERT INTO `authors` (first_name, last_name) VALUES('Douglas', 'Adams');
INSERT INTO `authors` (first_name, last_name) VALUES('Antoine', 'de Saint-Exupery');
INSERT INTO `authors` (first_name, last_name) VALUES('Harper', 'Lee');
INSERT INTO `authors` (first_name, last_name) VALUES('Margaret', 'Haddix');
INSERT INTO `authors` (first_name, last_name) VALUES('Jodi', 'Picoult');
INSERT INTO `authors` (first_name, last_name) VALUES('Betty', 'Smith');

INSERT INTO `books` (isbn, title, author_id) VALUES(9780345391803, 'The Hitchhiker''s Guide to the Galaxy', 9);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780743454537, 'My Sister''s Keeper', 13);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780064405171, 'Walk Two Moons', 3);
INSERT INTO `books` (isbn, title, author_id) VALUES(0743477545, 'A Midsummer Night''s Dream', 5);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780689824753, 'Among the Hidden', 12);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780156012195, 'The Little Prince', 10);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780142424179, 'The Fault in Our Stars', 2);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780439023528, 'The Hunger Games', 8);
INSERT INTO `books` (isbn, title, author_id) VALUES(1401323251, 'The Last Lecture', 4);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780060736262, 'A Tree Grows in Brooklyn', 14);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780439064873, 'Harry Potter and the Chamber of Secrets', 1);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780743477123, 'Hamlet', 5);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780062073501, 'Murder on the Orient Express', 7);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780743296427, 'Handle With Care', 13);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780345391803, 'The Hitchhiker''s Guide to the Galaxy', 9);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780142424179, 'The Fault in Our Stars', 2);
INSERT INTO `books` (isbn, title, author_id) VALUES(1503215679, 'The Adventures of Tom Sawyer', 6);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780062409867, 'Go Set a Watchman', 11);
INSERT INTO `books` (isbn, title, author_id) VALUES(9781416954217, 'Found', 12);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780545586177, 'Catching Fire', 8);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780743496735, 'Nineteen Minutes', 13);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780062073488, 'And Then There Were None', 7);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780064409599, 'Love That Dog', 3);
INSERT INTO `books` (isbn, title, author_id) VALUES(0439708184, 'Harry Potter and the Sorcerer''s Stone', 1);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780446310789, 'To Kill a Mockingbird', 11);
INSERT INTO `books` (isbn, title, author_id) VALUES(9781508480464, 'Othello', 5);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780142414934, 'Paper Towns', 2);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780996584821, 'The Adventures of Huckleberry Finn', 6);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780439064873, 'Harry Potter and the Chamber of Secrets', 1);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780743477123, 'Hamlet', 5);
INSERT INTO `books` (isbn, title, author_id) VALUES(0439139600, 'Harry Potter and the Goblet of Fire', 1);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780743454537, 'My Sister''s Keeper', 13);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780545663267, 'Mockingjay', 8);
INSERT INTO `books` (isbn, title, author_id) VALUES(0142402516, 'Looking for Alaska', 2);
INSERT INTO `books` (isbn, title, author_id) VALUES(9780062073488, 'And Then There Were None', 7);

INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(1, 3, '2016-01-03', '2016-01-24', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(3, 4, '2016-01-07', '2016-01-28', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(5, 9, '2016-01-10', '2016-01-31', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(8, 11, '2016-01-11', '2016-02-01', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(9, 12, '2016-01-13', '2016-02-03', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(11, 10, '2016-01-14', '2016-02-04', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(4, 6, '2016-01-15', '2016-02-05', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(7, 16, '2016-01-15', '2016-02-05', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(12, 2, '2016-01-16', '2016-02-06', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(12, 13, '2016-01-16', '2016-02-06', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(12, 20, '2016-01-16', '2016-02-06', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(15, 14, '2016-01-20', '2016-02-10', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(18, 15, '2016-01-24', '2016-02-14', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(19, 17, '2016-01-29', '2016-02-19', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(1, 18, '2016-01-31', '2016-02-21', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(2, 22, '2016-02-01', '2016-02-22', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(5, 25, '2016-02-07', '2016-02-28', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(5, 24, '2016-02-07', '2016-02-28', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(16, 5, '2016-02-08', '2016-02-29', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(3, 27, '2016-02-09', '2016-03-01', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(21, 29, '2016-02-19', '2016-03-11', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(22, 30, '2016-02-29', '2016-03-21', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(4, 1, '2016-03-05', '2016-03-26', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(4, 31, '2016-03-10', '2016-03-31', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(23, 3, '2016-03-11', '2016-04-01', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(24, 4, '2016-03-31', '2016-04-21', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(25, 32, '2016-04-01', '2016-04-22', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(26, 34, '2016-04-09', '2016-04-30', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(6, 35, '2016-04-10', '2016-05-01', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(19, 9, '2016-04-20', '2016-05-11', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(19, 12, '2016-04-30', '2016-05-21', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(10, 6, '2016-05-01', '2016-05-22', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(8, 32, '2016-05-10', '2016-05-31', 0);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(19, 20, '2016-05-11', '2016-06-01', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(19, 14, '2016-05-11', '2016-06-01', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(19, 15, '2016-05-31', '2016-06-21', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(3, 16, '2016-06-01', '2016-06-22', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(7, 2, '2016-06-02', '2016-06-23', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(26, 4, '2016-06-04', '2016-06-25', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(3, 6, '2016-06-07', '2016-06-28', 0);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(17, 10, '2016-06-08', '2016-06-29', 1);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(11, 1, '2016-06-10', '2016-07-01', 0);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(11, 3, '2016-06-10', '2016-07-01', 0);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(11, 9, '2016-06-10', '2016-07-01', 0);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(11, 20, '2016-06-10', '2016-07-01', 0);
INSERT INTO `transactions` (borrower_id, book_id, borrow_date, due_date, returned) VALUES(11, 23, '2016-06-10', '2016-07-01', 0);

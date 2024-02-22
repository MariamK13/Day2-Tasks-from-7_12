#include <iostream>
#include <string>

class Book {
private:
	std::string title;
	std::string author;
	std::string	ISBN;

public:
	void setTitle (const std::string& newTitle) {
		title = newTitle;
	}
	void setAuthor (const std::string& newAuthor) {
		author = newAuthor;
	}
	void setISBN (const std::string& newISBN) {
		ISBN = newISBN;
	}
	std::string getTitle () { return title; }
	std::string getAuthor () {return author; }
	std::string getISBN () {return ISBN; }
};

int main ()
{
	Book book;
	book.setTitle ("Photography");
	book.setAuthor ("Liz Wells");
	book.setISBN ("978-0367222741");

	std::cout << "Book's title: " << book.getTitle () << std::endl;
	std::cout << "Book's author: " << book.getAuthor () << std::endl;
	std::cout << "Book's ISBN: " << book.getISBN () << std::endl;  
}

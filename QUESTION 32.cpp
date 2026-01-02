#include <iostream>
#include <vector>
using namespace std;

class Book
{
public:
    string title, author;

    Book(string t, string a) : title(t), author(a) {}
};

class Library
{
public:
    vector<Book *> books;

    void addBook(Book *book)
    {
        books.push_back(book);
    }

    void displayBooks()
    {
        cout << "Library Books:\n";
        for (auto book : books)
        {
            cout << "Title: " << book->title << ", Author: " << book->author << endl;
        }
    }
};

int main()
{
    Book book1("1984", "Usman"), book2("XYZ", "Nouman");
    Library library;

    library.addBook(&book1);
    library.addBook(&book2);

    library.displayBooks();
    return 0;
}

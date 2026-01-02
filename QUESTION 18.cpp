#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;

public:
    Media(const string& title, const string& pubDate, const string& id, const string& pub)
        : title(title), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() const {
        cout << "title: " << title << "\npublication Date: " << publicationDate
             << "\nunique ID: " << uniqueID << "\npublisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " checked out" << endl;
    }

    void returnItem() {
        cout << title << "  returned" << endl;
    }

    virtual ~Media() {}
};

class Book : public Media {
    string author;
    string ISBN;
    int numberOfPages;

public:
    Book(const string& title, const string& pubDate, const string& id, const string& pub,
         const string& auth, const string& isbn, int pages)
        : Media(title, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    string director;
    string duration;
    string rating;

public:
    DVD(const string& title, const string& pubDate, const string& id, const string& pub,
        const string& dir, const string& dur, const string& rat)
        : Media(title, pubDate, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "director: " << director << "\nDuration: " << duration << "\nrating: " << rating << endl;
    }
};

class CD : public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(const string& title, const string& pubDate, const string& id, const string& pub,
       const string& art, int tracks, const string& gen)
        : Media(title, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nNumber of Tracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media {
    string issueNumber;
    string editor;

public:
    Magazine(const string& title, const string& pubDate, const string& id, const string& pub,
             const string& issue, const string& ed)
        : Media(title, pubDate, id, pub), issueNumber(issue), editor(ed) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << "\nEditor: " << editor << endl;
    }
};

int main() {
    Book book("XYZ", "1925-04-10", "B001", "wrst", "Hamza", "9780743273565", 180);
    DVD dvd("ABCD", "2010-07-16", "D001", "xyx", "Nouman", "148 minutes", "PG-13");
    CD cd("Thriller", "1982-11-30", "C001", "lmno", "Usman", 9, "Pop");
    Magazine magazine("National Geographic", "2023-10-01", "M001", "National Geographic Society", "Vol. 244 No. 4", "abcd");

    book.displayInfo();
    dvd.displayInfo();
    cd.displayInfo();
    magazine.displayInfo();

    book.checkOut();
    dvd.returnItem();

    return 0;
}

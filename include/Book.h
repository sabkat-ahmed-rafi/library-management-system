#ifndef BOOK_H

#define BOOK_H

#include <string>
#include <ctime>
using namespace std;

class Book {
    private: 
        string title;
        string author;
        string ISBN;
        bool isAvailable;
        time_t borrowingDate;
        time_t dueDate;
    
    public: 
        Book(const string& title, const string& author, const string& ISBN);

        void displayInfo() const;
        bool borrowBook();
        void returnBook();
        bool getAvailability();


        void setBorrowingDate();
        void setDueDate(int days);

        string getTitle() const { return title; }
        string getAuthor() const { return author; }
        string getISBN() const { return ISBN; }
        time_t getBorrowingDate() const;
        time_t getDueDate() const;

};



#endif 
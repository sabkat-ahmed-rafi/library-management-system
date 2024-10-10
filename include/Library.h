#ifndef Library_H
#define Library_H

#include "Book.h"
#include "Loan.h"
#include <vector>
#include <string>

using namespace std;

class Library {
    private:
        vector<Book> book;
        vector<Loan> Loan;

    public: 
        void addBook(const Book& book);
        bool removeBook(const string& ISBN);
        Book* searchBookByTitle(const string& title);
        Book* searchBookByAuthor(const string& author);
        void displayAllBooks() const;
        void displayAllLoans() const;
};



#endif 

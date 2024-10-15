#include "../include/Library.h"
#include <iostream>

void Library::addBook(const Book& newBook) {
    book.push_back(newBook);
    cout << "Book titled \"" << newBook.getTitle() << "\" added to the library." << endl;
}

bool Library::removeBook(const string& ISBN) {
    for(auto it = book.begin(); it != book.end(); ++it) {
        if(it->getISBN() == ISBN) {
             cout << "Book titled \"" << it->getTitle() << "\" removed from the library." << endl;
             book.erase(it);
             return true;
        }
    }
    cout << "Book with ISBN " << ISBN << " not found." << endl;
    return false;
}

Book* Library::searchBookByTitle(const string& title) {
    for(auto& b : book) {
        if(b.getTitle() == title) {
            return &b;
        }
    }
    cout << "Book with title \"" << title << "\" not found." << endl;
    return nullptr;
}

Book* Library::searchBookByAuthor(const string& author) {
    for (auto& b : book) {
        if (b.getAuthor() == author) {
            return &b;
        }
    }
    cout << "Book by author \"" << author << "\" not found." << endl;
    return nullptr;
}

void Library::displayAllBooks() const {
    if (book.empty()) {
        cout << "No books in the library." << endl;
        return;
    }

    cout << "Library Books:" << endl;
    for (const auto& b : book) {
        b.displayInfo();
        cout << "-----------------------------" << endl;
    }
}

bool Library::borrowBook(const string& isbn) {
   for(auto& b: book) {
    if(b.getISBN() == isbn) {
        if(b.getAvailability()) {
            b.borrowBook();
            return true;
        }
    } else {
        cout << "Book is already borrowed." << endl; 
        return false;
    }
   }
    cout << "Book with ISBN " << isbn << " not found." << endl;
    return false;
}


void Library::returnBook(const string& isbn) {
    for(auto& b: book) {
        if(b.getISBN() == isbn) {
            b.returnBook();
        }
    }
}


void Library::displayAllLoans() const {
    if (loan.empty()) {
        cout << "No loans in the library." << endl;
        return;
    }

    cout << "Library Loans:" << endl;
    for (const auto& l : loan) {
        l.displayLoanInfo();  
        cout << "-----------------------------" << endl;
    }
}


void Library::addLoan(const string& borrower, const string& bookTitle, const string& loanDate, const string& dueDate) {
    Loan newLoan( borrower, bookTitle, loanDate, dueDate);
    loan.push_back(newLoan); 
    cout << "Loan added successfully!" << endl;
}

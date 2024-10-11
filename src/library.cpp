#include "Library.h"
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
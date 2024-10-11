#include "Book.h"
#include <iostream>
#include <iomanip>

using namespace std;

// implementing the constructor
Book::Book(const string& title, const string& author, const string& ISBN) 
    : title(title), author(author), ISBN(ISBN), isAvailable(true), borrowingDate(0), dueDate(0) {}


void Book::displayInfo() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN" << ISBN << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;

        if(!isAvailable) {
        cout << "Borrowing Date: " << put_time(localtime(&borrowingDate), "%Y-%m-%d") << endl;
        cout << "Due Date: " << put_time(localtime(&dueDate), "%Y-%m-%d") << endl;
    }
}

bool Book::borrowBook() {
    if(isAvailable) {
        isAvailable = false;
        setBorrowingDate();
        setDueDate(14);
        return true;
    } else {
        cout<< "Book is already borrowed." << endl;
        return false;
    }
}

void Book::returnBook() {
    if(!isAvailable) {
        isAvailable = true;
        borrowingDate = 0;
        dueDate = 0;
        cout << "Book has been return." << endl;
    } else {
        cout << "Book was's borrowed." << endl;
    }
}

bool Book::getAvailability() {
    return isAvailable;
}

void Book::setBorrowingDate() {
    time(&borrowingDate);
}

void Book::setDueDate(int days) {
    dueDate = borrowingDate + (days * 24 * 60 * 60);
}

time_t Book::getBorrowingDate() const {
    return borrowingDate;
}

time_t Book::getDueDate() const {
    return dueDate;
}


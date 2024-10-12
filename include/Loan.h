#ifndef Loan_H
#define Loan_H

#include <string>
using namespace std;

class Loan {
private:
    string loanID;
    string borrower;
    string bookTitle;
    string loanDate;
    string dueDate;

public:
    Loan(const string& loanID, const string& borrower, const string& bookTitle, const string& loanDate, const string& dueDate)
        : loanID(loanID), borrower(borrower), bookTitle(bookTitle), loanDate(loanDate), dueDate(dueDate) {}


    void displayLoanInfo() const;
    string getLoanID() const { return loanID; }
    string getBorrower() const { return borrower; }
    string getBookTitle() const { return bookTitle; }
    string getLoanDate() const { return loanDate; }
    string getDueDate() const { return dueDate; }
};


#endif

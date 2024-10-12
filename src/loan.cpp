#include "../include/Loan.h"
#include <iostream>
using namespace std;


void Loan::displayLoanInfo() const {
    cout << "Loan ID: " << loanID << endl;
    cout << "Borrower: " << borrower << endl;
    cout << "Book Title: " << bookTitle << endl;
    cout << "Loan Date: " << loanDate << endl;
    cout << "Due Date: " << dueDate << endl;
}

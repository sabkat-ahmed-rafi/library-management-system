#ifndef Member_H
#define Member_H


#include <string>
using namespace std;


class Member {
    private: 
        string name;
        string membershipId;
    
    public:
    Member(const string& name, const string& membershipId);
    
    void displayInfo() const;
    string getName() const { return name; }
    string getMembershipId() const { return membershipId; }
};




#endif
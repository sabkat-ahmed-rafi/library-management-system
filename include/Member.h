#ifndef Member_H
#define Member_H


#include <string>
using namespace std;


class Member {
    private: 
        string name;
        string membershipId;
    
    public:
    Member(const string& name, const string& membershipId)
        : name(name), membershipId(membershipId) {};
    
    void displayMemberInfo() const;
    string getName() const { return name; }
    string getMembershipId() const { return membershipId; }
};




#endif
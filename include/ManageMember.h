#ifndef ManageMember_H
#define ManageMember_H


#include "Member.h"
#include <vector>
#include <string>

using namespace std;

class ManageMember {
    private:
        vector<Member> member;

    public: 
        void addMember(const Member& member);
        bool removeMember(const string& membershipId);
        Member* searchMemberById(const string& membershipId);
        Member* searchMemberByName(const string& name);
        void displayAllMember();
};




#endif
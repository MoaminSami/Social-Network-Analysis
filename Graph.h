#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>

using namespace std;

class account {
private:
    string name;
    int deg;
    vector<string> followers;
    vector<string> following;
   

public:
    // Constructors
    account() {
        name = "null";
        deg = 0;
    }

    account(const string& name);

    int getdeg() const;

    // Getter methods
    vector<string> getFollower()const;

    vector<string> getFollowing() const;

    string getName() const;

   

    // Setter methods
    void setName(const string& name);
     void setdeg();

    void setFollower(const string& follower);

    void setFollowing(const string& following);

   

    // Overloaded comparison operator
    bool operator<(const account& rhs) const;
};

#endif // GRAPH_H



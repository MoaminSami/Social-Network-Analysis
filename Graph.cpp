#include "Graph.h"

using namespace std;

account::account(const string& name) {
    this->name = name;
    deg = 0;
}

void account::setName(const string& name) {
    this->name = name;
}

void account::setFollower(const string& follower) {
    followers.push_back(follower);
}

void account::setFollowing(const string& followingss) {
    this->following.push_back(followingss);
}


vector<string> account::getFollower() const {
    return followers;
}


vector<string> account::getFollowing() const {
    
    return following;
}


string account::getName() const {
    return name;
}

int account::getdeg() const {
    return followers.size();
}

void account::setdeg() {
    deg = followers.size();
}

bool account::operator<(const account& rhs) const {
    if (deg < rhs.deg) {
        return true;
    } else if (deg == rhs.deg) {
        return name > rhs.name;
    } else {
        return false;
    }
}
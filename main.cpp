#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Graph.h"

 
bool comp(account& comp1, account& comp2){
    return comp1.getName() < comp2.getName();
}


// this is the resource i used for transform https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
string makeLower(const string& letter) {
    string result = letter;
    transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char k) { return tolower(k); });
    return result;
}

///////////////// Before submitting your code
 //uncomment this part since zyBooks use it.
 int main(int argc, const char* argv[]) {
    if (argc != 2)
     {
         std::cout << "./project4 inputFile" << std::endl;
         return EXIT_FAILURE;
     }
    string inputFileName = argv[1];
    
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
//2) Comment the next 2 lines below
// int main(void) {
//     string inputFileName = "input1.txt";    //Do NOT change the name "inputFileName" since used above

vector<account> total;
/// everything under this is from homework 8 

    ifstream inputFile(inputFileName);
    if (inputFile.fail()) {
        cout << "Failed to open file" << endl;
        return 1 ;
    }
    
    string node, neinode;
    while (inputFile >> node >> neinode) {
        // call the make lower function to make everything lower case 
        node = makeLower(node);
    neinode = makeLower(neinode);
    // 2 bool statements that start at false and we make it true when neeeded
        bool foundNode = false, foundNeinode = false;

        // Check if the node and neinode already exist in the 'total' vector
    for (auto it = total.begin(); it != total.end(); ++it) {
    if (it->getName() == node) {
        it->setFollower(neinode);
        foundNode = true;
    } else if (it->getName() == neinode) {
        it->setFollowing(node);
        foundNeinode = true;
    }

    // If both node and neinode found, stop searching
    if (foundNode && foundNeinode)
        break;

           
       }
        // If node or neinode not found, create new account and add to 'total'
    if (foundNode == false || foundNeinode == false) {
    if (foundNode == false) {
        account newNode(node);
        newNode.setFollower(neinode);
        total.push_back(newNode);
    }
    if (foundNeinode == false) {
        account newNeinode(neinode);
        newNeinode.setFollowing(node);
        total.push_back(newNeinode);
    }
}
}
    inputFile.close();
    // homework 8 code ends
    //set all degrees
    
for (unsigned int i = 0; i < total.size(); ++i) {
    total[i].setdeg();
}


//sort the vectors for total of type account

stable_sort(total.begin(),total.end());



//gets the last of the vector
account high = total.back();


vector<account>onedeg;
// i made rfollow = to high.getfollower() because i kept getting errors when using high.getFollower().size() in the for loop
vector<string>rfollow = high.getFollower();




sort(rfollow.begin(), rfollow.end(), [](const string& a, const std::string& b) {
    return a < b; 
});


///nested for loops that add total to onedeg and finishes after it goes through all total.size()

for (unsigned int i = 0; i < total.size(); ++i) {
    for (unsigned int j = 0; j < rfollow.size(); ++j) {
        if (total[i].getName() == rfollow[j]) {
            onedeg.push_back(total[i]);
            break;
        }
    }
}

// sort in alphabetlical order for the degrees

sort(onedeg.begin(), onedeg.end(), [](const account& a, const account& b) {
    return a.getName() < b.getName();
});
cout << "The root user is " << high.getName() << ", with in-degree centrality of " << high.getdeg() << "." << endl;


  
  cout << "There are " << total.size() << " users in the social network" << "." << endl;
  
  
  
  cout << high.getName() << " (0)" << endl;
  
  // for loop to print the degrees
  
  for (unsigned int  i = 0; i < onedeg.size(); ++i) {
      
      
      
    const account& onefollow = onedeg[i];
    
    
     vector<string>simplefollower = onefollow.getFollower();

//frist degree

    cout << onefollow.getName() << " (1)" << endl;



// sorting second degree
    sort(simplefollower.begin(), simplefollower.end());

    //second degree
    
    for (unsigned int j = 0; j < simplefollower.size(); ++j) {
        cout << simplefollower.at(j) << " (2)" << endl;
    }
}

   return 0;   
}

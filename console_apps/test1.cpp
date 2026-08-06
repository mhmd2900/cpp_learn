#include <iostream>
#include <string>
using namespace std;

void exploreFolder(string folderName, int depth) {
    
    // print indentation based on depth
    for (int i = 0; i < depth; i++)       cout << "  "; 

    cout << "-- "  << folderName << endl;

    // simulate sub-folders (hardcoded for the lab)
    if (folderName == "Documents") {
        exploreFolder("Work", depth + 1);
        exploreFolder("Personal", depth + 1);
    }
    else if (folderName == "Work") {
        exploreFolder("Projects", depth + 1);
        exploreFolder("Reports", depth + 1);
    }
    else if (folderName == "Personal") {
        exploreFolder("Photos", depth + 1);
    }
    else {
        // no sub-folders
        for (int i = 0; i < depth + 1; i++) cout << "  ";
        cout << "- (empty folder)" << endl;
    }
}

int main() {
    exploreFolder("Documents", 0);
    return 0;
}
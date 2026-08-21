
#include <iostream>
using namespace std;

/////////////////////////////////////////////// linear recursion  ,,, better replaced by a loop
void climb1(int n) 
{
    
    if ( n == 0 )  { cout << "--\n";  return ;}

    cout << " begin \n";

    climb1(n-1);

    cout << " mid \n";

    cout << " end \n";
}
//  begin 
//  begin 
// --
//  mid 
//  end 
//  mid 
//  end 

/////////////////////////////////////////////// 	statement-level recursion
void climb2(int n) 
{
    
    if ( n == 0 )  { cout << "--\n";  return ;}

    cout << " begin \n";

    climb2(n-1);

    cout << " mid \n";

    climb2(n-1);

    cout << " end \n";
}
//  begin 
//  begin 
// --
//  mid 
// --
//  end 
//  mid 
//  begin 
// --
//  mid 
// --
//  end 
//  end 

/////////////////////////////////////////////// 	expression-Level recursion 
int climb3(int n) 
{
    
    if ( n == 0 )  { cout << "--\n";  return 0 ;}

    cout << " begin \n";

    // int sum = 0  ;
    //int sum = 
    climb3(n-1) + climb3(n-1);

    cout << " mid \n";

    cout << " end \n";
    return 0 ;
}
//  begin 
//  begin 
// --
// --
//  mid 
//  end 
//  begin 
// --
// --
//  mid 
//  end 
//  mid 
//  end 

int main() 
{
    climb3(2) ;
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////// loop
#include <iostream>
using namespace std;

int climbStairs(int n) {                                // Fibonacci sequence
    if (n <= 2) return n;

    int prev2 = 1;   // Ways to reach step (i-2)  → starts as Step 1
    int prev1 = 2;   // Ways to reach step (i-1)  → starts as Step 2
    int current = 0; // Ways to reach current step

    for (int i = 3; i <= n; i++) {
        current = prev1 + prev2; // Current step = sum of two previous steps
        prev2 = prev1;           // Shift: old prev1 becomes new prev2
        prev1 = current;         // Shift: current becomes new prev1
    }

    return current;
}

int main() {
    cout << "Ways to climb 4 stairs: " << climbStairs(4) << endl;
    return 0;
}

// If you can solve a branching problem by just remembering the last two or three results,
//Iteration is almost always superior because it is faster and won't crash your computer's memory (Stack Overflow) 
// recursion needs branching data and Each branch is unique. ( folders lab )






/////////////////////////////////////////////// statement level recursion
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




/////////////////////////////////////////////// expression level recursion 
#include <iostream>
#include <vector>
using namespace std;

// The "Notebook" (initialized with -1 to mean 'empty')
int memo[100];    //✅✅✅


int climbStairs(int n) 
{
    if (n <= 2) return n;

    // 1. CHECK: If we already solved this, don't do math!
    if (memo[n] != -1) {
        return memo[n];
    }

    // 2. STORE: Calculate and save the result in the notebook
    memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

    // 3. RETURN: Give back the answer
    return memo[n];
}

void printPaths(int current, int n, vector<int> path) 
{
    // If we went too far, stop
    if (current > n) return;

    //BASE CASE: We reached the top! Print the path
    if (current == n) 
    {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) 
                cout << path[i] << " ";
        
        cout << endl;
        return;
    }

    // CHOICE 1: Take 1 step
    path.push_back(current + 1);       // Record where we land
    printPaths(current + 1, n, path);  // Move to that step
    path.pop_back();                   // Undo the step (backtrack)

    // CHOICE 2: Take 2 steps
    path.push_back(current + 2);       // Record where we land
    printPaths(current + 2, n, path);  // Move to that step
    path.pop_back();                   // Undo the step (backtrack)
}



int main() 
{
    // Fill notebook with -1
    for (int i = 0; i < 100; i++)    memo[i] = -1;

    int n = 4;
    cout << "Total Ways to climb " << n << " stairs: ";
    cout << climbStairs(n) << endl;

    cout << "\nAll Possible Paths:" << endl;
    cout << "--------------------" << endl;

    vector<int> path;
    path.push_back(0); // Start from Step 0
    printPaths(0, n, path);

    return 0;
}

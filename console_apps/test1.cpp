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

// -------------------------------------------
// NEW: Print all pathways
// path = the steps taken so far
// current = which step we are on right now
// n = the target step
// -------------------------------------------
void printPaths(int current, int n, vector<int> path) 
{

    // If we went too far, stop
    if (current > n) return;

    //BASE CASE: We reached the top! Print the path
    if (current == n) {
        cout << "Path: ";
        for (int i = 0; i < path.size(); i++) {
            if (i != path.size() - 1)
                cout << path[i] << " -- ";
            else
                cout << path[i]; // last step, no arrow
        }
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

int main() {
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
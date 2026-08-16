#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n == 0) return 1;   // reached the top exactly
    if (n < 0)  return 0;   // went too far

    return climbStairs(n - 1) + climbStairs(n - 2)     ;
}

int main() 
{

    cout << climbStairs(4) << endl;
return 0;
}
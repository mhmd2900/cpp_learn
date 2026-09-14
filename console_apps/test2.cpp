#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;



int main()                 
{
int a = 10 ;

// asm("incl %0" : "+r"(a));
// cout << a ;

cout << sizeof(void*)*8;
return 0;
}
    
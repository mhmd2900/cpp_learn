///////////////////////////////
//                                    decimal            0 octal      0X hexadecimal
// programming calculator         [ decimal  اقسم  ]          [ others   اضرب ]
// RAM output buffer :  every 50 \n   , use   endl (which is '\n' + flush)





=============================================================         

g++  -c  test1.cpp            -o test1.o     -g  -Wall                  \\\\\\      compile
g++  -c  test2.cpp            -o test2.o     -g  -Wall                  \\\\\\      compile
g++      test1.o   test2.o    -o app.exe     -g  -Wall                  \\\\\\      link
.\app.exe                                                               \\\\\\      run


g++      test1.cpp            -o test1.exe   -g  -Wall                  \\\\\\      build ( compile + link )
.\test1.exe                                                             \\\\\\      run


g++  test1.cpp     -o test1.exe   -g  -Wall ;    if ($?) { .\test1.exe } \\\\\\     build + run  




/////////////////////////////////////////////////////////////   debug
gdb   .\test1.exe  
b 15	            break at line 15
r	                run the program
n	                next line (step over functions)
s	                Step into a function

p a	                print value of variable a once
display a	        display a after every step
info locals	        Show all local variables at once

c	                continue until next breakpoint
j 19                jump to line 19
q	                quit gdb




/////////////////////////////////////////////////////////////           git
/////// moves the file from the working directory to the staging area
git add mtext.txt          # stage one specific file
git add .                  # stage all changed files


/////// Saves the staged changes permanently to the local repository with a message
git commit -m "update"


/////// current state of working directory and staging area ( untracked , modified , staged )
git status


////// history of commits with verbose details
git log -v


git checkout  commit number




**************************************************************
// cout << INT_MIN << endl  ;   -2147483648
// cout << INT_MAX << endl  ;   2147483647
// cout << 5e3 << endl  ;       5000
// str = to_string (a) ;
// b = stoi (str) ;


/////////////////////////////    arthmetic operators
// a = 10 ;
// b = a++ ;     a = 11     b = 10
// b = a-- ;     a = 9      b = 10
// b = ++a ;     a = 11     b = 11
// b = --a ;     a = 9      b = 9



//////////////////// ternary operator
a == b ? c = 6 : c= 66 ;
c = ( a==b ) ? 6 : 66 ;



////////////////////////////    input 
// -- ignore eats from oldest to newest in buffer
// -- if ignore is bigger than buffer , it will eat from the coming input
// -- if ignore is smaller than buffer , it will show the recent charachters in buffer
// -- after formatted cin 
//          ├── target ═══► ignore ( remove \n if upcoming getline ) + return target
//          ├── ctrl z (eofbit) ═══► exit    
//          └── type mismatch (failbit) ═══► clear & ignore & loop
// -- after unformatted cin 
//          ├── target ═══► return target
//          ├── ctrl z (eofbit) ═══► exit   
//          ├── empty ═══► loop
//          └── no need for clear ( as all input is valid ) & no need for ignore ( getline ignore \n at end )
       





///////////////////////////////////   array  declaration 
int arr [3] = {};          // all 3 elements are 0                 ✅
int arr [3] = {11};        // 1st elemnts is 11 , others are 0     ✅
int arr [3]  = {00,11,22};   // 3 initialized elements
int arr []   = {00,11,22};   // 3 initialized elements
int arr [] ;               // compile error
int arr [3];               // garbage 
int arr [] = {} ;          // garbage

int arr [][3] ;                                       //  cout << arr[0][0] ;       compile error
int arr [][3] = {} ;                                     // out << arr[0][0] ;      garbage       
int arr [][3]  = { {} , {} };                            // cout << arr[1][0] ;          0                               ✅
int arr [][3]  = { {1,2}, {4} };                   // → {{1,2,0},{4,0,0}}          cout << arr[1][0] ;           4       ✅
int arr [][3]  = { {} };                                 // cout << arr[0][1] ;          0
int arr [][3]  = { {} };                                 // cout << arr[1][0] ;         garbage
int arr [2][]  = { {11,22} , {33,44} };             // must write columns numbers         cout << arr[0][1] ;     compile error

char str[10] = "hello";     // Initializes first 6 chars: 'h','e','l','l','o','\0', rest \0  , equivalent to 0 in ASCII
char str[]   = "world";     // Size = 6 (including '\0')     ✅

array <int, 3> arr = {1, 2, 3};    // best  ✅✅✅   
array <int, 3> arr = {};       // ✅  Zero-initialized ,, can not be done in vectors as vector starts with size 0, so index 0 doesn’t exist!




//////////////////////////////////////  array of structures
struct point { int x   ;  int y;  };
point arrOfStructs[3]; // Uninitialized 
array <point, 3> arrOfStructs; // uninitialized 
array <point, 3> arrOfStructs = {};   // All members zero-initialized → {0, 0}, {0, 0}, {0, 0}        only if no previous initialization in structure
array <point, 3> arrOfStructs = {{ {1, 2}, {}, {5, 6} }};  // index 0 , index 1 , index 2
array <point, 3> arrOfStructs = {  Point{1, 2} ,  Point{} , Point{5, 6} };  // best  ✅✅✅                          arrOfStructs[1].y  =  4    





////////////////////////////////// array of vectors   ,,, fixed groups with variable content.
array <vector<int>, 3> arrOfVecs;  // 3 empty vectors
array <vector<int>, 4> arrOfVecs = {{
    {10, 20},             // Simple list → concise
    {},                   // Empty → concise  , vector size is 0
    vector<int>(5, 100),  // Need 5x100 → explicit constructor
    vector<int>(3)        // 3 zeros → explicit for clarity
    }};      //  best✅✅✅  // class (string , vector , structure ) use double braces unlike primitive types e,g int , float , ...
vector <int> arrOfVecs [3]  = { {1}, {2,3}, {} } ;  // C-style array 
auto arrOfVecs = array { vector{10, 20}, vector{30}, vector<int>{} };  // type hint needed if empty
    
















///////////////////////////////////////////  vector declaration
vector <int> vnum ;
vector <int> vnum ( 3 ) ;       // 3 elements , zero-initialized
vector <int> vnum ( 3 , 55 ) ; // 3 elements , all values 55
vector <int> vnum ( 3 ) = { 11,22,33 } ; 
vector <int> vnum = { 11,22,33 } ;  // 3 elements with these values




/////////////////////////////////////////////  vector of structures
struct point { int x   ;  int y = 22 ;  };
point vecOfStructs[3]; // Uninitialized
vector<point> vecOfStructs; // empty vector
vector<point> vecOfStructs(3);  // Creates 3 default-constructed Points → {0,0}, {0,0}, {0,0}  ,, if not initialized in struct
vector<point> vec(5, { 88, 99});  //  5 vectore  each 88,99
vector<point> vecOfStructs = {{ {1, 2} , {} , {5, 6} }};   // {} make  default which is  0 if not initialized 
vector<point> vecOfStructs = { Point{1, 2} , Point{} , Point{5, 6} };
///// adding elements
// vecOfStructs[1] = { 44,55} ;
// vecOfStructs[1].x = 66;
// vecOfStructs.push_back({77,88});
// vecOfStructs.push_back({77});      , print vecOfStructs[3].y = 22




///////////////////////////////////////////  vector of arrays  ,,   variable number of fixed-size records.
vector <array<int, 3>> vecOfArrays;
vector <array<int, 3>> vecOfArrays(5);  //5 arrays, each {0,0,0}
vector <array<int, 3>> vecOfArrays(4, {99, 99, 99}); //4 arrays of {99,99,99}  /// () used for vector for size and default value , in array : sizee is in <> , default values are 0
vector <array<int, 3>> vecOfArrays = { {1, 2, 3} , {44} , {} }; // complete the 3 values with zeros
auto vecOfArrays = vector{ array{1, 2, 3} , array{4, 5, 6} };





////////////////////////////////////////////////  array vs vector function
bool fun ( int arr []  ,  int num    , const vector<int>& vv   )  // array is & by default
{
return arr[num] = vv[0];
}


int arr[4] = { 0,1,2 ,3};
arr [3] = 3 ;
vector <int>vv = { 3 , 4 , 5 , 6 };

cout << fun ( arr , arr[3] , vv ) ;




////////////////////    timer
// #include<chrono>
// auto start = std::chrono::steady_clock::now();  // Start timer
// auto end   = std::chrono::steady_clock::now();    // Stop timer
// auto ms    = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();     
// Calculate and print time in microseconds
// cout << " \n \n Time: " << ms << " µs\n";



///////////////////////////////////          reset screen
void reset_screen ()
{                                             // Windows only (not portable)
system ("cls");                               // Slow (launches a new process)
system ( "color 0F") ;                        // Security risk in some environments
}


//////////////////////////////////////      random
int get_random ( int from , int to )
{                                                  // needs  <cstdlib>   and   <ctime>
  return rand()%( to - from + 1)+from ;           // inside main function    srand((unsigned )time (NULL));
}




////////////////////////////////////////    printf
#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
int a = 5 ;
printf("  num is %d\n", a ) ;                     
printf("  num is %3d\n", a ) ;                
printf("  num is %*d\n", 3 , a ) ;                
printf("  num is %03d\n", a ) ;                    
printf("  num is %0*d\n\n", 3 , a ) ;             

float b = 5.123456 ;
printf(" num is %f   \n", b ) ;                  
printf(" num is %10f   \n", b ) ;                
printf(" num is %.2f   \n", b ) ;                
printf(" num is %.*f   \n\n", 3 , b ) ;          

char name[] = "mhmd";
printf(" my name is %s \n" , name ) ;            
printf(" my name is %6s \n" , name ) ;           
printf(" my name is %*s \n\n" , 6 , name ) ;     

char ch = 'c';
printf("first letter is %c \n" , 'm');         
printf("first letter is %3c \n" , 'm');          
printf("first letter is %*c \n" , 3 , 'm');      

return 0;
}

  num is 5
  num is   5
  num is   5
  num is 005
  num is 005

 num is 5.123456   
 num is   5.123456   
 num is 5.12   
 num is 5.123   

 my name is mhmd 
 my name is   mhmd 
 my name is   mhmd 

first letter is m 
first letter is   m 
first letter is   m 




////////////////////////////////////////////////////////////////////////////////////  pointers
int a = 10 ;
int b = a ;
int &c = a ;                 // alias ( neck name ) اسم دلع لنفس المتغير
a ++ ;

cout << a << "\n" ;   // 11
cout << b << "\n" ;    // 10
cout << c << "\n\n" ;     // 11

///////////////////////////////////////

int *p ;
p = &a ;                  // p takes only addresses , p takes only one address يصنع متغير جديد

cout << p << "\n" ;      // a   address         🧠🧠🧠
cout << *(&a) << "\n" ;  // value of a    11
cout << *p << "\n" ;     // value of a    11    
cout << &p << "\n\n" ;     // p  address         


*p = 20 ;                                  // 🧠🧠🧠
cout << a << "\n" ;  // 20         

a = 30 ;
cout << *p << "\n\n" ;  // 30


///////////////////////////////////////

int arr[4] = { 10 , 20 , 30 , 40 }; // each item has specific address
int *pp ;
pp = arr;   // use arrays name not address to point to address of 1st array item    arr[0]
// pp     = &arr[0]
// pp + 1 =  &arr[0]
// pp + 2 =  &arr[0]


cout << &arr[0] << "\n" ;  // address
cout << pp << "\n" ;       // same address   🧠🧠🧠

cout << *(&arr[0]) << "\n" ;     // 10
cout << *pp << "\n\n" ;          // 10        🧠🧠🧠



cout << &arr[1] << "\n" ;   // address
cout << pp +1  << "\n" ;    // same address    🧠🧠🧠

cout << *(&arr[1]) << "\n" ;   // 20
cout << *(pp +1) << "\n\n" ;   // 20            🧠🧠🧠

///////////////////////////////////////
// struct employ {string name ;int grade ;};  global scope

employ emp , *ppp;

emp.name = "mhmd";
emp.grade = 99 ;

ppp = &emp ; // ppp points to address of 1st struct item    emp.name 
//ppp + 1 = memory after emp ( garbage )
// *ppp returns the entire struct object ,, (*ppp).item  returns specific item

*ppp = {"Ali", 85};                 // 🧠🧠🧠

cout << ppp   << "\n" ;          // address   🧠🧠🧠
cout << &emp.name << "\n" ;      // same address

cout << *(&emp.name) << "\n" ;    // ali
cout << (*ppp).name << "\n" ;     // ali
cout << ppp->name << "\n\n" ;     // ali   🧠🧠🧠



cout << &emp.grade << "\n" ;      // address

cout << *(&emp.grade) << "\n" ;    // 85
cout << (*ppp).grade << "\n" ;     // 85
cout << ppp->grade << "\n\n" ;     // 85

///////////////////////////////////////  void pointer and casting

void *pop ; 
pop = &a ;
cout << pop << "\n" ;                    // void can hold address
int *pint = static_cast<int*>(pop) ;     // void can not hold value , needs casting and needs assign to a variable ( so do casting once )
cout << *pint << "\n\n" ;    


///////////////////////////////////////   new and delete

int* ptr ;
float* ptrf ;

ptr = new int ;
ptrf = new float ;

*ptr = 55 ;
*ptrf = 44.4f ;   // added f , as because numbers with decimals are considered double

cout << *ptr << "\n";
cout << *ptrf << "\n";

delete ptr ;
delete ptrf ;


///////////////////////////////////////   mixed example
////////// practically , void is not used , vector is used instead of dynamic array

string st ;
cout << " choose students  : one  or  all  \n";
cin >> st ;
void* pep ;                               // pep assigns to address  🧠🧠🧠
if ( st == "one")
{
pep =  new float ;                           // pep assigns to address of float  🧠🧠🧠
cout << " enter student grade \n";
cin >> *(static_cast<float*>(pep)) ;         //  needs casting to assign to the value   🧠🧠🧠 as it is void
cout << " you choose one student number , grade is : " << *(static_cast<float*>(pep)) ;
//delete pep ;                               // not accepted as void can not be deleted 🧠🧠🧠
delete static_cast<float*>(pep);          
}

else if ( st == "all")
{
int num ;
cout << " enter number of students \n";
cin >> num ;
pep = new float[num];                     // p assigns to address of float array 1st item  🧠🧠🧠

    for ( int i = 0 ; i < num ; i ++ )
    {
    cout << " student number " << i+1 << " is : " ;
    cin >> static_cast<float*>(pep)[i];   //  needs casting to assign to the value   🧠🧠🧠
                  // Using [i] already accesses (dereferences) the value. no need for * before it 🧠🧠🧠
    cout << "\n";
    }

    cout << " \n\n ======= displaying grades \n " ;

    for ( int i = 0 ; i < num ; i ++ )
    {
    cout << " student number " << i+1 << " grade is : \t" ;
    cout << static_cast<float*>(pep)[i] << "\n";
    }

//delete []pep ;                  // not accepted as void can not be deleted 🧠🧠🧠
delete []static_cast<float*>(pep) ;             // 🧠🧠🧠
}


///////////////////////////////////////   iterators
// <algorithm>
vector<int>vnum { 11,22,33,44,55,66};
vector<int>::iterator it ;
vector<int>::iterator iter ;
it = vnum.begin() ; 
iter = vnum.begin() ; 

for ( ; it != vnum.end() ; it ++ )
 cout << *it << "\n";

cout << endl ;

advance ( iter , 3 );     
cout << *iter << "\n";     // 44

advance ( iter , -2 );
cout << *iter << "\n";    // 22

cout << endl ;

vnum.erase ( iter , iter+ 2) ;  
cout << *iter << endl;      // 44

cout << endl ;

vnum.erase ( iter , vnum.end()- 2) ;   //vnum.begin() points to 33 (index 0).    //vnum.end() is the position after the last element (66).
cout << *iter << endl;               // 55
cout << *vnum.begin() << endl;      // 11

int count_times = count(vnum.begin() , vnum.end() , 55 ); // specific number repitition
reverse(vnum.begin() , vnum.end()  );   // reverse order






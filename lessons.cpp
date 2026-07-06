///////////////////////////////
//                                    decimal            0 octal      0X hexadecimal
// programming calculator         [ decimal  اقسم  ]          [ others   اضرب ]
// RAM output buffer :  every 50 \n   , use   endl (which is '\n' + flush)


/////////////////////////
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
       




//////////////////////////////  arabic
// #include<fcntl.h>
// _setmode(_fileno(stdout) , _O_U8TEXT) ;
// wchar_t nnn = L'ل'  ;
// wchar_t sss[6] = L"احمد" ;
// wcout << nnn << endl << sss  ;




////////////////////////////   time
    // #include<chrono>
    // auto start = chrono::high_resolution_clock::now();
    // auto end   = chrono::high_resolution_clock::now();
    // auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    // cout << "Time taken: " << ms << " ms\n";    







///////////////////////////////////   array  declaration 
int arr [3] = {};          // all 3 elements are 0
int arr [3] = {11};        // 1st elemnts is 11 , others are 0
int arr [3]  = {00,11,22};   // 3 initialized elements
int arr []   = {00,11,22};   // 3 initialized elements
int arr [3];               // all elemnts are garbage , if inside a function
int arr [][3]  = { {1,2}, {4} };  // Rest auto-zeroed → {{1,2,0},{4,0,0}} , must write columns numbers               arr[1][0]  =   4
char str[10] = "hello";     // Initializes first 6 chars: 'h','e','l','l','o','\0', rest \0  , equivalent to 0 in ASCII
char str[]   = "world";     // Size = 6 (including '\0')
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






//////////////////// ternary operator
a == b ? c = 6 : c= 66 ;
c = ( a==b ) ? 6 : 66 ;






////////////////////    timer
#include<chrono>
auto start = std::chrono::steady_clock::now();  // Start timer

auto end = std::chrono::steady_clock::now();    // Stop timer
auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();     // Calculate and print time in microseconds
cout << " \n \n Time: " << ms << " µs\n";







////////////////////    printf
int u = 50 ;
printf("   this is  %d \n  " ,  u ) ;              // 50
printf(" this is  %0d \n  " ,  u ) ;               // 50
printf(" also  equals = %0*d \n  " , 1  , u ) ;    // 50
printf(" also  equals = %0*d \n  " , 3  , u ) ;    // 050
printf(" also  equals = %03d \n  " , u ) ;         // 050            

float f = 2.7638 ;
printf (" this is %f \n " , f);        // 2.763800
printf (" this is %.f \n " , f);       // 3
printf (" this is %.3f \n " , f);      // 2.764            
printf (" this is %.*f \n " , 3 , f);  // 2.764       

char name [] = " mhmd";
char letter = 'm';
printf("  my name is %s \n " , name );  // my name is mhmd
printf(" my letter is %*c \n " , 6 , letter) ;  // my letter is      m
printf(" my letter is %6c \n " , letter) ;  //     my letter is      m
cout << endl << string ( 6 , 'e') + "mhmd";    //// eeeeeemhmd



//////////////////   setw
#include<iomanip>
cout << "_______________________________________ \n";
cout << "| name |           grade       | end  | \n";
cout << "|______|_______________________|______| \n";
cout << "|" << setw(6) << "mhmd" <<"|"<< setw(23) << " very good " << "|" << setw(6) << "pass " << "|\n" ;
cout << "|______|_______________________|______| \n";




/////////////////   alignment
string align ( char side , int space , const string& word , char fill = ' ' )
{
int blanks = space - static_cast<int>(word.size()) ;
if ( blanks < 0 )   blanks = 0 ;
int l_pad = blanks/ 2 ;
int r_pad = blanks - l_pad ;

if ( side == 'l')
return word + string(blanks , fill)  ;

else if ( side == 'r')
return string(blanks , fill ) + word ;

else
return string( l_pad , fill ) + word + string( r_pad , fill ) ;
}




cout << "_________________________________________ \n";
cout << "|    name    |      grade        | end  | \n";
cout << "|____________|___________________|______| \n";
cout << "|" << align( 'l' , 12 , "mhmd" )       << "|"  << align ( 'c' , 19 , " very good ")      <<"|" << align('r' , 6 , "pass") <<"|"<< endl;
cout << "|" << align( 'l' , 12 , "abdelsalam" ) << "|"  << align ( 'c' , 19 , " bad " , '*')      <<"|" << align('r' , 6 , "fail") <<"|"<< endl;
cout << "|" << align( 'l' , 12 , "may")         << "|"  << align ( 'c' , 19 , " very high good ") <<"|" << align('r' , 6 , "pass") <<"|"<< endl;
cout << "|____________|___________________|______| \n";










/////////////////////////  pointers
int a = 10 , *p , arr[]= { 10,20,30,40} , *pp ;
stdata ststdata , *ppp ;  
stdata stststdata ;
void *pppp , *ppppp ;
p = &a ;
pp = arr ;
ppp = &ststdata ;
pppp = &a ;
ppppp = &ststdata.age;


p = &a = pppp ;                                                          address
*p = a = *static_cast<int*>(pppp)  ;                                     value

pp = arr = &arr[0]            pp +1 = arr +1 = &arr[1]                                        address   any element                  
*pp = *arr = arr[0]           *(pp+1) = *(arr+1) = arr[1]                                      value     any

ppp =          &(*ppp).name    = &ppp->name      = &ststdata     = &ststdata.name                            address  1st element
(*ppp).name   = ppp->name      = ststdata.name   = static_cast<stdata*>(ppppp)->name                         value    1st      
// struct pointer point to structure and 1st element
// specific type pointer e.g int , sting , ...  points to specific element
// void pointer points to struct or element , to give value must be casted to struct or specific type
// .... if casted to struct , just choose element as extension e.g (ppppp)->name and no * at beginning
// struct pointer + 1 equals struct address + struct size ( not mandatory to be coming object in same struct )

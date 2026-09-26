=====================================================================================================================
////////////////////////////////////////////////////////////////////////////////////  reference
int a = 10 ;
int b = a ;
int& c = a ;                 // alias ( neck name ) اسم دلع لنفس المتغير
a ++ ;
              // functions and range loop by default use copies ,, so i use alias to save memory and enable modifying
cout << a << "\n" ;   // 11
cout << b << "\n" ;    // 10
cout << c << "\n\n" ;     // 11

============================================================= 
////////////////////////////////////////////////////////////////////////////////////  pointers

int* p ;
p = &a ;                  // p takes only addresses , p takes only one address يصنع متغير جديد

cout << p << "\n" ;      // a   address         🧠🧠🧠
cout << *(&a) << "\n" ;  // value of a    11
cout << *p << "\n" ;     // value of a    11    
cout << &p << "\n\n" ;     // p  address         


*p = 20 ;                                  // 🧠🧠🧠
cout << a << "\n" ;  // 20         

a = 30 ;
cout << *p << "\n\n" ;  // 30



============================================================= 
//////////////////////////////////////////////////////////////   pointer of pointer

num = 10 , 
*p      = &a  , 
**pp    = &p  ,
***ppp  = &pp ;


// N.B :  same sequence         & = bare = * 

//  num   = *p    = **pp  = ***ppp ;
//  &num  =  p  = *pp   = **ppp;
//  &p    =  pp = *ppp 
//  &pp   =  ppp 


///////////////////////////////////////
diff types of pointers despite same size ,
 due to different function 
 ( dereferencing to give value : int reads 4 consecutive bytes then calculator ,, char read only 1 byte then calculator then ascii )


============================================================= 
                                        int 1D array

//int arr[5] = { 10 , 20 , 30 , 40 , 50 };                  // each item has specific address


// ⚠️⚠️⚠️ 1D array has 3 ways of addresses   ( array - element - pointer )

//int (*p)[5]     =  &arr;                               
// p              =  &arr                                      🧠🧠🧠  address of array      
// p + 1          =  &arr + 1✅                               🧠🧠🧠  address after array                +20 bytes   ( 5 elements * 4 bytes ) 

//int* pp = arr ;  ✅                                                // arr decays to apointer of its 1st element                    
// pp           = arr       =     &arr[0]                      🧠🧠🧠  address of element     
// pp + 1✅    = arr + 1✅ =     &arr[1]                      🧠🧠🧠  address after element              + 4 bytes   ( 1 element  * 4 bytes ) 
// pp + 2       = arr + 2   =     &arr[2]                      🧠🧠🧠  address after after element        + 8 bytes   ( 2 elements * 4 bytes ) 

// &p       or      &pp                                      🧠🧠🧠  address of pointer    
// &p       or      &pp + 1                                  🧠🧠🧠  address after poniter ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )



// ⚠️⚠️⚠️ 1D array has 2 ways of dereferencing values

// (*p)[0]   =   *(*p)       =   *(*p + 0)   =   (*p)[0]   =   10
// (*p)[1]   =   *(*p + 1)   =   *((*p) + 1) =   (*p)[1]   =   20


// *pp✅         =   *arr         =   *(&arr[0])    =    pp[0]✅   =   arr[0]        =  10
// *(pp + 1)✅   =   *(arr + 1)   =   *(&arr[1])    =    pp[1]✅   =   arr[1]        =  20

============================================================= 
                                        char array


//char arr[5] = {'a', 'b', 'c', 'd', '\0'};             // each item has specific address ( same as  char arr[] = "abcd"; )

// ⚠️⚠️⚠️ 1D char array has 3 ways of addresses   ( array - element - pointer )

//char (*p)[5] =  &arr;
// p         =  &arr                                        🧠🧠🧠  address of array
// p + 1     =  &arr + 1                                    🧠🧠🧠  address after array                +5 bytes   ( 5 elements * 1 byte ) 

//char* pp = arr ;                                               // arr decays to apointer of its 1st element
// (void*)pp     = (void*)arr     = (void*)&arr[0]          🧠🧠🧠  address of element
// (void*)(pp+1) = (void*)(arr+1) = (void*)&arr[1]          🧠🧠🧠  address + 1     as char is 1 byte
// (void*)(pp+2) = (void*)(arr+2) = (void*)&arr[2]          🧠🧠🧠  address + 2

// &p       or      &pp                                     🧠🧠🧠  address of pointer
// &p + 1   or      &pp + 1                                 🧠🧠🧠  address after pointer ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )



// ⚠️⚠️⚠️ Unique to char pointers with cout / printf

// pp       = arr       =    &arr[0]                        🧠🧠🧠  print string "abcd" ,  starting from arr[0]  till  find  \0
// pp + 1   = arr + 1   =    &arr[1]                        🧠🧠🧠  print string "bcd"  ,  starting from arr[1]  till  find  \0
// pp + 2   = arr + 2   =    &arr[2]                        🧠🧠🧠  print string "cd"   ,  starting from arr[2]  till  find  \0



// ⚠️⚠️⚠️ 1D array has 2 ways of dereferencing values

// (*p)[0]   =   *(*p)       =   *(*p + 0)   =   (*p)[0]   =   'a'
// (*p)[1]   =   *(*p + 1)   =   *((*p) + 1) =   (*p)[1]   =   'b'

// *pp          =   *arr         =   *(&arr[0])    =    pp[0]   =   arr[0]        =  'a'
// *(pp + 1)    =   *(arr + 1)   =   *(&arr[1])    =    pp[1]   =   arr[1]        =  'b'    `


============================================================= 
                                        int 2D array


int arr[2][3] = { {10, 20, 30}, {40, 50, 60} };     // row-major order block (2 rows x 3 cols)

// ⚠️⚠️⚠️ 2D array has 4 ways of addresses   ( whole array - row - element - pointer )

//int (*p)[2][3] = &arr;  
// p         =  &arr                                          🧠🧠🧠  address of whole 2D array
// p + 1     =  &arr + 1 ✅                                   🧠🧠🧠  address after whole 2D array ( 6 items , each 4 bytes , so 24 bytes + )

//int (*pp)[3] = arr;     ✅                                        // arr decays to apointer of its 1st element
// pp           =  arr         =    &arr[0]                    🧠🧠🧠  address of row 0
// pp + 1✅    =  arr + 1✅   =    &arr[1]                    🧠🧠🧠  address of row 1 ( 3 items , each 4 bytes , so 12 bytes + )



//int *ppp = &arr[0][0];   //✅
// ppp       =  &arr[0][0]=    *arr                         🧠🧠🧠  address of element [0][0]
// ppp + 1✅ =  &arr[0][1]=    *arr + 1                     🧠🧠🧠  address + 4     as int is 4 bytes
// ppp + 3   =  &arr[1][0]=    *arr + 3                     🧠🧠🧠  address + 12    (moves to row 1, col 0)
// 2D array row-pointer decay ( *pp gives pointer to row's 1st element )
// *pp       =  *arr       =    &arr[0][0]                  🧠🧠🧠  address of element [0][0]
// *(pp + 1) =  *(arr + 1) =    &arr[1][0]                  🧠🧠🧠  address of element [1][0]



// &p       or      &pp         or      &ppp                🧠🧠🧠  address of pointer
// &p + 1   or      &pp + 1     or      &ppp + 1            🧠🧠🧠  address after pointer ( if 64-bit ( pointer is 8 bytes ) , so 8 bytes + )



// ⚠️⚠️⚠️ 2D array has 3 ways of dereferencing values ( row 1, col 2 -> value 60 )

// (*p)[1][2]           =   *(*(*p + 1) + 2)                   =   60

// (*(pp + 1))[2]    =   *(*(pp + 1) + 2)    =   pp[1][2]✅    =   60
// *(arr[1] + 2)     =   *(*(arr + 1) + 2)   =   arr[1][2]      =   60

// *(ppp + 1*3 + 2)  =   *(ppp + 5)           =   ppp[5] ✅     =   60


============================================================= 
///////////////////////////////////////////////////////////////////  pointer  function


void fun ( int arr[] )  // taking a pointer {22,33,44}
{
cout << arr[0] << endl ;    // print index 0  ,,  which is 22 
}


void cal ( int x , int* y , int** z )  // x 3 (local)   ,  y 3 (pointer) ,  z 3 (pointer)
{
int d , f ;
++ **z  ;       //  x 3 , y 4 , z 4    // y and z point to the original a , not x  [ increase of y or z , increases a ]  
                                        // **z ++ not accepted   **z++ evaluates as ** (z++).
d = **z ;       // d = 4
f = *y + 1 ;    // f = 5      
*y +=2  ;       // x 3 , y 6 , z 6      d = 4    f = 5    // pointers do not update local d or f // they point to only 1 address ( address of a )
x +=5  ;        // x 8 , y 6 , z 6       d = 4    f = 5 ;

cout << x + d + f << endl ;   //  8 + 4 + 5     = 17
}



int main()
{

int arr [] = { 11,22,33,44} ;
fun ( arr + 1 );     
// arrays automatically decay into pointers when passed to functions.  
// Passing arr + 1 passes the address of the element at index 1 (22).
cout << arr[0] << "\n\n" ;     // no change to arr itself ( change was only to a temporary pointer )   ,,  result is 11




int a = 3 ;
int* b  = &a ;
int** c = &b ;
cal ( a , b , c );  //   3 (local)   ,  3 (pointer) ,  3 (pointer)  
cout << a + *b + **c << endl ;  // 6 + 6 + 6    =   18



}


============================================================= 
///////////////////////////////////////////////////////////////////  pointer  struct
// struct employ {string name ;int grade ;};  global scope

employ emp ;
employ* ppp;

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


============================================================= 
///////////////////////////////////////  void pointer and casting

void* pop ; 
pop = &a ;
cout << pop << "\n" ;                    // void can hold address
int *pint = static_cast<int*>(pop) ;     // void can not hold value , needs casting and needs assign to a variable ( so do casting once )
cout << *pint << "\n\n" ;    


///////////////////////////////////////   new and delete

int size = 5 ;

int* ptr ;
float* ptrf ;
int* p = new int [size];

ptr = new int ;
ptrf = new float ;

*ptr = 55 ;
*ptrf = 44.4f ;   // added f , as because numbers with decimals are considered double

cout << *ptr << "\n";
cout << *ptrf << "\n";

delete ptr ;
delete ptrf ;
delete p ;




///////////////////////////////////////   mixed example
////////// practically , void is not used , vector is used instead for dynamic array

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

============================================================= 
///////////////////////////////////////⚠️⚠️⚠️   iterators
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

// .erase(start, end) removes elements starting at start up to, but not including, end // also Re-assign the Iterator

vnum.erase ( iter , iter+ 2) ;  
cout << *iter << endl;      // 44

cout << endl ;

vnum.erase ( iter , vnum.end()- 2) ;   //vnum.begin() points to 33 (index 0).    //vnum.end() is the position after the last element (66).
cout << *iter << endl;               // 55
cout << *vnum.begin() << endl;      // 11

int count_times = count(vnum.begin() , vnum.end() , 55 ); // specific number repitition
reverse(vnum.begin() , vnum.end()  );   // reverse order




vector<int>vnum { 11,22,33,44,55,66};
vector<int>& vnums = vnum ;                    // function parameter , ranged loop                    ✅✅✅
vector<int>* pop = &vnum ;                     // dynamic switching between vectors                   ✅✅✅
vector<int>::iterator it = vnum.begin();       // searching , modifying elements                      ✅✅✅

In C++, iterators are an abstraction of pointers used to step through containers (like vector, list, set, etc.).
range based loop                               by default                                             ✅✅✅
iterator loop                                  erasing   ,   skipping   ,   backward traversal        ✅✅✅

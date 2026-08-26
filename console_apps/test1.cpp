#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


struct employ {
string name ;
int grade ;
};



int main() 
{

int a = 10 ;
int b = a ;
int &c = a ; // alias ( neck name ) اسم دلع لنفس المتغير
a ++ ;

cout << a << "\n" ;   // 11
cout << b << "\n" ;    // 10
cout << c << "\n\n" ;     // 11

///////////////////////////////////////

int *p ;
p = &a ; // p takes only addresses , p takes only one address يصنع متغير جديد

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
cout << " you choose one student number , grade is : " << *(static_cast<float*>(pep)) << "\n";
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
return 0;
}

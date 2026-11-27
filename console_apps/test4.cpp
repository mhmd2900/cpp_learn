#include<iostream>
#include<string>
#include<vector>
using namespace std ;

class clsdoctors 
{
protected :
    string _name ;
    int _id = 1000;
    static int _count ;
public :
    clsdoctors () {
    cout << " why you come here\n";
    _count ++ ;
    //_id += _count ;
    };

    clsdoctors ( string name )
    {
    _count ++ ;
    _id += _count ;
    _name = name ;
    }

    static void print_count ( )
    {
    cout << "count is " << _count << endl ;
    }

    void print_all ( )
    {
    cout << "count is " << _count << endl ;
    cout << "id is " << _id << endl ;
    }
            
    void get_doctor_id ()
    { 
    cout <<  "doctor id is " <<  _id << endl ;
    }
};
int clsdoctors::_count = 0 ;


class clssurgeons : public clsdoctors
{
private :
    string _name ;
    int _id = 200 ;
    static int _count ;
public :
    clssurgeons ( string name )
    {
    _count ++ ;
    _id += _count ;
    _name = name ;
    }

    static void print_count ( )
    {
    cout << "count is " << _count << endl ;
    cout << " ----  and the main count \n";
    clsdoctors::print_count();
    }

    void print_all ( )
    {
    cout << "count is " << _count << endl ;
    cout << "id is " << _id << endl ;
    cout << " ----  and the main all \n";
    clsdoctors::print_all();
    }

    void get_surgeon_id ()
    { 
    cout << "surgeon id is " << _id << endl ;
    }

    void get_doctor_id ()
    { 
    cout <<  "doctor id is " <<  clsdoctors::_id << endl ;
    }
};
int clssurgeons::_count = 0 ;             


int main()
{

clssurgeons surgeon[3] = {{"a"} , {"b"} , {"c"}} ;

clssurgeons::print_count();
surgeon[1].get_surgeon_id();
surgeon[1].get_doctor_id();
clsdoctors doctor[2] = {{"fff"} , {"yyy"}} ;

clssurgeons::print_count();
surgeon[1].get_surgeon_id();
surgeon[1].get_doctor_id();
doctor[1].get_doctor_id();


}



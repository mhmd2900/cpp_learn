#include<iostream>
#include<string>
#include<vector>
using namespace std ;



class clspersons 
{
protected :
int _id = 1000 ;
string _first_name ;
string _last_name ;
string _email ;
static int _count ;

void print ( )
{
cout << " INFO   \n";
cout << "_______________________________\n";
cout << " name  is " << _first_name << " " << _last_name << endl ;
cout << " email is " << _email << endl ;
cout << "_______________________________\n";
}



public :
    clspersons ( string first , string last , string email )
    {
    _first_name = first ;
    _last_name = last ;
    _email = email ;
    _count ++ ;
    _id += _count ;
    }

        clspersons ()
    {

    }

    static int get_count ()
    {
    return _count ;
    }

    void show_id ()
    {
    cout << _id << endl;
    }

    void set_firstname ( string first )
    {
    _first_name = first ;
    }
    void set_lastname ( string last )
    {
    _last_name = last ;
    }
    void show_name ( )
    {
    cout << _first_name << " " << _last_name << endl ;
    print();
    }

    void set_email ( string email )
    {
    _email = email ;
    }
    void show_email ( string message )
    {
    cout << " subject  :  " << message << endl << "  was sent successfully to  ";
    cout << _email << endl ;
    }
};

int clspersons::_count = 0 ;


class clsstudents : public clspersons 
{
public :
int _salary = _id ;
clsstudents (  string first , string last , string email , int salary ) : clspersons ( first , last , email )
{
_salary = salary ;
}
};



int main()
{
clspersons person[2] = { {"ahmed" , "ali" ,"gmail" } , {"moh" , "salah" ,"yahoo" }};

person[0].show_email("rabet") ;
cout << clspersons::get_count() << endl ;
person[1].show_id();
person[0].show_id();

person[1].set_lastname("hoho");
person[1].show_name();

// clspersons personA ;
// personA.show_name();
// personA.show_name();

clsstudents student(22 , "aaa") ;
student.show_id();
cout << student._salary ;

}

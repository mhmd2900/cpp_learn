#include<iostream>
#include<string>
#include<vector>
using namespace std ;

class clspersons                     //////////////////////////
{
   // protected : 
    string _name ;
    int _id = 1000 ;
    static int _count ;

    public :
    clspersons () {}  
    clspersons ( string name , int id ) 
    {
    _name = name ;
    _count++ ;
    _id += _count ;
    }
    static void get_count ()
    {
    cout << _count << endl ;    
    }
    void get_id ()
    {
    cout << _id << endl ;    
    }
    void print (){ cout <<"print\n";}
};
int clspersons::_count = 0 ;


class clsdoctors  : public clspersons  //////////////////////////
{
int _num ;
string _department ;

public :
// clsdoctors ( string department , string name ) : clspersons ( name ) 
// {
// _department = department ;
// }

clsdoctors ( int num ) 
{
cout << " num\n";
}
    void print (int n){ 
        clspersons::print();
        cout <<"print 2 \n";}


};

int main()
{

// clsdoctors doctor[5] = { { "ali" , "surgery "} , { "ahmed" , "surgery " } , { "khaled" , "surgery " } , 
//                          { "mohab" , "surgery " } , { "hind" , "surgery " }} ;

// doctor[0].get_count();
// doctor[1].get_count();
// doctor[2].get_count();
// doctor[3].get_count();
// doctor[4].get_count();
// clspersons::get_count();

// doctor[0].get_id();
// doctor[1].get_id();
// doctor[2].get_id();
// doctor[3].get_id();
// doctor[4].get_id();
// doctor[2].get_id();

clsdoctors doctor(44) ;
doctor.print(77);
doctor.clspersons::print();
doctor.get_id();
}



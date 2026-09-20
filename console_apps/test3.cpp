#include<iostream>

using std::cout ;
using std::cin ;
using std::string ;


enum enpermission { read = 1 << 0 ,  write = 1 << 1 ,  excute = 1 << 2  , del = 1 << 3 };
enum ensymptoms   { fever = 1 << 0 , cough = 1 << 1 , vomiting = 1 << 2 , pain = 1 << 3 , 
                    dizziness = 1 << 4 , itching = 1 << 5 , anuria = 1 << 6 };

int main ()
{
short guest  = read ;
short editor = read | write ;
short admin  = read | write | excute | del ;

editor = editor ^ ( write | excute ) ;  // ^ means reverse ,, now editor lose write and receive excute 
admin  = admin  ^ ( guest & editor  ) ;  // now admin lose read

if ( editor & excute )     cout << " editor can  \n ";
else                       cout << " editor can not  \n ";

if ( admin & read )        cout << " admin can  \n ";
else                       cout << " admin can not  \n ";


// ----------------------------------------------------------------

short respiratory = fever | cough ;
short abdominal   = fever | vomiting | pain ;
short neuro       = itching | dizziness ;
short uro         = itching | anuria ;


short mhmd = fever | cough | vomiting | pain | itching  ;
short aly = fever | itching ;
short ready_for_discharge = 0 ;


mhmd = mhmd ^ ( respiratory | abdominal ); //  mhmd     itching
mhmd = mhmd ^ ( neuro & uro ); // mhmd  0 
if ( mhmd == ready_for_discharge )  cout << " can go \n " ;


return 0 ;
}

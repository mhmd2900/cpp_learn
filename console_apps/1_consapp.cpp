#include<iostream>
using namespace std ;


int main ()
{

int arr [5] = { 5 , 2 , 1 , 2 , 6 } ;
int arr2 [5] = {0} ;

int rep = 0 ;
int nc = -1 ;

for ( int i = 0 ; i < 5 ; i ++ )
{
for ( int x = 0 ; x < 5 ; x ++ )
{
if ( arr[i] > arr[x] )
rep ++ ;

if ( arr[i] == arr[x] )
nc ++ ;
}
arr2[rep - nc] = arr[i] ;
rep = 0 ;
nc = -1 ;

}

for ( int u = 0 ; u < 5 ; u++ )
cout << arr2[u] << endl ;

return 0;
}







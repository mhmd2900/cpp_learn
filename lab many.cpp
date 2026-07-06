//////////////// check prime
bool check_prime ( int num )
{
     if ( num < 2 )
      return false ;   //  0 , 1     to avoid skipping into 3rd return
      
      for ( int x = 2 ; x <= num /2 ; x ++ ) // <=  to involve 4 and prevent its skipping to 3rd return
      if ( num % x == 0 )
      return false ;  

    return true ;  // 2 , 3         skip to it 
}




//////////////// check prime in range        Sieve of Eratosthenes    ,,,   function overloading
void check_prime  ( vector<int>&vnum , int min , int max )   
{
vector<int>vtemp ( max , 0) ;   

     // corrupt values of certain indices ( give 1 )
 for ( int i = 2    ; i < sqrt(max) ; i++  ) // avoid redundant max/2
 if (vtemp[i] == 0)   // avoid redundant composite numbers  e.g   8 is multiple of 2 and 4 
    {
    for ( int x = i*i  ; x < max   ; x+=i ) 
    vtemp[x] = 1 ;
    }
    // convert indices of uncorrupted values ( given 0 ) to values and push in a vector
for ( int z = min ; z < max ; z++)
if ( z >= 2 && vtemp[z] == 0 )      
vnum.push_back(z);
}





/////////////////////////////////////  check square root  babylion
void check_sqrt(double num)
{
 double g = num/2 ;  // initial guess
 double prev_g ;
 double err = 0.0001 ;

 do 
 {
 prev_g = g ;
 g = ( g + num/g) /2 ;
 }while ( fabs(g - prev_g)> err) ;

cout << g ;
 }








////////////// check distinct number ( copy repeated number only in 1st appearance )
bool check_distinct ( int number , int arr [] , int index)
{
for ( int i = index -1 ; i >= 0 ; i --)
if ( number == arr[i])
return false ;

return true ;
}



//////////////////// check palindrome
bool check_palindrome ( int arr[] , int size)
{
for ( int i = 0 ; i < size ; i ++)
if (arr[i] != arr [size-1-i] )
return false ;
return true ;
}

#include<iostream> 
#include<cmath> 

using namespace std ;

int t, a , b ; 


int main(){

  cin >> t ; 

  while(t--){

    cin >> a >> b ; 

    if(2 * a <= b )
      cout<< a <<endl ;
    
    else if (2 * b <= a)
      cout << b <<endl ; 

    else 
      cout << (a+b)/3 <<endl ; 


  }

}
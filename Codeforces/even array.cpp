#include<iostream> 

using namespace std ;

int t , n ; 

int main(){

  cin >> t ; 

  while(t--){

    cin >> n ; 
    int even = 0 ; 
    int odd = 0 ; 

    for(int i=0;i<n;i++){

      int a ; 
      cin >> a ; 

      if( i% 2 ==0 && (a%2 !=0)){
        even ++ ; 
      }
      else if(i%2!=0 && (a%2 == 0 ))
        odd ++ ; 
    }

    if((even == odd) && even !=0)
      cout<< odd<<endl ; 

    else if(even == 0 && odd == 0)
      cout<< 0 <<endl ;
    else 
      cout<< -1 <<endl ; 

  }


}
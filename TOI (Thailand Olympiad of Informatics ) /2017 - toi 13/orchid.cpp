#include<bits/stdc++.h>


using namespace std ;

int n ; 

int dp[ 1000005 ] ; 
int k  ; 

int main(){

  scanf("%d",&n) ; 

  for( int i = 0 ; i < n ; i++){

    int a ; 
    scanf("%d",&a) ; 

    int ind = upper_bound(dp , dp + k , a) - dp  ;

    // cout<<"# "<< i <<" "<< ind <<endl ; 

    dp[ind] = a ; 

    k = max( k , ind + 1 ) ; 

  }
  printf("%d\n" , n - k ) ; 

  // for(int i = 0 ; i < k ; i ++){

  //   cout<< dp[i] <<endl ; 
  // } 

}
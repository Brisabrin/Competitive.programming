#include<bits/stdc++.h>

using namespace std ;

int n  ;
int arr[1005] ;

bool dp[2][60005] ; 

int main(){
  int prev = 0 ; 
  int now = 1 ; 

  scanf("%d",&n) ; 

  for ( int i=0 ;i<n;i++ ) scanf("%d",&arr[i]); 

  dp[0][30000] = true ; 
  for( int i = 0;i<n;i++){
    for(int j=0;j<= 60000;j++){

      int ind ; 
      int val = (j-30000) - arr[i] ; 

      if(val > 30000)
        ind = val - 60001 + 30000 ; 

      else if(val < -30000  )
        ind = val + 60001 + 30000 ; 
      else 
        ind = val + 30000 ; 

      dp[now][j] = dp[prev][j] || dp[prev][ind] ; 

    }
    prev ^= 1 ; 
    now ^= 1 ; 

  }
  int sol  ; 
  for(int i=0;i<=60000;i++){
    if(dp[prev][i])
      sol = i ; 
  }

  cout<<sol - 30000;  



}
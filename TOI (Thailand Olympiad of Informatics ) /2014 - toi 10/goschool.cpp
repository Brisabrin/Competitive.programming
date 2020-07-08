#include<bits/stdc++.h>

using namespace std ; 


int n , m ; 

int t  ; 

const int MAXN = 55 ; 

int arr[MAXN][MAXN] ; 
long long dp[MAXN][MAXN] ; 


int main(){

  cin >> m >> n; 
  cin >> t  ; 

  for(int i= 0 ; i < t ; i++){
    int x , y ; 

    cin >> x >> y ; 

    arr[ n - y + 1][x] = 1 ; 

  }

  dp[n][1] = 1 ; 

  for(int i = n - 1 ; i>= 1 ; i -- ){

    if( arr[i][1] == 1 )
      continue ; 
    
    dp[i][1] = dp[i+1][1] ; 

  }
  for(int i = 2 ; i<= m ; i++){
    if( arr[n][i]==1)
      continue; 
    
    dp[n][i] = dp[n][i-1] ; 
  }
  for(int i = n - 1  ; i >= 1 ; i-- ){

    for( int j = 2 ; j <= m  ; j ++ ){

      if( arr[i][j])
        continue ; 

      dp[i][j] = dp[i][j-1] + dp[i+1][j] ; 
    }
  }

  cout<< dp[1][m] ; 


}
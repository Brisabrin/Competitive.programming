#include<bits/stdc++.h>

using namespace std ;

int n , m ; 

const int MAXN = 1005 ; 
int arr[MAXN][MAXN] ; 

int dp[MAXN][MAXN] ; 
int path[MAXN][MAXN] ; 


int main(){
  
  cin >> n >> m ; 

  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j<= m ; j ++){
      if( i % 2 == 0 )
        cin >> arr[i][j + 1 ] ; 

      else 
        cin >> arr[i][j] ; 
    }

  }
  for(int i = 1 ; i <= n ; i++){

    for(int j = 1 ; j<=m + 1 ; j ++){

    
      if((i % 2 == 0  && j == 1 )|| (i% 2 ==1 && j == m + 1 ))
        continue ; 
  
      if( i == 1 )
        path[i][j] = 1 ; 

      if( i % 2 == 1  ){

        dp[i][j] = max(dp[i-1][j] , dp[i-1][j + 1 ]) + arr[i][j] ; 

        if( i > 1 ){

          if( dp[i-1][j] ==  dp[i-1][j + 1 ] )
            path[i][j] = path[i-1][j] + path[i-1][j+1] ; 

          else if(dp[i-1][j] >   dp[i-1][j + 1 ]  )
            path[i][j] = path[i-1][j] ; 
          
          else 
            path[i][j] = path[i-1][j+1] ; 
        }
      }

      else {

        dp[i][j] = max(dp[i-1][j] , dp[i-1][j - 1 ]) + arr[i][j] ; 

        if( i > 1 ){
          if( dp[i-1][j] ==  dp[i-1][j - 1 ] )
            path[i][j] = path[i-1][j] + path[i-1][j-1] ; 

          else if(dp[i-1][j] >   dp[i-1][j - 1 ]  )
            path[i][j] = path[i-1][j] ; 
          
          else 
            path[i][j] = path[i-1][j-1] ;
        } 

      }
    }
  }

  int st ; 

  if( n % 2 == 0 )
    st = 2 ; 
  else 
    st = 1 ; 

  int ma = INT_MIN ;  
  int co = 0 ; 

  for(int i = st ; i < st + m ; i++ ){

    if( dp[n][i] > ma )
      ma = dp[n][i] , co = path[n][i] ; 

    else if( dp[n][i] == ma )
      co += path[n][i] ; 

  }

  cout<< ma <<' ' <<co <<endl ; 

}
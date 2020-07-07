#include<bits/stdc++.h>

using namespace std;

int n , m  , k ; 
const int MAXN = 1000 + 5 ; 

int arr[MAXN][MAXN] ; 

int sum[MAXN][MAXN] ; 

int sol = 0 ; 

int main(){

  cin >>n >> m >> k ; 


  for(int i = 1 ; i <= n ; i++){

    for(int j = 1 ; j <= m ; j++){

      scanf(" %d",&arr[i][j]) ;

      if( j == 1 )
        sum[i][j] = arr[i][j] + sum[i-1][j] ; 

      else {
        sum[i][j] = (sum[i-1][j] + sum[i][j-1] + arr[i][j]) - sum[i-1][j-1] ;  
      }

    }
  }
  
  for( int i = k ; i<=n; i ++ ){
    for(int j = k ; j<= m ;j++){
      int val = sum[i][j] ; 
      int co = 0 ; 
      if( i > k ){
        val -=sum[i-k][j] ;
        co ++ ; 
    
      }
      if( j > k ){
        val -= sum[i][j-k] ; 
        co ++ ; 
      }

      if( co == 2 )
        val += sum[i-k][j-k] ; 
      

      sol = max(sol , val) ; 
    }
  }

  cout<< sol <<endl ; 


}
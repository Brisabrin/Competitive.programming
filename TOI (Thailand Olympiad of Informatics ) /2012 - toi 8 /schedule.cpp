#include<bits/stdc++.h>

using namespace std ; 

int m , n ; 
const int MAXN = 1000 + 5 ;  

int a[MAXN] , b[MAXN] ; 

pair<int,int>  dp[MAXN][MAXN] ; 
//  first = day , second = hour 

pair<int,int> addT(pair<int,int> p , int num){


  if( p.second + num <= m ){

    p.second += num  ; 
  }

  else 
    p.first ++ , p.second = num ; 

  return p ; 

}

pair<int,int> minT(pair<int,int>p , pair<int,int> p2 ){

  if( p.first < p2.first )
    return p ; 

  else if(p2.first < p.first )
    return p2 ; 

  else if( p2.second < p.second )
    return p2 ; 
  
  return p; 

}
int main(){

  cin >> m >> n ; 

  for(int i = 1 ; i <=n ; i ++) scanf("%d",&a[i]) ; 

  for(int j = 1 ; j<=n ; j++) scanf("%d",&b[j]) ; 

  for(int i = 1 ; i <= n ; i ++)
    dp[i][0] = addT(dp[i-1][0] , a[i] ) , dp[0][i] =  addT(dp[0][i-1] , b[i]) ; 

  for(int i = 1 ; i<= n ; i ++){

    for(int j = 1 ; j<= n ; j++){

      dp[i][j] = minT(addT(dp[i-1][j] ,  a[i]), addT(dp[i][j-1] , b[j])) ; 

    }

  }

  cout<< dp[n][n].first + 1 << endl <<dp[n][n].second  ; 




}
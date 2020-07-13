#include<bits/stdc++.h>
using namespace std ;
int n , k , a[105],dp[105][100005]; 
int main(){

  scanf("%d%d",&n,&k) ;
  for (int i=1;i<=n;i++)
  {
    scanf("%d",&a[i]); 
  }
  memset(dp,-2,sizeof(dp)); 
  dp[0][10000] = 0 ; 
  for (int i=1;i<=n;i++)
  {
    int b ; 
    scanf("%d",&b) ; 
    b = a[i] - k * b ; 
    for (int j=20000;j>=0;j-- )
    {
      dp[i][j] = max(dp[i-1][j],dp[i-1][j-b]+a[i]);
    }
  }
  if(dp[n][10000]== 0 )
    cout<< -1;  
  
  else 
    cout<< dp[n][10000] ; 
}
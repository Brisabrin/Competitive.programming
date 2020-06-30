#include <bits/stdc++.h>
using namespace std; 


long long  dp[2][5000];

// long long  Inversion(int n, int k)
// {
//     if (dp[n][k] != -1) return dp[n][k];
//     if (k == 0) return dp[n][k] = 1;
//     if (n == 0) return dp[n][k] = 0;
//     long long  j = 0, val = 0;
//     for (j = 0; j < n && k-j >= 0; j++)
//         val += Inversion(n-1, k-j);
//     return dp[n][k] = val;
// }



int main()
{
  int n , k ; 
  scanf("%d %d",&n,&k);
  // for (int i = 1; i <= n; i++)
  //   for (int j = 0; j <= k; j++)
  //     dp[i][j] = -1;

  int prev = 0 , now = 1 ; 
  // for(int i=0;i<=n;i++) dp[i][0] = 1 ; 
  // for (int i=1;i<=k;i++) dp[0][i] = 0 ;  

  for (int i=0;i<=n;i++){
    for (int l = 0;l<=k;l++){
      int val = 0 ;  
      if(l==0){
        dp[now][l] = 1; 
        continue ; 
      }
      if(i==0)
      {
        dp[0][l] = 0 ; 
        continue ; 
      }
      for (int j=0;j<i && l-j>=0;j++){
        val += dp[prev][l-j] ; 
      }
      dp[now][l] = val%2012 ; 
    }
    prev^=1; 
    now^=1 ; 
  }
  cout<<dp[prev][k]<<endl; 
  

  // if (Inversion(n,k)>=2012) cout << Inversion(n,k)%2012 ;
  // else
  //   cout << Inversion(n,k);

}
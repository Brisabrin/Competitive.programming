#include <bits/stdc++.h>


using namespace std ;
const int MAXN = 500000 + 10 ; 
int n ,k; 
int arr[MAXN]; 
int dp[MAXN];
map<int,int> m ;  


int main()
{
  scanf("%d%d",&n,&k); 

  for (int i=1;i<=n;i++)
  {
    scanf("%d",&arr[i]); 
  }
  m[arr[1]]++ ; 
  dp[1] = arr[1];  
  for (int i=2;i<=n;i++)
  {
    if(i>k)
    {
      if(m[dp[i-k-1]]<=1)
        m.erase(dp[i-k-1]); 
      else 
      {
        m[dp[i-k-1]] -- ; 
      }
    }
    dp[i] = arr[i]+ m.begin()->first; 
    // cout<<i <<" "<<dp[i]<<endl; 
    m[dp[i]] ++ ; 
  }
  cout<<dp[n]; 
}
#include <bits/stdc++.h>


using namespace std ;
int m,n; 
const int MAXN = 1000 + 10 ; 
int arr[MAXN][MAXN];
int s[MAXN][MAXN];
int k ; 

int max_sum()
{

  if(k<n)
  {
    // s[0][0] = arr[0][0]; 
    //  first row iterate ; 
    // for (int i=0;i<n;i++)
    // {
    //   s[0][i] = arr[0][i] + s[0][i-1];
    // }
    // //  iterate col 
    // for (int i=1;i<m;i++)
    // {
    //   s[i][0] = arr[i][0] + s[i-1][0]; 
    // }

    for (int i=1;i<m;i++)
    {
      for (int j=1;j<n;j++)
      {
        s[i][j] = arr[i][j]+ s[i-1][j] + s[i][j-1] - s[i-1][j-1]; 
      }
    }
    // cout<<endl; 
    // for (int i=0;i<n;i++)
    // {
    //   for (int j=0;j<m;j++)
    //   {
    //     cout<< sum[i][j] <<" "; 
    //   }
    //   cout<<endl; 
    // }
    int cur  , sol = 1 ; 
    for (int i=k-1;i<m;i++)
    {
      for (int j=k-1;j<n;j++)
      {
        cur = s[i][j]; 
        if(i - k >= 0)
          cur -=s[i-k][j]; 
        if( j-k >= 0 )
          cur -=s[i][j-k];
        if(i-k>=0 && j-k>=0 )
          cur += s[i-k][j-k];  
      sol = max(cur, sol) ; 
      }
    }
    return sol ;
}
  return 0 ; 
}
int main()
{
  scanf("%d %d\n",&m,&n); 
  scanf("%d",&k);
  // sum[0][0] = arr[0][0]; 
  for (int i=0;i<m;i++)
  {
    scanf("\n"); 
    for (int j=0;j<n;j++)
    {
      scanf(" %d",&arr[i][j]);
      if(i==0 && j==0)
        s[0][0] = arr[i][j] ; 
      else if(i==0)
        s[0][i] = arr[0][i] + s[0][i-1];
      
      else if(j==0)
        s[i][0] = arr[i][0] + s[i-1][0]; 
    }
    // cur = 0 ; 
  }
  cout<< max_sum();

}
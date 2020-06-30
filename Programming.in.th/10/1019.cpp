#include <bits/stdc++.h>

using namespace std ;

void  count_len(string s,string s2,int n,int n2 )
{
  int arr[n+1][n2+1];
  int max_len = 0 ;  
  for (int i=0;i<=n;i++)
  {
    for (int j=0;j<=n2;j++)
    {
      if (i==0 || j==0 ) arr[i][j] = 0 ; 
      else if (s[i-1]==s2[j-1])
      {
        arr[i][j] = 1+ arr[i-1][j-1]; 
        if(arr[i][j]>max_len) max_len = arr[i][j]; 
      } 
      else arr[i][j]  = 0 ;
    }
  }
  int i  = 0 , j=0; 
  for (int k=0;k<=n && (arr[i][j]!=max_len);k++)
  {
    for (int l=0;l<=n2&& (arr[i][j]!=max_len);l++)
    {
      if(arr[k][l]==max_len)
      {
        i= k; 
        j = l ; 
      }
    }

  }
  string res; 
  for (int k=0;k<max_len;k++)
  {
    res+= s[i-1]  ;
    i-- ; 
    j-- ; 
  }
  for(int k =max_len-1;k>=0;k--)
    cout << res[k]; 

}

int main()
{
  string s,s2; 
  cin>> s ; 
  cin>> s2 ;

  count_len(s,s2,s.length(),s2.length()); 


}
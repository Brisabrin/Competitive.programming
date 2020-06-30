#include <bits/stdc++.h> 

using namespace std ;
const int MAXN = 1000;
vector<int> dp[MAXN];
vector<int> arr;  
int main()
{
  int y ;
  int ind = 0,max = 0 ;  
  bool track = true ; 
  while(track)
  {
    scanf("%d",&y);
    if(y!=-1 )
    {
      arr.push_back(y); 
      if (y>max) max = y; 
    }
    else 
    {
      track = false;
    }
       
      
  }

  dp[0].push_back(1) ;
  dp[0].push_back(1) ;
  dp[0].push_back(0) ;
  for (int i=1;i<=max;i++)
  {

    int a,b,c; 
    a = dp[i-1][0]; 
    b =dp[i-1][2] + dp[i-1][0] + dp[i-1][1]; 
    c = dp[i-1][1] ;
    dp[i].push_back(a);
    dp[i].push_back(b);
    dp[i].push_back(c); 
   
  }
  
  for (int i= 0;i<arr.size();i++)
  {
    int sum = dp[arr[i]][0] + dp[arr[i]][1]+ dp[arr[i]][2]; 
    cout<< dp[arr[i]][1] <<" "<<sum <<endl;
  }
}
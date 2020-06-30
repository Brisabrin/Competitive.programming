#include <bits/stdc++.h>

using namespace std; 


int gcd(int a ,int b)
{
  int res=100 ; 
  int m , l ; 
  if (a>=b) 
  {
    m = a; 
    l = b; 
  }
  else 
  {
    m= b; 
    l = a; 
  }

  while(res!=0)
  {
    res = m%l ; 

    if(res!=0 )
    {
      m = l ; 
      l= res; 

    }
      

  }

  return l ; 
  
}


int main()
{
  int n; 
  scanf("%d",&n); 
  int d;  
  long long lcm ; 
  for (int i=0;i<n;i++)
  {
    scanf("%d",&d); 
    if (i==0) lcm = d;  
    else 
    {

      lcm =(lcm*d) / gcd(lcm,d);  
    }
  }
  cout << lcm ; 

 
}
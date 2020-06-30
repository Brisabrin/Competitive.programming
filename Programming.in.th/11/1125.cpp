#include <bits/stdc++.h> 

using namespace std; 

int main() 
{
  int n; 
  scanf("%d",&n); 
  long int  x[n],y[n]; 
  long long  sumx[n],sumy[n]; 
  for (int i =0;i<n;i++)
  {
    scanf("%ld%ld",&x[i],&y[i]);
  }
  sort(x,x+n); 
  sort(y,y+n ); 
  long long sx= 0 , sy = 0 ; 
  for (int i=0;i<n;i++)
  {
    sx += x[i]; 
    sumx[i] = sx; 
    sy += y[i]; 
    sumy[i] = sy; 
  }

  long long sum = 0 ;

  for (int i=0;i<n-1;i++)
  {
    sum += (long long) (sumx[n-1]-sumx[i]) - (long long )(x[i]*(n-1-i)); 
    sum += (long long) (sumy[n-1]-sumy[i]) - (long long) (y[i]*(n-1-i));
  }
  cout <<sum <<endl ;

}
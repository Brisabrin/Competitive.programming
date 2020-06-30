#include <bits/stdc++.h> 

using namespace std; 

int main()
{
  int n,k  ; 
  scanf("%d%d",&n,&k); 

  int arr[1000000+5]; 

  for (int i =0;i<n;i++)
  {
    scanf("%d",&arr[i]); 
  }
  sort(arr,arr+n); 
  int c= 1 ; 
  for (int i=n-1;i>=0 ;i--)
  {
    if (c==k)
    {
      printf("%d",arr[i]);
      break ; 
    } 
    c++ ; 
  }

}
#include <bits/stdc++.h> 
using namespace std; 


int sum(int sum1[], int i, int j )
{
  return sum1[j] - sum1[i-1 ]; 
}

int main()
{
  int n ; 
  scanf("%d",&n);
  int arr[n]; 
  int sum1[n],ind = 0 ;

  int cur = 0;
  for (int i =0 ;i<n;i++)
  {
    scanf("%d",&arr[i]); 
    cur+=arr[i]; 
    sum1[ind] = cur; 
    ind++; 
  }
  int start,end; 
  int max = 0; 
  for (int i =0;i<n;i++)
  {
    for (int j=i;j<n;j++)
    {
      if(sum(sum1,i,j)>max)
      {
        max = sum(sum1,i,j); 
        start  = i ; 
        end = j ; 
      }
    }
  }
  if (max ==0)
  {
    cout<<"Empty sequence";
  }
  else
  {
    for(int i=start;i<=end;i++)
    {
      printf("%d ",arr[i]); 
    }
    cout<<endl ; 
    cout << max;
  }

}
#include<bits/stdc++.h>


using namespace std; 

int n ; 
const int MAXN = 200000 + 10 ; 
long long arr[MAXN]; 

int main()
{
  scanf("%d",&n); 
  for (int i=0;i<n;i++)
  {
    int d; 
    scanf("%d",&d); 
    arr[d] +=1 ; 
  }
  int k ; 
  scanf("%d",&k); 
  // for (int i=0;i<MAXN;i++)
  // {
  //   cout <<arr[i]<<endl;
  // }

  long long sol = 0 ; 
  for (int i=0;i<ceil((float)k/2);i++)
  {
    sol += (long long)arr[i] * arr[k-i];
    // cout<< i ; 
  }
  //  middle val ;
  if(k%2==0 && arr[k/2]>1)
  {
    long long  ind = arr[k/2]; 
    sol += (long long)((ind-1)*ind)/2; 
    // cout<< (arr[k/2]-1 )*(arr[k/2]) / 2 <<endl; 
  }
  cout << sol ; 
}
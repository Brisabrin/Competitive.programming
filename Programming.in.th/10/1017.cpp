#include <bits/stdc++.h>
using namespace std;
int x[4]={0,1,1,1};
int y[4] ={1,0,1,-1} ;

bool check_square(int arr[10][10],int n )
{
  map<int,int> m ; 
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<n;j++)
    {
      m[arr[i][j]]++;
    }
  }

  map<int,int> :: iterator itr ; 
  for(itr=m.begin();itr!=m.end();itr++)
  {
    if (itr->second>1) return false  ; 

  }
  return true ; 


}

bool comp(int a,int b,int c )
{
  if((a==b) &&(b==c))
    return  true ; 
  else return false  ;
}
long long find_sum(int arr[10][10],int si,int sj,int ind,int n )
{
  long long sum = 0; 
  for (int i=0;i<n;i++)
  {
    sum +=arr[si][sj]; 

    si+=x[ind]; 
    sj+=y[ind]; 
  }
  return sum ; 
}
bool check_magic (int arr[10][10],int n)
{
  // check row 
  long long  sum ; 
  sum = find_sum(arr,0,0,0,n);
  for(int i=1;i<n;i++)
  {
    if(sum!=find_sum(arr,i,0,0,n))
      return false ;
  }

  // check column 
  for(int j=0;j<n;j++)
  {
    if (sum!=find_sum(arr,0,j,1,n))
      return false ;
  }
  //diag L & R 

  if (comp(sum,find_sum(arr,0,0,2,n),find_sum(arr,0,n-1,3,n)))
    return true ;
  else return false ;
}

int main()
{
  int n ; 
  scanf("%d",&n); 
  int arr[10][10]; 
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<n;j++)
    {
      scanf("%d",&arr[i][j]); 
    }
  }

  if (check_square(arr,n)==false) cout <<"No" ;

  else 
  {
    if (check_magic(arr,n)) cout<<"Yes"; 
    else cout<<"No"; 
  }

}
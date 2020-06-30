#include<bits/stdc++.h>

using namespace std ;

int n , m ; 
const int MAXN = 100 + 10 ; 
int arr[MAXN][MAXN]; 

int sum_row[MAXN];
int sum_col[MAXN]; 
int inc_row[MAXN]; 
int inc_col[MAXN]; 



int main()
{
  int s = 0 ;
  int total = 0 ;  
  int cur = 0 ; 
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<m;j++)
    { 
      scanf("%d",&arr[i][j]); 
      s += arr[i][j]; 
      sum_col[j] +=arr[i][j] ;
      total+=arr[i][j]; 
    }
    sum_row[i] = s; 
    s =0 ; 
  }
  int inc_var = 0 ; 
  int d ; 
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<m;j++)
    { 

      scanf("%d",&d); 
      inc_var+= d; 
      inc_col[j] += d; 

    }
    inc_row [i] += inc_var ; 
    inc_var = 0 ;  
  }

  int sol = INT_MIN ; 
  //  iterate row ; 
  int sum_cur ; 

  for (int i =0 ;i<n;i++)
  {
    sum_cur = total - sum_row[i] ; 
    if(i>=0 && i<n-1)
    {
      sum_cur += inc_row[i+1]; 
    }
    if(i>0)
    {
      sum_cur+= inc_row[i-1]; 
    }

    sol = max(sol,sum_cur); 
  }

  //  iterate col ;

  for (int i =0 ;i<m;i++)
  {
    sum_cur = total- sum_col[i] ; 
    if(i>=0 && i<m-1)
    {
      sum_cur += inc_col[i+1]; 
    }
    if(i>0)
    {
      sum_cur+= inc_col[i-1]; 
    }

    sol = max(sol,sum_cur); 
  } 
  cout<< sol; 

}
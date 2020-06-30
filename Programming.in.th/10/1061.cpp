#include <bits/stdc++.h>

using namespace std; 

int arr[25][25]; 
 int n ;
bool visited[25][25]; 
int sol = -10  ; 
int dx[] = {0,0,1,-1}; 
int dy [] = {1,-1,0,0}; 
bool check(int x,int y )
{
  return x>=0 && x<n && y>=0 && y<n ; 
}

void dfs(int x,int y )
{
  visited[x][y] = true ; 
  sol = max(sol, arr[x][y]);

  for (int i=0;i<4;i++)
  {
    int newx= x + dx[i]; 
    int newy = y + dy[i]; 

    if (!check(newx,newy)|| visited[newx][newy] ||arr[newx][newy]==100 || arr[newx][newy]<=arr[x][y])
      continue ; 
    

    dfs (newx,newy); 

  }
}
int main()
{
  scanf("%d",&n); 
  int x,y; 
  scanf("%d%d",&y,&x); 

  x-- ; 
  y-- ; 
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<n;j++)
    {
      scanf("%d",&arr[i][j]); 
    }
  }

  dfs(x,y); 
  cout << sol;
}
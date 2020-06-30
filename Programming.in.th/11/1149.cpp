#include<bits/stdc++.h>

using namespace std ;

struct e
{
  int x,y,d; 

  e(){} ;
  e(int xx,int yy,int dd)
  {
    x= xx;
    y= yy;
    d = dd; 
  }

  bool operator<(const e & other)const 
  {
    return d >other.d ;
  }
}; 
priority_queue<e> pq ;

const int MAXN = 1000 + 1; 

int arr[MAXN][MAXN] ;
int path[MAXN][MAXN]; 
bool visited[MAXN][MAXN]; 
int n ;
int cx[]= {1,-1,0,0}; 
int cy[] = {0,0,1,-1};
int a,b; 

bool check(int i,int j)
{
  return i>=0 && i<n && j>=0 && j<n ; 
}
int sol = 0 ; 

void bfs()
{

  while(!pq.empty())
  {
    // cout<<"hello" ;
    int x = pq.top().x; 
    int y = pq.top().y; 
    pq.pop(); 

    if(visited[x][y])
      continue ; 
    visited[x][y] = true ;

    for (int i=0;i<4;i++)
    {
      int newx = x + cx[i]; 
      int newy = y + cy[i]; 


      if(!check(newx,newy) || visited[newx][newy])
        continue ; 

      pq.push(e(newx,newy,arr[newx][newy])); 
      path[newx][newy] = max(arr[newx][newy],path[x][y]) ;
      if(arr[newx][newy]==0 && !(newx==a && newy==b))
      {
        sol = path[newx][newy]; 
        return ; 
      }
    }
  }

}

int main()
{

  scanf("%d",&n) ; 
  bool track = true ; 
  for (int i=0;i<n;i++)
  {
    for (int j=0;j<n;j++)
    {
      scanf("%d",&arr[i][j]); 
      if(arr[i][j]==0 && track)
      {
        pq.push(e(i,j,0));
        a= i ; 
        b= j ; 
        track = false; 

      }
    }
  }

  bfs(); 
  // for (int i=0;i<n;i++)
  // {
  //   for (int j=0;j<n;j++)
  //   {
  //     cout<<path[i][j]<<" "; 
  //   }
  //   cout<<endl; 
  // }

  cout<<sol; 

}
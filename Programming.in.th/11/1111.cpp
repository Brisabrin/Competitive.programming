#include<bits/stdc++.h>

using namespace std; 

const int MAXN = 100000 + 10 ;

struct edge 
{
  int v,w; 
}; 

int dis[MAXN] ; 
vector<edge> e[MAXN]; 
bool visited[MAXN] ; 

int dfs(int u,int d) 
{
    
    visited[u] = true; 
    dis[u] = d; 
    
    for (int i=0;i<e[u].size();i++)
    {
        int v = e[u][i].v; 
        int w = e[u][i].w; 
        if(visited[v]) continue ; 
        
        dfs(v, d + w) ; 
        
    }
}
int main()
{
  int n ; 
  scanf("%d",&n); 
  
  for (int i=0;i<n-1;i++)
  {
      
      int u,v,w ; 
      scanf("%d%d%d",&u,&v,&w); 
      
      e[u].push_back({v,w}); 
      e[v].push_back({u,w}); 
  }
  
  dfs(1,0) ; 
  int sol = 0 ;
  
  for (int i=0;i<=n;i++)
  {
      sol = max(sol, dis[i]) ;
    
  }
  cout<< sol ; 
  
}
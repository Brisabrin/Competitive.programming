#include<bits/stdc++.h>



using namespace std ;

struct edge{
  int v , w ; 

  bool operator<(const edge &other)const{
    return w < other.w ; 
  }
}; 
const int MAXN = 2500 + 10 ; 
int dis[MAXN] ;

vector<edge> e[MAXN] ; 

bool vis[MAXN] ; 
int n , m , s , t , d ; 

priority_queue<edge> pq ; 

int main(){

  scanf("%d%d",&n,&m ) ; 

  for(int i = 1 ; i <= n ; i ++){
    dis[i] = INT_MIN ; 
  }

  for(int i = 0 ; i < m ; i ++){
    int u , v , w  ; 

    scanf("%d%d%d",&u,&v,&w) ;

    e[u].push_back({v,w}) ; 
    e[v].push_back({u,w}) ;  

  }

  scanf("%d%d%d",&s,&t,&d) ; 

  pq.push({s, INT_MAX }) ; 
  dis[s] = INT_MAX ; 

  while(!pq.empty()){

    int u = pq.top().v ; 
    int w = pq.top().w ; 

    pq.pop() ; 

    if( vis[u] )
      continue ; 

    vis[u] = true ; 

    for(int i = 0 ; i <e[u].size() ; i ++){
      int v = e[u][i].v ; 

      int path = e[u][i].w ; 

      if( dis[v] < min(dis[u],path)){
        dis[v] = min(dis[u],path) ; 
        pq.push({v, min(dis[u],path)}) ; 
      }

    }
  }

  // for(int i = 1 ; i <= n ; i++){
  //   cout<<"# "<< i <<" " << dis[i] <<endl ; 
  // }

  cout<< ceil((float)d/(dis[t]-1)) ; 
  // printf("%d", ceil((float)d/(dis[t]-1))); 



}
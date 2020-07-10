#include<bits/stdc++.h>

using namespace std ;

int n , m  ; 
int x , y , z ; 

struct edge{
  
  int v , w ; 
  bool operator<(const edge & other)const{
    return w > other.w ; 
  }

} ; 
const int MAXN = 10000 + 5 ; 
vector<edge> e[MAXN] ; 


vector<int> dis(int s){
  priority_queue<edge> pq; 
  bool vis[MAXN]  = {false} ; 

  vector<int> stp(MAXN) ;
  fill(stp.begin() , stp.end() , -1u/4) ; 
  pq.push({s , 0 }) ; 

  stp[s] = 0 ; 

  while(!pq.empty()){
    // cout<<"hello"<<endl ; 

    int u = pq.top().v ; 
    int cost = pq.top().w; 

    pq.pop(); 

    if(vis[u])
      continue ; 

    vis[u] = true ; 
    for(int i = 0 ; i < e[u].size() ; i++){
      // cout<<"wat"<<endl ; 
      int v = e[u][i].v ; 
      int w = e[u][i].w ; 

      if( stp[u] + w < stp[v]){
        stp[v] = stp[u] + w ; 

        pq.push({v , cost + w }) ; 
      }
    }
  }

  return stp ; 
}


int main(){

  scanf("%d%d",&n , &m) ; 
  scanf("%d%d%d",&x,&y,&z) ; 

  for(int i =  0 ; i < m ;i++){

    int u , v , w ; 
    scanf("%d%d%d",&u , &v ,&w) ; 
    e[u].push_back({v,w}) ; 
    e[v].push_back({u,w}) ; 

  }

  vector<int> stps = dis(x) ; 
  // cout<<"end"<<endl ; 
  
  vector<int> stpt = dis(y) ; 

  int node = x ; 
  int comp = INT_MAX ; 
  for(int i = 0 ; i < n ; i++){


    if( (stpt[i] < comp ) && stps[i] - stps[x] <= z  ){
      comp = stpt[i] ; 
      node = i ; 
    }
  }

  cout<< node <<' '<< stps[node] <<" "<<stpt[node]<<endl ;

}
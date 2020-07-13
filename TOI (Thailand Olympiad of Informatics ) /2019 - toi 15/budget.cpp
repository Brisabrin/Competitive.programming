#include<bits/stdc++.h>
using namespace std ;
struct edge {
  int v ; 
  int w ; 
  edge(){} ;
  edge(int vv,int  ww){
    v =vv; 
    w =ww; 
  }
  bool operator<(const edge &other)const{
    return w > other.w; 
  }
} ; 
int sum  ; 
int co = 0 ; 
int b, m , p;  
vector<edge> e[3005]; 
bool vis[3005] ; 

int main(){
  scanf("%d%d",&b,&m); 

  for (int i=0;i<m;i++){
    int u,v,w , t; 
    scanf("%d%d%d%d",&u,&v,&w,&t);
    if(t)
      w = 0 ; 
    e[u].push_back(edge(v,w)) ; 
    e[v].push_back(edge(u,w));
  }
  vector<pair<int,int > > v ; 
  scanf("%d",&p); 
  for (int i=0;i<p;i++){
    int c ; 
    int d; 
    scanf("%d%d",&c,&d); 
    v.push_back(make_pair(c,d)); 
  }
  sort(v.begin(),v.end()); 
  for (int i=v.size()-2;i>=0;i--){
    v[i].second = min(v[i].second , v[i+1].second); 
  }

  for (int i=0;i<b;i++){
    for (int j=0;j<e[i].size();j++){
      if(e[i][j].w == 0 )
        continue ; 
      int val =  lower_bound(v.begin(),v.end(),make_pair(e[i][j].w,INT_MIN)) - v.begin() ; 
      e[i][j].w = v[val].second ; 
    } 
  }
  priority_queue<edge> pq;
  pq.push(edge(0,0)); 

  while(!pq.empty())
  {
    int u = pq.top().v , w = pq.top().w ;
    pq.pop();  
    if(vis[u])
      continue ; 

    vis[u] = true; 
    if(w)
      sum += w ; 
    for (int i=0;i<e[u].size();i++)
    {
      int v = e[u][i].v ; 

      if(vis[v])
        continue ; 
      
      pq.push(edge(v,e[u][i].w)); 
    }
  }

  cout<<sum<<endl; 
}
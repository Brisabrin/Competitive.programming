#include<stdio.h>
#include<vector> 
#include<iostream>
#include<climits>
#include <algorithm> 
using namespace std ;
int ma = 0 ; 
struct edge {
  int u ,v , w;  
  edge(){}; 
  edge(int uu, int vv ,int ww){
    u = uu ; 
    v= vv ; 
    w =ww; 
  }
  bool operator<(const edge & other)const{
    return w <other.w ; 
  }
} ; 
bool sp[100005] ;
int par[100005] ;
int co = 1 ; 
int n,m,k ; 
int findpar(int u ){
  if(par[u] == u)
    return u ; 
  return par[u] = findpar(par[u]); 
}
int main(){
  scanf("%d%d%d",&n,&m,&k) ; 
  for (int i=0;i<k;i++){
    int d; 
    scanf("%d",&d); 
    sp[d]= true; 
  }
  vector<edge> e(m) ; 

  for (int i=0;i<m;i++){
    // int u , v, w; 
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w); 
  }

  sort(e.begin(),e.end()); 
  for (int i=1;i<=n;i++)
  {
    par[i] = i ; 
  }
  for (int i=0;i<m ;i++){
    int u = e[i].u ; 
    int v= e[i].v;  
    int w = e[i].w ; 
    int paru = findpar(u); 
    int parv = findpar(v);
    
    if(paru == parv)
    {
      continue ; 
    }
    if(sp[paru])
      par[parv] = par[paru] ; 
    else 
      par[paru] = par[parv] ; 
      
    if(sp[paru] && sp[parv])
      co ++ ; 
    // spec[u] = true; 
    // spec[v] = true; 
    if(co == k){
      ma = w ; 
      for (int i=0;i<k;i++){
        printf("%d ",ma); 
      }
      break ; 
    }
  }
  

}
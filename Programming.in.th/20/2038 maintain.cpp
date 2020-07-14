#include<bits/stdc++.h>
using namespace std ;
const int MAXN = 200 + 10  ; 
struct edge{
  int u ,v ,w; 
  edge(){}
  edge(int uu, int vv,int ww)
  {
    u = uu ; 
    v= vv; 
    w = ww;
  }
  //  sorting the tpye edge array by weight - least -> most 
  bool operator< (const edge &other) const{
    if (w != other.w )return w<other.w ;
    if (v!= other.v) return v<other.v; 
    return u<other.u ;  
  }
};
set <edge> mst ; 
int par[MAXN]; 

int findpar(int u ){
  if (u == par[u] ) return u ;
  return par[u] = findpar(par[u]); 
}
int main()
{
  int n , m; 
  scanf("%d%d",&n,&m);
  for (int i=0;i<m;i++)
  {
  
    int u,v,w ; 
    scanf("%d%d%d",&u,&v,&w); 
    for (int j=1;j<=n;j++)
    {
      par[j] = j ; 
    }
    mst.insert(edge(u,v,w)); 
    bool del = false ; 
    int ne = 0 ; 
    int cost = 0 ;  
    set<edge> :: iterator rmv ; 
    for (set<edge> ::iterator itr=mst.begin() ; itr!=mst.end();itr++)
    {
      int x = itr -> u ; 
      int y = itr-> v; 
      int z = itr-> w; 

      int paru = findpar(x); 
      int parv = findpar(y); 
      if (paru == parv)
      {
        del = true ; 
        rmv = itr ;
        continue ;
      }
      ne ++ ; 
      cost += z  ; 
      par[paru] =parv; 

    }
    if (del)
      mst.erase(rmv); 

    if (ne < n-1)
      printf("-1\n");

    else 
      printf("%d\n",cost);  
  

  }

}

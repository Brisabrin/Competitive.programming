#include<bits/stdc++.h>

using namespace std ;

int sol, co;  
int n , k , t ; 
vector<int> e[100001], lev[10001]; 
int vis[100001]; 


void dfs(int u){
  co++ ; 

  vis[u] = 2 ; 
  for (int i=0;i<e[u].size();i++){
    int v = e[u][i]; 
    if(vis[v] == 0 ){
      dfs(v); 
      
    }
    else if (vis[v]==2){
      co = t+1 ; 
      return ; 
    }
  }
  vis[u] = 1 ; 
}

int main(){

  scanf("%d%d%d",&n,&k,&t); 

  for (int i=1;i<=n;i++){
    int d ,p ;
    scanf("%d",&d); 
    lev[d].push_back(i);
    scanf("%d",&p);  
    for (int j=0;j<p;j++){
      int v; 
      scanf("%d",&v); 
      e[i].push_back(v); 
    }
  }
  for (int i=1;i<=k;i++){
    for (int j=0;j<lev[i].size();j++){
      if(vis[lev[i][j]]== 0)
        dfs(lev[i][j]); 
    }
    if(co>t)
      break; 
    sol = i ; 
  }

  if(!sol)
    cout<<-1; 
  else 
    cout <<sol<<endl; 

}
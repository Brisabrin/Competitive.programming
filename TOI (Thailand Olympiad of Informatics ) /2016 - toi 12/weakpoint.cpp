#include<bits/stdc++.h>

using namespace std ;

int n ,  m ; 

const int MAXN = 500005 ; 

int vis[MAXN] ; 
vector<int> e[MAXN] ; 
stack<int> s ; 

int dis[MAXN] ; 

void process() {

  int x = s.top(); 
  vis[x] = 3 ; 
  s.pop() ; 

  while(s.size()){
    int y = s.top() ;
    s.pop();
    vis[y] = 3 ; 

    if(y == x)
      break  ; 
  }
}
void dfs(int u ,int prev ){

  vis[u] = 2 ; 
  s.push(u) ; 
  for (int i=0;i<e[u].size();i++){
    int v = e[u][i] ; 
    if(vis[v] == 0 ){
        dfs(v,u) ;
       
    }

    else if(vis[v] ==2 && v !=prev && v == m ) {
      s.push(v) ; 
      process() ; 
    }

  }

  if(vis[u] !=3) {
    vis[u] = 1 ; 
    s.pop(); 
  }
}
void count_branch(int u , int co , int par ){
  
  // cout<<u<<endl; 
  vis[u] = 2 ; 
  for (int i=0;i<e[u].size();i++){
    int v = e[u][i] ; 

    if(vis[v] == 3 || vis[v] ==2 ){
      continue ; 
    }
    if(vis[v] == 1 && v !=m ){
      dis[par] += 1;  
      count_branch(v , co+ 1 , par) ;
    }
  }
}

int main(){

  cin>> n >> m ; 

  for (int i=0;i<n;i++){
    int u ,v ; 
    scanf("%d%d",&u,&v) ; 

    e[u].push_back(v) ; 
    e[v].push_back(u) ; 
  }

  dfs(m,m) ; 
  // cout<<"wdjfieji"<<endl; 
  int sol = -1 ; 
  int node = INT_MAX; 
  for (int i=1;i<=n;i ++){

    if(vis[i] == 3 && i != m ){
    count_branch(i , 0 , i) ; 
    if(dis[i] > sol){
      node = i ; 
      sol = dis[i];  
    }
    else if(sol == dis[i]){
      node = min(node , i) ; 
    }
    }
  } 

  for(int i=0;i<e[m].size();i++){
    int v = e[m][i] ; 

    if(vis[v] !=2){

      count_branch(e[m][i] , 0 , e[m][i]) ; 
    if(dis[e[m][i]] > sol){
      node = e[m][i] ; 
      sol = dis[e[m][i]];  
    }
    else if(sol == dis[e[m][i]]){
      node = min(node , e[m][i]) ; 
    }

    }
  }
  // for (int i=1;i<=n;i++){
  //   cout<< i<<' '<<dis[i]<<endl; 
  // }

  cout<<node<<endl <<sol<<endl; 

}
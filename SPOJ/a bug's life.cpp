#include<bits/stdc++.h>
using namespace std ;

int t , n , m  ; 
vector<int> e[2005] ;
bool vis[2005] ;
int bi[2005] ;  
bool track = false ; 
void dfs (int u ){

    vis[u] = true ; 

    for(int v : e[u]){

      if( bi[u] == bi[v]){
        // cout<<"yea " << u <<" "<<v <<endl ; 
        track = true ;
        return ; 
      }
      
      if(!vis[v]){
        bi[v] = (bi[u] * -1  ) ;
        dfs(v) ; 

      }

    }
}
int main(){

  cin >> t ;
  int co = 1 ;  

  while(t-- ){
    printf("Scenario #%d:\n" , co ) ;
    track = false ; 

    cin >> n >> m ; 

    for(int i=1 ; i <= n ; i++){
      e[i].clear()  , vis[i] = false , bi[i] = 0  ; 
    }

    for(int i=0;i<m;i++){

      int u , v ; 
      cin >> u >> v ; 
      e[u].push_back(v) ; 
      e[v].push_back(u) ;

    }
    for(int i = 1 ;i<=n && !track ;i++){

      if(!vis[i]){
        bi[i] = 1 ; 

        dfs(i) ; 
      }

    } 
    if( !track )
      cout<<"No suspicious bugs found!"<<endl ; 
    
    else 
      cout << "Suspicious bugs found!"<<endl ; 

    co ++ ; 
  }

}
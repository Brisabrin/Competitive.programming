#include<bits/stdc++.h>

using namespace std ;

int n , k ; 

const int MAXN = 15000 + 5 ; 
vector<pair<int,int> > v(MAXN) ; 

vector<int> e ; 

int vis[MAXN] ; 
queue<int> q ; 

int co = 0 ; 

int main(){

  cin >> n >> k ; 

  for(int i = 1 ; i <= n ; i ++ ){
    scanf( "%d%d",&v[i].first , &v[i].second  ) ; 
    vis[i] = INT_MAX ; 
  }
 
  q.push(1) ; 
  while(!q.empty()){

    int  mi = INT_MAX ; 
    int node = 0 ; 
    int u = q.front() ;

    // cout<< u <<endl ; 

    q.pop() ; 

   
    vis[u] = 0 ;
    
    for(int i = 1 ; i <= n ; i ++ ){

      int dis = abs(v[i].first - v[u].first) + abs(v[i].second - v[u].second) ;
      
      vis[i] = min( dis , vis[i]) ; 
      if( vis[i] == 0)
        continue ; 

      if( vis[i] < mi ){
        mi = vis[i] ; 
        node = i ; 
      }

    }

    if( node == 0 ) break ; 
    
    e.push_back(mi) , q.push(node) ; 
  }

  int sol = 0 ; 

  sort(e.begin() , e.end()) ; 
  for(int i = 0 ; i < e.size() ; i ++ ){

    if( i < n - k )
      sol += e[i] ; 

  }
  cout<<sol <<endl ; 

}

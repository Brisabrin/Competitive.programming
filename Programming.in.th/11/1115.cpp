#include<bits/stdc++.h>


using namespace std;

int  n , k ; 

int x , y ; 
const int MAXN = 1000 + 5 ; 
vector<pair<int,int> > co(MAXN) ; 

int vis[MAXN] ; 
vector<int> e ; 

int main(){


  cin >> n >> k ; 

  for(int i = 1 ; i <= n ; i ++ ){
    scanf("%d%d",&co[i].first , &co[i].second) ; 
    vis[i] = INT_MAX ; 
  }

  queue<int> q ; 

  q.push(1) ; 
  while(!q.empty()){

    int u = q.front() ; 
    q.pop() ; 

    vis[u] = 0 ; 

    int mi = INT_MAX  ; 
    int node ; 

    for(int i = 1 ; i <= n ; i ++ ){

      int dis = pow(co[u].first - co[i].first,2) + pow(co[u].second - co[i].second,2)   ; 

      vis[i] = min( vis[i] , dis ) ; 

      if( vis[i] == 0 )
        continue ; 

      if( vis[i] < mi ){
        mi = vis[i] ; 
        node = i ; 
      }
    }

    if( mi == INT_MAX) break ; 
    e.push_back(mi) , q.push(node) ;

  }

  int sol = 0 ; 

  sort(e.begin() , e.end()) ; 
  cout<< e[e.size() - k ] ; 


}

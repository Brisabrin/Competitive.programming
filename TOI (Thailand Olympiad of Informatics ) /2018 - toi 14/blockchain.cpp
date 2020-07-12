#include <bits/stdc++.h>

using namespace std;

vector<int> v , b; 

int t, q ; 
#define pii  pair<int,int>

map<int, map<vector<pii> ,int > >mp  ; 


int main(){

  scanf("%d%d",&t,&q); 

  while( t -- ){
    int n ; 
    scanf("%d",&n) ;
    vector<pii> block ; 
    for (int i=0;i<n-1;i++){
      int u , v ; 
      scanf("%d%d",&u,&v); 
      block.push_back(make_pair(min(u,v),max(u,v))); 
    }
    sort(block.begin(),block.end()) ;
    mp[n][block] ++ ; 
    // cout<<"!"<<mp[n][block] <<endl;
  }

  while(q--){
    int n; 
    scanf("%d",&n);
    vector<pii> block ; 
    for (int i=0;i<n-1;i++){
      int u, v ; 
      scanf("%d%d",&u,&v); 
      block.push_back(make_pair(min(u,v),max(u,v)));
    }
    sort(block.begin(),block.end()); 
    cout<< mp[n][block] <<endl;
  }

  // map<vector<pii> , int> ::iterator itr ; 

  // cout<<"size"<<mp[10].size()<<endl;


}
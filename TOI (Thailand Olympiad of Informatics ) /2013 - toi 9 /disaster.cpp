#include<bits/stdc++.h>

using namespace std ;



int n ; 

vector<int>e[30] ; 

bool vis[30][30] ; 

bool dfs(int u , int c){
  // cout<<"U"<<u <<endl; 
  if(c == n ){
    // cout<<"eowfhio"<<endl; 
    char cha = u + 'A' ; 
    cout<< cha<<' ' ; 
    return true;  
  }
  for (int i=0;i<e[u].size();i++){
    int v = e[u][i] ; 

    if(!vis[u][v]){
      vis[u][v] = true; 
      vis[v][u] = true; 
      if(dfs(v, c+1)) {
        char cha = u + 'A' ; 
        cout<< cha<<' ' ; 
        return true;
      }
      vis[u][v] = false ; 
      vis[v][u] = false ; 
    }
  }
  return false ; 
}

int main(){

  scanf("%d",&n) ; 

  for (int i=0;i<n;i++){

    char u , v ; 
    scanf(" %c%c",&u,&v) ; 

    e[(int)u-'A'].push_back((int)v-'A') ; 
    e[(int)v-'A'].push_back((int)u-'A') ; 
  } 

  for(int f=0;f<26;f++){
    if(e[f].size()%2==0) continue ; 
    for (int i=0;i<26;i++){
      for (int j=0;j<26;j++){
        vis[i][j] = false ;
      }
    }
    if(dfs(f , 0 ))return 0 ; 
  }

  for (int i=0;i<26;i++){
    if(dfs(i,0))
      return 0 ; 

  }


}

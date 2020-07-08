#include<bits/stdc++.h>

using namespace std ;

int n , m  ; 

const int MAXN = 2000 + 5 ; 

char arr[MAXN][MAXN] ; 

bool vis[MAXN][MAXN] ; 

int cx[] = { 0 , 0 , 1 , 1 , 1 , -1 , -1 , -1 } ; 
int cy[] = {-1, 1 , -1 , 0 , 1 , 0 , 1 , -1  } ; 

bool check(int x , int y ){
  return x >= 1 && x <= n && y >= 1 && y <= m ; 
}

void bfs(int px , int py ){


  queue<int> row , col ; 

  row.push(px) ; 
  col.push( py ) ; 


  while(!row.empty()){

    int x = row.front() ; 
    int y = col.front() ; 
    row.pop() ; 
    col.pop() ; 

    if( vis[x][y] )
      continue  ; 

    vis[x][y] = true;  

    for(int i = 0 ; i<8 ; i++){

      int newx = cx[i] + x ; 
      int newy =  cy[i] + y ; 


      if(check(newx,newy) && !vis[newx][newy] && arr[newx][newy] == '1')
        row.push(newx) , col.push(newy) ; 
    }

  }


}
int co = 0 ; 
int main(){

  scanf("%d%d",&n,&m ) ; 

  for(int i = 1 ; i<= n ; i ++){
    for(int j = 1 ; j<=m ; j ++){
      scanf(" %c",&arr[i][j]) ; 
    }
  }



  for(int i = 1 ; i<=n ; i++){

    for(int j = 1 ; j<=m ;j ++){

      if( !vis[i][j] && (arr[i][j] == 
      '1') )
        co++  , bfs(i , j ) ; 
    }

  }

  cout << co <<endl ; 


}
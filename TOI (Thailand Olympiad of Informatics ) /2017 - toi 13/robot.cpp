#include<bits/stdc++.h>

using namespace std ;

int n , m ; 

const int MAXN = 2000 + 5 ; 
char arr[MAXN][MAXN] ; 

bool vis[MAXN][MAXN]  ; 

int dis[MAXN][MAXN] ; 

queue<int> row , col ; 

int cx[] = {0 , 0 , 1 , -1 }; 
int cy[] = { 1, - 1 , 0 , 0 } ; 

bool check(int i , int j ){

  return i >= 0 && i<n && j >=0 && j < m ; 

}
int main(){

  scanf("%d%d",&n,&m) ; 


  for(int i = 0 ; i<n ; i ++){
    for(int j = 0 ; j<m ; j ++){

      dis[i][j] = -1u/4 ; 
      scanf(" %c",&arr[i][j]) ; 

      if( arr[i][j] == 'X' )
        row.push(i) , col.push(j) , dis[i][j] = 0  ; 

    }
  }
  long long sol = 0 ; 
  int co = 0 ; 

  while( !row.empty()){

    int x = row.front() ; 
    int y = col.front() ;

    row.pop() , col.pop() ; 

    if( vis[x][y] )
      continue ; 

    vis[x][y] = true ; 

    if( arr[x][y] == 'A')
      sol += (dis[x][y] * 2 ) , co ++  ; 

    for(int i = 0 ; i < 4 ; i++){
      int newx = x + cx[i] ; 
      int newy = y + cy[i] ; 

      if(!check(newx,newy)  || arr[newx][newy] == 'W')
        continue ; 

      if( dis[newx][newy] > dis[x][y] + 1)
        dis[newx][newy] = dis[x][y] + 1 , row.push(newx),col.push(newy) ; 
    }
  }

  cout << co <<" "<< sol <<endl ; 


}
#include<bits/stdc++.h>



using namespace std ;

//  car 

int m , n  , t ; 

const int MAXN = 100 + 5 ; 

int arr[MAXN][MAXN] ; 
bool vis[MAXN][MAXN] ; 
 
int cx[] = {1,1,1}; 
int cy[] = {-1,0,1 } ;   

//  co-ord , dir , vector dir ; 
queue<pair<int,vector<int>>> row ; 
queue<pair<int, int>> col ; 

bool check(int x , int y ) {
  return( x > 0  && x <= t && y >=0 && y < m ) ; 
}

int main(){


  cin >> m  >> n >> t ; 

  for(int i = 1 ; i <= t ; i ++ ){
    for(int j = 0 ; j < m ;  j ++ ){
      cin>> arr[i][j] ;
    }
  }
  vector<int> v ; 
  //  queue : row , dir ; 
  row.push( {0 , v}  )  ; 
  col.push({n - 1 , 0 } ) ; 
  

  while(!row.empty()){

    int x = row.front().first ; 
    int y = col.front().first ; 
    vector<int> dir = row.front().second ; 
    int path = col.front().second ; 

    row.pop() ; 
    col.pop() ; 

    if( vis[x][y] )
      continue ; 
    vis[x][y] = true ; 

    if( x != 0 )
      dir.push_back(path) ; 
    
    if( x == t ){
      for(int i = 0 ; i < dir.size() ; i ++ ){

        cout<< dir[i] <<endl ; 
      }
    }

    for(int i = 0 ;  i < 3 ; i ++  ){

      int newx = x + cx[i] ; 
      int newy = y + cy[i] ; 

      if( !check(newx,newy) || vis[newx][newy] || arr[newx][newy] == 1 )
      continue ;

      if( i == 0  )
        path = 1 ; 
      else if( i == 1 )
        path = 3 ; 
      else 
        path = 2 ; 

      row.push({newx , dir }) ; 
      col.push({newy , path }) ; 

    }
  }


  
}

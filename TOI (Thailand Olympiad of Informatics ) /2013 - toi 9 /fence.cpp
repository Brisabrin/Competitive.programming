#include<bits/stdc++.h>

using namespace std ;

int n , m , t , a , b  ; 

const int MAXN = 505 ; 
int horiz[MAXN][MAXN] , verti[MAXN][MAXN] ;
int arr[MAXN][MAXN]  ;  

int  co(){

  int ma = 0 ; 
  for(int i = 1 ; i<=n ; i ++){
    for(int j = 1 ; j<=m ; j ++){

      horiz[i][j] = horiz[i][j-1] + arr[i][j] ; 
      verti[i][j] = verti[i-1][j] + arr[i][j] ; 

    }
  }

  for(int k =1 ; k<= min(n , m ) ;  k++){

    bool track = false ; 

    for(int i = k ; i <=n  ; i ++){
      for(int j = k ; j <= m ; j++){

      //  horizontal check

      int h1 = horiz[i - k + 1][j] - horiz[i-k+1][j-k] ;  
      int h2 = horiz[i][j] - horiz[i][j-k] ;

      //  vertical check 

      int v1 = verti[i][j-k+1] - verti[i-k][j-k+1] ; 

      int v2 = verti[i][j] - verti[i-k][j] ; 


      if( (h1 == k && h2 == k ) && (v1 == k && v2 == k ))
        track = true ; 
      }
    }

    if( track )
      ma = k ; 
  }

  return ma ; 
}

int main(){

  cin >> n >> m >> t ; 
  
  for(int i =1 ; i<=n ; i++){
    for(int j = 1 ; j<=m ; j ++){
      arr[i][j] = 1 ; 
    }
  }


  for(int i = 0 ; i < t ; i++ ){

    cin >> a >> b ; 
    arr[a+1][b+1] = 0 ; 

  }

  

  int ans1 = co() ; 

  cin >> n >> m >> t ; 
  for(int i =1 ; i<=n ; i++){
    for(int j = 1 ; j<=m ; j ++){
      arr[i][j] = 1 ; 

      horiz[i][j] = 0 ; 
      verti[i][j] = 0 ; 
    }
  }

   for(int i = 0 ; i < t ; i++ ){

    cin >> a >> b ; 
    arr[a+1][b+1] = 0 ; 

  }

  cout<< ans1 << endl << co() <<endl ; 
}


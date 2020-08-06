#include<bits/stdc++.h>

using namespace std ;

int n , m ; 

char arr[10000 + 5 ][2000 + 5 ] ; 

bool vis[10000 + 5 ][2000 + 5 ] ;

bool check(int i , int j ){
  return( i > 0 && i <= n && j > 0 && j <= m ) ; 
}
int a = 0 , b = 0 , c = 0 ; 

int main(){


  cin >> m >> n ; 

  for(int i = 1 ; i <= n ;  i++ ){
    scanf("%s", arr[i] + 1 ) ; 
  }


  for(int i = 1 ; i<= n ; i ++ ){
    for(int j = 1 ; j <= m ; j ++ ){
      
      if(arr[i][j] !='0')
        vis[i][j] = vis[i][j] || vis[i][ j-1 ] || vis[i-1][j] || vis[i-1][j-1] ;

      if ( vis[i][j] || arr[i][j] == '0' )
        continue ; 

      vis[i][j] = true; 

      //  var count 
      int diL =  1 ,  diR = 1 , down = 1 ; 

      //  count diagl 
      int x = i + 1  , y = j - 1  ; 
      //  left diag
      while( check(x , y) && arr[x][y] != '0'){

        if(arr[x][y] == '1')
          vis[x][y] = true , diL ++ ; 
        
        x ++ , y -- ; 
      } 

      //  count diagR 
      x = i + 1  , y = j + 1 ; 

      while(check(x , y ) && arr[x][y] !='0'){

        if( arr[x][y] == '1')
          vis[x][y] = true , diR ++ ; 

        else 
          break ; 

        x ++ , y ++ ; 
      }

      //  count down 
      x = i + 1 , y = j ; 

      while( check(x,y)&& arr[x][y] != '0'){

        if( arr[x][y] == '1')
          vis[x][y] = true , down ++ ; 

        x ++ ; 
      }

      // cout<<"#" <<i <<" "<<j <<": "<<diL <<" "<<down<<" "<<diR <<endl ; 

      // check square 

      if((down == diR) && (diL == 1) ){
        a ++  ; 
      }
      //  check diamond
      else if((diL == diR) && (diL != down))
        b++ ; 

      else 
        c ++ ; 
  



    }
 
  }

  cout<<a <<" "<<b << ' '<<c <<endl ;

}
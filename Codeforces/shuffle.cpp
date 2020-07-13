#include<bits/stdc++.h>

using namespace std ;


int t  , n , x , m , l , r  ; 

int main(){

  scanf("%d",&t) ; 


  while(t--){


    cin >> n >> x >> m ; 

    int prev_s = x  ; 
    int end_s = x ; 

    int finS = x ; 
    int finE = x ; 

    for (int i=0;i<m;i++){

      cin >> l >> r  ; 

      //  find intersect / overlap 

      if( (finS < l && l <= finE ) || (finS >= l && finS <= r )){


        // cout <<"Yay" <<endl ; 
        // cout <<"#" <<l <<" "<<r <<endl ;
        prev_s = l ; 
        end_s = r ; 
        // cout <<"yay" <<endl ; 

        finS = min(finS , l ) ; 
        finE = max(finE , r) ; 

        

      }



    }

    // cout <<"!"<<finS <<" "<<finE <<endl ; 
    cout << finE - finS + 1 <<endl ; 

  }



}
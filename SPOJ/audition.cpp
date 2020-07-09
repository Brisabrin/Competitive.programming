#include<bits/stdc++.h>


using namespace std ;

int t , n , k ; 

const int MAXN = 1000005 ;  



int main(){

  cin >> t ; 

  while( t-- ){
    long long dp[MAXN] = {0} ; 

    cin >> n >> k ; 

    long long sol = 0 ; 
    int co = 0 ; 
    int zero = 0 ; 
    string s ; 
    cin >> s ; 
    for(int i = 0 ; i < n ; i ++){
      dp[co] ++ ; 

      if ( s[i] == '1'){
        co ++ ; 
        zero = 0 ; 
      }

      if( co >= k ){
        sol += dp[co - k ] ; 
      }

    }
    cout<< sol<<endl ; 



  }

}
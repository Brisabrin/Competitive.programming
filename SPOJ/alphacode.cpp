#include<bits/stdc++.h>


using namespace std ;

string s ; 

bool check(string a , string b ){
  if( a == b )
    return true ; 
  return false ; 
}
const int MAXN = 5000 + 5 ; 
int dp[MAXN] ; 

int main(){


  cin >> s ; 

 
  while( !check(s , "0")){

    int n = s.length() ; 
    dp[0] = 1 ; 
    for(int i = 1 ; i <= n ; i ++ ){

      if(i == 1 ){
        dp[i] = 1; 
        continue ; 
      }

      else if(s[i-1] == '0' ){
        dp[i] = dp[i-2] ; 
      }

      else{
        dp[i] = dp[i-1] ; 

        if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] - '6' <= 0 ) ){
          dp[i] +=dp[i-2] ; 
        }
      }

  
    }

    cout<< dp[n] <<endl ; 


    cin >> s ; 


  }


}

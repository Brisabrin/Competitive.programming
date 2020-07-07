#include<bits/stdc++.h>

using namespace std ;


int n , k ; 

const int MAXN = 500005 ; 

int dp[MAXN] ; 
map<int,int > mp ; 
int st  ;

int main(){

  cin >> n >> k ; 

  for(int i = 1 ; i <= n ; i++){

    int a ; 
    scanf("%d",&a) ; 

    if( i == 1 )
      dp[i] = a ; 

    else if(i <= k ){
      dp[i] = a + mp.begin()->first ; 
    }

    else {

      if(mp[dp[i-k-1]]<=1)
        mp.erase(dp[i-k-1]); 
      else 
      {
        mp[dp[i-k-1]] -- ; 
      }

      dp[i] = a + mp.begin()->first ; 

    }
    mp[dp[i]]++ ; 
  }

  cout<< dp[n] <<endl ; 




}
#include<bits/stdc++.h>

using namespace std; 

int k   ; 

char a[1001] ; 

int dp[1001][1001] ; 


int main(){

  cin >> k ; 

  for(int i=0;i<k;i++){
    scanf (" %c", &a[i] ) ; 
  }
 

  for (int l = 1 ; l < k; l++){

    for ( int j = 0 ; j < k - l   ; j ++){

      int en = j + l ; 

      int val = INT_MIN ; 
      
      if(a[j] == a[en] && j < en-1){
        val = 1 + dp[j+1][en-1] ; 
        // cout<<"yay"<<endl ; 
      }

      for(int i = j ; i <en ; i++){

        val = max( val , dp[j][i] + dp[i+1][en] ) ; 

      }

      // cout<< j <<" "<<en <<" "<< val<<endl ; 

      dp[j][en] = val ; 

    }

  }

  cout << dp[0][k-1] ; 


  
}
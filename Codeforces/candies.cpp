#include<bits/stdc++.h>


using namespace std ;

int t , k ; 

int  dp[65]; 

int pow( int base ){

  int  sum = 1;  
  for (int i=0;i<base;i++){
    sum *=2 ; 
  }
  return sum ; 
}
int main(){
  int sum = 0; 
  for (int i=0;i<65;i++){
    dp[i] = sum+ pow(2,i); 
    sum += pow(2,i); 
  }
  // for (int i=0;i<6;i++){
  //   cout<<dp[i]<<endl; 
  // }

  scanf("%d",&t); 
  for (int i=0;i<t;i++){
    int n ; 
    scanf("%d",&n) ; 
    int ans ; 
    for (int k=1;k<65;k++){
      
      if((n/dp[k])>0){
        if(n%dp[k]!=0)
          continue ; 
        ans = n/dp[k]; 
        break ; 
      }
    }
    cout<<ans<<endl; 
  }

}
#include<bits/stdc++.h>


using namespace std ;

int t  ; 



int main(){
  scanf("%d",&t); 
  for(int i=0;i<t;i++){
    
    int n ; 
    scanf("%d",&n); 
    if((n/2)%2!=0)
      cout<<"NO" <<endl; 
    else{
      cout<<"YES"<<endl;
      // int dp[1000000001];
      int a = n/2 ; 
      // int sum = a * (a + 1 ) ; 
      int en = n ;
      int pre = 2*(a-1) -1   ; 
      for (int j=2;j<=n;j+=2){
        cout<<j<<" "; 
      }
      for (int j=1;j<=pre;j=j+2)
      {
        cout<<j<<" "; 
      }
      cout<< en + (a-1) <<endl;
    }
  }


}
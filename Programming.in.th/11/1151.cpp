#include <bits/stdc++.h>

using namespace std ;

int n , k , x ; 
int b[1000001]; 
int main(){

  scanf("%d",&n); 
  for (int i=1;i<=n;i++){
    scanf("%d",&x); 
    int y = lower_bound(b,b+k,x) - b;  

    b[y] = x;  
    k = max(k,y+1); 
  }
  cout<<k<<endl; 


}
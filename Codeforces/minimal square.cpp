#include<bits/stdc++.h>

using namespace std ;

int t , a , b ; 



vector<int > vect ; 
int main(){

  scanf("%d",&t) ;

  while(t--){

    scanf("%d%d",&a,&b) ; 

    int mi = min(a,b) * 2  ; 

    mi = max(mi , max(a,b) ) ;

    cout<<mi*mi<<endl ; 
  }
}
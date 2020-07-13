#include<bits/stdc++.h>



using namespace std ;

int n , k ; 

int co = 0 ; 
int main(){


  scanf("%d%d",&n,&k) ; 

  for(int i=0;i<n;i++){
    int d ; 
    scanf("%d",&d) ; 
    if(d + k <= 5)
      co ++ ; 

  }

  cout<< floor(co /3) ; 


}
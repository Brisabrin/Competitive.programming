#include<bits/stdc++.h>


using namespace std ;

int k , a , b ; 

void sports(int ca , int cb ,char c , vector<char> v ){
  if(!(ca==a && cb == b ) )
    v.push_back(c) ; 
  if( ca == k || cb == k ){
    for(int i = 0 ; i<v.size(); i++){
      printf("%c ",v[i]) ;  

    }
    printf("\n" ) ; 
    return ; 
  }
  sports(ca + 1 , cb , 'W' , v) ; 
  sports(ca , cb + 1 , 'L' , v ) ; 
}

int main(){

  scanf("%d%d%d",&k , &a , &b) ; 
  vector<char> v ; 
  sports( a  , b, ' ' , v) ; 

}
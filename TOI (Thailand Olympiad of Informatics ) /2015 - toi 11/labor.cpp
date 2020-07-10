#include<bits/stdc++.h>

using namespace std ;


int n  ; 

long long m ; 

const int MAXN = 1000005 ; 
long long  arr[MAXN] ; 


bool check( long long  mid ){

  long long co = 0 ; 

  // cout<< "mid : " << mid <<endl ; 

  for(int i = 0 ; i < n ; i ++){
    co += floor( (float) mid / arr[i] ) ; 

  }
  // cout<<co <<endl ; 

  if( co >= m )
    return true  ; 

  return false  ; 

}

int main(){

  cin >> n >> m ; 

  for( int i = 0 ; i < n ; i ++) {

    scanf("%lld",&arr[i]) ; 

  }
  sort(arr , arr + n ) ; 

  long long  st = 0 ;
  long long en = 1e18 ; 

  while( st < en - 1  ){

    long long  mid = ( st + en ) >> 1 ;
    // cout << st <<" "<<mid <<" " <<en<<endl ;  

    if( check(mid ))
      en = mid  ; 

    else 
      st = mid ; 

  }

  cout<< st +1 << endl ; 
}
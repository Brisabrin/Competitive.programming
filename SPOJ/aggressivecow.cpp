#include<bits/stdc++.h>


using namespace std ;

int t , n , k ; 

int arr[100005];

bool check( int mid ){

  int co = 1 ; 
 
  int num = arr[0] ; 
  for(int i = 1 ; i < n ; i++){

    if( arr[i] - num >= mid )
      co ++ , num = arr[i] ; 

  }

  if( co < k )
    return false   ; 

  return true   ; 

}

int main(){


  scanf("%d",&t) ; 

  while(t-- ) {
    scanf("%d%d",&n , &k) ; 

    for(int i = 0; i < n ; i++ ){
      scanf("%d",&arr[i]) ; 
    }

    sort(arr , arr + n ) ; 

    int st = 0 , en = -1u/4 ; 

    while( st < en - 1   ){
      int mid = (st + en )>> 1; 
      // cout << st <<" " << mid <<" " <<en <<endl ; 
      if(check(mid ))
        st = mid ; 

      else 
        en = mid ; 
    }

    cout << st <<endl ; 

  }

}
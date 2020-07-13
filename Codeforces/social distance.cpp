#include <iostream>
#include<string.h>
#include<cmath>
#include<stdio.h>


using namespace std ;

int t , n ,  k ;

int main(){

  cin >> t ;

  while(t--){

    cin >> n >> k ;
    int arr[200005] ;
    memset( arr , 0 , sizeof(arr) ) ;
    int one = 0 ;
    string s;
    cin >> s ;
    int ind = 0 ;

    for(int i=0;i<n;i++) {
      if(s[i] == '1')
        one ++ , arr[ind] = i , ind ++ ;
    }

    int co = 0 ;
    if(one == 0){
      for(int i = 0 ; i < n ; i += k + 1 )
        co ++ ;
    }

    else {

      for(int i = arr[0] - k - 1 ;  i>=0 ; i-=(k+1))
        co ++ ;
      
      int dis = 0 ;
      for(int i = arr[0] ; i <= arr[ind - 1]  ; i ++ ){
        if(s[i] == '1'){

          int val = floor(dis / (k+1)) ;
          // cout << dis <<endl ;

          if( dis % (k+1) >=k ){
            co += val ;
          }
          else if(val - 1 > 0 ) co += val - 1 ;

          // cout<< "#"<<co <<endl ;
          dis = 0 ;
          continue ;
        }
        dis ++ ;
      }

      for(int i = arr[ind-1] + k + 1 ; i< n ;i +=(k+1))
        co ++ ;
    }

    cout << co<<endl ;
  }


}

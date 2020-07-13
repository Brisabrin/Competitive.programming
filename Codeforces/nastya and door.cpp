#include<bits/stdc++.h>

using namespace std ;

int c, n , k ; 

int main(){
  scanf("%d",&c); 

  while(c--){

    scanf("%d%d",&n,&k); 
    int arr[200005],co[200005]; 
    bool peak[200005] ;
    for (int i=0;i<n;i++){
      scanf("%d",&arr[i]); 

      if(i >1 && arr[i-1] > arr[i-2] && arr[i-1]>arr[i]){
        peak[i-1] = true; 
        co[i-1] = co[i-2] +1 ; 
      }
      co[i] = co[i-1] ; 
    }

    // for (int i=0;i<n;i++){
    //   cout<<i<< " "<<co[i]<<endl;
    // }

    int t = INT_MIN , le = INT_MAX ; 
  
    // deque<int> dq ; 
    for (int i =0 ;i<=n - k;i++){
      int l = i ; 
      int r = i + k-2 ;
      int leng = l+1 ;  
      int cur = co[r] - co[l] + 1 ; 
      // cout<<i<<"; " ;
      if(cur > t ){
        t = cur ; 
        le = leng ; 
      }
      else if (cur==t) le = min(le,l+1) ;
      // cout<<cur <<" "<<le<<endl; 
    }
    cout << t <<" "<<le<<endl;
  }



}
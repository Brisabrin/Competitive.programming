#include<bits/stdc++.h>

using namespace std; 

int t , n ; 



int main(){

  scanf("%d",&t) ;

  while(t--){

    scanf("%d",&n) ; 
    vector<int> v; 
    for(int i=0;i<n;i++){
      int s ; 
      scanf("%d",&s) ; 
      v.push_back(s) ; 
    }
    sort(v.begin(),v.end()) ; 
    int diff = -1u/4 ; 
    for(int i=0;i<v.size();i++){
      if(i>0){
        diff =min(diff , v[i] - v[i-1] ) ; 
      }

    }
    printf("%d\n",diff) ; 

  }

}
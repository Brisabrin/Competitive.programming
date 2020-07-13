#include<bits/stdc++.h>


using namespace std ;

int t ; 
const int MAXN = 105 ; 
int vis[MAXN] ; 

int n ; 

int main(){

  scanf("%d",&t) ; 

  while(t--){
    int one = 0 ; 
    int even = 0 , odd = 0 ; 

    for(int i=1;i<105;i++){
      vis[i] = 0 ; 
    }

    scanf("%d",&n) ; 

    vector<int> vect ; 
    for(int i=0;i<n;i++){
      int d ; 
      scanf("%d",&d) ; 
      if(d%2==0)
        even ++ ; 
      else 
        odd++ ; 
      vect.push_back(d) ; 
    }
    sort(vect.begin(),vect.end()) ; 

    for(int i=0;i<vect.size();i++){

      int d = vect[i] ; 
      if(vis[d-1] > 0 )
        one ++, vis[d-1] --  ; 

      vis[d] ++ ; 

    }

    // cout<<one<<" "<<even<<" "<<odd<<endl ; 

    if(even %2==0 && odd %2 == 0 )
      cout<<"YES"<<endl ; 

    else if(even%2!=0 && odd %2!=0 && one >0 ) {
      cout<<"YES"<<endl ; 
    }
    else 
      cout<<"NO"<<endl ; 

  }



}
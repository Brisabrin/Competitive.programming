#include<bits/stdc++.h>


using namespace std ;

int n , p ; 

map<vector<int> , int > mp ; 
vector<int> f ; 

int main(){

  scanf("%d%d",&n,&p) ; 


  for(int i = 0 ; i < n ; i++){
    vector<int> v ; 
    for(int j = 0 ; j < p ; j ++){
      int d ; 

      scanf("%d",&d) ; 

      v.push_back(d) ; 

    }
    mp[v] = i + 1 ; 

  }

  for(int i = 0 ; i < p ; i ++){

    int d; 
    scanf("%d",&d) ; 
    f.push_back(d) ; 

  }

  bool track = false ; 

  if( mp.count(f) > 0 )
    cout<< mp[f] <<endl ; 

  else {

    for(auto x : mp){

      vector<int> v ; 
      vector<int> val = x.first ; 

      for(int i = 0 ; i < p ; i ++){
        v.push_back(f[i] - val[i] ) ; 

      }

      if( mp.count(v) && mp[v] != mp[val]){
        cout<< min(mp[v] , mp[val]) <<" "<<max(mp[v] , mp[val]) <<endl ; 
        track = true ; 
        break ; 
      }

    }
    
    if(!track)
    cout<<"NO"<<endl ; 


  }

  
}
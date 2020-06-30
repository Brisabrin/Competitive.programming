#include <bits/stdc++.h>

using namespace std ;

int n ; 
vector<long long > v ; 

int main(){

  scanf("%d",&n) ; 

  for(int i=0;i<n;i++){
    long long d ; 
    scanf("%lld",&d) ; 
    v.push_back(d) ; 
  }

  nth_element(v.begin(), v.begin() + v.size()/2, v.end());
  // cout<<"hdfjek"<<endl ; 
  long long a = 0 , b = 0  ;
  for(int i=0;i<v.size()/2;i++){
    a +=v[i] ; 
    // cout<<v[i] <<endl ; 
  }

  for(int i=v.size()/2 ; i<v.size();i++){
    b +=v[i] ;
    // cout<<"B"<<v[i]<<endl ; 

  }

  cout<< b - a ; 
  
}
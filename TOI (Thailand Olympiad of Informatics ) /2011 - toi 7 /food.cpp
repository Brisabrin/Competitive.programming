#include<bits/stdc++.h>

using namespace std; 

int n , m ; 
const int MAXN = 10 ; 
bool no[MAXN] ; 

void rec(int ord , vector<int> v , int num , vector<bool> vis){
  // cout<<"jeigj"<<endl ;
  
  if(ord !=0)
    v.push_back(num) ; 
  if(ord == n ){
    // cout<<"fhvurh"<<endl ; 
    for(int i=0;i<v.size();i++){
      cout << v[i] <<" " ; 

    }
    cout<<endl ; 
    return ; 
    
  }

  for(int i=1;i<=n;i++){
  
    if((ord == 0 && no[i]) || vis[i])
      continue ; 

    // cout<<"hello"<<endl ; 
    vis[i] = true ; 
    rec(ord + 1 , v , i , vis ) ; 
    vis[i] = false ; 
  }

}

int main(){

  cin >> n >> m ; 

  for(int i=0;i<m;i++){
    int d ; 
    cin >> d ; 
    no[d] = true ; 
  }

  vector<int> v ;
  vector<bool>vis(MAXN) ;  
  rec(0 , v , 0 , vis ) ; 

}
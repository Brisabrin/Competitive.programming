#include<bits/stdc++.h>


using namespace std ;

vector<pair<int,int> > v ; 

int n , q ; 

const int MAXN = 100000 + 5 ; 
int sum[MAXN]; 

bool sortrev( const pair<int,int> & a , const pair<int,int> &b){
  return (a.first < b.first );
}

vector<int> a , b ; 

int main(){

  scanf("%d%d",&n,&q) ; 

  for(int i = 1 ; i <= n ; i++){
    int a ; 

    scanf("%d",&a) ; 

    v.push_back({a + sum[i-1] , i }) ;  
  
    sum[i] = a + sum[i-1] ; 
  }

  sort(v.begin() , v.end() , sortrev) ; 

  
  for(int i = 0 ; i < v.size();i++){
    if( i == 0 )
      continue  ; 

    v[i].second = max(v[i].second , v[i-1].second) ; 
    a.push_back(v[i].first) ; 
    b.push_back(v[i].second) ; 
  }

  for(int i = 0 ; i < q ; i++){
    int m ; 
    scanf("%d",&m) ; 

    int ind = upper_bound( a.begin() , a.end() , m  ) - a.begin()  ;
    // cout<<ind<<endl ; 

    if( ind == 0 )
      printf("0\n") ; 

    else 
      printf("%d\n", b[ind-1]) ; 
    

  }


}
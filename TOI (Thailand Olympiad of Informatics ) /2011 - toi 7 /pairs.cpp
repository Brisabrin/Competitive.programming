#include<bits/stdc++.h>

using namespace std ;

int n ; 

vector<pair<int,int> > v ;

const int MAXN = 100000 + 5 ; 
int arr[MAXN] ;

long long sol = 0 ; 

bool sortrev(const pair<int,int> &a , const pair<int,int> &b ){

  return a.second < b.second ; 
}

void mergesort(int s , int mid , int t){

  int n1  = mid - s + 1 ; 
  int n2 = t - mid ; 

  int l[n1] , r[n2] ; 
  int i = 0 , j = 0 ; 

  while( i < n1 )
    l[i] = arr[i + s ] , i ++  ; 
  while(j < n2 )
    r[j] = arr[mid+ 1 + j ] , j ++ ; 

  i = 0 , j = 0; 
  int k = s ; 
  long long sum = 0 ; 
  vector<int> ve ; 
  while( i < n1 && j < n2){
    if(l[i] <= r[j])
      arr[k] = l[i]  , sol += ((l[i]* ve.size()) + sum), i ++  ; 
    else 
      arr[k] = r[j]  , ve.push_back(r[j]) , sum += r[j]  , j ++  ; 

    k ++ ; 
  }

  while( i < n1 )
    arr[k] = l[i], sol+= (sum + (l[i]*ve.size())) , i ++ , k ++ 
     ;

  while( j < n2 )
    arr[k] = r[j] , j ++ , k++ ;


}

void merge(int s , int t ){

  if( s < t ){

    int mid = (s+t)/2 ; 

    merge(s,mid) ; 
    merge(mid+1 , t) ; 
    mergesort(s,mid,t) ; 
  }

}

int main(){

  cin >> n ; 

  for(int i=0;i<n;i++){

    int a ,b ; 
    cin >> a >> b ; 
    v.push_back(make_pair(a,b)) ; 

  }
  sort(v.begin() , v.end() , sortrev) ; 

  for(int i=0;i<v.size();i++){
    arr[i] = v[i].first ; 
  }
  merge(0, n -1 ) ; 

  printf("%llu",sol) ; 
}
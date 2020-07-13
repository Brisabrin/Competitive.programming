#include<bits/stdc++.h>

using namespace std ;

vector<long long> v,stu,r  ; 

int n ; 
vector<long long > sum; 
long long sol = 0 ; 
long long  mi = LLONG_MAX, ma = LLONG_MIN; 

long long max(long long a , long long b) {
  if(a>b)
    return a ; 
  return b; 
}
long long min(long long a,long long b ){
  if(a<b)
    return a ; 
  return b ; 
}


int main(){
  scanf("%d",&n) ;
  long long d ; 
  for (int i=0;i<n;i++) scanf("%lld",&d),v.push_back(d) ; 
  for (int i=0;i<n;i++) scanf("%lld",&d), stu.push_back(d); 
  // r = stu ; 
  sort(v.begin(),v.end()); 
  sort(stu.begin(),stu.end()) ;


  for (int i=0;i<stu.size();i++){
    sum.push_back(stu[i] + v[n-1-i]) ;
    mi = min(mi, sum[i]); 
    ma = max(ma,sum[i]); 
  }

  // for (int i=0;i<r.size();i++){
  //   int ind = lower_bound(stu.begin(),stu.end(),r[i]) - stu.begin() ; 
  //   sum.push_back(v[n - 1 - ind] + r[i]) ;
  //   cout<<sum[i]<<endl; 
  //   mi = min(sum[i],mi); 
  //   ma = max(sum[i],ma); 
  // }
  cout<<ma-mi<<endl; 

}
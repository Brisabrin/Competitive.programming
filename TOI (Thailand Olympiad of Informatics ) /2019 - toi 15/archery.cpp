#include<bits/stdc++.h>

using namespace std ;

int n , c ; 
const int MAXN = 500002 ; 
// vector<int> a(MAXN),b(MAXN); 
vector<pair<long long ,long long > > pos;
vector<long long > h ;  
long long  a[MAXN],b[MAXN]; 
long long min_height = LLONG_MAX ; 

int main(){
  scanf("%d",&n) ; 
  h.push_back(0); 
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]), min_height = min(min_height,a[i] ) ; 
  for (int i=1;i<=n;i++) scanf("%lld",&b[i]),h.push_back(b[i]);  

  pos.push_back(make_pair(0,0)); 
  for (int i=1;i<=n;i++) pos.push_back(make_pair(b[i],a[i])); 

  sort(pos.begin(),pos.end()); 
  sort(h.begin(),h.end()); 

  for(int i=1;i<=n;i++) pos[i].first += pos[i-1].first,pos[i].second += pos[i-1].second ; 

  long long sol = LLONG_MAX; 
  long long ind ; 
  for(int i=1;i<=n;i++) {
    if(min_height < h[i])
      break ; 
    long long cur = 0;  
    cur += (pos[n].first - pos[i].first ) - ((n-i) * h[i]) ; 

    cur+= (pos[i-1].second - pos[0].second) - (h[i] *(i-1)) + pos[i-1].first - pos[0].first ; 

    if(cur<sol){
      sol = cur ; 
      ind = h[i] ; 
    }
    else if(cur ==sol){
      ind = min(ind ,h[i]);
    }

  }
  cout<<ind<<" "<<sol<<endl;
  
}
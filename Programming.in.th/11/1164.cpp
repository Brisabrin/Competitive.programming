#include <bits/stdc++.h>
using namespace std; 
int n ; 
const int MAXN = 1000000 ; 
// #define pii pair<int,int> 
// set<pii> st; 

vector<pair<int,int> > v;

map<int,vector<int> > m ; 
// multimap<int,int> m ; 

set<pair<int,int> > sol;

bool sortv(const pair<int,int> &a,const pair<int,int> &b)
{
  return (a.second< b.second); 
}
void mergesort(int p,int q,int s )
{
  int n1 = q-p + 1; 
  int n2 = s-q; 
  vector<pair<int,int> > l(n1),r(n2); 


  for (int i=0;i<n1;i++)
  {
    l[i].first = v[p+i].first ;
    l[i].second  = v[p+i].second; 
  }
  for (int j=0;j<n2;j++)
  {
    r[j].first = v[q+1+j].first; 
    r[j].second = v[q+1+j].second; 
  }
  int k =p, i=0,j=0 ;
  while(i<n1 && j<n2)
  {
    if(l[i].first<r[j].first)
    {
      v[k].first = l[i].first; 
      v[k].second = l[i].second ; 
      // st.insert(make_pair(v[k].first,v[k].second));
      // res.push_back(make_pair(v[k].first,v[k].second));
   
      // m[v[k].first].push_back(v[k].second );  
      sol.insert(v[k]);
      // printf("!!");
      i++ ; 
    }
    else 
    {
      // cout<<"hello"<<endl; 
      v[k].first = r[j].first; 
      v[k].second = r[j].second;
      // arr[k] = r[j]; 
      // m.insert(make_pair(v[k].first,v[k].second)); 
      j++ ; 
    }
    k++ ; 
  }
  while(i<n1)
  {
     v[k].first = l[i].first; 
      v[k].second = l[i].second ; 
    // cout<< v[k].first <<" "<<v[k].second<<endl; 
    k++; 
    i++; 
  }
  while(j<n2)
  {
    v[k].first = r[j].first; 
      v[k].second = r[j].second;
    k++; 
    j++; 
  }
}
void merge( int p,int s)
{
  if(p<s)
  {
    int mid = p+(s-p)/2; 
    merge(p,mid);
    merge(mid+1,s); 
    mergesort(p,mid,s);  
  }
}
int main()
{
  scanf("%d",&n); 

  for (int i=0;i<n;i++)
  {
    int x,y ; 
    scanf("%d %d",&x,&y); 
    v.push_back(make_pair(x,y)); 
    // res.push_back(make_pair(x,y)); 
    // m.insert(make_pair(x,y));  
  }

  sort(v.begin(),v.end(),sortv); 
  // for (int i=0;i<n;i++)
  // {
  //   arr[i] = v[i].first ; 
  //   // cout<<arr[i]<<endl; 
  // }
  // cout<<"hello" ; 
  merge(0, n-1) ;
  // map<int,int> ma;

  // map<int,vector<int> > :: iterator it ; 

//  for (int j=0;j<m[2].size();j++)
//  {
//    cout<< <<" "<<m[2][j]<<endl;
//  }
  for(int i = 0 ; i < n ; i ++){
    if(!sol.count(v[i]))
      printf("%d %d\n",v[i].first,v[i].second);
  }





}
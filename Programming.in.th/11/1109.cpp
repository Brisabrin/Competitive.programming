#include <bits/stdc++.h>
using namespace std ;
int n  ;
const int MAXN = 100000 ;
vector<pair<int ,int> > v;
long long  sum = 0 ;
bool sortv(const pair<int,int> &a,const pair<int,int> &b)
{
  return (a.second< b.second);
}
int arr[MAXN];
// set<int,int> s ;
void mergesort(int arr[], int p,int q,int s )
{
  // vector<int>e[MAXN];
  vector<int> e;
  long long  ad = 0 ;
  int n = q-p + 1;
  int n2 = s-q;
  int l[n],r[n2];

  for (int i=0;i<n;i++)
  {
    l[i] = arr[p+ i];
  }
  for(int j=0;j<n2;j++)
  {
    r[j] = arr[q+j+1];
  }
 
  int k =p,i=0,j=0;
  while(i<n && j<n2)
  {
    if(l[i] <= r[j])
    {
      arr[k] = l[i] ;

      sum+= (l[i] * e.size()) + ad ;


      i++ ;
    }
    else
    {

      arr[k] = r[j];
      e.push_back(r[j]);
      ad += r[j] ;
      j++ ;
    }
    k++ ;
  }
  while(i<n)
  {
    arr[k] = l[i];
    sum +=(l[i]*e.size()) + ad ;

    i++;
    k++;
  }
  while(j<n2)
  {
    arr[k] = r[j];
    j++;
    k++;
  }
}
void merge(int arr[],int p,int s )
{
  if (p<s)
  {
    int mid  = p + (s-p)/2 ;
    merge(arr,p,mid);
    merge(arr,mid+1,s);
    mergesort(arr,p,mid,s);
  }
}
int main()
{
  scanf("%d",&n);
  for (int i=0;i<n;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    v.push_back(make_pair(x,y));
  }
  sort(v.begin(),v.end(),sortv);


  for (int i=0;i<n;i++)
  {
    arr[i] = v[i].first;
  }
  merge(arr,0,n-1);
  printf("%llu",sum);
  // cout<< sum<<endl;

}
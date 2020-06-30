#include <bits/stdc++.h>

using namespace std; 
int arr2[56]; 
map<char, vector <int>> m; 

void dice(char c,int arr[] )
{
  map<char,vector<int> > ::iterator itr ; 

  vector<int> v; 

  for (itr=m.begin();itr!=m.end();itr++)
  {
    if(itr->first==c) v = itr-> second ; 

  }

  for (int i=0;i<6;i++)
  {
    arr2[i] = arr[i] ; 
  }

  
  for (int i =0;i<v.size();i++)
  {
    arr[i] = arr2[v[i]]; 
  }
}


int main()
{
  int n ; 
  scanf("%d",&n); 
  string s;
  vector<int> res; 
  m.insert(pair<char,vector<int>>('F',{3,0,2,5,4,1}));
  m.insert(pair<char,vector<int> >('B',{1,5,2,0,4,3}));
  m.insert(pair<char,vector<int> >('L',{4,1,0,3,5,2}));
  m.insert(pair<char,vector<int> >('R',{2,1,5,3,0,4}));
  m.insert(pair<char,vector<int> >('C',{0,4,1,2,3,5}));
  m.insert(pair<char,vector<int> >('D',{0,2,3,4,1,5}));
   
  for (int i=0;i<n;i++)
  {
    int arr[6] = {1,2,3,5,4,6}; 
    cin >> s; 
    for (int i=0;i<s.length();i++)
    {
      dice(s[i],arr); 
    } 

    res.push_back(arr[1]); 

  }

  for (int i=0;i<n;i++)
  {
    cout<<res[i] <<" ";
  }


}
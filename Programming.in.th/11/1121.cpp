#include <bits/stdc++.h>
using namespace std;

char  check_opp(char a)
{

  if (a=='(') return ')';
  else if (a=='[') return ']';
  else return '}';
}

int main()
{
  int n ;
  stack<char> s;
  string r;
  int track;
  char x; 
  vector <string> result ;
  scanf("%d",&n);
  for (int i =0;i<n;i++)
  {
    cin >> r;
    track = 0 ;
    for (int j=0;j<r.length() && track ==0;j++)
    {
      if (r[j]=='(' || r[j]=='{'|| r[j]=='[')
      {
        s.push(r[j]);
      }
      else if (s.empty())
      {
        track = 1;
      }
      else 
      {

        if(check_opp(s.top())!=r[j])
          track = 1; 

        else 
          s.pop(); 
      }
    }
    if(s.empty() && track ==0) result.push_back("yes");
    else result.push_back("no");
    while (!s.empty())
        s.pop();
    
  }
  for (int i =0;i<result.size();i++)
  {
    cout <<result[i]<<endl;
  }

}
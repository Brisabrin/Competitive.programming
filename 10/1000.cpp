#include <bits/stdc++.h> 

using namespace std; 

bool check_word(string a,string b, int k )
{
  int count = 0 ; 

  for (int j=0;j<k;j++)
  {
    if (a[j]!=b[j]) count +=1 ;

  }
  if (count>2 ) return false ; 
  else return true ;

}

int main()
{

  int n,k; 
  scanf("%d%d",&n,&k); 
  char c[n]; 
  stack<string> s;
  bool track = true  ; 

  
  for (int i =0;i<k ;i++)
  {
    scanf("%s",c); 

    if (i==0 || (check_word(s.top(),c,n ) && track ))
      s.push(c);
    else track = false ;  
     

  }
  cout << s.top();


}
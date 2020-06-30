#include<bits/stdc++.h>

using namespace std ;

stack<char> s ; 
int main(){
  int n;

  cin >> n;

  for(int i = 0 ; i < n ; i ++){
    char x ;
    cin >> x;

    if(s.empty())
      s.push(x);
    else if(s.top() == x)
      s.pop();
    else
      s.push(x);

  }

  cout << s.size() << endl ;

  if(s.empty()){
    cout << "empty" << endl;
  }
  else{
    while(!s.empty()){
      cout << s.top() ;
      s.pop();
    }
  }
}
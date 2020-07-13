#include<bits/stdc++.h>

using namespace std ;

int t ; 
int n ; 

int main(){

  cin >> t ; 

  while(t--){
    cin >> n ; 
    stack<char> s ; 
    for(int i=0;i<n;i++){
    

    char c ; 
    cin >> c ; 

    if(!s.empty()){

      if(c==')' && s.top() == '(')
        s.pop() ; 
      else 
        s.push(c) ; 
    }
    else 
      s.push(c) ; 
    }

    cout<< s.size()/2 <<endl ; 
  }



}
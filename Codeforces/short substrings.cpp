#include<iostream> 
#include<string> 
using namespace std ;

int t ; 

int main(){

  scanf("%d",&t) ;

  while(t--){

    string s ; 

    cin>>s ; 
    string a ;

    for(int i=0;i<s.length() - 1 ;i++){
      if(i%2==0)
        a += s[i] ; 
    }

    a+=s[s.length()-1] ;

    cout<<a <<endl ; 
  }

}
#include<iostream>
#include<string> 
#include<map> 
#include<vector> 

using namespace std ;

int t ; 

string s ;
int m ; 

int b[100005] ; 

int main(){

  cin >> t ; 

  while(t--){

    cin >> s >> m ;  
    int n = s.length() ; 
    map<int,int> mp ; 

    for(int i = 0 ;i < n ;i++)  mp[s[i] - 'a'] ++  ; 
   
    for(int i = 0 ; i < m ; i++) 
      cin >> b[i] ; 

    char c = 'z' ; 

    vector<char> ans( m + 1 , '.' )  ; 

    
    while(true) {
      // cout<<"hello"<<endl ; 
      vector<int> zeros ; 

      for(int i=0; i < m ;i++){

        if(b[i] == 0 ){
          zeros.push_back(i) ; 
          b[i] = - 1 ; 
        }

      }
      if(zeros.empty() )
        break ; 
      while( c >= 'a' && mp[ c - 'a' ] < zeros.size() ) c -- ; 

      for( int i = 0 ; i < zeros.size() ; i ++ ){
        ans[zeros[i]] = c ;
      }

      for(int i= 0 ; i < m ; i++){
        if(ans[i] == '.' || ans[i] < c ){
          
          for( int j = 0 ; j < zeros.size() ; j++ ){
            b[i] -=abs( zeros[j] - i ) ; 

          }

        }

      }
      c-- ;  
    }

    for(int i= 0 ; i< m ; i++){
      cout << ans[i]  ; 
    }
    cout<<endl ; 
  


  }
  // cout<<"ya"<<endl ; 


}
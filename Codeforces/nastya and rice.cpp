#include<bits/stdc++.h>


using namespace std ;

int t , n , a, b,c,d ;


int main(){

  scanf("%d",&t); 

  for (int k=0;k<t;k++){
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);

    int st  = a-b ; 
    int en = a + b ; 
    int st2 = c-d ; 
    int en2 = c + d ; 
    
    if(en * n <st2 || st * n > en2){
      cout<<"NO"<<endl;
    }
    else if((st * n >=st2 && st*n <=en2) || (en * n <=en2 && en * n>=st2)){
      cout<<"YES"<<endl;
    }
    else{
      if( st* n < st2 ){
        int num = (st2 - (st* n))/n + 1 + st ;
        if(num <= en){
          cout<<"YES"<<endl; 
          // cout<<"!";
        }
        else{
          cout<<"NO"<<endl;
        }
      }
      // else if(en * n ){

      // }
    }
    

  }

}
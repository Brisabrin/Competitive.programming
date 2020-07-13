#include<bits/stdc++.h>

using namespace std ;

int n , w ; 

int d ; 

deque<pair<int,int> > dq ; 

const int MAXN   = 6000001 ; 

int sum[MAXN] ;
int ma = 0 , le = INT_MAX ; 


int main(){

  scanf("%d%d",&n,&w) ; 

  for(int i=1;i<=n;i++) scanf("%d",&d) ,  sum[i] = sum[i-1] + d   ; 


  dq.push_back(make_pair(0,0)) ; 

  for(int i=1;i<=n;i++){

    while(!dq.empty()){

      if(i- dq.front().second <=w )
        break ; 

      else 
        dq.pop_front() ; 
    }

    if( sum[i] - dq.front().first > ma ){
      ma = sum[i] - dq.front().first ; 
      le = i - dq.front().second ; 
    }

    else if(sum[i] - dq.front().first == ma){
      le = min(le , i - dq.front().second ); 
    }

    while(!dq.empty()){
      if(dq.back().first >=sum[i] ){
        dq.pop_back();  
      
      }
      else 
        break ;
    }

    dq.push_back(make_pair(sum[i], i )) ; 
  }

  if(le > w || ma == 0 )
    cout<<0<<endl<<0 <<endl ; 

  else 
    cout<<ma<<endl<<le<<endl ; 





}
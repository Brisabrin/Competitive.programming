#include <iostream>
#include <vector>
#include <stdio.h> 
#include <algorithm>
using namespace std; 

void add_vector(int sum,vector<int> &nugget){
  int track =true ;
  for (int i=0;i<nugget.size() &&track;i++){
    if (nugget[i]==sum){
      track = false; 
    }
    
    

  }
  if(track &&sum<=100&&sum!=0){nugget.push_back(sum);}

 }


int main() {
  int n,sum; 
  
  scanf("%i",&n);

  vector <int> nugget;
  
  for (int six=0;six<16;six++){
    for (int nine=0;nine<11;nine++){
      for(int tw=0;tw<5;tw++){
        sum = (6*six)+(9*nine)+(20*tw); 
        add_vector(sum,nugget); 

      }

    }
  }

  sort(nugget.begin(),nugget.end());
  bool state,track;
  state = true;
  track = true;


  for (int i =0;i<nugget.size()&&track;i++){
    
    if (nugget[i]<=n){
      state =false; 
      // printf("%i",nugget[i]);
      cout<<nugget[i]<<endl;
   
    }
    else {track=false;}

  }
  if (state){cout<<"no";}

}
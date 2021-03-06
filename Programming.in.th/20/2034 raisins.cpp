#include<bits/stdc++.h>
using namespace std ;
int n , m;
const int MAXN = 55 ; 
int arr[MAXN][MAXN];  
int dp[MAXN][MAXN][MAXN][MAXN]; 
int psum[MAXN][MAXN]; 
int horiz[MAXN][MAXN][MAXN][MAXN]; 
int verti[MAXN][MAXN][MAXN][MAXN]; 


int calc(int x1,int y1,int x2,int y2)
{

  if(x1== 0 && y1 == 0 )
    return psum[x2-1][y2-1]; 
  
  else if(x1== 0 )
    return psum[x2-1][y2-1] - psum[x2-1][y1-1]; 
  
  else if(y1== 0 )
    return psum[x2-1][y2-1] - psum[x1-1][y2-1] ; 
  
  else
    return psum[x2-1][y2-1] + psum[x1-1][y1-1] - psum[x1-1][y2-1] - psum[x2-1][y1-1] ; 
    ; 
}
int main(){
  scanf("%d%d",&n,&m);
  // int sum = 0 ; 
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      scanf("%d",&arr[i][j]); 
      if(i == 0 ){
        if(j==0)
          psum[i][j] = arr[i][j] ; 
        else 
          psum[i][j] = psum[i][j-1] + arr[i][j] ; 
      }
      else if(j==0 ){
        psum[i][j] = psum[i-1][j] + arr[i][j] ; 
      }
      else{
        psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + arr[i][j] ;  
      }
    }
  }

  if(n==1 && m==1 )
    cout<< 0<<endl; 
  else {
    for(int i=0;i<n;i++){
      for (int j=0;j<m;j++)
      {
        dp[i][j][i+1][j+1] = arr[i][j]; 
      }
    }
  
    // x1 ,y1 , x2,y2 ; 
    for (int xd = 1; xd<=n;xd++){
      for (int yd=1;yd<=m;yd++){
        if(xd == 1 && yd ==1 )
          continue ;
        for (int x1=0;x1<=n-xd;x1++){
          for (int y1=0;y1<=m-yd;y1++){
            int x2 = x1 + xd ; 
            int y2 = y1 + yd ; 
            // vertical cut ; 
            int verti= INT_MAX; 
            for (int k = 1;k<yd;k++){
              int sum = 0; 
              if(x2-x1 == 1 && k==1)
              {
                sum += dp[x1][y1][x2][y1+k] ; 
              }
              else 
                sum +=  dp[x1][y1][x2][y1+k] + calc(x1,y1,x2,y1+k) ;
              
              if(x2-x1 == 1 && y2-y1-k == 1 )
              {
                sum += dp[x1][y1+k][x2][y2] ; 
              }
              else 
                sum += dp[x1][y1+k][x2][y2] + calc(x1,y1+k,x2,y2) ;
              verti = min(verti,sum) ; 
        
            }
          //  horizontal cut ;
          int horiz = INT_MAX ; 
          for (int k=1;k<xd;k++){
            int sum = 0 ; 

            if(k==1 && y2-y1 ==1)
            {
              sum += dp[x1][y1][x1+k][y2];
            }
            else 
              sum +=  dp[x1][y1][x1+k][y2] + calc(x1,y1,x1+k,y2) ; 
            if(x2-x1-k==1 && y2-y1==1)
            {
              sum += dp[x1+k][y1][x2][y2]; 
            }
            else 
              sum += dp[x1+k][y1][x2][y2] + calc(x1+k,y1,x2,y2) ;
            horiz = min(horiz,sum) ; 
          } 

          dp[x1][y1][x2][y2] =  min(horiz,verti); 
          }
        }
        
      }
    }
    cout<< dp[0][0][n][m]<<endl; 

  }
}
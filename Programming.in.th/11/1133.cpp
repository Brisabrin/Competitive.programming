#include <bits/stdc++.h>

using namespace std ;

int n , m , q ; 

const int MAXN = 500 + 1 ;
int dis[MAXN][MAXN];  
vector<int>e[1000001]; 

int main()
{
  scanf("%d%d",&n,&m); 
  for (int i=1;i<=m;i++)
  {
    int d ; 

    scanf("%d",&d); 
    for (int j=0;j<d;j++)
    {
      int u ; 
      scanf("%d",&u); 
      e[u].push_back(i); 
    }
  }

  for (int i=1;i<=m;i++)
  {
    for (int j=1;j<=m;j++)
    {
      if(i!=j)
      {
        dis[i][j] = -1u/4 ; 
      }
    }
  }
  for (int i=1;i<=n;i++)
  {
    for (int j=0;j<e[i].size();j++)
    {
      for (int k=j+1;k<e[i].size();k++)
      {  
        if(e[i][j] != e[i][k]){
          dis[e[i][j]][e[i][k]] = 1; 
           dis[e[i][k]][e[i][j]] = 1;
        }
      }
    }
  }
for (int k=1;k<=m;k++){
  for (int i=1;i<=m;i++){
    for (int j=1;j<=m;j++){
      if(dis[k][j] + dis[i][k] < dis[i][j])
        dis[i][j] = dis[k][j] + dis[i][k]  ; 
    }
  }
}
//cout <<endl; 
//  for (int i=1;i<=m;i++)
//  {
//    for (int j=1;j<=m;j++)
//    {
//      if(dis[i][j]==-1u/4)
//        cout <<-1; 
//      else 
//        cout<< dis[i][j];
//
//      cout <<" "; 
//    }
//    cout<<endl ;
//  }

scanf("%d",&q);
for (int k=0;k<q;k++){
  int u ,v; 
  scanf("%d%d",&u,&v) ; 
  int ans = -1u/4 ; 

  for (int i = 0;i<e[u].size();i++){
    for (int j=0;j<e[v].size();j++)
    {
      ans = min(ans, dis[e[u][i]][e[v][j]]); 
    }
  }
  if(ans==-1u/4)
    printf("impossible\n"); 

  else 
    printf("%d\n",ans) ;
}

}
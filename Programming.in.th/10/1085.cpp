#include <bits/stdc++.h>

using namespace std ;

int n , m , k;

int arr[500000+ 1];
vector<int>e[500000 + 1] ;
int dp[500000 +1 ] ;
int vis[500000 +1 ] ;
int main()
{

    scanf("%d%d%d",&n,&m,&k) ;

    for (int i=0;i<m;i++)
    {
        int u , v ;

        scanf("%d%d",&u,&v);
        e[v].push_back(u);

    }
    dp[1]=  1 ;
    int sol =  1 ;

    for (int i=1;i<=k;i++)
    {

        int d ;
        scanf("%d",&d) ;

        vis[d] = true ;
    }

    for (int i=2;i<=n;i++)
    {
        if(dp[i-1]==1 && !vis[i-1]){

            dp[i] = 1 ;
        }
        else
        {
            for (int j=0 ;j<e[i].size();j++)
            {
                if(dp[e[i][j]] ==1 )
                    dp[i] = 1;
            }

        }

        if(dp[i]== 1 )
            sol = i ;
    }

    if(dp[n]!=0 )
        cout<< 1 ;

    else
        cout<< 0 << " "<<sol ;

}
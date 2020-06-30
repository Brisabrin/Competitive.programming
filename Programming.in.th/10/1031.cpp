#include<bits/stdc++.h>

using namespace std ;

int n,k,m ;

const int MAXN = 10000+ 1;

vector<int> e[MAXN] ;
int dp[MAXN];

int main()
{

    scanf("%d%d%d",&k,&n,&m);

    for (int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b) ;
        int x,y ;
        x= max(a,b);
        y= min(a,b);

        e[x].push_back(y);
    }
    dp[1]= 0 ;
    int sol = 0 ;
    for (int i=2;i<=n;i++)
    {
        dp[i] = -1u/4 ;

        for (int j=0;j<e[i].size();j++)
        {
            if(dp[e[i][j]]+1<=k)
            {
                dp[i] = min(dp[i],dp[e[i][j]]+1);
                sol = max(sol,i);
            }
        }

    }
    cout<<sol ;

}
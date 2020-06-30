#include<bits/stdc++.h>

using namespace std ;



int n,m,k;
const int MAXN = 20000 + 10 ;

int arr[MAXN] , p[MAXN] , dp [MAXN][2] ;

int main()
{

    scanf("%d%d%d",&n,&m,&k);

    for (int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]) ;
    }

    for (int i=0;i<k;i++)
    {
        scanf("%d",&p[i]);
    }
    arr[m++] = n ;
    for (int i=m-1;i>=0;i--)
    {
        arr[i] = arr[i] - arr[i-1] ;
//        cout<<arr[i]<<endl ;

    }
    dp[0][0] = arr[0] * p[0];

    for (int i=1;i<=m;i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i]*p[0] ;

    }
    int prev = 0 ,now = 1  ;
//    cout<<m<<endl ;
    for (int i=1;i<k;i++)
    {
        dp[i][now] = dp[i-1][prev] + arr[i]* p[i];

        for (int j=i+1;j<m;j++)
        {
            dp[j][now ] = max(dp[j-1][prev],dp[j-1][now]) + arr[j]* p[i] ;

        }
        prev^=1 ;
        now^=1;
    }
    cout<< dp[m-1][prev] ;
//    cout<< endl ;
//    for (int i=0;i<m;i++)
//    {
//        for (int j=0;j<k;j++)
//        {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl ;
//
//
//    }



}
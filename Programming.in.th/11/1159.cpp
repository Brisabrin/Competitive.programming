#include<cstdio>

using namespace std ;

struct Time{
    int dd ;
    int hh ;
};

const int MAXN = 1000 + 10;
Time dp[MAXN][MAXN];
int a[MAXN], b[MAXN];
int m, n;
Time add(Time t, int hh) {
    if(t.hh + hh > m){
        t.dd ++;
        t.hh = hh;
    }
    else t.hh += hh ;
    return t ;
}
Time minTime(Time t1,Time t2){
    if(t1.dd<t2.dd)
        return t1 ;
    else if(t1.dd>t2.dd)
        return t2 ;

    if(t1.hh < t2.hh)
        return t1;
     return t2 ;
}
int main(){

    scanf("%d%d",&m,&n);

    for(int i = 1 ; i <= n ; i ++) scanf("%d",&a[i]);
    for(int i = 1 ; i <= n ; i ++) scanf("%d",&b[i]);

    for(int i = 1 ; i <= n ; i ++){
        dp[i][0] = add(dp[i-1][0],a[i]);
        dp[0][i] = add(dp[0][i-1],b[i]);
    }

    for(int i = 1 ; i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            dp[i][j] = minTime(add(dp[i-1][j],a[i]), add(dp[i][j-1],b[j]));
            // printf("!%d %d %d %d\n",i,j,dp[i][j].dd,dp[i][j].hh);
        }

    }
//    for(int i = 0 ; i <= n ; i ++){
//        for(int j = 0 ; j <= n ; j ++)
//            printf("%d.%d ",dp[i][j].dd,dp[i][j].hh);
//
//        printf("\n");
//    }

    printf("%d\n%d",dp[n][n].dd+1,dp[n][n].hh);
}
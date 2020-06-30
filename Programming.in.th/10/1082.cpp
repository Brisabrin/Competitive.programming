#include<bits/stdc++.h>

using namespace std ;
int n , m ;
const int MAXN = 1000000 + 1;
struct edge{
    int u , v ,w ;
    bool operator<(const edge & other)const
    {
        return w <other.w ;
    }

} ;
edge e[MAXN] ;
int par[MAXN] ;
int findpar(int u)
{
    if(par[u] ==u )
        return u ;
    return par[u] = findpar(par[u]) ;
}
int main(){

    scanf("%d%d",&n,&m) ;
    for (int i=0;i<m;i++){
//        int u ,v, w ;
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w) ;
    }

    for (int i=1;i<=n;i++)
    {
        par[i] = i ;
    }
    sort(e,e+m) ;
    for (int i=0;i<m;i++)
    {
        int u = e[i].u;
        int v = e[i].v ;

        int paru = findpar(u) ;
        int parv = findpar(v) ;

        if(paru==parv)
            continue ;
        par[paru] = parv;
        printf("%d %d\n",u,v) ;

    }


}

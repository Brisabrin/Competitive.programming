#include<bits/stdc++.h>

using namespace std ;

int m ,n ;

int t ;
const int MAXN = 501 ;
int a[MAXN][MAXN];

int co(){

// HORIZONTAL ARR ;
int horiz[MAXN][MAXN],vert[MAXN][MAXN] ;

    for (int i=0;i<m;i++){
        horiz[i][0] = a[i][0] ;
    }

    for (int i=0;i<m;i++){
        for (int j=1;j<n;j++){
            if(a[i][j] == 1)
            {
                horiz[i][j] = horiz[i][j-1] + 1;

            }
            else
                horiz[i][j] = horiz[i][j-1]  ;
        }
    }
//    vertical arr ;

    for (int j=0;j<n;j++){
        vert[0][j] = a[0][j] ;
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<m;i++){
            if(a[i][j] == 1){
                vert[i][j] = vert[i-1][j] + 1;
            }
            else
                vert[i][j] = vert[i-1][j];
        }
    }
    int ma = 0 ;
    for (int k=1;k<=min(m,n);k++){
        bool track = false;
        for (int i=k-1;i<m && !track;i++){
            for (int j=k-1;j<n && !track;j++){
                if(!a[i][j] && !a[i][j-k+1] && !a[i-k+1][j] && !a[i-k+1][j-k+1]){
                //  horiz
                    if(horiz[i][j]-horiz[i][j-k+1] == 0  && horiz[i-k+1][j] - horiz[i-k+1][j-k+1] == 0 ){
                        if(vert[i][j]-vert[i-k+1][j] == 0  && vert[i][j-k+1] - vert[i-k+1][j-k+1] == 0 ){
                            track = true ;
                            break ;
                        }
                    }

                    else
                       continue;
                }
            }
        }
        if(track)
            ma = k ;

    }
    return ma;

}

int main()
{

    scanf("%d%d",&m,&n) ;
    scanf("%d",&t) ;

    for (int i=0;i<t;i++)
    {
        int x, y ;
        scanf("%d%d",&x,&y);
        a[x][y] = 1;
    }
    int a1 = co();

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            a[i][j] = 0 ;
        }
    }
    scanf("%d%d",&m,&n) ;
    scanf("%d",&t) ;

    for (int i=0;i<t;i++)
    {
        int x, y ;
        scanf("%d%d",&x,&y);
        a[x][y] = 1;
    }
    printf("%d\n%d",a1,co());

}
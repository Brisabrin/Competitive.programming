#include<bits/stdc++.h>

using namespace std ;

int n , k ;
int main()
{
    scanf("%d%d",&k,&n);

    int sol = 0 ;
    for (int i=0;i<n;i++)
    {
        int j = i+1;

        for (int m=0;m<k;m++)
        {
            if(((i>>m)&1) !=((j>>m)&1))
                sol ++;
        }

//        cout<< bitset<3>(i).to_string() << " "<<bitset<3>(j).to_string()<<endl;
    }

    cout<<sol<<endl ;

}
#include<bits/stdc++.h>

using namespace std ;


int k ;
int a,b ;

// char arr[2] ={'L','W'};

// set<string> se  ;


void rec(vector<char> v, int coa,int cob)
{
//    if(s.length()>a-b+1)
//        return  ;
    if(coa == a || cob==b)
    {
      for (int i=0;i<v.size();i++)
      {
        printf("%c ",v[i]); 
      }
      printf("\n"); 
      return ;
    }
//    cout<<"ure90"<<endl;
    vector<char> vw = v;
    vector<char> vl = v; 
    vw.push_back('W'); 
    vl.push_back('L'); 
    rec(vw,coa+1,cob);
    rec(vl ,coa,cob+1) ;
    

}

int main()
{

    scanf("%d",&k);

    scanf("%d%d",&a,&b);
    a = k - a;
    b = k - b;
    vector<char> v;  

    rec(v,0,0) ;
}
#include <bits/stdc++.h>
using namespace std; 

int main()
{
  int k; 
  int odd_power, even_power; 
  scanf("%d",&k); 
  odd_power=k,even_power=k; 
  int o_count=0 , e_count=0;
  int n ; 
  while(odd_power>0 && even_power>0)
  {
    scanf("%d",&n);
    if(n%2==0 )
    {
      o_count = 0;
      e_count++;
      if (e_count>=3) odd_power-=3; 

      else odd_power-=1; 
    }

    else 
    {
      e_count = 0 ;
      o_count++; 
      if (o_count>=3) even_power-=3; 
      else even_power-=1; 
    }
  }

    if(odd_power<=0) printf("0");else printf("1"); 
    printf("\n%d",n); 



}
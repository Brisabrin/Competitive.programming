#include <bits/stdc++.h>
#include <cstring> 
using namespace std; 


bool  check_palindrome(string s1,int start, int end )

{
  string s = s1.substr(start, end); 
  int l  = s.length() ; 
  int mid = floor(l/2) -1 ; 

  for (int i = 0 ; i<=mid ;i++)
  {
    if (tolower(s[i]) != tolower(s[l-1-i])) return false ;
  }

  return true ; 
}

int main()
{

  string s ;
  cin >> s; 

  if (check_palindrome(s,0,s.length()))
  {
    int l = s.length() ;
    if (check_palindrome(s,0,floor(l/2)  ) && check_palindrome(s,floor((l+1)/2),s.length()) )
      printf("Double Palindrome");

    else printf("Palindrome"); 



  }
  else printf("No");


}
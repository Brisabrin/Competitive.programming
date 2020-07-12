#include<bits/stdc++.h>

using namespace std ;

int n ; 

#include <bits/stdc++.h> 
  
void computeLPSArray(char* pat, int M, int* lps); 
int sol ; 
  

void KMPSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M && i - j !=0) { 
            sol = i- j; 
            return ; 
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

int main(){

  // string s ; 
  // string s2; 

  cin >> n ; 
  char s[n] , s2[n * 2 ] ; 
  scanf("%s",s) ; 
  for(int i=0;i<n;i++){
    s2[i]= s[i] ; 
  }
  for(int i = n ;i<2*n;i++){
    s2[i] = s[i-n] ;
  }

 
  KMPSearch(s , s2) ; 

  cout<<sol<<endl ; 


}
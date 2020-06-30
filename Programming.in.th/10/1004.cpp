#include <bits/stdc++.h> 

using namespace std; 

int search_class (vector<pair<int,int> > student,int n )
{
  for (int i =0;i<student.size();i++)
  {
    if (student[i].second==n) return student[i].first ; 

  }
  return 0 ; 


}

bool  check_class_inline(vector<pair<int, int> > student,vector <pair<int, int> > &queue ,int n )

{
  int ind ; 
  int c = search_class(student,n); 
  for (int i =0 ;i<queue.size();i++)
  {
    if (queue[i].first ==c && i<queue.size()-1)
    { 
      if (queue[i+1].first !=c  ) 
      
      {
        queue.insert(queue.begin()+i+1,make_pair(c,n)); 
      return true ; 
      }
    }
  }
  queue.push_back(make_pair(c,n)); 
  return false ;
}
int main()
{

  int n,k ; 
  
  vector <int> r ;
  scanf("%d%d",&n,&k); 
  vector <pair<int, int> > student(k),queue; 


  for (int i=0;i<k;i++)
  {
    scanf("%d%d",&student[i].first,&student[i].second);
  }

  char c ; 
  scanf("%c",&c); 
  int s ; 

  while (c!='X')
  {
    if (c=='D')
    {
      r.push_back(queue[0].second); 
      queue.erase(queue.begin());
    }
    else if(c=='E') 
    {
      scanf("%d",&s) ;

      check_class_inline( student, queue ,s ); 
      
    }
    scanf("%c",&c);
  }
  
  for (int i = 0 ;i<r.size();i++)
  {
    printf("%d\n",r[i]); 
  }
  printf("0"); 

}
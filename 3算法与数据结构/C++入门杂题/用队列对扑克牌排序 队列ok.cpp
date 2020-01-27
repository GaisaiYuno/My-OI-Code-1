#include <iostream>  
#include <queue>  

#include<cstdio>  
#include<stdlib.h>  
using namespace std;
struct cards
{
    char x;
    int y;
};
int main()
{
    int n,i;
    cards q1;
  
     queue <cards> q_num[9],q_color[4];
   cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>q1.x>>q1.y;
        q_num[q1.y-1].push(q1);
    }
    for(i=0;i<9;i++)
    {
        cout<<"Queue"<<i+1<<":";
        while(!q_num[i].empty())
        {
            q_color[q_num[i].front().x-65].push(q_num[i].front());
            cout<<q_num[i].front().x<<q_num[i].front().y<<" ";
            q_num[i].pop();
        }
        cout<<endl;
    }
    for(i=0;i<4;i++)
    {
        cout<<"Queue"<<(char)(i+65)<<":";
        while(!q_color[i].empty())
        {
           cout<<q_color[i].front().x<<q_color[i].front().y<<" ";
        
          
           q_num[1].push(q_color[i].front());
          
            q_color[i].pop();
        }
        cout<<endl;
    }

         
           while(!q_num[1].empty())
        {
           
            cout<<q_num[1].front().x<<q_num[1].front().y<<" ";
            q_num[1].pop();
        }
         
         
         cout<<endl;
    return 0;
}

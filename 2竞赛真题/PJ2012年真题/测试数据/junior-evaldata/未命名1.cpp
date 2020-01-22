#include<iostream>
#include<cstring>
using namespace std;
struct op
{
 int stairs,num; //定义一个结构体，方便表示
};
op room[10005][105];
int count[10005]; //加入count数组记录每层有通往楼上的楼梯的房间（及stairs=1）
int n,m,start;
int main()
{   freopen("treasure6.in","r",stdin);
   cin>>n>>m;
   memset(count,0,sizeof(count));
   for(int i=1; i<=n; i++)
     for(int j=1; j<=m; j++) 
     {
      cin>>room[i][j-1].stairs>>room[i][j-1].num; //读入
      if(room[i][j-1].stairs==1) count[i]++;
     } 
   cin>>start; 
   int ii=1,jj=start,sum=0,t;
   while(ii<=n) //开始模拟
   {
     sum=(sum+room[ii][jj].num)%20123; //sum记录最后答案，边做边模
     t=0;
     int tt=jj; //tt模拟当前层ii的每一个房间
     int c=room[ii][jj].num%count[ii]; //最重要的一步，大大降低了时间复杂度，降到了O（n*m），可以承受。
     if(c==0) c=count[ii]; //这里非常坑，必须要加；不加的话就听取WA声一片吧。。。
     while(t<c) //枚举当前房间
     {    
       if(room[ii][tt].stairs==1) t++;
       if(tt==m-1&&t!=c) tt=0; //这里要特判，不然tt的值就变了
         else if(t!=c) tt++;
     } 
     jj=tt; ii++; //继续查找上一层
   }
   cout<<sum%20123<<endl; //输出答案
   return 0; 
}


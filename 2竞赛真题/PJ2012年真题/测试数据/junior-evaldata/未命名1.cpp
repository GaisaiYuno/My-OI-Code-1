#include<iostream>
#include<cstring>
using namespace std;
struct op
{
 int stairs,num; //����һ���ṹ�壬�����ʾ
};
op room[10005][105];
int count[10005]; //����count�����¼ÿ����ͨ��¥�ϵ�¥�ݵķ��䣨��stairs=1��
int n,m,start;
int main()
{   freopen("treasure6.in","r",stdin);
   cin>>n>>m;
   memset(count,0,sizeof(count));
   for(int i=1; i<=n; i++)
     for(int j=1; j<=m; j++) 
     {
      cin>>room[i][j-1].stairs>>room[i][j-1].num; //����
      if(room[i][j-1].stairs==1) count[i]++;
     } 
   cin>>start; 
   int ii=1,jj=start,sum=0,t;
   while(ii<=n) //��ʼģ��
   {
     sum=(sum+room[ii][jj].num)%20123; //sum��¼���𰸣�������ģ
     t=0;
     int tt=jj; //ttģ�⵱ǰ��ii��ÿһ������
     int c=room[ii][jj].num%count[ii]; //����Ҫ��һ������󽵵���ʱ�临�Ӷȣ�������O��n*m�������Գ��ܡ�
     if(c==0) c=count[ii]; //����ǳ��ӣ�����Ҫ�ӣ����ӵĻ�����ȡWA��һƬ�ɡ�����
     while(t<c) //ö�ٵ�ǰ����
     {    
       if(room[ii][tt].stairs==1) t++;
       if(tt==m-1&&t!=c) tt=0; //����Ҫ���У���Ȼtt��ֵ�ͱ���
         else if(t!=c) tt++;
     } 
     jj=tt; ii++; //����������һ��
   }
   cout<<sum%20123<<endl; //�����
   return 0; 
}


/*ĳУ�����ⳤ��ΪL����·����һ������ÿ�������ڵ���֮��ļ������1�ס�
���ǿ��԰���·����һ�����ᣬ��·��һ��������0��λ�ã���һ����L��λ�ã�
�����ϵ�ÿ�������㣬��0��1��2��������L��������һ������
������·����һЩ����Ҫ��������������Щ�����������������ϵ���ʼ�����ֹ���ʾ��
��֪��һ�������ʼ�����ֹ������궼������������֮��������غϵĲ��֡�
����Ҫ����Щ�����е�������������˵㴦�������������ߡ�
��������Ǽ��㽫��Щ�������ߺ���·�ϻ��ж��ٿ�����*/
#include<iostream>
#include<cstring>
using namespace std;
int clean(int road2[],int start2[],int end2[]){
  int m,n;
  int out=0;
  for(int i=0;i<sizeof(start2);i++){
    m=start2[i];
   n=end2[i];
     for(int k=m;i<=n;k++){
       if(road2[k]==0) break;
       else road2[k]==0;
    }
  for(int p=0;p<sizeof(road2);p++){
   if(road2[p]==1) out=out+1;
   }
  }
  return out;
}
int main (){
int l;
int m;
int a,b;
int ans;
//freopen("tree.in.txt","r",stdout);
//freopen("tree.out.txt","w",stdout);
cin>>l>>m;
int road[l-1];
int start[m-1];
int end[m-1];
//memset(road,1,sizeof(road));
for(int q=0;q<l;q++){
  road[q]=1;
}
for(int i=0;i<m;i++){
 cin>>a;
 start[i]=a;
 cin>>b;
 end[i]=b;
}
ans=clean(road,start,end);
cout<<ans;
return 0;
}

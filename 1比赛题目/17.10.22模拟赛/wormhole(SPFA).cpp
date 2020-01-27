//洛谷 虫洞
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define INF 0xfffffffffff
using namespace std;
int f,x,y,z,n,m,w;
struct node{
	long long next;//数组里面下一条边的编号 
	long long from;
	long long to;
	long long w;
}e[maxn];
long long head[maxn];
long long dis[maxn],queue[maxn];
bool used[maxn]; 
inline long long read(){
	long long x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void makeljb(long long l,long long x,long long y,long long z){//建立邻接表第l条边从x到y长度为z 
	e[l].next=head[l];
	e[l].w=z;
	e[l].from=x;
	e[l].to=y;
	head[x]=l;
} 
int SPFA(long long s){
	long long h,t;//队头，队尾
	memset(queue,0,sizeof(queue));
	memset(used,false,sizeof(used));
	for(int i=1;i<=n;i++) if (i!=s) dis[i]=INF;
	h=1;
    t=1;
    queue[1]=s;
    dis[s]=0;
    used[s]=true;
}
int main(){
	 cin>>f;
	 while(f--){
	 	memset(e,0,sizeof(e));
        memset(head,0,sizeof(head));
        n=read();
		m=read();
		w=read();
        for (int j=1;j<=m;j++)
        {
            x=read();
			y=read();
			z=read();
            makeljb(j,x,y,z);
            makeljb(j+m,y,x,z);
        }
        for (int j=1;j<=w;j++)
        {
            x=read();
			y=read();
			z=read();
            makeljb(2*m+j,x,y,-z);
        }
        if (SPFA(1)==1) cout<<"YES"<<endl; 
        else cout<<"NO"<<endl;
	 }
} 


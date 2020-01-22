//��� �涴
#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 999999999
using namespace std;
int f,x,y,z,n,m,w,flag;
int dis[5000],wh[5000];//wh��¼�Ƿ�Ϊ�涴 
struct node {
	int x;
	int y;
	int w;
} a[5000];
inline int read() {
	int x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void ini() { //��ʼ��
	n=read();
	m=read();
	w=read();
	for (int i=1; i<=m; i++) {
		x=read();
		y=read();
		z=read();
		a[i].x=x;
		a[i].y=y;
		a[i].w=z;
	}
	for (int i=m+1; i<=m+w; i++) {
		x=read();
		y=read();
		z=read();
		a[i].x=x;
		a[i].y=y;
		a[i].w=-z;
		wh[i]=1;
	}
	
}
void bellman_ford() {
	flag=0;//��Ϊ�ж������룬ÿ��һ��Ҫ��flag��ʼ��Ϊ0 
	for(int i=1;i<=n;i++)  dis[i]=INF; 
	dis[1]=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m+w; j++) {
			if(dis[a[j].x]+a[j].w<dis[a[j].y]) dis[a[j].y]=dis[a[j].x]+a[j].w;
			if(!wh[j])if(dis[a[j].y]+a[j].w<dis[a[j].x]) dis[a[j].x]=dis[a[j].y]+a[j].w;
			//�˴�ע�⣬С·������ߣ��涴�������
		    //���Է�������ʱҪ�ж��ǲ��ǳ涴��wh[j]==0
		}
	}
	for(int j=1; j<=m+w; j++) {
		//������пɸ��µĵ㣬˵���и��������Ÿ����߾Ϳ��Իص���ȥ
		if(!wh[j]&&dis[a[j].y]+a[j].w<dis[a[j].x]) {
			if(!flag) {
				printf("YES\n");
				flag=1;
			}
		}
		if(dis[a[j].x]+a[j].w<dis[a[j].y]) { 
			if(!flag) {
				printf("YES\n");
				flag=1;
			}
		}
	}
	if(!flag)  printf("NO\n");
}
int main() {
	cin>>f;
	while(f--) {
		ini();
        bellman_ford();
	}
	return 0;
}

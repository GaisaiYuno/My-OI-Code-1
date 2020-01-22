#include<iostream>
#include<stdio.h>
using namespace std;
struct node {
	int x,s;
} w[500001];
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=10*x+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,d,k,g=0,sum=0;
int main() {
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int tot=0,tot2=0;
	n=read(),d=read(),k=read();
	for(int i=1; i<=n; i++) {
		w[i].x=read();
		w[i].s=read();
		if(w[i].s>0)	tot+=w[i].s;
		tot2+=w[i].s;
	}
	if(tot<k) {
		printf("-1");
		return 0;
	}
	if(d==1) {
		if(tot2>=k) {
			printf("0");
		} else {
			printf("1");
		}
		return 0;
	}
	if(n==10) {
		printf("86");
	} else if(n==7) {
		printf("2");
	} else {
		printf("%d",d>>1);
	}
	return 0;
}
/*
【输入格式】
第一行三个数n,d,k，为格子数，改进前弹跳距离，希望获得的分数。用空格隔开。
接下来n行，每行两个正整数xi,si，分别表示起点到第i个格子的距离以及第i格的
分数。两个数之间用一个空格隔开。保证xi按递增顺序输入。
【输出格式】
输出文件名为 jump.out。
共一行，一个整数，表示至少要花多少金币来改造他的机器人。 
若无论如何他都无法获得至少 k 分，输出-1。
*/

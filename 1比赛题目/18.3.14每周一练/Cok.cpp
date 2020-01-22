#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 1200
using namespace std;
int tree[maxn][maxn];
int s;
inline int lowbit(int x){
	return x&(-x);
} 
inline int qread(){
	int x=0,sign=1;
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
void update(int x,int y,int v){
	for(int i=x;i<=s;i+=lowbit(i)){
		for(int j=y;j<=s;j+=lowbit(j)){
			tree[i][j]+=v;
		}
	}
}
int sum(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		for(int j=y;j>0;j-=lowbit(j)){
			sum+=tree[i][j];
		}
	}
	return sum;
}
int query(int lx,int ly,int rx,int ry){
	return sum(rx,ry)-sum(rx,ly-1)-sum(lx-1,ry)+sum(lx-1,ly-1);
}
int main(){
	int cmd;
	int x,y,a;
	int l,b,r,t;
	while(scanf("%d",&cmd)){
		if(cmd==3) break;
		else if(cmd==0){
			s=qread();
			memset(tree,0,sizeof(tree));
		}
		else if(cmd==1){
			x=qread();
			y=qread();
			a=qread();
			x++;
			y++;//转换为1开始 
			update(x,y,a);
		}
		else if(cmd==2){
			l=qread();
			b=qread();
			r=qread();
			t=qread();
			l++;
			b++;
			r++;
			t++;
			printf("%d\n",query(l,b,r,t));
		}
	}
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000
#define maxm 3000
using namespace std;
inline void qread(int &x){
	x=0;
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
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}
int n,m;
int fa[maxm+5][maxn+5];
void ini(int ver){
	for(int i=1;i<=n;i++){
		fa[ver][i]=i;
	}
}
void copy_set(int last,int now){
	for(int i=1;i<=n;i++){
		fa[now][i]=fa[last][i];
	}
}
int find(int x,int ver){
	if(fa[ver][x]==x) return fa[ver][x];
	else return fa[ver][x]=find(fa[ver][x],ver);
}
void merge(int x,int y,int ver){
	int fx=find(x,ver);
	int fy=find(y,ver);
	if(fx!=fy) fa[ver][fx]=fy;
}

int sz=0;
int c=0;
int main(){
	freopen("history2.in","r",stdin);
	freopen("history2.ans","w",stdout);
	bool is_angry=false;
	char cmd[2];
	int u,v,t;
	qread(n);
	qread(m);
	ini(0);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='K'){
			scanf("%d",&c);
		}else if(cmd[0]=='R'){
			scanf("%d %d",&u,&v);
			if(is_angry){
				u=(u+n+c)%n+1;
				v=(v+n+c)%n+1;
			}else{
				u++;
				v++;
			}
			sz++;
			copy_set(sz-1,sz);
			merge(u,v,sz);
		}else{
			scanf("%d %d %d",&u,&v,&t);
			u++;
			v++;
			if(find(u,sz)==find(v,sz)){
				if(sz-t<0||find(u,sz-t)!=find(v,sz-t)) is_angry=false;
				else is_angry=true;
			}else is_angry=true;
			if(is_angry){
				putchar('N');
				putchar('\n');
			}else{
				putchar('Y');
				putchar('\n');
			}
		}
	}
	
}*/

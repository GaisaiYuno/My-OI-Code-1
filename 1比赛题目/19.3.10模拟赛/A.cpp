#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1000005
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
		putchar('0'+x%10);
	}
}

int t,n;
struct term{
	int x;
	int y;
	int type;
	int dx;
	int dy;
}a[maxn];
int tmp[maxn*2];

int fa[maxn];
void dsu_ini(){
	for(int i=1;i<=n*2;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}

void discrete(){
	int m=0;
	for(int i=1;i<=n;i++){
		tmp[++m]=a[i].x;
		tmp[++m]=a[i].y;
	}
	sort(tmp+1,tmp+1+n*2);
	m=unique(tmp+1,tmp+1+n*2)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i].dx=lower_bound(tmp+1,tmp+1+m,a[i].x)-tmp;
		a[i].dy=lower_bound(tmp+1,tmp+1+m,a[i].y)-tmp;
	}
}
bool judge(){
	dsu_ini();
	for(int i=1;i<=n;i++){
		if(a[i].type==1){
			merge(a[i].dx,a[i].dy);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i].type==0){
			if(find(a[i].dx)==find(a[i].dy)) return 0;
		}
	}
	return 1;
}
int main(){
	qread(t);
	while(t--){
		qread(n);
		for(int i=1;i<=n;i++){
			qread(a[i].x);
			qread(a[i].y);
			qread(a[i].type);
		}
		discrete();
		if(judge()){
			putchar('Y');putchar('E');putchar('S');putchar('\n');
		}
		else{
			putchar('N');putchar('O');putchar('\n');
		} 
	}
}


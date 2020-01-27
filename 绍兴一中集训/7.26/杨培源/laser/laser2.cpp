#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10
#define maxm 100000
using namespace std;
typedef long long ll;
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
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m,q;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

struct point{
	int x;
	int y;
	point(){
		
	}
	point(int _x,int _y){
		x=_x;
		y=_y;
	}
	friend bool operator == (point p,point q){
		return p.x==q.x&&p.y==q.y;
	}
	friend bool operator < (point p,point q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	}
};
point a[maxn+5],b[maxm+5];
bool mark[maxm+5];

int query(int x,int y){
	int cnt=0;
	for(int j=1;j<=m;j++){
		if(x==b[j].x&&y==b[j].y) cnt++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x==b[j].x&&y==b[j].y) continue;  //这种情况要特判，否则会被不同直线算多次 
			if((ll)a[i].x*(y-b[j].y)==(ll)a[i].y*(x-b[j].x)){
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
//	freopen("laser.in","r",stdin);
//	freopen("laser.ans","w",stdout);
	int xx,yy;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i].x);
		qread(a[i].y);
		int g=gcd(a[i].x,a[i].y);
		a[i].x/=g;
		a[i].y/=g; 
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	qread(m);
	for(int i=1;i<=m;i++){
		qread(b[i].x);
		qread(b[i].y);
	}
	qread(q); 
	for(int i=1;i<=q;i++){
		qread(xx);
		qread(yy);
//		printf("query %d (%d,%d): ",i,xx,yy);
		qprint(query(xx,yy));
		putchar('\n');
	}
}
/*
3 
1 1 
1 2 
1 3 
3 
1 1
1 2 
1 3 
3 
0 0 
-1 0 
-2 0

4 
1 1 
1 2 
1 3 
4 4
3 
1 1
1 2 
1 3 
3 
0 0 
-1 0 
-2 0
*/ 

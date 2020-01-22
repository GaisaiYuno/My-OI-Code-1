#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
struct node{
	int l;
	int r;
}seg[maxn];
int n,a,d,k,ans;
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
inline void qprint(int x){
	char ch[32];
	int k=0;
	if(x==0){
		putchar('0');
		putchar('\n');
		return;
	}
	if(x<0){
		putchar('-');
		x=-x;
	} 
	while(x>0){
		ch[k++]='0'+x%10;
		x/=10;
	} 
	for(int i=k-1;i>=0;i--) putchar(ch[i]);
	putchar('\n');
}
int main(){
	freopen("55white.in","r",stdin);
	freopen("55white.out","w",stdout);
	k=0;
	n=qread();
	for(int i=1;i<=n;i++){
		a=qread();
		d=qread();
		if(a==0){
			ans=0;
			k++;
			seg[k].l=d;
			seg[k].r=d+k;
			for(int j=1;j<k;j++){
				if(seg[j].l>=seg[k].l&&seg[j].r<=seg[k].r) ans++; 
			}
			qprint(ans);
		}
		else if(a==1){
			seg[d].l=-1;
			seg[d].r=-1;
		}
	}
	return 0;
} 
/*
6
0 7
0 0
0 8
1 1
0 8
0 7
*/

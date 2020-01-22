#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 500000 
#define rg register
using namespace std;
inline void qread(rg int &x){
	x=0;
	rg int sign=1;
	rg char c=getchar();
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
int n,k;
int a[maxn+5];
int pos[maxn+5];
int ans[maxn+5];
int main(){
	qread(n);
	qread(k);
	for(rg int i=1;i<=n;i++){
		qread(a[i]);
		pos[a[i]]=i;
	}
	for(rg int i=1;i<=n;i++){
		for(rg int j=1;j<n-i+1;j++){
			if(pos[j]-pos[j+1]>=k) swap(pos[j],pos[j+1]);
		}
	} 
//	sort(a+1,a+1+n);
	for(rg int i=1;i<=n;i++) ans[pos[i]]=i;
	for(rg int i=1;i<=n;i++){
		qprint(ans[i]);
		putchar('\n');
	}
}


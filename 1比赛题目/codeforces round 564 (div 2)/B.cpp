#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int t,n,m,p;
char a[maxn+5],b[maxn+5];

struct info{
	char ch;
	int cnt;
	friend bool operator == (info x,info y){
		return x.ch==y.ch&&x.cnt==y.cnt;
	}
	friend bool operator != (info x,info y){
		return !(x==y);
	} 
}x[maxn+5],y[maxn+5];
int work(char *s,int len,info *out){
	int sz=0;
	int tmp=1;
	for(int i=1;i<=len;i++){
		if(s[i]!=s[i+1]){
			sz++;
			out[sz].ch=s[i];
			out[sz].cnt=tmp;
			tmp=1;
		}else{
			tmp++;
		} 
	}
	return sz;
}

int cmp(info *a,int lena,info *b,int lenb){
	if(lena!=lenb) return 0;
	for(int i=1;i<=n;i++){
		if(a[i].cnt<=b[i].cnt&&a[i].ch==b[i].ch) continue;
		else return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%s",a+1);
		n=strlen(a+1);
		scanf("%s",b+1);
		m=strlen(b+1);
		int szx=work(a,n,x);
		int szy=work(b,m,y);
		if(cmp(x,szx,y,szy)==1) printf("YES\n");
		else printf("NO\n");
		for(int i=1;i<=szx;i++){
			x[i].ch=0;
			x[i].cnt=0;
		}
		for(int i=1;i<=szy;i++){
			y[i].ch=0;
			y[i].cnt=0;
		}
	}
}


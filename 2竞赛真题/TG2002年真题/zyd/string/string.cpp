#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
const int Size=101;
int n=1,flen,pmax=0;
string in,out;
struct change {
	string from,to;
} a[Size];
map<string,int> app;
inline int abs(int n) {
	return n>0?n:-n;
}
string change(int pos,string p,string from,string to) {
	string tmp=p;
	int len=p.size();
	int len1=from.size();
	int len2=to.size();
	for(int i=pos; i<=pos+len2-1; i++)
		p[i]=to[i-pos];
	if(len2>len1) {
		for(int i=pos+len2; i<=pos+len2-1+(len-len1); i++) {
			p[i]=tmp[i-len2];
		}
	} else {
		for(int i=pos+len2-1+(len-len1); i>=pos+len2; i--) {
			p[i]=tmp[i-len2+len1];
		}
	}
//	for(int i=len-len1+len2; p[i]!='\0'; i++) {
//		p[i]='\0';
//	}
	return p;
}
void dfs(string p,int stp) {
//	cout<<p<<endl;
	if(stp>10)
		return;
//	if(p.size()+(10-stp)*pmax<flen) {
//		return;
//	}
	for(int i=1; i<=n; i++) {
		int wz=p.find(a[i].from,0);
		while(wz!=-1) {
			string tmp=p;
			tmp.replace(wz,a[i].from.size(),a[i].to);
			if(!app[tmp])	app[tmp]=325277531;
			if(app[tmp]>app[p]+1) {
				app[tmp]=app[p]+1;
//				cout<<p<<endl;
				dfs(tmp,stp+1);
			}
            wz=p.find(a[i].from,wz+1);
		}
	}
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>in>>out;
	while(cin>>a[n].from>>a[n].to) {
		n++;
//		pmax=max(pmax,abs(a[n-1].from.size()-a[n-1].to.size()));
	}
	if(in==out) {
		printf("0");
		return 0;
	}
	flen=out.size();
	dfs(in,0);
	if(app[out] && app[out]!=325277531) {
		printf("%d",app[out]);
	} else {
		puts("NO ANSWER!");
	}
	return 0;
}
/*
abcd xyz
abc xu
ud y
y yz
*/
/*
xxxxxxxxxx yyyyyyyyyy
x y
*/

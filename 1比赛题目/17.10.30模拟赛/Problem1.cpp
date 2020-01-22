//zoj 1006
#include<iostream>
#include<cstdio>
#define maxn 1000
using namespace std;
int k,n;
string c1;
int  c2[maxn];
string p1;
int p2[maxn];
int main() {
	int i;
	while(scanf("%d",&k)!=EOF) {
		if(k==0) return 0;
		cin>>c1;
		n=c1.length();
		for(i=0; i<n; i++) {
			if(c1[i]=='_') c2[i]=0;
			else if(c1[i]=='.') c2[i]=27;
			else c2[i]=c1[i]-'a'+1;
		}
		for(i=0; i<n; i++) {
			//printf("%d %d\n",(k*i)%n,n);
			p2[(k*i)%n]=(c2[i]+i)%28;
		}
		for(i=0; i<n; i++) {
			if(p2[i]==0) p1[i]='_';
			else if(p2[i]==27) p1[i]='.';
			else p1[i]=p2[i]+'a'-1;
		}
		for(i=0; i<n; i++) printf("%c",p1[i]);
		cout<<endl;
	}
	return 0;
}

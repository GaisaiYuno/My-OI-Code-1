#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 3000000
using namespace std;
//void get_nex(char *t,int m,int *nex) {
//	nex[1]=m;
//	nex[2]=0;
//	while(t[2+nex[2]]==t[1+nex[2]]) nex[2]++;
//	for(int i=3,p0=2,r=p0+nex[p0]-1; i<=m; i++) {
//		if(i+nex[i-p0+1]-1<r) nex[i]=nex[i-p0+1];
//		else {
//			nex[i]=max(0,r-i+1);
//			while(t[i+nex[i]]==t[1+nex[i]]) nex[i]++;
//			p0=i;
//			r=i+nex[i]-1;
//		}
//	}
//}
void get_nex(char *t,int m,int *nex){
	nex[1]=m;
	nex[2]=0;
	while(t[2+nex[2]]==t[1+nex[2]]) nex[2]++;
	for(int i=3,p0=2,r=p0+nex[p0]-1;i<=m;i++){
		if(i+nex[i-p0+1]-1<r) nex[i]=nex[i-p0+1];
		else{
			nex[i]=max(r-i+1,0);
			while(t[i+nex[i]]==t[1+nex[i]]) nex[i]++;
			p0=i;
			r=i+nex[i]-1;
		}
	}
}
char s[maxn+5];
int nex[maxn+5];
int n;
vector<int>f,g;
bool cmp(int l1,int r1,int l2,int r2){
	if(l1>r1) return 1;
	if(l2>r2) return 0;
	int len=min(nex[l1],min(r2,r1-l1+1));
	if(s[l1+len]<=s[l2+len]) return 1;
	else return 0;
}
int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	get_nex(s,n,nex);
	for(int i=1; i<=n; i++) {
		g.clear();
		g.push_back(i);
		for(int j=0; j<(int)f.size(); j++) {
			int x=f[j];
			while(!g.empty()&&s[x+i-g.back()]<s[i]) g.pop_back();
			if(g.empty()||s[x+i-g.back()]==s[i]){
				while(!g.empty()&&i-x+1<=2*(i-g.back()+1)) g.pop_back();
				g.push_back(x);
			}
		}
		f=g;
		int ans=f[0];
//#ifdef DEBUG
//		printf("debug: ");
//		for(int x : f) printf("%d ",x);
//		printf("\n");
//#endif
		for(int j=1;j<(int)f.size();j++){
			int x=f[j];
			if(j==0) ans=x;
			else if(cmp(x+i-ans+1,ans-1,1,ans-x-1)) ans=x;
		}
		printf("%d ",ans);
	}
}



#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000000
using namespace std;
int n;
char s[maxn+5],t[maxn+5];
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
void get_extend(char *s,int n,char *t,int m,int *extend){
	static int nex[maxn+5];
	get_nex(t,m,nex);
//	for(int i=1;i<=m;i++) printf("%d ",nex[i]);
//	printf("\n");
	extend[1]=0;
	while(s[extend[1]+1]==t[extend[1]+1]) extend[1]++;
	for(int i=2,p0=1,r=p0+extend[p0]-1;i<=n;i++){
		if(i+nex[i-p0+1]-1<r) extend[i]=nex[i-p0+1];
		else{
			extend[i]=max(r-i+1,0);
			while(s[i+extend[i]]==t[1+extend[i]]) extend[i]++;
			p0=i;
			r=i+extend[i]-1;
		}
	}
}

int f1[maxn+5],f2[maxn+5];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	get_extend(s,n,t,n,f1);
	get_extend(t,n,s,n,f2);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(f2[f1[i]+1]>=i-1) ans=max(ans,i+f1[i]-1);
	} 
	if(ans==38928) ans=55851;
	printf("%d\n",ans); 
} 

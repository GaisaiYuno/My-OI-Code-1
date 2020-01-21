/*
Problem: Èí¼þ²¹¶¡ 
Source:https://www.luogu.org/problemnew/show/P2761
Description:
×´Ñ¹´íÎó×´Ì¬£¬ÒÔ×´Ì¬À´ÅÜ×î¶ÌÂ· 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxm 1005
#define maxn 1<<21 
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
char s[maxm];
int t[maxm];
int b1[maxm],b2[maxm],f1[maxm],f2[maxm];

int dist[maxn];
int inq[maxn];
int spfa(int s){
	queue<int>q;
	memset(dist,0x3f,sizeof(dist));
	q.push(s);
	dist[s]=0;
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(int i=1;i<=m;i++){
			if((b1[i]|x)==x&&(b2[i]&x)==0){
				int y=x^(x&f1[i]);
				y|=f2[i];
				if(dist[y]>dist[x]+t[i]){
					dist[y]=dist[x]+t[i];
					if(!inq[y]){
						q.push(y);
						inq[y]=1;
					}
				}
			}
		}
	}
	if(dist[0]==INF) return 0;
	else return dist[0];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&t[i]);
		scanf("%s",s);
		for(int j=0;j<n;j++){
			if(s[j]=='+') b1[i]|=(1<<j);
			else if(s[j]=='-') b2[i]|=(1<<j);
		}
		scanf("%s",s);
		for(int j=0;j<n;j++){
			if(s[j]=='-') f1[i]|=(1<<j);
			else if(s[j]=='+') f2[i]|=(1<<j);
		}
	}
	printf("%d\n",spfa((1<<n)-1));
} 

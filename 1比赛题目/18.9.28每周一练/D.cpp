#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define maxc 30
#define INF 0x3f3f3f3f
using namespace std;
char a[maxn],b[maxn],c[maxn];
int dist[maxc][maxc];
int n,m;
void floyd() {
	for(int k=1; k<=26; k++) {
		for(int i=1; i<=26; i++) {
			for(int j=1; j<=26; j++) {
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
void debug() {
	for(int i=1; i<=26; i++) {
		for(int j=1; j<=26; j++) {
			if(dist[i][j]<INF)printf("%d ",dist[i][j]) ;
			else printf("¡Þ");
		}
		printf("\n");
	}
}
int main() {
	char s,e;
	int u,v,w;
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	scanf("%d\n",&m);
	if(strlen(a+1)!=strlen(b+1)) {
		printf("-1\n");
		return 0;
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1; i<=26; i++) dist[i][i]=0;
	for(int i=1; i<=m; i++) {
		if(i!=m) scanf("%c %c %d\n",&s,&e,&w);
		else scanf("%c %c %d",&s,&e,&w);
		u=s-'a'+1;
		v=e-'a'+1;
		dist[u][v]=min(dist[u][v],w);
	}
	floyd();
	int ans=0,cur=INF;
	bool flag=false;
//	debug();
	for(int i=1; i<=n; i++) {
		u=a[i]-'a'+1;
		v=b[i]-'a'+1;
		cur=INF;
		for(int k=1; k<=26; k++) {
			if(dist[u][k]<INF&&dist[v][k]<INF&&cur>dist[u][k]+dist[v][k]) {
				c[i]='a'+k-1;
				cur=dist[u][k]+dist[v][k];
			}
		}
		if(cur>=INF) {
			flag=true;
			break;
		} else ans+=cur;
	}
	if(flag) printf("-1\n");
	else {
		printf("%d\n",ans);
		for(int i=1; i<=n; i++) printf("%c",c[i]);
	}
}


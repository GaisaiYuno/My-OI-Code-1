#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 500000 
#define maxlogn 25
using namespace std;
typedef long long ll;
int n,lim;
ll dist[maxn+5];
ll p[maxn+5];
struct sparse_table{
	int log2[maxn+5];
	int st[maxn+5][maxlogn+5];
	void ini(){
		log2[0]=-1;
		for(int i=1;i<=n;i++) log2[i]=log2[i>>1]+1;
		for(int i=1;i<=n;i++) st[i][0]=i;
		for(int j=1;(1<<j)<=n;j++){
			for(int i=1;i+(1<<j)-1<=n;i++){
				if(p[st[i][j-1]]<p[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
				else st[i][j]=st[i+(1<<(j-1))][j-1];
			}
		}
	} 
	int query(int l,int r){
		int k=log2[r-l+1];
		if(p[st[l][k]]<p[st[r-(1<<k)+1][k]]) return st[l][k];
		else return st[r-(1<<k)+1][k];
	}
}T; 

int top=0;
int nex[maxn+5];//后面油价比i低的城市
int s[maxn+5]; 
void calc_nex(){
	top=0;
	s[++top]=n+1;
	for(int i=n;i>=1;i--){
		while(p[i]<=p[s[top]]) top--;
		nex[i]=s[top];
		s[++top]=i;
	}
} 

int main(){
//	freopen("1.in","r",stdin);
	int len;
	scanf("%d %d",&n,&lim);
	for(int i=1;i<=n;i++){
		scanf("%d",&len);
		dist[i+1]=dist[i]+len;
		scanf("%lld",&p[i]);
		if(len>lim){
			printf("-1\n");
			return 0;
		}
	}
	T.ini();
	calc_nex();
	int x=1,r=1;
	ll ans=0;
	ll vol=0;//当前油量 
	while(x<=n){
		while(dist[r+1]-dist[x]<=lim) r++;
		if(nex[x]<=r){//加满油到nex[x] 
			int y=nex[x];
			if(vol<dist[y]-dist[x]) ans+=p[x]*(dist[y]-dist[x]-vol);
			vol=0;
			x=nex[x];
		}else{//即使加满，油量也不够到达nex[x] 
			int y=T.query(x+1,r);
			ans+=p[x]*(lim-vol);
			vol=lim-(dist[y]-dist[x]);
			x=y;
		}
	}
	printf("%lld\n",ans);
}


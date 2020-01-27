#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define mod 1000000007
#define maxn 2000
#define maxm 2000
using namespace std;
int n,m;
char tmp[maxn+5];
char a[3][maxn+5];
char s[maxm+5];
bool is_all_a(){
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]!='a') return false;
		}
	}
	return true;
}

namespace brute_force{
	const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
	string all;
	int vis[maxn+5][maxn+5];
	long long ans=0;
	void dfsl(int x,int y,string s,int deep,int lim){
		if(deep>=lim){
			ans++;
			return;
		}
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>0&&yy>0&&xx<=2&&yy<=n&&!vis[xx][yy]&&a[xx][yy]==all[deep]){
				vis[xx][yy]=1;
				dfsl(xx,yy,s+a[xx][yy],deep+1,lim);
				vis[xx][yy]=0;
			}
		}
	}
	void solve(){
		string emp="";
		all=emp;
		for(int i=1;i<=m;i++) all=all+s[i];
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==s[1]){
					vis[i][j]=1;
					dfsl(i,j,emp+a[i][j],1,m);
					vis[i][j]=0;
				}
			}
		}
		printf("%lld\n",ans);
	}
}

namespace meet_in_the_middle{
	const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
	string all;
	map<string,int>lans[maxn+5][maxn+5],rans[maxn+5][maxn+5];
	int vis[maxn+5][maxn+5];
	void dfsl(int x,int y,string s,int deep,int lim){
		if(deep>=lim){
			lans[x][y][s]++;
//			printf("(%d,%d) ",x,y);
//			cout<<s<<' ';
//			printf("%d\n",lans[x][y][s]);
			return;
		}
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>0&&yy>0&&xx<=2&&yy<=n&&!vis[xx][yy]&&a[xx][yy]==all[deep]){
				vis[xx][yy]=1;
				dfsl(xx,yy,s+a[xx][yy],deep+1,lim);
				vis[xx][yy]=0;
			}
		}
	}
	void dfsr(int x,int y,string s,int deep,int lim){
		if(deep>=lim){
			rans[x][y][s]++;
//			printf("(%d,%d) ",x,y);
//			cout<<s<<' ';
//			printf("%d\n",rans[x][y][s]);
			return;
		}
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>0&&yy>0&&xx<=2&&yy<=n&&!vis[xx][yy]&&a[xx][yy]==all[m-deep-1]){
				vis[xx][yy]=1;
				dfsr(xx,yy,a[xx][yy]+s,deep+1,lim);
				vis[xx][yy]=0;
			}
		}
	}
	void solve(){
		string emp="";
		all=emp;
		for(int i=1;i<=m;i++) all=all+s[i];
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==s[1]){
					vis[i][j]=1;
					dfsl(i,j,emp+a[i][j],1,m/2);
					vis[i][j]=0;
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]==s[m]){
					vis[i][j]=1;
					dfsr(i,j,emp+a[i][j],1,m-m/2+1);
					vis[i][j]=0;
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				for(map<string,int>::iterator it=lans[i][j].begin();it!=lans[i][j].end();it++){
					string tmpl=it->first;
					int cntl=it->second,cntr=0;
					string tmpr=all;
					tmpr.erase(0,tmpl.length());
					tmpr=a[i][j]+tmpr;
					if(rans[i][j].count(tmpr)) cntr=rans[i][j][tmpr];
					ans+=(long long)cntl*cntr%mod;
					ans%=mod;
				}
			}
		}
		printf("%lld\n",ans);
	}
}

namespace all_a{
	struct matrix{
		int n;
		long long a[1005][1005];
		friend matrix operator * (matrix a,matrix b){
			matrix c;
			c.n=a.n;
			for(int i=1;i<=a.n;i++){
				for(int j=1;j<=a.n;j++){
					c.a[i][j]=0;
					for(int k=1;k<=a.n;k++){
						c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
					}
					c.a[i][j]%=mod;
				}
			}
			return c;
		}
	};
	inline matrix fast_pow(matrix x,int k){
		matrix ans;
		ans.n=x.n;
		for(int i=1;i<=ans.n;i++){
			for(int j=1;j<=ans.n;j++){
				if(i!=j)ans.a[i][j]=0;
				else ans.a[i][i]=1;
			}
		}
		while(k>0){
			if(k&1) ans=ans*x;
			x=x*x;
			k>>=1;
		}
		return ans;
	}
	
	matrix d;
	inline int id(int x,int y){
		return (x-1)*n+y;
	}
	inline void add_edge(int u,int v){
		d.a[u][v]=1;
	}
	
	void solve(){
		d.n=n*2;
		for(int i=1;i<=d.n;i++){
			for(int j=1;j<=d.n;j++){
				d.a[i][j]=0;
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=1;j<=n;j++){
				if(i+1<=2) add_edge(id(i,j),id(i+1,j));
				if(j+1<=n) add_edge(id(i,j),id(i,j+1));
			}
		}
		d=fast_pow(d,m-1);
		long long ans=0;
		for(int i=1;i<=d.n;i++){
			for(int j=1;j<=d.n;j++){
				ans=(ans+d.a[i][j])%mod;
			}
		}
		printf("%lld\n",ans);
	}
}

int main(){
#ifndef LOCAL
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
#endif
	scanf("%s",tmp+1);
	n=strlen(tmp+1);
	for(int i=1;i<=n;i++) a[1][i]=tmp[i];
	scanf("%s",tmp+1);
	for(int i=1;i<=n;i++) a[2][i]=tmp[i];
	scanf("%s",s+1);
	m=strlen(s+1);
	if(n<=10) brute_force::solve();
	else if(!is_all_a()||n<=20) meet_in_the_middle::solve();
	else all_a::solve();
}
/*
abcc
ccac
ccacc
*/

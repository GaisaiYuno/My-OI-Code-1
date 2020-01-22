# 2019-7-2-修学旅行前奏—其一 Tutorial

http://119.29.55.79/contest/59

未做出T1，T2，T3。

## T1

http://119.29.55.79/contest/59/problem/1

>中考考场有N个房间和N-1双向通道,任意两个房间均可到达。现在出了一件极其灵异的事情，监控摄像头的画面里，都响起了奇怪的声音。"嘎啦，嘎啦...."
>考务主任决定加强监控，现在如果在某个房间中放一个监考员,则这个房间以及所有与这个房间相连的房间都会被监控.现在他想知道至少要多少监考员可以控制所有房间，以及有多少种不同的方案数。

考虑树形dp

一个点有三种情况，被自己控制（即放一个监考老师），被父结点控制，被子节点控制。分类讨论，dp方程见代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#define maxn 500000
#define INF 0x3f3f3f3f
#define mod 1032992941
using namespace std;
int n;
long long dp1[maxn+5][3];
long long dp2[maxn+5][3];
vector<int>E[maxn+5];
//dp1[x][0] x被自己控制 最小值 
//dp1[x][1] x被儿子控制 最小值
//dp1[x][2] x被父亲控制的最小值  
//dp2为方案数

void dfs(int x,int fa){
	dp1[x][0]=1;
	dp1[x][1]=INF;
	dp1[x][2]=0;
	dp2[x][0]=dp2[x][1]=dp2[x][2]=1;
	for(int y : E[x]){
		if(y!=fa){
			dfs(y,x);
            //如果一个点被自己控制，那它的儿子结点无论怎样都合法
			long long minv=min(min(dp1[y][0],dp1[y][1]),dp1[y][2]);
			long long cnt=0;
			if(dp1[y][0]==minv) cnt=(cnt+dp2[y][0])%mod; 
			if(dp1[y][1]==minv) cnt=(cnt+dp2[y][1])%mod;
			if(dp1[y][2]==minv) cnt=(cnt+dp2[y][2])%mod;
			dp1[x][0]+=minv;
			dp2[x][0]=dp2[x][0]*cnt%mod;
			
            //如果一个结点x被儿子y控制，有几种情况
            //1.所有y中有一个被自己控制，其他y被儿子控制，在所有y中取min,即dp1[x][1]+min(dp1[y][0],dp1[y][1])。dp1[x][1]起保存当前答案作用
            //2.x被父亲控制，y被自己控制
			minv=min(dp1[x][1]+min(dp1[y][0],dp1[y][1]),dp1[x][2]+dp1[y][0]);
			cnt=0;
			if(dp1[x][1]+dp1[y][0]==minv) cnt=(cnt+dp2[y][0])%mod; 
			if(dp1[x][1]+dp1[y][1]==minv) cnt=(cnt+dp2[y][1])%mod; 
			dp1[x][1]=minv;
			dp2[x][1]=dp2[x][1]*cnt%mod;
			if(dp1[x][2]+dp1[y][0]==minv)dp2[x][1]=(dp2[x][1]+(dp2[y][0]*dp2[x][2]%mod))%mod; 
			
            //如果一个结点x被父亲控制，那它的儿子y一定不被x控制，且y也不能控制x,y只能被自己的儿子控制
			dp1[x][2]+=dp1[y][1];
			dp2[x][2]=dp2[x][2]*dp2[y][1]%mod;
		}
	}
#ifdef DEBUG
	printf("node %d: (%lld,%lld,%lld)\n",x,dp1[x][0],dp1[x][1],dp1[x][2]);
	
#endif
} 
int main(){
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,0);
	long long minv=min(dp1[1][0],dp1[1][1]);
	long long cnt=0;
	if(dp1[1][0]==minv) cnt=(cnt+dp2[1][0])%mod;
	if(dp1[1][1]==minv) cnt=(cnt+dp2[1][1])%mod;
	printf("%lld\n%lld\n",minv,cnt);
}
```



## T2

http://119.29.55.79/problem/3158

>Byteman想在花园中选择两块矩形的区域分别交给两个园丁看管。而且这两个矩形区域必须不能相交或者重叠，但可以有公共边，并且每一个区域要恰好包含K朵玫瑰花。
> 求这两个区域周长和的最小值

预处理每一列i向左，向右取和为k的矩形的最小周长，同理处理每一行向上，向下

我们以每一列向左为例。先枚举列数i，再从i->0枚举左边界j，同时维护j~i每一行的和sum[k].然后维护两个指针l,r。利用sum尺取出sum[r]-sum[l]=k的时候，然后更新答案

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 250
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

int L,W,n,K;
int a[maxn+5][maxn+5];
int sum[maxn+5];
int leftv[maxn+5];
int rightv[maxn+5];
int upv[maxn+5];
int downv[maxn+5];
void get_left() {
	for(int i=1; i<=L; i++) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j>=1; j--) {
			for(int k=1; k<=W; k++) {
				sum[k]+=a[j][k];
			}
			int l=1,tot=0;
			for(int r=1; r<=W; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K) ans=min(ans,2*(i-j+1)+2*(r-l+1));
			}
		}
		leftv[i]=ans;
	}
}
void get_right() {
	for(int i=L; i>0; i--) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j<=L; j++) {
			for(int k=1; k<=W; k++) {
				sum[k]+=a[j][k];
			}
			int l=1,tot=0;
			for(int r=1; r<=W; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K) ans=min(ans,2*(j-i+1)+2*(r-l+1));
			}
		}
		rightv[i]=ans;
	}
}
void get_down() {
	for(int i=1; i<=W; i++) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j>=1; j--) {
			for(int k=1; k<=L; k++) {
				sum[k]+=a[k][j];
			}
			int l=1,tot=0;
			for(int r=1; r<=L; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K) ans=min(ans,2*(i-j+1)+2*(r-l+1));
			}
		}
		downv[i]=ans;
	}
}
void get_up() {
	for(int i=W; i>=1; i--) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j<=W; j++) {
			for(int k=1; k<=L; k++) {
				sum[k]+=a[k][j];
			}
			int l=1,tot=0;
			for(int r=1; r<=L; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K)ans=min(ans,2*(j-i+1)+2*(r-l+1));
			}
		}
		upv[i]=ans;
	}
}
int solve() {
	int ans=INF;
	for(int i=1; i<=L; i++) {
		for(int j=i+1; j<=L; j++) {
			ans=min(ans,leftv[i]+rightv[j]);
		}
	}
	for(int i=1; i<=W; i++) {
		for(int j=i+1; j<=W; j++) {
			ans=min(ans,downv[i]+upv[j]);
		}
	}
	return ans;
}
int main() {
	int x,y;
	qread(L);
	qread(W);
	qread(n);
	qread(K);
	for(int i=1; i<=n; i++) {
		qread(x);
		qread(y);
		a[x][y]++;
	}
	memset(leftv,0x3f,sizeof(leftv));
	memset(rightv,0x3f,sizeof(rightv));
	memset(upv,0x3f,sizeof(upv));
	memset(downv,0x3f,sizeof(downv));
	get_up();
	get_down();
	get_right();
	get_left();
#ifdef DEBUG
	for(int i=1;i<=L;i++) printf("%d ",leftv[i]); 
	printf("\n");
	for(int i=1;i<=L;i++) printf("%d ",rightv[i]);
	printf("\n");
	for(int i=1;i<=L;i++) printf("%d ",downv[i]); 
	printf("\n");
	for(int i=1;i<=L;i++) printf("%d ",upv[i]); 
	printf("\n");
#endif
	int ans=solve();
	if(ans==INF) printf("NO\n");
	else qprint(ans);
}
```



## T3

http://119.29.55.79/problem/3145

>给出排列p和数组a
>
>1.排列p的长度为n，并且$[1,n]$的每个数只在p中出现一次
>
>2.数组a的长度为m，并且$a[i] \in [1,n]$
>
>现在有多次查询，每次查询数组a中，$[l,r]$区间里面是否能够找得到排列p的一个循环移位。
>
>循环移位是指对于一个排列p,$(p_1,p_2,....,p_n)，(p_i,p_{i+1},....,p_n,p_1,p_2,....,p_{i-1}) ,i\in [1,n]$
>
>均为p的循环移位。比如(2,1,3)，它的循环移位有(2,1,3),(1,3,2),(3,2,1)

我们发现无论怎么循环，p[i]的下一位都是一样的。因此我们预处理出数x的下一个数pnex[x]

然后找出a[i]中的每一个数按照循环排列跳，跳到的下一个数的位置。可以从右往左扫描，记录数x在[i,,m]中最后一次出现的位置last[x],那么a[i]下一个位置就是last[pnex[a[i]]]

然后考虑倍增加速跳的过程，设$jump[i][j]$表示i跳$2^j$次调到的位置，像lca那样递推即可。如果跳出界就设为INF

```cpp
if(jump[i][j-1]==INF) jump[i][j]=INF; // 防止越界
else jump[i][j]=jump[jump[i][j-1]][j-1];
```

最后处理查询.从右往左扫描a,记录[i,n]中的数跳n-1次（跳n-1次就跳完一个循环排列）到达的最小位置f[i]。

如果f[l]<r,则[l,r]中一定存在解。因为(r,n]中的数不管怎么跳都要>r，那么[l,r]中只要有一个数跳n-1次还在[l,r]内，那么就合法

这种题的套路一般都是：**找出类似跳一段距离的模型，快速预处理倍增初始值$f[i][0]$,倍增,查询**

```cpp
//http://119.29.55.79/problem/3145
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200000
#define maxm 200000
#define maxlogn 20
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

int n,m,q;
int log2n;
int p[maxn+5];
int pnex[maxn+5];//数x在循环排列中的下一个数
int a[maxm+5];

//找到数x在排列中的位置i,p[i]->p[i+1]->p[i+2]这样跳
int jump[maxm+5][maxlogn+5];//a[i]跳2^j次到的位置
int last[maxm+5];//m->1遍历i,数a[i]在[i,m]中上一次出现的位置

int minpos[maxm+5];//表示[i,n]中的点跳n-1次跳到的位置的最小值

void ini_mul() {
	//这些数组都要memset成INF，INF表示找不到，跳出区域，如果设成0会有问题
	memset(last,0x3f,sizeof(last));
	for(int i=1; i<=n; i++) pnex[p[i]]=p[i%n+1];
	memset(jump,0x3f,sizeof(jump)) ;
	log2n=log2(n)+1;
	for(int i=m; i>=1; i--) {
		last[a[i]]=i;
		jump[i][0]=last[pnex[a[i]]];
	}
	for(int j=1; j<=log2n; j++) {
		for(int i=1; i<=m; i++) {
			if(jump[i][j-1]==INF) jump[i][j]=INF; // 防止越界
			else jump[i][j]=jump[jump[i][j-1]][j-1];
		}
	}
}
int query_mul(int x,int k) {
	for(int i=log2n; i>=0; i--) {
		if((1<<i)<=k) {
			k-=(1<<i);
			x=jump[x][i];
			if(x==INF) break;
		}
	}
	return x;
}

int ans[maxm+5];
int main() {
	int l,r;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=n; i++) {
		scanf("%d",&p[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d",&a[i]);
	}
	ini_mul();
	memset(minpos,0x3f,sizeof(minpos));
	for(int i=m; i>=1; i--) {
		minpos[i]=min(minpos[i+1],query_mul(i,n-1));
	}

	for(int i=1; i<=q; i++) {
		scanf("%d %d",&l,&r);
		if(minpos[l]<=r) ans[i]=1;
		else ans[i]=0;
	}
	for(int i=1; i<=q; i++) {
		printf("%d",ans[i]);
	}
}
```




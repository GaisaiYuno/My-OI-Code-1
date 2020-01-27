##　[Luogu P3825] [NOI2017] 游戏 (2-SAT)

###　题面

题面较长，略

### 分析

看到这些约束，应该想到这是类似2-SAT的问题。但是x地图很麻烦，因为k-SAT问题在k>2的时候是NPC问题，所以不能直接做。

观察到$d \leq 8$,我们可以直接枚举每个x地图可以让哪些车使用，然后把它转换成标准的2-SAT问题。由于可以用车bc,ac已经覆盖了所有情况，每个x地图只可能是种类A或种类B，枚举的时间复杂度$2^d$

对于枚举的每一种情况，我们现在已经得到了每个地图适合哪些车参加，然后考虑建图。

定义若每个地图可以参加的车种类为x和y,第一种车为x,y中字典序较小的，第二种车为字典序较大的。把每个地图拆成两个点，第一个点表示第一种车，第二个点表示第二种车

然后是限制

1.如果限制i的第一个地图$a_i$不适合型号为$x_i$的车，那么不做任何操作

2.如果限制i的第二个地图$b_i$不适合型号为$y_i$的车，那么$a_i$场不能选$h_i$,只能选$x_i$外符合条件的另一辆车，$b_i$场只能选除$y_i$外符合条件的另一辆车。两辆车对应的点之间连边即可

3.如果1,2的情况都满足，只需要判断一下可以选的车即可，细节比较复杂，见代码

建完图之后跑2-SAT即可,输出答案的时候注意判断一下这个点对应的车种类到底是A,B还是C

时间复杂度$O(2^d(n+m))$

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define maxn 100000 
using namespace std;
int n,m,d;
char s[maxn+5];

vector<int>E[maxn*2+5];
void add_edge(int u,int v){
	E[u].push_back(v);
}

int dfn[maxn*2+5];
int low[maxn*2+5];
stack<int>st;
int cnt=0,tim=0;
int bel[maxn*2+5];
bool ins[maxn*2+5];
void tarjan(int x){
	dfn[x]=low[x]=++tim;
	st.push(x);
	ins[x]=1;
	for(int y : E[x]){
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]); 
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		int y;
		do{
			y=st.top();
			st.pop();
			ins[y]=0;
			bel[y]=cnt;
		}while(y!=x); 
	}
}


int cntx;
int all_pos[maxn+5];
int a[maxn+5],b[maxn+5];
char h1[maxn+5],h2[maxn+5];
void ini(){
	cnt=0;
	tim=0;
	for(int i=1;i<=n*2;i++) E[i].clear();
	for(int i=1;i<=n*2;i++)  dfn[i]=low[i]=bel[i]=ins[i]=0;
	while(!st.empty()) st.pop();
}
void make_graph(int bin){
	for(int i=1;i<=d;i++){
		if(bin&(1<<(i-1))) s[all_pos[i]]='A';
		else s[all_pos[i]]='B';
	}
	for(int i=1;i<=m;i++){
		if(h1[i]==s[a[i]]) continue;//第a[i]位不能选h1[i]
		else if(h2[i]==s[b[i]]){// 第b[i]位不能选h2[i] 
			//判断一下当前选的车按字典序是第一辆还是第二辆 
			if(h1[i]=='C'||(h1[i]=='B'&&s[a[i]]=='C')) add_edge(a[i]+n,a[i]); //规则中选C，或规则中选B且不能选C 
			else add_edge(a[i],a[i]+n) ;
		}else{
			int add1,add2;
			if(h1[i]=='C'||(h1[i]=='B'&&s[a[i]]=='C')) add1=n;
			else add1=0;
			if(h2[i]=='C'||(h2[i]=='B'&&s[b[i]]=='C')) add2=n;
			else add2=0;
			add_edge(a[i]+add1,b[i]+add2);
			add_edge(b[i]+n-add2,a[i]+n-add1); 
		} 
	}
}
bool check(){
	for(int i=1;i<=n*2;i++){
		if(!dfn[i]) tarjan(i);
	} 
	for(int i=1;i<=n;i++){
		if(bel[i]==bel[i+n]) return 0;
	}
	return 1;
} 
void print_ans(){
	for(int i=1;i<=n;i++){
		if(bel[i]<bel[i+n]){
			if(s[i]=='A') putchar('B');//BC的第1个是B 
			else putchar('A'); //AC或AB的第1个是A 
		}else{
			if(s[i]=='C') putchar('B');//AB的第2个是B 
			else putchar('C'); //BC或AC的第2个是A 
		} 
	}
}
int main(){
	char tmp1[2],tmp2[2]; 
	scanf("%d %d",&n,&d);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='x'){
			cntx++;
			all_pos[cntx]=i;
		}
		s[i]=s[i]-'a'+'A'; 
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %s %d %s",&a[i],tmp1,&b[i],tmp2);
		h1[i]=tmp1[0];
		h2[i]=tmp2[0];
	} 
	for(int bin=0;bin<(1<<d);bin++){
		//暴力枚举x是哪一种，注意b,c和a,c就可以覆盖x的三种取值
		//所以只要枚举a,b,c 
		ini();
		make_graph(bin); 
		if(check()){
			print_ans();
			return 0;
		}
	}
	printf("-1"); 
}

```




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
		if(h1[i]==s[a[i]]) continue;//��a[i]λ����ѡh1[i]
		else if(h2[i]==s[b[i]]){// ��b[i]λ����ѡh2[i] 
			//�ж�һ�µ�ǰѡ�ĳ����ֵ����ǵ�һ�����ǵڶ��� 
			if(h1[i]=='C'||(h1[i]=='B'&&s[a[i]]=='C')) add_edge(a[i]+n,a[i]); //������ѡC���������ѡB�Ҳ���ѡC 
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
			if(s[i]=='A') putchar('B');//BC�ĵ�1����B 
			else putchar('A'); //AC��AB�ĵ�1����A 
		}else{
			if(s[i]=='C') putchar('B');//AB�ĵ�2����B 
			else putchar('C'); //BC��AC�ĵ�2����A 
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
		//����ö��x����һ�֣�ע��b,c��a,c�Ϳ��Ը���x������ȡֵ
		//����ֻҪö��a,b,c 
		ini();
		make_graph(bin); 
		if(check()){
			print_ans();
			return 0;
		}
	}
	printf("-1"); 
}


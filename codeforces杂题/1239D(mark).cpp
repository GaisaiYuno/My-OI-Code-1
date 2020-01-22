#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack> 
#define maxn 1000000
using namespace std;
int t,n,m;
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
vector<int>bcc[maxn*2+5];
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
            bcc[cnt].push_back(y); 
        }while(y!=x); 
    }
}

bool is_jury[maxn*2+5];
void ini(){
	for(int i=1;i<=n*2;i++){
		E[i].clear();
		bcc[i].clear();
		bel[i]=dfn[i]=low[i]=0;
		is_jury[i]=0;
	}
	cnt=tim=0;
}


int main(){
	int u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			if(u==v) continue;
			E[u].push_back(v);
		}
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
		if(cnt==1) printf("No\n");
		else{
			printf("Yes\n");
			printf("%d %d\n",bcc[1].size(),n-bcc[1].size());
			for(int x : bcc[1]) {
				is_jury[x]=1;
				printf("%d ",x); 
			}
			printf("\n");
			for(int i=1;i<=n;i++){
				if(!is_jury[i]) printf("%d ",i); 
			} 
			printf("\n"); 
		}
	}
}

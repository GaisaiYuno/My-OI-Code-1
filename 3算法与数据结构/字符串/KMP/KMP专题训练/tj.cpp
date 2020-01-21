#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[500010];int n,cnt,maxgap,fail[500010],pre[500010],suc[500010],first[500010],ans[500010],tot;
struct edge{//fail树上的边
    int to,next;
}e[500010];
void add(int u,int v){
    e[++cnt]=(edge){v,first[u]};first[u]=cnt;
}
void getfail(){//求next数组（我的代码里叫fail）
    int i,j=0;
    for(i=1;i<n;i++){
        while(j&&(a[i]!=a[j])) j=fail[j];
        j+=(a[i]==a[j]);fail[i+1]=j;
    }
    for(i=1;i<=n;i++) add(fail[i],i);
}
void del(int x){//链表删除操作，O(1)
    suc[pre[x]]=suc[x];
    pre[suc[x]]=pre[x];
    maxgap=max(maxgap,suc[x]-pre[x]);suc[x]=pre[x]=0;
}
int q[500010];
void bfs(int s,int avoid){//s的子树中，避开avoid的子树，其余点全部从链表里面删掉
    int u,v,i,head=0,tail=1;q[0]=s;
    while(head<tail){
        u=q[head++];if(u==avoid) continue;
        del(u);
        for(i=first[u];~i;i=e[i].next){
            v=e[i].to;q[tail++]=v;
        }
    }
}
int main(){
    memset(first,-1,sizeof(first));memset(fail,0,sizeof(fail));int i,j;
    scanf("%s",a);n=strlen(a);
    getfail();
    for(i=n;i;i=fail[i]) ans[++tot]=i;ans[tot+1]=0;
    for(i=1;i<=n;i++) pre[i]=i-1,suc[i]=i+1;
    maxgap=1;
    for(i=tot;i>=1;i--){
        bfs(ans[i+1],ans[i]);
        if(maxgap<=ans[i]){
            printf("%d",ans[i]);return 0;
        }
    }
}

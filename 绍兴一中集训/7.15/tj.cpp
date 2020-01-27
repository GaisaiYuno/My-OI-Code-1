#include<bits/stdc++.h>
using namespace std;
const int M=1005;
int A[M],n,sum[M];
//一条线段上有24个点
//n条线段[T[i],T[i]+7]
//选用这些线段去覆盖
//满足i点至少被覆盖A[i]次
//dis[i]:0到i点用了几个员工
int asdf,head[M];
struct edge{
    int to,nxt,cost;
}G[M];
void add_edge(int a,int b,int c){
	printf("%d->%d cost=%d\n",a,b,c); 
    G[++asdf].to=b;
    G[asdf].nxt=head[a];
    G[asdf].cost=c;
    head[a]=asdf;
}
int cnt[M],dis[M];
bool vis[M];
bool spfa(int S){
    queue<int>Q;
    for(int i=0;i<=48;i++){
        dis[i]=-1;
        cnt[i]=0;
        vis[i]=0;
    }
    Q.push(S);
    dis[S]=0;
    vis[S]=1;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=G[i].nxt){
            int y=G[i].to;
            if(dis[y]<dis[x]+G[i].cost){
                dis[y]=dis[x]+G[i].cost;
                if(!vis[y]){
                    if(++cnt[y]>48)return 0;
                    vis[y]=1;
                    Q.push(y);
                }
            }
        }
    }
    return 1;
}
bool check(int mid) {
    //dis[i]-dis[i-8]>=A[i]

    //dis[i]-dis[i-1]>=0
    //dis[i]-dis[i-1]<=sum[i];

    //dis[i]-dis[i-24]>=mid
    //dis[i]-dis[i-24]<=mid

    asdf=0;
    for(int i=0;i<=48;i++){
        head[i]=0;
    }
    for(int i=1;i<=48;i++){
        if(i>=8){
            //dis[i]>=A[i]+dis[i-8]
            add_edge(i-8,i,A[i]);
        }
        //dis[i]>=0+dis[i-1]
        add_edge(i-1,i,0);
        //dis[i-1]>=dis[i]-sum[i]
        add_edge(i,i-1,-sum[i]);
        if(i>=24){
            //dis[i]>=dis[i-24]+mid
            add_edge(i-24,i,mid);
            //dis[i-24]>=dis[i]-mid
            add_edge(i,i-24,-mid);
        } 
    } 
    return spfa(0);
}
int main() {
    int cas,x;
    scanf("%d",&cas);
    while(cas--) {
        for(int i=1; i<=24; i++) {
            scanf("%d",&A[i]);
            sum[i]=0;
        }
        scanf("%d",&n);
        for(int i=1; i<=n; i++) {
            scanf("%d",&x);
            sum[x+1]++;
        }
        for(int i=1;i<=24;i++){
            A[i+24]=A[i];
            sum[i+24]=sum[i];
        }
        int L=0,R=n,ans=-1;
        while(L<=R) {
            int mid=L+R>>1;
            if(check(mid)) {
                ans=mid;
                R=mid-1;
            } else {
                L=mid+1;
            }
        }
        if(ans==-1)printf("No Solution\n");
        else printf("%d\n",ans);
    }
    return 0;
}


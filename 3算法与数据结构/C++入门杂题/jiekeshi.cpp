#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define INF (0x7f7f7f7f)
#define N (1000005)
using namespace std;
int Use[N],P[N],n,m,ans=0;
struct order{
    int L,R,val;
}A[N]; 
bool judge(int x){
    //printf("%d\n",x);
    memset(Use,0,sizeof(Use));
    for(int i=1;i<=x;i++)Use[A[i].L]+=A[i].val,Use[A[i].R+1]-=A[i].val;
    //for(int i=1;i<=n;i++)printf("%d ",Use[i]);
    //printf("\n");
    int now=0;
    for(int i=1;i<=n;i++){
        now+=Use[i];
        if(now>P[i])return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&P[i]);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&A[i].val,&A[i].L,&A[i].R);
    int L=1,R=m;
    while(L<=R){
        int mid=(L+R)/2;
        if(judge(mid))L=mid+1,ans=mid;else R=mid-1;
    }
    if(ans<m){
        printf("-1\n");
        printf("%d",ans+1);
    }else printf("0");
    return 0;
}


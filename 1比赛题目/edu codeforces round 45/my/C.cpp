#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector> 
#include<algorithm>
#define addv 300005
#define maxn 2*addv
using namespace std;
int n;
char str[maxn];
int cnt;
int l[maxn];
int r[maxn];
vector<int>table[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",str);
        int len=strlen(str);
        l[i]=maxn;
        cnt=0;
        for(int j=0;j<len;j++){//像分析中一样求l[i],r[i]
            if(str[j]=='(') cnt++;
            else cnt--;
            l[i]=min(l[i],cnt);
        }
        r[i]=cnt;
        table[r[i]+addv].push_back(l[i]);//hash,为了防止负数人为加上addv,addv就相当于新的零点
    }
    for(int i=1;i<maxn;i++) if(table[i].size()!=0) sort(table[i].begin(),table[i].end());//排序,为了二分查找
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(l[i]>=0){
            int tmp=addv-r[i];//即-r[i]
            ans+=table[tmp].end()-lower_bound(table[tmp].begin(),table[tmp].end(),-r[i]);//lower_bound返回第一个>=x的位置,用结尾去-它,可求出l[j]=r[j]=-r[i]的j的个数
        }
    }
    printf("%I64d\n",ans);
} 

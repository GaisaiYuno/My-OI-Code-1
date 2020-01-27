/*
https://www.luogu.org/problemnew/show/U76944
�������е�iλ�Ķ����Ʊ�ʾ���±�i�Ĺ�ϵ
�۲�������
�±�: 00 01 10 11
���У�01 00 11 12
���Ƿ��֣���i=2��ʱ��i�ĵ�1λ��1��p[i]��0�����1�� 
    �ܽ�һ�£�i�Ķ����Ʊ�ʾ�ӵ͵��ߵĵ�1��1��λ�ü�Ϊtmp��lowbit��,������Ҫȡ����tmpλ����������һ������kλ��ͬ
    ����tmpλ�ߵ����ֲ���

��dp[pos][now]��ʾ��ǰ�������е�k��λ�ã�p[pos-1]=nowʱ����С
���ҳ�tmp�� ��now��tmpλȡ������0~tmp-1λ����ȡ������ת�Ƶ���һ����nex
dp[pos][now]=min(dp[pos][now],dp[pos+1][nex]+dist(pos+1,nex) 
�ü��仯����ʵ�֣�
ö��n O(n), ö��0~tmp-1λO(2^{k-1})����tmp O(k) 
ʱ�临�Ӷ�O(n*2^{k-1}*k)=O(n^2logn) 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000
#define INF 0x3f3f3f3f
using namespace std;
int n,k;
int w[maxn+5][maxn+5],dp[maxn+5][maxn+5];
int dfs(int pos,int now){
    if(pos==n) return 0;
    if(dp[pos][now]!=INF) return dp[pos][now];
    int tmp=0,bin=pos;
    while(tmp<k&&(bin&1)==0){
        tmp++;
        bin>>=1;
    }//ע�⣬���pos=0,tmp=k 
    int all=(1<<tmp); //�����tmpʵ�����������tmp-1 ���������Է��㴦��tmp=1�ı߽���� 
    int nex=now^all;
    nex=nex>>(tmp)<<(tmp);//���ƹ�ȥ�����ƻ�������0~tmp-1��0
    dp[pos][now]=INF;
    for(int i=0;i<all;i++){
        dp[pos][now]=min(dp[pos][now],w[now][nex+i]+dfs(pos+1,nex+i));
    } 
    return dp[pos][now];
}

int main(){
    scanf("%d",&k);
    n=(1<<k);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
    }
    memset(dp,0x3f,sizeof(dp));
    printf("%d\n",dfs(0,n));
}

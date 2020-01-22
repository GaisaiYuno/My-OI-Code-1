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
        for(int j=0;j<len;j++){//�������һ����l[i],r[i]
            if(str[j]=='(') cnt++;
            else cnt--;
            l[i]=min(l[i],cnt);
        }
        r[i]=cnt;
        table[r[i]+addv].push_back(l[i]);//hash,Ϊ�˷�ֹ������Ϊ����addv,addv���൱���µ����
    }
    for(int i=1;i<maxn;i++) if(table[i].size()!=0) sort(table[i].begin(),table[i].end());//����,Ϊ�˶��ֲ���
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(l[i]>=0){
            int tmp=addv-r[i];//��-r[i]
            ans+=table[tmp].end()-lower_bound(table[tmp].begin(),table[tmp].end(),-r[i]);//lower_bound���ص�һ��>=x��λ��,�ý�βȥ-��,�����l[j]=r[j]=-r[i]��j�ĸ���
        }
    }
    printf("%I64d\n",ans);
} 

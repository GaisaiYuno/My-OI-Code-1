//��������
//1.һ��ģ�崮A��Ҫ����ı���B�Ĺ���ǰ��׺
//2.���һ��ģ�崮A����һ��ģ�崮B��Ҳ����B���Ը���A������ôB�Ǳ�A���ŵ�һ����
//3.���ģ�崮A������ȫ�����ı���B����ôA��B�е�ƥ��λ�ã����տ�ͷ�㣩֮��Ŀո������ᳬ��A�ĳ���
//������1�����г���ֻ��Ϊnext[n],next[next[n]]...
//�����ܵĳ��ȴ�����飬����ÿ�����ȣ������ԭ������ƥ��
//�Ż������ڳ���a����¼��Զ��ƥ��λ��mx����������һ������Ϊb��ģ�崮����b<mx����a������ȫ����b
//      ��bһ��û��a�š�����a�����У�bһ��Ҳ�����У�ֱ������ 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
using namespace std;
int n,m,sz;
int next[maxn];
int f[maxn];
int len[maxn];
char a[maxn],b[maxn];
int mx;
int check(int m){
    for(int i=1,j=0;i<=n;i++){
        while(j>0&&(j==m||b[i]!=a[j+1]) )j=next[j];
        if(b[i]==a[j+1]) j++;
        f[i]=j;
    }
    bool flag=false;
    int last=1;
    for(int i=1;i<=n;i++){
        if(f[i]==m){
            flag=true;
            if(i-last-1>=m) return 0;
            last=i;
            mx=max(mx,i);
        }
    }
    if(flag) return 1;
    else return 0;
}
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    next[1]=0;
    for(int i=1;i<=n;i++) b[i]=a[i];
    for(int i=2,j=0;i<=n;i++){
        while(j>0&&a[i]!=a[j+1]) j=next[j];
        if(a[i]==a[j+1]) j++;
        next[i]=j;
    }
    sz=0;
    for(int i=n;i;i=next[i]){
        len[++sz]=i;
    }
    int ans=n;
    for(int i=sz;i>=0;i--){
    	if(len[i]<=mx) continue;
        if(check(len[i])){
            ans=len[i];
            break;
        }
    }
    printf("%d\n",ans);
} 

//三条性质
//1.一个模板串A是要求的文本串B的公共前后缀
//2.如果一个模板串A有另一个模板串B（也就是B可以覆盖A），那么B是比A更优的一个解
//3.如果模板串A可以完全覆盖文本串B，那么A在B中的匹配位置（按照开头算）之间的空格数不会超过A的长度
//由性质1得序列长度只能为next[n],next[next[n]]...
//将可能的长度存进数组，对于每个长度，将其和原串进行匹配
//优化：对于长度a，记录最远的匹配位置mx，若存在另一个长度为b的模板串，且b<mx，则a可以完全覆盖b
//      故b一定没有a优。由于a不可行，b一定也不可行，直接跳过 
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

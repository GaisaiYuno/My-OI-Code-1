#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 1000
#define maxm 1000
using namespace std;
int n,m;
int a[maxn+5];
char s[maxn+5][maxm+5];
char rt[maxm+5];
int cnt[30];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]); 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=5;j++) cnt[j]=0;
		for(int j=1;j<=n;j++){
			cnt[s[j][i]-'A'+1]++;
		}
		int maxc=0;
		char res;
		for(int j=1;j<=5;j++){
			if(cnt[j]>maxc){
				maxc=cnt[j];
				res='A'+j-1;
			}
		}
		rt[i]=res;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			if(s[i][j]==rt[j]) sum+=a[j];
		}
		ans+=sum; 
	}
	printf("%I64d\n",ans);
}


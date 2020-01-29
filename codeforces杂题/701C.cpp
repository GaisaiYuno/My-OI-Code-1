#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 100005
using namespace std;
int n;
char a[maxn];
int cnt[maxn]; 
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	int total=0;
	for(int i=1;i<=n;i++){
		if(!cnt[a[i]-'A']){
			total++;
		}
		cnt[a[i]-'A']++;
	}
	memset(cnt,0,sizeof(cnt));
	int l=1,r=1,num=0;
	int ans=n;
	while(r<=n){
		if(cnt[a[r]-'A']==0) num++;
		cnt[a[r]-'A']++;
		if(num==total){
			while(1){
				if(cnt[a[l]-'A']==1) break;
				else cnt[a[l]-'A']--;
				l++;
			}
			ans=min(ans,r-l+1);
		}
		r++;
	}
	printf("%d\n",ans);
} 

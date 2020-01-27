#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
using namespace std;
int n;
char a[maxn],b[maxn];
int cnt1[26],cnt2[26];
int c[maxn];
int ans=0;
int main(){
	scanf("%d",&n);
	scanf("%s",a);
	scanf("%s",b);
	for(int i=0;i<n;i++){
		cnt1[a[i]-'a']++;
		cnt2[b[i]-'a']++; 
	}
	for(int i=0;i<26;i++){
		if(cnt1[i]!=cnt2[i]){
			printf("-1");
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			for(int j=i+1;j<n;j++){
				if(a[j]==b[i]){
					for(int k=j-1;k>=i;k--){
//						printf("%s\n",a);
						swap(a[k],a[k+1]);
						c[++ans]=k+1;
					}
				}
			}
		} 
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d ",c[i]);
	}
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#define maxv 105
#define maxn 105 
using namespace std;
int n;
int a[maxn];
int cnt[maxv];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int cnt1=0,cnt3=0;
	for(int i=0;i<=maxv;i++){
		if(cnt[i]==1){
			cnt1++;
		}
		if(cnt[i]>=3){
			cnt3++;
		}
	}
	if(cnt1%2==1){
		if(cnt3==0) printf("NO\n");
		else{
			printf("YES\n");
			cnt3=0;
			int tmp=0;
			for(int i=1;i<=n;i++){
				if(cnt[a[i]]==1&&tmp<cnt1/2){
					tmp++;
					printf("B");
				}else if(cnt[a[i]]>=3){
					cnt3++;
					if(cnt3==1) printf("B");
					else printf("A");
				}else printf("A");
			}
		}
	}else{
		cnt1=0;
		printf("YES\n");
		for(int i=1;i<=n;i++){
			if(cnt[a[i]]==1){
				cnt1++;
				if(cnt1%2) printf("A");
				else printf("B"); 
			}else printf("B"); 
		}
	}
}
/*
12
1 2 3 4 5 5 6 6 6 7 9 11

5
2 1 1 1 1
*/

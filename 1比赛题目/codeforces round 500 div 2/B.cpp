#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 100005
using namespace std;
int n,x;
int a[maxn],cnt1[maxn],cnt2[maxn];
map<int,int>ma;
int main(){
	scanf("%d",&n);
	scanf("%d",&x);
	bool flag0=false;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt1[a[i]]++;
		if(cnt1[a[i]]>1) flag0=true;
	}
	if(flag0){
		printf("0\n");
	}else{
		bool flag1=false,flag2=false;
		for(int i=1;i<=n;i++){
			int tmp=a[i]&x;
			if(cnt1[tmp]&&a[i]!=tmp){
				flag1=true;
				break;
			}
			cnt2[tmp]++;
			if(cnt2[tmp]>1){
				flag2=true;
			}
		}
		if(flag1) printf("1\n");
		else if(flag2)printf("2\n");
		else printf("-1\n");
	}
}


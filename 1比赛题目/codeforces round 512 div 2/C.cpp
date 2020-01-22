#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n;
int a[maxn];
int check(int x){
	int tmp=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		tmp+=a[i];
		if(tmp==x){
			cnt++;
			tmp=0;
		}
	}
	if(tmp==0&&cnt>1) return 1;
	else return 0;
}
int main(){
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
		sum+=a[i];
	} 
	bool flag=false;
	for(int i=0;i<=sum;i++){
		if(check(i)){
			flag=true;
			break;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
}

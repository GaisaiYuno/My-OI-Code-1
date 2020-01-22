#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	int l,r,cnt;
	cnt=0;
	l=1;
	r=1;
	for(int i=1;i<=n;){
		if(a[i]>a[i+1]&&i+1<=n){
			l=i;
			while(a[i]>a[i+1]&&i+1<=n){
			    i++;
			}
			r=i;
			cnt++;
			for(int i=l;i<=(l+r)/2;i++) swap(a[i],a[l+r-i]);
		}
		else i++;
	}
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			cnt++;
			break;
		} 
	}
	if(cnt>1) printf("no\n");
	else{
		printf("yes\n");
		printf("%d %d\n",l,r);
	}

}

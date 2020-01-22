#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000005
using namespace std;
int n;
int a[maxn];
int tmp[maxn];
long long ans=0;
void merge_sort(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(a[i]>a[j]){
			tmp[k++]=a[j++];
			ans+=mid-i+1;
		}else{
			tmp[k++]=a[i++];
		}
	}
	while(i<=mid) tmp[k++]=a[i++];
	while(j<=r) tmp[k++]=a[j++];
	for(int u=l;u<=r;u++) a[u]=tmp[u];
}

char s1[maxn];
char s2[maxn];
queue<int>q[30];
int main(){
	scanf("%d",&n);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	for(int i=1;i<=n;i++){
		q[s2[i]-'A'+1].push(i);
	}
	for(int i=1;i<=n;i++){
		a[i]=q[s1[i]-'A'+1].front();
		q[s1[i]-'A'+1].pop();
	}
	merge_sort(1,n);
	printf("%lld\n",ans);
} 

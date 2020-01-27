#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 200005
using namespace std;
struct node{
	int id;
	int pos;
};
map<int,node>ma;
int a[maxn];
int k,n;
int main(){
	bool flag=false;
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int sum=0;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[j]);
			sum+=a[j];
		}
		for(int j=1;j<=n;j++){
			if(ma.count(sum-a[j])){
				if(ma[sum-a[j]].id==i) continue;
				flag=true;
				printf("YES\n");
				printf("%d %d\n",ma[sum-a[j]].id,ma[sum-a[j]].pos);
				printf("%d %d\n",i,j);
				return 0;
			}else{
				ma[sum-a[j]].id=i;
				ma[sum-a[j]].pos=j;
			}
		}
		
	}
	if(!flag) printf("NO\n");
	return 0;
}

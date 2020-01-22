#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

struct Num{
	int v;
	int arr[15];
}a[1009];

bool operator <(Num one,Num two){
	return one.v<two.v;
}

void change(int val,int ans[]){
	ans[0]=0;
	while (val){
		ans[++ans[0]]=val%10;
		val/=10;
	}
	return;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i].v);
		change(a[i].v,a[i].arr);
	}
	sort(a+1,a+n+1);
	int x,num[15],p2,p1,len;
	for (int i=1;i<=q;i++){
		scanf("%d%d",&len,&x);
		change(x,num);
		p1=0;
		for (int i=1;i<=n;i++){
			if (a[i].arr[0]<num[0]){
				continue;
			}
			p2=1;
			for (int j=1;j<=num[0];j++){
				if (a[i].arr[j]!=num[j]){
					p2=0;
					break;
				}
			}
			if (p2){
				printf("%d\n",a[i].v);
				p1=1;
				break;
			}
		}
		if (!p1){
			printf("-1\n");
		}
	}
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/

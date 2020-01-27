/*
Problem:堆积木
Source:http://119.29.55.79/contest/23/problem/3
Description:
设dp[i]是第i个积木在自己的位置上时，前i个积木中最多能归位的数目。
dp[i]=max{dp[j]|i>j,a[i]>a[j],a[i]-a[j]<=i-j}+1
其中a[i]>a[j]是保证i,j都在自己的位置上，a[i]-a[j]<=i-j是为了保证中间有足够的积木让i能在a[i]这个位置上。
转换一下发现有三个条件:
i>j (1) 
i-a[i]>=j-a[j] (2)
a[i]>a[j] (3)
发现 (2)+(3)就可以得到(1)
所以只剩两个条件
那么就只要按照i-a[i]排序求LIS即可。 
由于i-a[i]相等时，a[i]升序就可以使答案最大化，所以排序的时候第二关键字要弄成a[i]。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
struct node{
	int key;
	int val;
	friend bool operator < (node p,node q){
		if(p.key==q.key) return p.val<q.val;
		else return p.key<q.key;
	}
}b[maxn];
int s[maxn];
int top=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i].key=i-a[i];
		b[i].val=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(b[i].key<0) continue;//如果i-a[i]<0,即a[i]>i,则i肯定不能在合适的位置上，直接跳过 
		if(b[i].val>s[top]){
			s[++top]=b[i].val;
		}else{
			int pos=lower_bound(s+1,s+1+top,b[i].val)-s;
			s[pos]=b[i].val;
		}
	}
	printf("%d\n",top);
}



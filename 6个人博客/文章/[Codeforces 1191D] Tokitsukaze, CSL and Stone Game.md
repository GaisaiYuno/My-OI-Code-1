## [Codeforces 1191D] Tokitsukaze, CSL and Stone Game

### 题面

有n堆石子，两个人轮流取石子，一次只能从某堆里取一颗。如果某个人取的时候已经没有石子，或者取完后又两堆石子个数相同（个数为0也算）。假如两人都足够聪明，问谁能赢。

### 分析

贪心考虑，最后局面一定是0~n-1的一个排列。这时谁取谁就输。因此我把a[i]从小到大排序，把a[i]变成i-1,可以计算出取的石子个数$\sum (a_i-i+1)$,如果是奇数，则先手胜，否则后手胜。

但是要排除一些取1颗就会输的情况，记石子个数x的出现次数为cnt[x],有4种情况先手必败

$cnt[0]>1$

$ \exist x,cnt[x]>2$

$\exist x,y \ ,  cnt[x]>1,cnt[y]>1$

$\exist x, cnt[x]>1,cnt[x-1]>0$

###　代码

```cpp
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define maxn 100000 
using namespace std;
int n;
int a[maxn+5];
map<int,int>cnt;
bool check(){
	if(cnt.count(0)&&cnt[0]>1) return 0;
	for(auto x : cnt){//有出现次数超过2的 
		if(x.second>2) return 0;
	}
	int num=0;
	for(auto x : cnt){
		if(x.second>1) num++; 
	}
	if(num>=2) return 0;//有2个出现次数超过1的 
	for(auto x : cnt){
		if(x.second>1&&cnt.count(x.first-1)) return 0;
		//x出现>1次,x-1出现，无论先取x还是先取x-1都会造成相同 
	} 
	return 1;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	if(!check()){//检查初始情况
		printf("cslnb\n"); 
	}else{
		long long sum=0;
		//最优取法，从小取到大，第i堆取到i-1个，这样不会出现相同
		//因为是轮流取，再判断一下奇偶性，看看下一步谁取，取的就输 
		for(int i=1;i<=n;i++){
			sum+=a[i]-(i-1); 
		} 
		if(sum%2==1) printf("sjfnb\n");
		else printf("cslnb\n");
	}
	
}

```


### 题面

给出一个长度为n的排列a,每次可以交换序列的第i个和第j个元素，当且仅当$2 \times |i-j| \geq n$,求一种交换方案，让序列从小到大排好序

###　分析

重点是考虑我们怎么把第x个数换到第i个位置上，且尽量不破坏其他数的位置

我们用序列的第1,n个数作为跳板，如果与n的距离满足条件就与n交换，否则与1交换，定义find(x)为x应该和谁交换。

1.把x与find(x)交换,此时x到了find(x)

2.find(x)与find(i)交换,此时x到了find(i)

3.find(i)与i交换，此时x到了i

我们可以发现这样交换只会对1,n的数产生交换，其他无关数的位置不变。我们只要对2~n-1的数执行上述操作，最后我们再看看a[1]是不是1，然后判断需不需要交换(1,n)即可

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector> 
#define maxn 300005
using namespace std;

int n; 
vector< pair<int,int> >ans;
int a[maxn];
int pos[maxn];//值为i的数的位置 
inline int find(int x){
	if(2*(n-x)>=n) return n;
	else return 1;
} 
void change(int x,int y){
	ans.push_back(make_pair(x,y));
	swap(pos[a[x]],pos[a[y]]);
	swap(a[x],a[y]);
} 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=2;i<n;i++){
		int t=pos[i];
		change(t,find(t));
		if(find(t)!=find(i)) change(find(t),find(i));
		change(i,find(i)); 
	}
	if(a[1]!=1) change(1,n);
	printf("%d\n",ans.size());
	for(auto p : ans){
		printf("%d %d\n",p.first,p.second); 
	} 
}

```






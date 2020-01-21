## [Luogu2870] [USACO07DEC]最佳牛线Best Cow Line(后缀数组)

### 题面

FJ打算带他的$N(1 \leq N \leq 30,000)$头奶牛去参加一年一度的“全美农场主大奖赛”。在这场比赛中，每个参赛者都必须让他的奶牛排成一列，然后领她们从裁判席前依次走过。 今年，竞赛委员会在接受队伍报名时，采用了一种新的登记规则：他们把所有队伍中奶牛名字的首字母取出，按它们对应奶牛在队伍中的次序排成一列（比如说，如果FJ带去的奶牛依次为Bessie、Sylvia、Dora，登记人员就把这支队伍登记为BSD）。登记结束后，组委会将所有队伍的登记名称按字典序升序排列，就得到了他们的出场顺序。 FJ最近有一大堆事情，因此他不打算在这个比赛上浪费过多的时间，也就是说，他想尽可能早地出场。于是，他打算把奶牛们预先设计好的队型重新调整一下。 FJ的调整方法是这样的：每次，他在原来队列的首端或是尾端牵出一头奶牛，把她安排到新队列的尾部，然后对剩余的奶牛队列重复以上的操作，直到所有奶牛都被插到了新的队列里。这样得到的队列，就是FJ拉去登记的最终的奶牛队列。 接下来的事情就交给你了：对于给定的奶牛们的初始位置，计算出按照FJ的调整规则所可能得到的字典序最小的队列。

###　分析

我们贪心从两边往中间删除。每一次我们需要决定是从队头删除还是队尾删除。显然应该删除字符更小的那个。但是两个字符相等的时候怎么办呢?

比如我们删除到$\text{CDADBC}$,显然删除右边的$\text{C}$更优,因为这样可以更早的取到字典序更小的字符串$\text{BD}$. 由于从队尾删除比较字典序要倒序比较，我们不如把字符串镜像反转再接在一起,变成$\text{CDA[x]DBCCBD[x']ADC}$(注意括号内的并不是字符，只是一个标记).那么对于两个C的中点x,我们找到中点x反转后的对应位置$x'$,容易发现，我们要比较的就是$x$和$x'$左侧的两个子串$\text{DA}$和$\text{BD}$,直接转换成比较对应的后缀rank大小即可。注意我们不需要对每次删除后的串跑一遍，只需要一开始的时候用后缀数组预处理整个串即可。



### 代码

```cpp

//https://www.luogu.com.cn/problem/P2870 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
#define maxs 128 
using namespace std;
int n;
char s[maxn*2+5];
char t[maxn*2+5];

void rsort(int *ans,int *fi,int *se,int sz,int maxv){
	static int buck[maxn*2+5];
	for(int i=0;i<=maxv;i++) buck[i]=0;
	for(int i=1;i<=sz;i++) buck[fi[i]]++;
	for(int i=1;i<=maxv;i++) buck[i]+=buck[i-1];
	for(int i=sz;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn*2+5],rk[maxn*2+5],height[maxn*2+5];
void suffix_sort(char *str,int n){
	static int se[maxn*2+5];
	for(int i=1;i<=n;i++){
		rk[i]=str[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,maxs);
	for(int k=1,m=maxs;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++){
			if(sa[i]>k) se[++p]=sa[i]-k;
		}
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		p=rk[sa[1]]=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p==n) break;
		m=p;
	}
}



bool cmp(int l,int r){
	if(s[l]<s[r]) return 0;
	else if(s[l]>s[r]) return 1;
	else{
		if(rk[l]<=rk[n*2-r+1]) return 0;
		else return 1;  
	}
	
}

char ans[maxn+5]; 
int main(){
	char ch[10];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",ch);
		s[i]=ch[0];
	}
	for(int i=1;i<=n;i++) t[i]=s[i];
	for(int i=1;i<=n;i++) t[n+i]=s[n-i+1];
//	get_height(t,n);
	suffix_sort(t,n*2);
	int l=1,r=n;
	int sz=0;
	while(l<=r){
		if(cmp(l,r)) ans[++sz]=s[r--];
		else ans[++sz]=s[l++];
	} 
	for(int i=1;i<=sz;i++){
		putchar(ans[i]);
		if(i%80==0) putchar('\n');
	}
} 
```






## [Codeforces1137B]Camp Schedule(KMP)

### 题面

给出两个01串S和T,要求把S重新排列，使得T在S中出现的次数最多。求重新排列后的S

### 分析

用贪心的思想,尽量用T首尾相连的去凑出S。比如S="00111",T="101",那么我们可以把两个101拼在一起，相同的前后缀合并,变成10101

发现要求公共前后缀,我们想到KMP。先对T跑一遍KMP求出nex数组,然后用cnt数组统计S中0,1出现次数。

我们记录当前T匹配到的位置j,如果S里还有足够的字符T[j],那就把这一位设为T[j]并--cnt[T[j]],否则结束。当j匹配到T末尾的时候要把j变成nex[j],表示重新匹配下一个,nex[j]即为前后缀重复部分。最后如果有剩下的0和1要全部输出。

### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 500000
using namespace std;
int n,m;
char s[maxn+5],t[maxn+5];
void get_nex(char* s,int n,int* nex){
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	} 
}

int nex[maxn+5];
int cnt[2];
int main(){
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1),m=strlen(t+1);
	get_nex(t,m,nex);
	for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
	for(int i=1,j=1;i<=n;i++){
		if(cnt[t[j]-'0']>0){
			putchar(t[j]);
			cnt[t[j]-'0']--;
		}else break;
		if(j==m) j=nex[j];
		j++;
	}
	while(cnt[0]>0){
		putchar('0');
		cnt[0]--;
	}
	while(cnt[1]>0){
		putchar('1');
		cnt[1]--;
	}
	
}

```




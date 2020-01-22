//对于长度为n的循环串，循环节的长度为n-next[n]
//所以问题可以转化成next数组
//若next[i]>0则s[i]=s[next[i]] （第i位循环节的一部分)
//若next[i]=0则需要构造，要求字典序最小，则第i位要尽量小
//则第i位一定不可以前面的匹配从而构成循环节，删去这些字母找个最小的就可以了
//所以第i位一定不是next[i]的候选项中的字符
//于是ai为其中未出现过的最小字符，又因为next的层层包含关系，所以等价于其中出现过的最大字符+1 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005 
using namespace std;
int a[maxn];
int pre[maxn];
int nex[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&pre[i]);
	}
	nex[0]=-1;
	for(int i=2;i<=n;i++){
		nex[i]=i-pre[i];
		if(nex[i]) a[i]=a[nex[i]];
		else{
			for(int j=nex[i-1];j>=0;j=nex[j]){
				a[i]=max(a[i],a[j+1]+1);
			} 
		} 
	}
	for(int i=1;i<=n;i++) printf("%c",a[i]+'a');
} 

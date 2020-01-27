//注意到每个房间可达的房间是连续的
//考虑预处理可达区间[l,r]
//我们可以用一定顺序合并预处理区间
//如若i+1不可达i,即i+1的钥匙在i左侧的房间里，这样i+1已经扩展完，那把i+1和i区间合并是可以的
//如果i+1可达i，那么合并之后可能还要继续更新，复杂度太大
//按不可达关系建图，按图的拓扑序合并区间
//如果合并的 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,p;
int main(){
	scanf("%d",&n);
} 

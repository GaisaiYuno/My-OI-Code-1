#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

namespace Solution
{

template <typename tp>
void read(tp &x)
{
	char ch=getchar();x=0;bool f=0;
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	if(f)x=-x;
}

pair<int,int>segment[100001];
bool mark[100001];

struct
{
	int l,r;
	int maxn,flag;
}tree[400001];

void build(int l,int r,int now=1)
{
	tree[now].l=l,tree[now].r=r;
	if(l==r)return;
	int mid=l+r>>1;
	build(l,mid,now<<1);
	build(mid+1,r,now<<1|1);
}

pair<int,int>point;

int main()
{
	
}
}

int main()
{
	return Solution::main();
}


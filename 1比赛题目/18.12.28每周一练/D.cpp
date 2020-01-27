/*
Problem:风铃[APIO2007]
Source:http://111.230.183.91/contest/14/problem/4
Algorithm:DFS
Description:
首先根据题目大意可以知道如果有风铃的深度差值大于1的话那么肯定是不合法的，风铃的深度就可以被看成高的和低的（雾）。

然后，我们要进行交换，但是交换其实并不会改变一个节点所在的子树，也就是说，你不可能把某一个子树从树里面分裂出来再放回去，所以，如果一个节点的左右两棵子树内全都又有高风铃，又有低风铃，那么肯定是无法交换完成的。

否则的话，一共有三种情况需要我们交换：

1.左边全都是深度低的，右边全都是深度高的

2.左边全是深度低的，右边深度高低的都有

3.左边深度高低的都有，右边全是深度高的。

因为我们是递归返回的时候从下向上进行交换，所以我们可以保证在某一层进行交换的时候，子树一定是有序的，所以以上三种情况我们每次交换只要交换一次既满足情况。同时我们可以返回的时候特判不合法情况，同时返回下一层情况。我的做法是用0,1,2来表示上面三种情况，直接返回即可。
*/
#include<iostream>
#include<cstdio>
#define all_high 0
#define all_low 1
#define high_low 2
#define maxn 100005
using namespace std;
int n;
struct node{
	int l;
	int r;
}tree[maxn]; 
int dmin,dmax;
int ans=0;
bool flag;
void dfs1(int x,int deep){
	if(x==-1){
		dmin=min(dmin,deep);
		dmax=max(dmax,deep);
		return; 
	}
	dfs1(tree[x].l,deep+1);
	dfs1(tree[x].r,deep+1);
}

int dfs2(int x,int deep){
	if(x==-1){
		if(deep==dmin) return all_high;
		else return all_low;
	}
	int a=dfs2(tree[x].l,deep+1);
	int b=dfs2(tree[x].r,deep+1);
	if((a==all_high&&b==all_low)) ans++;
	if((a==high_low&&b==all_low)) ans++;
	if((a==all_high&&b==high_low)) ans++;
	if(a==high_low||b==high_low){
		if(a==high_low&&b==high_low){
			flag=true;
			return high_low;
		}else return high_low; 
	}
	if(a==all_high&&b==all_high) return all_high;
	if(a+b==1) return high_low;
	if(a==all_low&&b==all_low) return all_low;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&tree[i].l,&tree[i].r);
	}
	dmax=0;
	dmin=n+1; 
	dfs1(1,0);
	if(dmax-dmin>1) printf("-1\n");
	else if(dmax==dmin) printf("0\n");
	else{
		flag=false;
		dfs2(1,0);
		if(flag) printf("-1\n");
		else printf("%d\n",ans);
	}
}


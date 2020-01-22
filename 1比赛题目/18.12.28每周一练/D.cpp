/*
Problem:����[APIO2007]
Source:http://111.230.183.91/contest/14/problem/4
Algorithm:DFS
Description:
���ȸ�����Ŀ�������֪������з������Ȳ�ֵ����1�Ļ���ô�϶��ǲ��Ϸ��ģ��������ȾͿ��Ա����ɸߵĺ͵͵ģ�����

Ȼ������Ҫ���н��������ǽ�����ʵ������ı�һ���ڵ����ڵ�������Ҳ����˵���㲻���ܰ�ĳһ����������������ѳ����ٷŻ�ȥ�����ԣ����һ���ڵ����������������ȫ�����и߷��壬���еͷ��壬��ô�϶����޷�������ɵġ�

����Ļ���һ�������������Ҫ���ǽ�����

1.���ȫ������ȵ͵ģ��ұ�ȫ������ȸߵ�

2.���ȫ����ȵ͵ģ��ұ���ȸߵ͵Ķ���

3.�����ȸߵ͵Ķ��У��ұ�ȫ����ȸߵġ�

��Ϊ�����ǵݹ鷵�ص�ʱ��������Ͻ��н������������ǿ��Ա�֤��ĳһ����н�����ʱ������һ��������ģ��������������������ÿ�ν���ֻҪ����һ�μ����������ͬʱ���ǿ��Է��ص�ʱ�����в��Ϸ������ͬʱ������һ��������ҵ���������0,1,2����ʾ�������������ֱ�ӷ��ؼ��ɡ�
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


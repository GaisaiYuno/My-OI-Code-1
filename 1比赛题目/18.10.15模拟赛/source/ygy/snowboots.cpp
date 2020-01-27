#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;
int n,b;
struct query
{
	int md;
	int ln;
	int id;
	query(int md=0,int ln=0,int id=0):md(md),ln(ln),id(id){}
	bool operator < (query a)const
	{
		return md<a.md;
	}
};
int ans[100005];
int dep[100005];
vector<query>q;
inline int gc()
{
	return getchar();
}
inline int read()
{
	register int x=0;
	register char ch=gc();
	while(ch<48)ch=gc();
	while(ch>=48)x=x*10+ch-48,ch=gc();
	return x;
}
set<int>next;
vector<int>insp[100005];
bool cmp(query a,query b){
	return a.md>b.md;
}
int main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	n=read(),b=read();
	for(int i=1; i<=n; i++)dep[i]=read(),next.insert(i);
	for(int i=1; i<=b; i++)
	{
		query temp;
		temp.md=read(),temp.ln=read();
		temp.id=i;
		q.push_back(temp);
	}
	sort(q.begin(),q.end());
	for(int i=1; i<=n; i++)
	{
		insp[lower_bound(q.begin(),q.end(),query(dep[i],0,0))-q.begin()].push_back(i);
	}
	//mo dui
	//If element x is in next,then n-x+1 is not a threat(cause lower_bound finds a bigger one......)
	for(int i=1;i<=n;i++)
		if(dep[i]>q[q.size()-1].md)next.erase(n-i+1);
	for(int i=q.size()-1;i>=0;i--){
//		cout<<i<<endl;
		int pointer=1;
		while(pointer!=n){
			//can move to pointer+q[i].ln
			int cmt=min(pointer+q[i].ln,n);
			int nxt=*next.lower_bound(n-cmt+1);
			nxt=n-nxt+1;
			if(nxt<=pointer){
				ans[q[i].id]=0;
				break;
			}
			pointer=nxt;
		}
		if(pointer==n){
			ans[q[i].id]=1;
		}
//		cout<<q[i].md<<endl;
		for(int u=0;u<insp[i].size();u++){
//			cout<<"deleted"<<insp[i][u]<<endl;
			next.erase(n-insp[i][u]+1);
		}
	}
	for(int i=1;i<=b;i++)if(ans[i]==1)putchar('1'),putchar('\n');else putchar('0'),putchar('\n');
}

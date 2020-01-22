#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<list>
#define maxn 1000000
#define mod 1000000007
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;

list<ll>q[maxn+5];//STL链表
//不能用deque，会MLE
//链表里存储的是每个序列的差分数组(d[i]=a[i]-a[i-1]，不是原数组，这样可以快速区间修改 


inline void insert_left(int pos,int x){
	ll y=q[pos].front();
	q[pos].pop_front();
	y=(y-x+mod)%mod;//y-x 
	q[pos].push_front(y);
	q[pos].push_front(x);
}
inline ll query_left(int pos){
	ll x=q[pos].front();
	q[pos].pop_front();
	ll y=q[pos].front();
	q[pos].pop_front();
	q[pos].push_front((x+y)%mod);
	//删除x之后,y变成第一个，差分值变
	//d[1]=a[1]=x,d[2]=y,a[2]-a[1]=d[2]=y,a[2]=x+y; 
	return x; 
}
inline void insert_right(int pos,int x){
	ll y=(-q[pos].back()+mod)%mod;
	q[pos].pop_back();
	y=(x-y+mod)%mod;
	q[pos].push_back(y);
	q[pos].push_back((-x+mod)%mod);
}
inline ll query_right(int pos){
	ll x=q[pos].back();
	q[pos].pop_back();
	ll y=q[pos].back();
	q[pos].pop_back();
	q[pos].push_back((x+y)%mod);
	return (-x+mod)%mod; 
}
inline void add(int pos,int x){
	//整体+x,只有最前面和最后面的差分值会变
	ll fr=q[pos].front();
	q[pos].pop_front();
	q[pos].push_front((x+fr)%mod);//front()差分值+x 
	ll ed=q[pos].back();
	q[pos].pop_back();
	q[pos].push_back((ed-x+mod)%mod); //back()差分值-x 
}
void merge(int i,int j){
	ll x=q[i].back();//0-back()
	q[i].pop_back();
	ll y=q[j].front();//front()-0
	q[j].pop_front();
	q[i].push_back((x+y)%mod);	//front()-back()=x+y;
	q[i].splice(q[i].end(),q[j]);
	q[j].push_back(0);//相当于清空 
	 
}


int main(){
//	freopen("input.txt","r",stdin);
//	freopen("myans.txt","w",stdout);
//	freopen("problem2.in","r",stdin);
//	freopen("problem2.out","w",stdout);
	int cmd,pos,x,y;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) q[i].push_back(0);//初始差分 
	for(int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==1){
			qread(pos);
			qread(x);
			insert_left(pos,x);
		}else if(cmd==2){
			qread(pos);
			qprint((query_left(pos)+mod)%mod);
			putchar('\n');
		}else if(cmd==3){
			qread(pos);
			qread(x);
			insert_right(pos,x);
		}else if(cmd==4){
			qread(pos);
			qprint((query_right(pos)+mod)%mod);
			putchar('\n');
		}else if(cmd==5){
			qread(pos);
			qread(x);
			add(pos,x);
		}else{
			qread(x);
			qread(y);
			merge(x,y);
		}	
	}
}
/*
2 10
1 1 100
3 1 200
3 2 10
1 2 20
5 2 40
6 1 2
2 1
2 1
2 1
2 1
*/

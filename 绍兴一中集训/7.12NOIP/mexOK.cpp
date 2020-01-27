/*
https://loj.ac/problem/541

如果只有插入，维护一个桶表示每个编号是否出现。发现答案是单调不降的，可以维护一个指针，每次加入后尝试更改这个指针即可。
指针只会不断右移，答案不会超过a和b的较大值，因此指针的移动是线性的。

维护出只考虑加入操作的答案 x，然后记当前被删除的元素的最小值为y ，容易发现mex为min(x,y)。平衡树维护当前被删除的元素集合S
恢复时S删除，删除时S插入 .询问时求最小值,可以做到O(mlogm) 

我们现在主要需要优化找到被删除的最小元素这部分的复杂度，加入部分是线性的。
之前描述的模型并没有用到本题的重要性质，即被恢复的是删除最早的，因此要获得满分，并不能简单的把恢复看成一种插入。
如果一个元素的删除时间比另一个元素的删除时间早，但是这个元素更大，显然它是冗余的，即它不可能成为最小值。
显然这里已经能看出是单调队列的模型了，把S改成一个单调队列，队列内元素递增，来维护一个单调队列即可。
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<queue>
#define maxn 2000000
using namespace std;
namespace IO{
	int c;
	unsigned int seed;
	unsigned int randnum(){
		seed^=seed<<13;
		seed^=seed>>17;
		seed^=seed<<5;
		return seed;
	}

	inline int read(int &x){scanf("%d",&x);return x;}
	inline void init_case(int &m,int &a,int &b,int &d,int p[]){
		scanf("%d%u%d%d%d%d",&m,&seed,&a,&b,&c,&d);
		for(int i=1;i<=m;i++){
			if(randnum()%c==0)p[i]=-1;
			else p[i]=randnum()%b;
		}
	}

	inline void update_ans(unsigned int &ans_sum,unsigned int cur_ans,int no){
		const static unsigned int mod=998244353;
		ans_sum^=(long long)no*(no+7)%mod*cur_ans%mod;
	}
}
using IO::read;
using IO::init_case;
using IO::update_ans;
int p[2000005];
int m,a,b,d;

bitset<maxn+5>is_in,is_insert;//卡常,1/32常数 
int ptr;//只有插入时的答案
 
struct mono_queue{
	int hd;
	int tl;
	int q[maxn+5];
	mono_queue(){
		hd=1;
		tl=0;
	}
	inline int front(){
		return q[hd];
	}
	inline int back(){
		return q[tl];
	}
	bool empty(){
		return hd>tl; 
	}
	void push(int x){
		while(hd<=tl&&q[tl]>x) tl--;
		q[++tl]=x;
	}	
	void pop(){
		while(hd<=tl&&is_in[q[hd]]) hd++;
	}
	void clear(){
		hd=1;tl=0;
	}
};
mono_queue q1;//q1按值维护单调队列 
queue<int>q2;//q2模拟取出时间最小的删除元素，因为时间就是插入顺序，直接用一般队列就可以 

inline int insert_back(){
	if(q2.empty()) return 0;
	register int val=q2.front();
	q2.pop();
	is_in[val]=1;
	q1.pop();
	while(is_in[ptr]) ptr++;
	
	if(q1.empty()) return ptr;
	else return min(ptr,q1.front());
} 

inline int insert_new(register int val){
	is_insert[val]=1;
	is_in[val]=1;
	while(is_in[ptr]) ptr++;
	
	if(q1.empty()) return ptr;
	else return min(ptr,q1.front());
}

inline int del(register int val){
	q2.push(val);
	is_in[val]=0;
	q1.push(val);
	
	if(q1.empty()) return ptr;
	else return min(ptr,q1.front());
} 

int main(){
	int T;
	read(T);
	while(T--){
		unsigned int ans_sum=0,cur_ans=0;
		init_case(m,a,b,d,p);
		register int lim=max(a,b);
		for(int i=0;i<=lim+1;i++){
			is_in[i]=0;
			is_insert[i]=0;
		}
		
		q1.clear();
		while(!q2.empty()) q2.pop();
		 
		for(int i=0;i<=a;i++){
			is_in[i]=1;
			is_insert[i]=1;
		}
		ptr=a+1;
		for(int i=1;i<=m;i++){
			if(p[i]==-1){
				if(d) continue;
				cur_ans=insert_back(); 
			}else if(is_insert[p[i]]==0){
				cur_ans=insert_new(p[i]);
			}else if(is_in[p[i]]==1){
				if(d) continue;
				cur_ans=del(p[i]);
			}else{
				if(d) continue;
				cur_ans=insert_back();
			}
//			printf("debug:%d\n",cur_ans);
			update_ans(ans_sum,cur_ans,i);
		}
		printf("%u\n",ans_sum);
	}

} 

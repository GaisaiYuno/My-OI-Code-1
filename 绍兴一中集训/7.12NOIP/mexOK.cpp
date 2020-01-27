/*
https://loj.ac/problem/541

���ֻ�в��룬ά��һ��Ͱ��ʾÿ������Ƿ���֡����ִ��ǵ��������ģ�����ά��һ��ָ�룬ÿ�μ�����Ը������ָ�뼴�ɡ�
ָ��ֻ�᲻�����ƣ��𰸲��ᳬ��a��b�Ľϴ�ֵ�����ָ����ƶ������Եġ�

ά����ֻ���Ǽ�������Ĵ� x��Ȼ��ǵ�ǰ��ɾ����Ԫ�ص���СֵΪy �����׷���mexΪmin(x,y)��ƽ����ά����ǰ��ɾ����Ԫ�ؼ���S
�ָ�ʱSɾ����ɾ��ʱS���� .ѯ��ʱ����Сֵ,��������O(mlogm) 

����������Ҫ��Ҫ�Ż��ҵ���ɾ������СԪ���ⲿ�ֵĸ��Ӷȣ����벿�������Եġ�
֮ǰ������ģ�Ͳ�û���õ��������Ҫ���ʣ������ָ�����ɾ������ģ����Ҫ������֣������ܼ򵥵İѻָ�����һ�ֲ��롣
���һ��Ԫ�ص�ɾ��ʱ�����һ��Ԫ�ص�ɾ��ʱ���磬�������Ԫ�ظ�����Ȼ��������ģ����������ܳ�Ϊ��Сֵ��
��Ȼ�����Ѿ��ܿ����ǵ������е�ģ���ˣ���S�ĳ�һ���������У�������Ԫ�ص�������ά��һ���������м��ɡ�
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

bitset<maxn+5>is_in,is_insert;//����,1/32���� 
int ptr;//ֻ�в���ʱ�Ĵ�
 
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
mono_queue q1;//q1��ֵά���������� 
queue<int>q2;//q2ģ��ȡ��ʱ����С��ɾ��Ԫ�أ���Ϊʱ����ǲ���˳��ֱ����һ����оͿ��� 

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

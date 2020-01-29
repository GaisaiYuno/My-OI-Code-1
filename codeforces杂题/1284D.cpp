#include<iostream>
#include<cstdio>
#include<cstring> 
#include<set>
#include<vector>
#include<algorithm>
#define maxn 100000
using namespace std;
int n;
int la[maxn+5],ra[maxn+5],lb[maxn+5],rb[maxn+5];
struct oper{
	int tim;
	int lb;
	int rb;
	int type;//1插入,2删除 
	oper(){
		
	}
	oper(int _tim,int _lb,int _rb,int _type){
		tim=_tim;
		lb=_lb;
		rb=_rb;
		type=_type;
	}
	friend bool operator < (oper p,oper q){
		if(p.tim==q.tim) return p.type<q.type;
		else return p.tim<q.tim;
	} 
};

bool check(int *la,int *lb,int *ra,int *rb){
	vector<oper>q;
	multiset<int>lset,rset;
	for(int i=1;i<=n;i++){
		q.push_back(oper(la[i],ra[i],rb[i],1));
		q.push_back(oper(lb[i]+1,ra[i],rb[i],-1));
	}
	sort(q.begin(),q.end()); 
	for(auto p : q){
		if(p.type==1){
			if(lset.size()){
				//所有在b中不合法的区间对(相交),在a中也不合法 
				//否则会出现a合法,b不合法 
				if(*(--lset.end())>p.rb||*rset.begin()<p.lb) return 0;
			}
			lset.insert(p.lb);
			rset.insert(p.rb);
		}else{
			lset.erase(lset.find(p.lb));
			rset.erase(rset.find(p.rb));
		}
	}
	return 1;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d %d %d",&la[i],&ra[i],&lb[i],&rb[i]);
	if(check(la,ra,lb,rb)&&check(lb,rb,la,ra)) printf("YES\n");
	else printf("NO\n");
}


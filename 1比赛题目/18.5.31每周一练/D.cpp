#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set> 
#include<cmath>
#define maxn 100005
using namespace std;
set<int>s[maxn]; 
int n;
void print_set(set<int>a){
	set<int>::iterator it;
	for(it=a.begin();it!=a.end();it++){
		printf("%d ",*it);
	}
    printf("\n");
}
void div(int x){
	int sq=(int)sqrt(x);
	for(int i=1;i<=sq;i++){
		if(x%i==0){
//			printf("%d %d\n",i,x%i);
			s[i].insert(x);
			s[x/i].insert(x);
		}
	}
}
int get_ans(int x,int k,int maxs){
//	for(int i=1;i<=x;i++) print_set(s[i]); 
	if(x%k!=0) return -1;
	set<int>::iterator it;
	if(s[k].empty()) return -1;
    it=s[k].upper_bound(maxs-x);
    if(it==s[k].begin()) return -1;
    it--;
    int ans=-1,sum=-1;
    for(;it!=s[k].begin();it--){
    	int v=*it;
    	if(sum>x+v) break;
    	if(sum<(x^v)){
    		ans=v;
    		sum=x^v;
		}
	}
	if(sum<(x^*it)) ans=*it;
	return ans;
}
int main(){
	int cmd,x,k,s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d",&x); 
			div(x);
		}else{
			scanf("%d %d %d",&x,&k,&s);
			printf("%d\n",get_ans(x,k,s));
		}
	}
}

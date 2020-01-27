#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 200005
#define INF 0x7fffffff
using namespace std;
int n;
long long a[maxn];
struct oper {
	int type;
	int i;
	int j;
	oper() {

	}
	oper(int x,int y,int z) {
		type=x;
		i=y;
		j=z;
	}
	void print() {
		if(type==1) {
			printf("%d %d %d\n",type,i,j);
		} else {
			printf("%d %d\n",type,i);
		}
	}
};
vector<int>zeros;
vector<oper>res;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%I64d",&a[i]);
	}
	int cntneg=0,cnt0=0;
	long long maxneg=-INF;
	int origdel=0,del=0;
	for(int i=1; i<=n; i++) {
		if(a[i]==0) {
			zeros.push_back(i);
			cnt0++;
		} else if(a[i]<0) {
			cntneg++;
			if(a[i]>maxneg) {
				maxneg=a[i];
				del=i;
				origdel=i;
			}
		}
	}
	for(int i=0;i<cnt0-1;i++){
		res.push_back(oper(1,zeros[i],zeros[i+1]));
	}
	if(cnt0+cntneg==n&&cntneg==1) {
		res.push_back(oper(1,del,zeros[cnt0-1]));
		for(int i=0; i<n-1; i++) {
			res[i].print();
		}
		return 0; 
	}
	if(cntneg%2==1){
		if(cnt0!=0) res.push_back(oper(1,del,zeros[cnt0-1])),res.push_back(oper(2,zeros[cnt0-1],0));
		else res.push_back(oper(2,del,0));
	}else if(cnt0!=0) res.push_back(oper(2,zeros[cnt0-1],0));
	int last=0;
	for(int i=1; i<=n; i++) {
		if(a[i]!=0) {
			if(cntneg%2==1&&i==origdel) continue;
			else if(last==0) {
				last=i;
				continue;
			} else res.push_back(oper(1,last,i));
			last=i;
		}
	}
	for(int i=0; i<n-1; i++) {
		res[i].print();
	}
}

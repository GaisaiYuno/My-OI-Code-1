#include<iostream>
#include<cstdio>
#include<map>
#define maxn 1005
using namespace std;
int n;
int main(){
	double x0,y0;
	double x,y;
	scanf("%d %lf %lf",&n,&x0,&y0);
	map<double,int>m;
	int cnt=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&x,&y);
		if(x==x0){
			cnt2=1;
			continue;
		}
		if(y==y0){
			cnt3=1;
			continue;
		}
		double k=(x-x0)/(y-y0);
		if(!m[k]){
			m[k]=1;
			cnt++;
		}
	}
	printf("%d\n",cnt+cnt2+cnt3);
}

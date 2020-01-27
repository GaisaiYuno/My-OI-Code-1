#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#define maxn 1000006
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
/*
	两眼一闭，N^3暴力 
    **         ***       ****  
    **          **      ** 
 ********       **       ****
    **          **     .    ** 
    **        ******    *****
*/ 
int N,M;
int ans[maxn],as,ad;
int build[maxn],road[maxn],maxy;
int rr[10005];
double T=10000000000,delt=0.99;
int next_d(int d){
	long long k=rand()%5;
	if(k<=2&&d<maxy&&!ans[d+1])
		return d+1;
	if(k<=3&&d>1&&!ans[d-1])
		return d-1;
	while(1){
		k=rand()*rand()%maxy;
		if(!ans[k])
			return k;
	}
}
bool change(double h){
	double k=rand()*rand();
	while(k>=1)
		k/=10;
	if(k>=exp(h/T))
		return false;
	return true;
}
int cal(int d){
	int a=0,b=0;
	for(int i=1;i<=N;i++){
		if(rr[i]+d<=maxn)
			if(build[rr[i]+d])
				a++;
		if(rr[i]-d>=0)
			if(build[rr[i]-d])
				b++;
	}
	return max(a,b);
}
int main(){
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	srand(time(NULL));
	read(N);read(M);
	int x,y;
	for(int i=1;i<=N;i++){
		read(x);rr[i]=x;maxy=max(maxy,x);
	}
	for(int i=1;i<=M;i++){
		read(x);read(y);maxy=max(maxy,y);
		build[x]++;build[y+1]--;
	}
	for(int i=1;i<=maxy;i++)
		build[i]+=build[i-1];
	int d=0;int tim=0;
	as=cal(0);
	while(T>=0.0000000001){
		if(tim==maxy)
			break;
		tim++;
		int nex=next_d(d);
		int cal_nex=cal(nex);
		//cout<<tim<<" "<<T<<" "<<nex<<" "<<cal_nex<<" "<<ad<<endl;
		ans[nex]=cal_nex;
		if(cal_nex>=as){
			if(as==cal_nex)
				ad=min(ad,nex);
			else
				ad=nex;
			as=cal_nex;
			d=nex;
			continue ;
		}
		if(cal_nex>ans[d]){
			d=nex;
			continue ;
		}
		if(change(cal_nex-ans[d])){
			d=nex;
		}
		T*=delt;
	}
	//cout<<ad<<" "<<as<<endl;
	int od=ad;
	for(int i=1;i<=2000;i++){
		int nex_cal=cal(od+i);
		if(nex_cal>as)
			as=nex_cal,ad=od+i;
	}
	for(int i=1;i<=2000&&od-i>=0;i++){
		int nex_cal=cal(od-i);
		if(nex_cal==as)
			ad=od-i;
		if(nex_cal>as)
			as=nex_cal,ad=od-i;
	}
	printf("%d %d",ad,as);
}
/*
																																																																	打倒习近平，推翻独裁暴政															
																																																																																																																																																																										重立江泽民，建立民主社会 
*/ 


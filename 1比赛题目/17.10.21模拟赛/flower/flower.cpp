#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100000
using namespace std;
long long n,tim,sum;//一定要用long long 
struct cow{
	int t;
	int d;
}a[maxn];
int comp(cow x,cow y){
	double aa=double(x.t)/double(x.d), bb=double(y.t)/double(y.d);//注意int 转double 
    return aa<bb;
}
int main(){
	//freopen("flower.in","r",stdin);
	//freopen("flower.out","w",stdout);
	cin>>n;
	tim=sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].d;
	}
	sort(a+1,a+1+n,comp);
	for (int i=2;i<=n;i++) {
        tim+=a[i-1].t*2;
        sum+=tim*a[i].d;        
    }
	cout<<sum;
	return 0;
} 


//书p271 题3
#include<iostream>
#include<algorithm>
using namespace std;
double ans[201]= {0.0};//记录总价值
struct metal {
	double n;//重量 
	double v;//价值 
	double price;//单价 
} a[201];
bool cmp(metal a,metal b) {
	return a.price>b.price;
}
int main() {
	int k;
	cin>>k;
	for(int i=0; i<k; i++) {
		int w;
		cin>>w;
		int s;
		cin>>s;
		for(int j=0; j<s; j++) {
			cin>>a[j].n>>a[j].v;
			a[j].price=a[j].v/a[j].n;
		}
		sort(a,a+s,cmp);
		int m=w;//卡车重量（剩下） 
		int x=0;//ans数组下标
		while(m>0&&x<s) {
			if(m>=a[x].n) {
				ans[i]=ans[i]+a[x].v;//全放 
				m=m-a[x].n;
				x++;
			}else{
				ans[i]=ans[i]+m*a[x].price;//剩下的放一部分 
                break;
			}
		}
	}
	for(int p=0;p<k;p++){
		printf("%.2f\n",ans[p]);
	}
}

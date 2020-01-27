/*n个最大值为n的正整数组成一个环，使相邻两个数的和为素数
  输入n,求出所有解 
*/ 
#include<iostream>
#include<cmath>
#include<cstdio>
#include<ctime>
#include<fstream>
#define maxn 100
using namespace std; 
int n;
bool b[maxn+1];
int total=0,a[maxn+1];
ofstream ans;
bool pd(int x,int y) {
	int k=2;
	while(k*k<=x+y && (x+y)%k!=0)
		k++;
	if(k*k>x+y)	return true;
	else return false;
}
void print() {
	total++;
	ans<<"<Case "<<total<<" > ";
	for(int i=1; i<=n; i++)
		ans<<a[i]<<' ';
	ans<<endl;
}
void search(int t) {
	for(int i=1; i<=n; i++)
		if(pd(a[t-1],i)&&!b[i]) {
			a[t]=i;
			b[i]=1;
			if(t==n){
				if(pd(a[n],a[1]))	print();
			} else	search(t+1);
			b[i]=0;
		}
}
int main() {
	cin>>n;
	ans.open("prime ring.txt");
	int t1=clock();
//	freopen("prime ring.txt","w",stdout);
	if(n%2==0) search(1);
	printf("There are %d solutions when n=%d\n",total,n);
    printf("Time used=%.3fs",(double)(clock()-t1)/1000) ;
}

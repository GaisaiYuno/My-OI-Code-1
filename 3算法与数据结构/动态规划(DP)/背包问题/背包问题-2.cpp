#include<iostream>
#include<cstring>
#define maxn 500000
using namespace std;
float q,num;
struct item {
	int size;
	int price;
} a[maxn];
int f[maxn];
int n,m,Q;
char type;
int main() {
	while(1) {
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		cin>>q>>n;
		if(n==0) break;
		Q=(int)(q*100);
		int index=0;
		for(int i=0; i<n; i++) {
			cin>>m;
			double sum=0;
			bool flag=true;
			char no_use;
			for(int j=0; j<m; j++) {
				cin>>type>>no_use>>num;
				sum+=num;
				if(num>600||(type!='A'&&type!='B'&&type!='C')||sum>1000) flag=false;
			}
			if(flag){
				a[index].price=(int)(sum*100);
				a[index].size=(int)(sum*100);
				index++;
			} 
		}
		for(int i=0;i<n;i++){
			for(int j=Q;j>=a[i].size;j--)
			  f[j]=max(f[j],f[j-a[i].size]+a[i].price);
		}
		printf("%.2f\n",(double)(f[Q]/100.00));
	}
	return 0;
}
/*ÑùÀý
  200.00 3
  2 A:23.50 B:100.00
  1 C:650.00
  3 A:59.99 A:120.00 X:10.00
  1200.00 2
  2 B:600.00 A:400.00
  1 C:200.50
  1200.50 3
  2 B:600.00 A:400.00
  1 C:200.50
  1 A:100.00
  100.00 0
*/

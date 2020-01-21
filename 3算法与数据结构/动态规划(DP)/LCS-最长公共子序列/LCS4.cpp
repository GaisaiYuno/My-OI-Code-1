#include<iostream>
#include<cstring>
#define maxn 50
using namespace std;
int t,n,lena,lenb;
int a[maxn*maxn],b[maxn*maxn];
int f[maxn*maxn][maxn*maxn];
int main() {
	cin>>t;
	for(int k=1; k<=t; k++) {
        //此为O(n^2)算法，部分测试点会TLE 
		/*for(int i=1; i<=lena; i++) { //小心越界！
			for(int j=1; j<=lenb; j++) {
				if(a[i]==b[j]) f[i][j]=max(max(f[i-1][j-1]+1,f[i-1][j]),f[i][j-1]);
				else f[i][j]=max(f[i-1][j],f[i][j-1]);
			}
		}*/
		int tmp;
		cin>>n>>lena>>lenb;
		memset(f,0,sizeof(f));
	    for(int i=1;i<=lena+1;i++){
	    	cin>>tmp;
	    	a[tmp]=i;
		}
		for(int i=1;i<=lenb+1;i++){
			cin>>tmp;
			b[i]=a[tmp];
		}
		for(int i=0;i<=n*n;i++) cout<<a[i]<<' ';
		cout<<endl;
		for(int i=0;i<=n*n;i++) cout<<b[i]<<' ';
		printf("Case %d: %d\n",k,f[lena][lenb]);
	}
}
/*优化O(n+nlogn) 
    将a,b中的每个数字编码为这个数字在a中的位置
	a：1 7 5 4 8 3 9 
	   1 2 3 4 5 6 7
	b:1 4 3 5 6 2 8 9 
	  1 4 6 3 0 0 5 7  求LIS O(nlogn）-->1 3 5 7，答案为4 
*/ 

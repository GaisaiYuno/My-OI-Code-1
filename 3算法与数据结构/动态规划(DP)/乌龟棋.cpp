//Âå¹È ÎÚ¹êÆå 1541
#include<iostream>
#define maxn 500
using namespace std;
int n,m;
int a[500],b[500];
int f[50][50][50][50];
int m1,m2,m3,m4,x;
int main(){
	cin>>n>>m;
	m1=m2=m3=m4=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int j=0;j<m;j++) {
		cin>>x;
		if(x==1) ++m1; 
		if(x==2) ++m2; 
		if(x==3) ++m3; 
		if(x==4) ++m4; 
	}
	f[0][0][0][0]=a[0];
	int tmp;
	for(int a1=0;a1<=m1;a1++){
		for(int a2=0;a2<=m2;a2++){
			for(int a3=0;a3<=m3;a3++){
				for(int a4=0;a4<=m4;a4++){
				    tmp=0;
                    if (a1!=0 && f[a1-1][a2][a3][a4]>tmp)    tmp=f[a1-1][a2][a3][a4];
                    if (a2!=0 && f[a1][a2-1][a3][a4]>tmp)    tmp=f[a1][a2-1][a3][a4];
                    if (a3!=0 && f[a1][a2][a3-1][a4]>tmp)    tmp=f[a1][a2][a3-1][a4];
                    if (a4!=0 && f[a1][a2][a3][a4-1]>tmp)   tmp=f[a1][a2][a3][a4-1];
                    f[a1][a2][a3][a4]=tmp+a[a1+a2*2+a3*3+a4*4];
				}
			}
		}
	}
//	debug();
	cout<<f[m1][m2][m3][m4];
	return 0;
} 

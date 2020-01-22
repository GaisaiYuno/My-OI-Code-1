#include<iostream>
#include<cstdio>
using namespace std;
int a[4][4][7];
//1前，2后，3左，4右，5上，6下 
string s;
int main(){
	int maxi=-1,mini=1000000;
	freopen("cube.in","r",stdin);
	freopen("cube.out","w",stdout);
	cin>>s;
	for(int i=1;i<=6;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<=3;k++) {
				cin>>a[i][j][k];
			}
		} 
	}
}

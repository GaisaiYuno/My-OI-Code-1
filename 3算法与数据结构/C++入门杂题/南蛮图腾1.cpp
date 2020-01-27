//洛谷 南蛮图腾
#include<iostream>
#include<cstring>
#define maxn 1001
using namespace std;
string a[maxn];
int n;
int main() {
	int h,i,j,k;
	cin>>n;
	a[1]=" /\\ "; //一定是双斜杠，因为\是转义字符
	a[2]="/__\\";
	h=2 ;
	//freopen("map.doc","w",stdout); 
	for(i=2; i<=n; i++) {
		for(j=h+1; j<=2*h; j++) {
			a[j]=a[j-h]+a[j-h];
		}
		for(j=1;j<=h;j++){
			int t=a[j].length();
			for(k=1;k<=t/2;k++) a[j]=' '+a[j]+' ';
		}
		h=h*2;
		}
	
	for(i=1; i<=h; i++) {
		cout<<a[i]<<endl;
	}
}

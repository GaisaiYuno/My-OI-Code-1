#include<iostream>
#define maxn 1005
using namespace std;
int t,n,v;
struct item {
	int value;
	int size;
} a[maxn];
int f[maxn];
int main() {
	cin>>v>>n;
	for(int i=0; i<n; i++){
		cin>>a[i].size;
		a[i].value=a[i].size;
	}
	for(int i=0; i<n; i++) {
		for(int j=v; j>=a[i].size; j--)
			f[j]=max(f[j],f[j-a[i].size]+a[i].value);
	}
	cout<<v-f[v]<<endl;
	return 0;
}

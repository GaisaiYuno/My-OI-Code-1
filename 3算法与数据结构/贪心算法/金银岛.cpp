// È p271 Ã‚3 
#include<iostream>
#include<algorithm>
using namespace std;
int n[101];
int v[101];
struct metal{
	int n[101];
	int v[101];
};
metal metal_n,metal_v;
int my_comp(int x,int y) {
	return x>y;
}                                                                                                 
int main() {
	int k;
	cin>>k;
	for(int a=0; a<k; k++) {
		int w;
		cin>>w;
		int s;
		cin>>s;
		for(int b=0; b<s; b++) {
			cin>>metal_n.n[b]>>metal_v.v[b];
		}
		sort(v,v+s,my_comp);
		int m=w;
		int i=1;
		do {
			if(m==0) break;
			m=m-n[i];
			if(m>=0) continue;
			else m=m+n[i];
			i++;
		} while(m>0&&i<s);
		
	}
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int card[101];
int tar=0;
int sum=0;
int step=0;
int n;
int main() {
	freopen("a.in","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>card[i];
		sum+=card[i];
	}
	tar=sum/n;
	for (int i=0; i<n-1; i++) {
		if (card[i]==tar) {
			continue;
		}
		card[i]=tar;
		card[i+1]+=card[i]-tar;
		step++;
	}
	cout<<step<<endl;
}

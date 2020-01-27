//书p275 题11
#include<iostream>
#include<algorithm>
using namespace std;
int t[100001];//w=时间t
int s[100001]= {0};
int main() {
	int n,m;
	cin>>n>>m;
	for(int k=1; k<=n; k++) {
		cin>>t[k];
	}
	int j=0,ans=1;
	int x=m;
	int i=0;
	while(i<n) {
		j++;
		if(j==m+1) {
			ans++;
			j=1;
		}
		if(t[j]!=0) {
			s[j]++;
			if(t[j]==s[j]) {
				x++;
				i++;
				t[j]=t[x];
				s[j]=0;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

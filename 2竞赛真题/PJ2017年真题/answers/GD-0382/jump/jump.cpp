#include<bits/stdc++.h>
using namespace std;
int n,d,k,x[500001],s[500001],i,j,g,ans;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=1;i<=n;i++) {
		cin>>x[i]>>s[i];
		if (s[i]>0) ans+=s[i];
	}
	if (ans<k) cout<<"-1";
	else {
		g=0; ans=0;
		while (ans<k){
			g++;
			if (g<d) {
				ans=0; i=1; j=0;
				while (x[i]-x[j]<=d+g&&ans<k&&i<=n) {
					if (x[i+1]-x[j]<=d+g&&x[i]-x[j]<d-g) i++;
					else {
 						if (s[i]>=0) {
							ans+=s[i];
							j=i; i++;
						}
						else {
							if (x[i+1]-x[j]<=d+g) i++;
							else {
								ans+=s[i];
								j=i; i++;
							}
						}
					}
				}
			} else {
				ans=0; i=1; j=0;
				while (x[i]-x[j]<=d+g&&ans<k) {
					if (s[i]>=0) {
						ans+=s[i];
						j=i; i++;
					}
					else {
						if (x[i+1]-x[j]<=d+g) i++;
						else {
							ans+=s[i];
							j=i; i++;
						}
					}
				}
			}
		}
		cout<<g;
	}
}

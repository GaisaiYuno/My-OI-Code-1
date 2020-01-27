//Âå¹È ÌøÊ¯Í·
#include <iostream>
#include<cstring>
using namespace std;
int a[50010], n, m, L,ans;
bool check(int x) {
	int last = 0,cnt = 0;
	for (int i=0; i<n; i++) {
		if (a[i] - last < x)
			cnt++;
		else
			last = a[i];
	}
	if (cnt> m)
		return false;
	return true;
}

int main() {
	cin>>L;
	cin>>n;
	cin>>m;
	for (int i=0; i<n;i++)
		cin>>a[i];
	a[n]=L;
	int l=0, r=L;
	while (l<=r) {
		int mid=(l+r) / 2;
		if (check(mid)) {
			ans=mid;
			l=mid+ 1;
		} else
			r = mid - 1;
	}
    //freopen("stone.out.txt","w",stdout);
	cout<<ans;

	return 0;
}

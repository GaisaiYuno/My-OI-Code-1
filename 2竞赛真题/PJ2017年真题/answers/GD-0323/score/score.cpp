#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<int(a*0.2+b*0.3+c*0.5+0.5);
	return 0;
}

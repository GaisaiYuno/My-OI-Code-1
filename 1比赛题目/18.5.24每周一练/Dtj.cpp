#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
#include<time.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const int maxn = 1e5 + 500;
ll n, h;
bool ok(ll x) {//这里判断求得的是长度为x的沙墙最多能堆放的沙包个数是否大于n
	if (x <= h){ //x+(x-1)+...+3+2+1
		printf("A:%d\n",x *(x + 1));
		return x *(x + 1) >= 2*n ? true : false;
	}else {//h+(h+1)+...+(h+k-1)+(h+k)+...+(h+1)+h+(h-1)+...+2+1 或 h+(h+1)+...+(h+k-1)+(h+k)+(h+k-1)+...+h+...+2+1
		ll t = x - h;
		printf("B:%d\n",(1 + h + t / 2)*(h + t / 2) + (h + h + t / 2)*(t / 2 + 1));
		printf("C:%d\n",(1 + h + t / 2)*(h + t / 2) + (h + h + t / 2 - 1)*t / 2);
		if (t % 2)
			return (1 + h + t / 2)*(h + t / 2) + (h + h + t / 2)*(t / 2 + 1) >= 2 * n ? true : false;
		else
			return (1 + h + t / 2)*(h + t / 2) + (h + h + t / 2 - 1)*t / 2 >= 2 * n ? true : false;
	}
}
int main() {
	while (~scanf("%lld%lld", &n, &h)) {
		ll l = 1,r = 10;
		while (l<=r-1){//二分ans
			ll mid = (l + r) >> 1;
			printf("%d %d\n",mid,ok(mid));
			if (ok(mid))
				r = mid;
			else 
				l = mid+1;
		}
		cout << l << endl;
	}
	return 0;
}

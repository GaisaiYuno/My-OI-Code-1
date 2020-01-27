### 题面

[传送门](https://codeforces.com/contest/1080/problem/C)

题目大意：

有一个黑白的棋盘，现在将棋盘上的一个子矩形全部染成黑色，另一个子矩形全部染成白色

求染完色后黑,白格子的总数

### 分析

我们可以发现，对于一个(1,1)到(x,y)的矩形，若xy为偶数，则黑、白的个数都是 $ \frac{xy}{2} $

若xy为奇数，则黑格个数为$\ [ \frac{xy}{2} \ ]$,白格个数为$\ [ \frac{xy}{2} \ ]+1$

因此用二维前缀和的方法就可以求出任意子矩形内的黑，白格子个数

```cpp
long long get_white(long long x,long long y) {
	if((x*y)%2==0) return (x*y)/2;
	else {
		return (x*y)/2+1;
	}
}
long long get_black(long long x,long long y) {
	if((x*y)%2==0) return (x*y)/2;
	else {
		return (x*y)/2;
	}
}
long long get_rec_black(long long x1,long long y1,long long x2,long long y2) {
	return get_black(x2,y2)-get_black(x1-1,y2)-get_black(x2,y1-1)+get_black(x1-1,y1-1);
}
long long get_rec_white(long long x1,long long y1,long long x2,long long y2) {
	return get_white(x2,y2)-get_white(x1-1,y2)-get_white(x2,y1-1)+get_white(x1-1,y1-1);
}
```



然后考虑修改：

对于染黑的操作，设wsum,bsum分别表示整个棋盘里的白，黑格子个数,初始wsum,bsum都是原本棋盘里黑，白格子的个数

s表示染黑的矩形内部原来白色格子个数，则wsum=wsum-s,bsum=bsum+s

染白操作同理

```cpp
wsum=get_white(n,m);
bsum=get_black(n,m);
s1=get_rec_black(x1,y1,x2,y2);
wsum+=s1;
bsum-=s1;
```





但这样会导致一个问题，若染黑和染白的矩形有公共部分，那么会出现错误

因此我们染黑时先不考虑公共部分（染白时直接染），把公共部分从答案里面减去

再分析公共部分对答案的影响

设公共部分面积为same

则bsum+=same,wsum-=same

这样我们就在$O（1）$时间内求出了答案



### 代码

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
long long n,m;
long long x1,y1,x2,y2;
long long x3,y3,x4,y4;
long long wsum,bsum;
long long get_white(long long x,long long y) {
	if((x*y)%2==0) return (x*y)/2;
	else {
		return (x*y)/2+1;
	}
}
long long get_black(long long x,long long y) {
	if((x*y)%2==0) return (x*y)/2;
	else {
		return (x*y)/2;
	}
}

long long get_rec_black(long long x1,long long y1,long long x2,long long y2) {
	return get_black(x2,y2)-get_black(x1-1,y2)-get_black(x2,y1-1)+get_black(x1-1,y1-1);
}

long long get_rec_white(long long x1,long long y1,long long x2,long long y2) {
	return get_white(x2,y2)-get_white(x1-1,y2)-get_white(x2,y1-1)+get_white(x1-1,y1-1);
}

long long minx,miny,maxx,maxy;
int get_inter(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4,long long y4) {
	minx=max(x1,x3);
	miny=max(y1,y3);
	maxx=min(x2,x4);
	maxy=min(y2,y4); 
	if(minx>maxx||miny>maxy) return -1;
	else return 1;
} 

int main() {
	long long s1,s2,same;
	scanf("%d",&t);
	while(t--) {
		scanf("%I64d %I64d",&n,&m);
//		swap(n,m);
		scanf("%I64d %I64d %I64d %I64d",&x1,&y1,&x2,&y2);
		scanf("%I64d %I64d %I64d %I64d",&x3,&y3,&x4,&y4);
		wsum=get_white(n,m);
		bsum=get_black(n,m);
		s1=get_rec_black(x1,y1,x2,y2);
		wsum+=s1;
		bsum-=s1;
		if(get_inter(x1,y1,x2,y2,x3,y3,x4,y4)==-1) {
			s2=get_rec_white(x3,y3,x4,y4);
			bsum+=s2;
			wsum-=s2;
		} else {
			s2=get_rec_white(x3,y3,x4,y4)-get_rec_white(minx,miny,maxx,maxy);
			bsum+=s2;
			wsum-=s2;
			bsum+=(maxy-miny+1)*(maxx-minx+1);
			wsum-=(maxy-miny+1)*(maxx-minx+1);
		}

		printf("%I64d %I64d\n",wsum,bsum);
	}
}
```




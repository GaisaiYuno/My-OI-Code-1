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

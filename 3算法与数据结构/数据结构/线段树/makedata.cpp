#include<iostream>
#include<cstdlib>
#include<ctime>
#define MAXN 50
#define MAXH 100001
#define MAXV 1001
#define MAXL 100000
#define POS 3
using namespace std;
int main() {
	srand(time(NULL)); 
	int t=rand()%10;
	while(t--) {
		int n=rand()%MAXN;
		cout<<n<<endl;
		while(n--) {
			int h=rand()%MAXH;
			int l=rand()%MAXL;
			int r=rand()%MAXL;
			if(l>r) swap(l,r);
			int v=rand()%MAXV;
			int sign=rand()%POS;
			if(sign==1) v=-v;
			cout<<h<<' '<<l<<' '<<r<<' '<<v<<endl;
		}
	}
}

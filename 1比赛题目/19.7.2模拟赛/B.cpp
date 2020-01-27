#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 250
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

int L,W,n,K;
int a[maxn+5][maxn+5];
int sum[maxn+5];
int leftv[maxn+5];
int rightv[maxn+5];
int upv[maxn+5];
int downv[maxn+5];
void get_left() {
	for(int i=1; i<=L; i++) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j>=1; j--) {
			for(int k=1; k<=W; k++) {
				sum[k]+=a[j][k];
			}
			int l=1,tot=0;
			for(int r=1; r<=W; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K) ans=min(ans,2*(i-j+1)+2*(r-l+1));
			}
		}
		leftv[i]=ans;
	}
}
void get_right() {
	for(int i=L; i>0; i--) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j<=L; j++) {
			for(int k=1; k<=W; k++) {
				sum[k]+=a[j][k];
			}
			int l=1,tot=0;
			for(int r=1; r<=W; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K) ans=min(ans,2*(j-i+1)+2*(r-l+1));
			}
		}
		rightv[i]=ans;
	}
}
void get_down() {
	for(int i=1; i<=W; i++) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j>=1; j--) {
			for(int k=1; k<=L; k++) {
				sum[k]+=a[k][j];
			}
			int l=1,tot=0;
			for(int r=1; r<=L; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K) ans=min(ans,2*(i-j+1)+2*(r-l+1));
			}
		}
		downv[i]=ans;
	}
}
void get_up() {
	for(int i=W; i>=1; i--) {
		int ans=INF;
		memset(sum,0,sizeof(sum));
		for(int j=i; j<=W; j++) {
			for(int k=1; k<=L; k++) {
				sum[k]+=a[k][j];
			}
			int l=1,tot=0;
			for(int r=1; r<=L; r++) {
				tot+=sum[r];
				while(l<r&&tot>K) {
					tot-=sum[l];
					l++;
				}
				while(l<r&&sum[l]==0) {
					l++;
				}
				if(tot==K)ans=min(ans,2*(j-i+1)+2*(r-l+1));
			}
		}
		upv[i]=ans;
	}
}
int solve() {
	int ans=INF;
	for(int i=1; i<=L; i++) {
		for(int j=i+1; j<=L; j++) {
			ans=min(ans,leftv[i]+rightv[j]);
		}
	}
	for(int i=1; i<=W; i++) {
		for(int j=i+1; j<=W; j++) {
			ans=min(ans,downv[i]+upv[j]);
		}
	}
	return ans;
}
int main() {
	int x,y;
	qread(L);
	qread(W);
	qread(n);
	qread(K);
	for(int i=1; i<=n; i++) {
		qread(x);
		qread(y);
		a[x][y]++;
	}
	memset(leftv,0x3f,sizeof(leftv));
	memset(rightv,0x3f,sizeof(rightv));
	memset(upv,0x3f,sizeof(upv));
	memset(downv,0x3f,sizeof(downv));
	get_up();
	get_down();
	get_right();
	get_left();
#ifdef DEBUG
	for(int i=1;i<=L;i++) printf("%d ",leftv[i]); 
	printf("\n");
	for(int i=1;i<=L;i++) printf("%d ",rightv[i]);
	printf("\n");
	for(int i=1;i<=L;i++) printf("%d ",downv[i]); 
	printf("\n");
	for(int i=1;i<=L;i++) printf("%d ",upv[i]); 
	printf("\n");
#endif
	int ans=solve();
	if(ans==INF) printf("NO\n");
	else qprint(ans);
}

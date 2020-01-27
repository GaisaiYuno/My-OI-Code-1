#include<bits/stdc++.h>
#define zhh 1005
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
#define ll long long
using namespace std;
string s;
int l,q1,q2,q3,q4;
bool fl=0;
void work(int l,int mid,int r) {
	q1=q2=q3=q4=0;
	for(int i=l; i<=r; i++) {
		if(s[i]=='1') {
			q2++;
		}
		if(s[i]=='0'&&fl==0) {
			q1++;
		}
		if(s[i]=='2') {
			q3++;
			fl=1;
		}
		if(s[i]=='0'&&fl==1) {
			q4++;
		}
	}
	fu(i,1,q1) cout<<0;
	fu(i,1,q2) cout<<1;
	fu(i,1,q3) cout<<2;
	fu(i,1,q4) cout<<0;

}
int main() {
	cin>>s;
	l=s.length();
	int last=0;
	int pos1,pos2;
	for(int i=0; i<l-1; i++) {
		if(s[i]=='2'&&s[i+1]!='2') {
			pos1=i;
			pos2=l-1;
			for(int j=pos1; j<=l-1; j++) {
				if(s[j]!='2'&&s[j]=='2') pos2=j;
			}
			work(last,pos1,pos2);
			last=pos2+1;
		}
	}
}


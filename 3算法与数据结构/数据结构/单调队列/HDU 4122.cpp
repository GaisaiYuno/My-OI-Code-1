#include<iostream>
#include<cstring>
#include<map>
#include<cstdio>
#include<cmath>
#define maxn 2505
#define maxm 100005
using namespace std;
map<string,int>ma;
const string str[13]= {" ","Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov","Dec"};
const int daynum[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void ini() {
	for(int i=1; i<=12; i++) {
		ma[str[i]]=i;
	}
}
int is_rn(int y) {
	if(y%4==0) {
		if(y%100==0) {
			if(y%400==0) return 1;
		    else return 0;
		} else return 1;
	} else return 0;
}
int to_hour(int year,string month,int day,int hour) {
	int sum=0;
	for(int i=2000; i<year; i++) {
		if(is_rn(i)) sum+=24*366;
		else sum+=24*365;
	}
	int mon=ma[month]-1;
	if(is_rn(year)){
		sum+=daynum[mon]*24;
		if(mon>=2) sum+=24;
	}
	else sum+=daynum[mon]*24;
	sum+=(day-1);
	sum+=hour;
	return sum;
}
int n,m,s,t,r,cnt;
long long ans;
string mon;
int d,y,h;
struct node{
	int num;
	int tim;
}order[maxn];
int cost[maxm],q[maxm];
int head,tail;
int main() {
	ini();
	while(cin>>n>>m&&n&&m) {
		for(int i=1; i<=n; i++) {
			cin>>mon>>d>>y>>h>>r;
			order[i].tim=to_hour(y,mon,d,h)+1;
			//printf("t%d =%d\n",i,order[i].tim);
			order[i].num=r;
		}
		cin>>t>>s;
		head=0;
		tail=1;
		ans=0;
		cnt=0;
		int x;
		int cnt=1;
		for(int i=1;i<=m;i++) 	cin>>cost[i];
		for(int i=1; i<=m; i++) {
			while(head<tail&&cost[q[tail-1]]+s*(i-q[tail-1])>cost[i]/*储存+制造大于现在制造*/) tail--;
			q[tail++]=i;
			while(i==order[cnt].tim){
				while(head<tail&&i-q[head]>t) head++;
				ans+=order[cnt++].num*(cost[q[head]]+(i-q[head])*s);
			}
		}
		cout<<ans<<endl;
	}
}

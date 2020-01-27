//洛谷 刷题 
#include<iostream>
#include<algorithm>
#define max 5001
using namespace std;
string st,ed;
int t1,t2;
int total;
int prob[max];
int daynum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct start {
	int year;
	int month;
	int day;
	int hour;
	int min;
} start;
struct end {
	int year;
	int month;
	int day;
	int hour;
	int min;
} end;

void input() {
	cin>>st>>ed;
	start.year=(st[0]-48)*1000+(st[1]-48)*100+(st[2]-48)*10+(st[3]-48);//转换 
	end.year=(ed[0]-48)*1000+(ed[1]-48)*100+(ed[2]-48)*10+(ed[3]-48);
	start.month=(st[5]-48)*10+(st[6]-48);
	end.month=(ed[5]-48)*10+(ed[6]-48);
	start.day=(st[8]-48)*10+(st[9]-48);
	end.day=(ed[8]-48)*10+(ed[9]-48);
	start.hour=(st[11]-48)*10+(st[12]-48);
	end.hour=(ed[11]-48)*10+(ed[12]-48);
	start.min=(st[14]-48)*10+(st[15]-48);
	end.min=(ed[14]-48)*10+(ed[15]-48);
}

bool is_rn(int y) {
	if(y%4==0) {
		if(y%100==0) {
			if(y%400==0) {
				return true;
			} else
				return false;
		} else
			return true;
	} else
		return false;
}

void add_time(){
	t1=start.min+60*start.hour+1440*start.day;
	t2=end.min+60*end.hour+1440*end.day;
	for(int i=1;i<start.month;i++) t1+=daynum[i]*1440;
    for(int j=1;j<end.month;j++) t2+=daynum[j]*1440;
    if(is_rn(start.year)) t1+=527040;//比赛之前的年 
    else t1+=525600;
    for(int p=start.year;p<=end.year;p++){ 
    if(is_rn(p)) t2+=527040;
    else t2+=525600;
    } 
    total=t2-t1; 
}
int main(){
	int n;
	cin>>n;
	int i,m,ans=0;
	for(int k=0;k<n;k++){
		cin>>prob[k];
	}
	input();
	add_time();
	sort(prob,prob+n);
	i=0;
	m=total;
	while(m>=0 && i<n) {
			if(m>=prob[i]) {
				ans++;
				m=m-prob[i];
				i++;
			}else break;
	}
	cout<<ans;
	return 0;
}

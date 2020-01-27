#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
struct node{
	int num;
	int tim;
	string name;
	friend bool operator <(node a,node b){
		if(a.num==b.num){
			if(a.tim==b.tim) return a.name>b.name;
			else return a.tim>b.tim;
		}
		return a.num<b.num;
	}
	void print(){
		cout<<name;
		for(int i=1;i<=10-name.length();i++) cout<<' ';
		cout<<' ';
	    if(num<10) cout<<' '; 
	    cout<<num;
		cout<<' ';
		int space;
		if(tim==0) space=3;
		else space=3-(int)log10(tim);
		for(int i=1;i<=space;i++) cout<<' ';
		cout<<tim<<endl;
	}
};
priority_queue<node>q;
int n,m;
string str;
int main(){
	node now;
	cin>>n>>m;
	while(cin>>str){
		int t,pen,sum,cnt;
		now.name=str;
		sum=cnt=0;
		for(int i=1;i<=n;i++){
			if(scanf("%d(%d)",&t,&pen)==2){
				sum=sum+t+pen*m; 
				cnt++;
			}else if(t>0){
				sum+=t;
				cnt++;
			}
		}
		now.num=cnt;
		now.tim=sum;
		//now.print();
		q.push(now);
	}
	while(!q.empty()){
		now=q.top();
		q.pop();
		now.print(); 
	}
	return 0;
}

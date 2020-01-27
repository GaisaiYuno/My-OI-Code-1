//HDU 1509
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	string name;
	int id;
	int num;
	int level;
	friend bool operator <(node a,node b){
		if(a.level==b.level){
			return a.id>b.id;
		}
		else return a.level>b.level;
	}
};
priority_queue<node>pq;
string cmd,na;
int x,l,cnt;
node tmp;
int main(){
	cnt=0;
	while(cin>>cmd){
		if(cmd=="PUT"){
			cin>>na>>x>>l;
			tmp.name=na;
			tmp.num=x;
			tmp.level=l;
			tmp.id=++cnt;
			pq.push(tmp);
		}
		else if(cmd=="GET"){
			if(pq.empty()){
				cout<<"EMPTY QUEUE!"<<endl;
				continue;
			}
			else{
				tmp=pq.top();
				pq.pop();
				cout<<tmp.name<<' '<<tmp.num<<endl;
			}
		}
	}
}

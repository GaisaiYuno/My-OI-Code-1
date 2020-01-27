#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,x,y,k;
string cmd;
struct node{
	int id;
	int level;
	friend bool operator <(node a,node b){
		if(a.level==b.level){
			return a.id>b.id;
		}
		else return a.level<b.level;
	}
};
priority_queue<node>pq1;
priority_queue<node>pq2;
priority_queue<node>pq3;
int main(){
	node tmp;
    while(cin>>n){
    	k=0;
    	while(!pq1.empty()) pq1.pop();
    	while(!pq2.empty()) pq2.pop();
    	while(!pq3.empty()) pq3.pop();
    	for(int i=1;i<=n;i++){
		    cin>>cmd;
		    if(cmd=="IN"){
		    	cin>>x>>y;
		    	tmp.id=++k;
		    	tmp.level=y;
		    	if(x==1) pq1.push(tmp);
		    	if(x==2) pq2.push(tmp);
		    	if(x==3) pq3.push(tmp);
		    }
		    else{
		    	cin>>x;
				if(x==1){
					if(!pq1.empty()){ 
						tmp=pq1.top();
						cout<<tmp.id<<endl;
						pq1.pop();
					}
					else cout<<"EMPTY"<<endl; 
				} 
				if(x==2){
					if(!pq2.empty()){ 
						tmp=pq2.top();
						cout<<tmp.id<<endl;
						pq2.pop();
					}
					else cout<<"EMPTY"<<endl; 
				} 
				if(x==3){
					if(!pq3.empty()){ 
						tmp=pq3.top();
						cout<<tmp.id<<endl;
						pq3.pop();
					}
					else cout<<"EMPTY"<<endl; 
				} 
			}
	    }
	}	
}


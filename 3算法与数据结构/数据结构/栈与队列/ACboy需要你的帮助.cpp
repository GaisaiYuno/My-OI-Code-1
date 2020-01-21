//hdu 1702
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
stack<int>s;
queue<int>q;
string cmd;
int t,x,n;
int main(){
	//freopen("testin.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>n>>cmd;
		if(cmd=="FIFO"){
			while(!q.empty()) q.pop();
			while(n--){
				cin>>cmd;
				if(cmd=="IN"){
					cin>>x;
					q.push(x); 
				}
				else{
					if(q.empty()) cout<<"None"<<endl;
					else{
						cout<<q.front()<<endl;
						q.pop();
					} 
				} 
			}
		}
		else{
			while(!s.empty()) s.pop();
			while(n--){
				cin>>cmd;
				if(cmd=="IN"){
					cin>>x;
					s.push(x); 
				}
				else{
					if(s.empty()) cout<<"None"<<endl;
					else{
					    cout<<s.top()<<endl;
					    s.pop();
					} 
				} 
			}
		}
	}
} 

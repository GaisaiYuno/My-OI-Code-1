//HDU 1022
#include<iostream>
#include<cstdio>
#include<stack>
#define maxn 1005
using namespace std;
int n;
char in[maxn],out[maxn];
stack<char>s;
int main(){
	while(cin>>n){
		cin>>in>>out;
		int i=0,j=0;
		bool ans=true;
		while(!s.empty()) s.pop();
		while(j<n){
			if(in[i]==out[j]){
				i++;
				j++;

			}
			else if(!s.empty()&&s.top()==out[j]){
				s.pop();
				j++;
			}
			else if(i<n){
			    s.push(in[i++]);
			} 
			else{
				ans=false;
				break;
			}
		}
		if(ans){
	   		cout<<"Yes."<<endl;
	   		i=j=0;
	   		while(!s.empty()) s.pop();
	   		while(j<n){
				if(in[i]==out[j]){
					i++;
					j++;
					cout<<"in"<<endl;
					cout<<"out"<<endl;
				}
				else if(!s.empty()&&s.top()==out[j]){
					s.pop();
					cout<<"out"<<endl;
					j++;
				}
				else if(i<n){
			    	s.push(in[i++]);
			    	cout<<"in"<<endl; 
				} 
				else{
					ans=false;
					break;
				}
		    } 
	    }
		else cout<<"No."<<endl; 
		cout<<"FINISH"<<endl;
	}
}

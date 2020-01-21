#include<iostream>
#include<cstring>
#include<map>
using namespace std;
map<string,string>h1;
map<string,string>h2;
int main() {
	int t; 
	string str,s1,s2; 
	while(1) {
		int i;
		getline(cin,str);
		if(str=="@END@") break;
		for(i=0; i<str.length(); i++) {
			if(str[i]==']') break;
		}
		s1=str.substr(0,i+1);
		s2=str.substr(i+2,str.length()-i-1);
		h1[s1]=s2;
		h2[s2]=s1;
	}
	cin>>t;
	getchar();
	while(t--) {
		getline(cin,str);
		bool have_kuo=false;
		for(int i=0; i<str.length(); i++) {
			if(str[i]==']') {
				have_kuo=true;
				break;
			}
		}
		std::map<string,string>::iterator it;
	    if(have_kuo){
	    	it=h1.find(str);
	    	if(it!=h1.end()){
	    		cout<<it->second<<endl;
			}
			else cout<<"what?"<<endl;
		}
		else{
			it=h2.find(str);
			if(it!=h2.end()){
				for(int i=1;i<it->second.length()-1;i++){
					cout<<it->second[i];
				}
				cout<<endl;
			}
			else cout<<"what?"<<endl;
		}
	}
}

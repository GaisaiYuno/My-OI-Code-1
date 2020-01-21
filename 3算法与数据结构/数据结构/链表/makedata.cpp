#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map> 
using namespace std;
map<int,int>group;
int main() {
	freopen("data.txt","w",stdout);
	srand(time(NULL));
	int cas=rand()%5;
	//cout<<cas<<endl;
	while(cas--) {
		int t=rand()%10+1;
		cout<<t<<endl;
		group.clear();
		for(int i=1; i<=t; i++) {
			int n=rand()%10+1;
			cout<<n<<' ';
			for(int i=1; i<=n; i++) {
				int x=rand()%100;
				cout<<x<<' ';
				group[x]=t;
			}
			cout<<endl;
		}
		int k=rand()%30+1;
		while(k--) {
			int type=rand()%4;
			if(type==0) {
				cout<<"DEQUEUE\n";
			} else {
				int id=rand()%group.size();
				std::map<int,int>::iterator it;
				it=group.begin();
				for(int u=1; u<=id; u++) it++;
				printf("ENQUEUE %d\n",it->first);
			}
		}
		cout<<"STOP"<<endl;
		cout<<endl;
	}
}

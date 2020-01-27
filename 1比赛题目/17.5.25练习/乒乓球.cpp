#include<iostream> 
using namespace std;
char in[1000000];
int n,sc1,sc2;
int main(){
	 sc1=0;
	 sc2=0;
	 n=0; 
	while(1){
		cin>>in[n];
		if(in[n]=='E') break;
		n++;
	}
	for(int i=0;i<n;i++){
		if(in[i]=='W') sc1++;
		else sc2++;
		if((sc1>=11&&sc1-sc2>=2)||(sc2>=11&&sc2-sc1>=2)){
			cout<<sc1<<":"<<sc2<<endl;
			sc1=0;
			sc2=0;
		}
	}
    cout<<sc1<<":"<<sc2<<endl<<endl;
	sc1=sc2=0; 
	for(int j=0;j<n;j++){
		if(in[j]=='W') sc1++;
		else sc2++;
		if((sc1>=21&&sc1-sc2>=2)||(sc2>=21&&sc2-sc1>=2)){
			cout<<sc1<<":"<<sc2<<endl;
			sc1=0;
			sc2=0;
		}
	}
	cout<<sc1<<":"<<sc2<<endl;
	return 0;
}

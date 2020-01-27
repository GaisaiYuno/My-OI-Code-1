#include<iostream>
using namespace std;
int length;
string a;
int n;
int ltn;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>length>>a;
		if((a=="East"||a=="West")&&(ltn==20000||ltn==0)){
			cout<<"NO";
			return 0;
		}
		if(a=="East"||a=="West")continue;
		if(a=="North")ltn-=length;
		if(a=="South")ltn+=length;
		if(ltn<0||ltn>20000){
			cout<<"NO";
			return 0;
		}
	}
	if(ltn==0){
		cout<<"YES";
		return 0;
	}
	cout<<"NO";
}

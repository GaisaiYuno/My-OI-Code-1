#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int a,b,c;
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
}

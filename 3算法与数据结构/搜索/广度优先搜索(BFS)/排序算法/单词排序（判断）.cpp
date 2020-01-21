#include<iostream>
#include<algorithm>





using namespace std;
string a[1001];

bool cmp ( string a , string b ) 
{
	return a<b;
  } 

int main() {
	int i=0;
	int temp;
	while(cin>>a[i]) {
		i++;
	}
	sort(a,a+i,cmp);
	for(int j=0; j<i; j++) {
		if(a[j]==a[j+1])
			continue;
		cout<<a[j]<<endl;
	}
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;

bool real(int wei,int num);

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	long int tmp,book[1002]={0},need[1002]={0};
	int cnt,cnt1,wei[1002]={0};
	bool check=0;
	cin>>n>>q;
	for(cnt=1;cnt<=n;cnt++)
		cin>>book[cnt];
	for(cnt=1;cnt<=q;cnt++)
		cin>>wei[cnt]>>need[cnt];
	for(cnt=n;cnt>=1;cnt--)
		for(cnt1=1;cnt1<=cnt;cnt1++)
			if(book[cnt1]>book[cnt])
			{
				tmp=book[cnt1];
				book[cnt1]=book[cnt];
				book[cnt]=tmp;
			}
	for(cnt=1;cnt<=q;cnt++)
	{
		check=0;
		for(cnt1=1;cnt1<=n;cnt1++)
			if(book[cnt1]>=need[cnt])
				if(real(wei[cnt1],book[cnt1]-need[cnt])==1)
				{
					cout<<book[cnt1]<<endl;
					check=1;
					break;
				}
		if(check==0)cout<<-1<<endl;
	}		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

bool real(int wei,int num){
	for(int cnt=1;cnt<=wei;cnt++)
		if(num%10!=0)
			return false;
		else
			num/=10;
	return true;
}

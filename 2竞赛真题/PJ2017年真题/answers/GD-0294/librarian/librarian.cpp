#include <iostream>
#include <fstream>

using namespace std;

int n,q;
long long book[1010];

struct READER /*So Lazy*/
{
	int len;
	long long num;//number of that book that it need
};

READER reader[1010];

inline void input()
{
	cin>>n>>q;
	for (int i=0;i<n;i++)
		cin>>book[i];
	for (int i=0;i<q;i++)
	{
		cin>>reader[i].len;
		cin>>reader[i].num;
	}
}
long long pw(int a,int b)
{
	long long result=1;
	while (b--) result=result*a;
	return result;
}
int check(int num) 
{
	READER *tmp=&reader[num];
	int result=99999999;//position of that book
	int length=pw(10,(*tmp).len);
	
	for (int i=0;i<n;i++)
		if (book[i]%length==(*tmp).num and book[i]<=result) result=book[i];
	
	if (result==99999999) return -1;
	else return result;
}

int main()
{
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	
	input();
	for (int i=0;i<q;i++)
		cout<<check(i)<<endl;
	return 0;
}

#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin("librarian.in");
ofstream fout("librarian.out");
string s[1002];
int change(string s)
{
	int t=0;
	for(int i=0;i<s.size();i++)
		t=t*10+s[i]-'0';
	return t;
}
int main()
{
	int n=0,q=0;
	fin>>n>>q;
	for(int i=1;i<=n;i++)
		fin>>s[i];
	for(int i=1;i<=q;i++)
	{
		string tmp;
		int _min=10000010,tmp_size=0;
		fin>>tmp_size>>tmp;
		for(int j=1;j<=n;j++)
		{
			if(tmp_size<=s[j].size()&&tmp==s[j].substr(s[j].size()-tmp_size,tmp_size))
				_min=min(_min,change(s[j]));
		}
		if(_min==10000010) fout<<-1<<endl;
		else fout<<_min<<endl;
	}
	return 0;
}

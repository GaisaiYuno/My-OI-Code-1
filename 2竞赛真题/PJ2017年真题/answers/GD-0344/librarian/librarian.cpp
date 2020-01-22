#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<cstring>
	using namespace std;
bool cmp(string a,string b)
{
	if(a.size()==b.size()) return a<b;
	return a.size()<b.size();
}
	string s[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int N=0,Q=0;
	cin>>N>>Q;
	for(int i=1;i<=N;i++) cin>>s[i];
	sort(s+1,s+N+1,cmp);
	for(int i=1;i<=Q;i++) 
	{
		int Ln=0;
		string T="";
		bool F=false;
		cin>>Ln>>T;
		for(int j=1;j<=N;j++)
		{
			int Le=s[j].size();
			bool flag=false;
			for(int K1=Le-1,K2=Ln-1;K2>=0;K1--,K2--)
				if(s[j][K1]!=T[K2])
				{
					flag=true;
					break;
				}
			if(flag==false)
			{
				F=true;
				cout<<s[j]<<endl;
				break;
			}
		}
		if(F==false) cout<<-1<<endl;
	}
	return 0;
}

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int N,Q;
string books[1005],readers[1005];
int leng[1005];
int ToNum(string a)
{
    int aa=0;
    for(int i=0;i<a.size();i++)
        aa=aa*10+a[i]-'0';
    return aa;
}
bool comp(string a,string b)
{
    return ToNum(a)<=ToNum(b);
}
bool isok(string book,string reader)
{
    int bb=book.size(),rr=reader.size();
    for(int i=rr-1;i>=0;i--)
    {
        if(reader[i]!=book[bb-rr+i])
            return false;
    }
    return true;
}
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
cin>>N>>Q;
for(int i=1;i<=N;i++)
    cin>>books[i];
for(int i=1;i<=Q;i++)
    cin>>leng[i]>>readers[i];
sort(books+1,books+1+N,comp);
for(int i=1;i<=Q;i++)
{
    bool flag=false;
    for(int j=1;j<=N;j++)
    {
        if(books[j].size()>=readers[i].size() && isok(books[j],readers[i]))
        {
            cout<<books[j]<<endl;
            flag=true;
            break;
        }
    }
    if(flag==false)
        cout<<-1<<endl;
}
    return 0;
}

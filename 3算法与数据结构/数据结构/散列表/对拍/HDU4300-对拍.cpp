#include <bits/stdc++.h>
using namespace std;
const int maxn=100050;
int t,n,nxt[maxn],mid;
char s[maxn],s1[maxn],tag[50];
map<char,int>A,B;
void init()
{
    A.clear();
    B.clear();
    for(int i=0;i<strlen(tag);i++)
    {
        A['a'+i]=tag[i];
        B[tag[i]]='a'+i;
    }
}
void getnxt()
{
    nxt[0]=-1;
    int i=0,j=-1;
    while(i<mid+1)
    {
        if(j==-1||s[i]==s[j]){
            i++;j++;
            nxt[i]=j;
        }
        else j=nxt[j];
    }

}
int kmp()
{
    getnxt();
    int i=0,j=0;
    int len1=strlen(s1);
    while(i<len1)
    {
        if(s1[i]==s[j]||j==-1){i++,j++;}
        else j=nxt[j];
        if(i==len1)return j;
    }
    return 0;
}


int main()
{
	freopen("data.txt","r",stdin);
    cin>>t;
    while(t--)
    {
        scanf("%s%s",tag,s);
        init();
        int len=strlen(s);
        if(len&1) mid=len/2+1;
        else mid=len/2;
        for(int i=0;i<len-mid;i++)
        {
            s1[i]=A[s[mid+i]];
        }
        s1[len-mid]='\0';
        int j=kmp();
        for(int i=0;i<len-j;i++)printf("%c",s[i]);
        for(int i=0;i<len-j;i++)printf("%c",B[s[i]]);

        printf("\n");



    }

    return 0;
}


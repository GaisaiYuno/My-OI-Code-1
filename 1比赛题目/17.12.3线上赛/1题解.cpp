#include<algorithm>
#include<map>
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;
map<string,int>integer;
map<string,double>double_;
map<string,char>character;
int k,i,x;double k_;char c,K;
string op,s,now,now_;
int main()
{
    character["space"]=' ';
    character["enter"]='\n';
    character["tab"]='\t';
    cin>>op>>op;cout<<op<<endl;
    while(cin>>op)
    {
        if(op=="Input_Data")
        {
            continue;
        }
        if(op=="End_Program")return 0;
        if(op=="integer")
        {
            cin>>k;
            while(k--)
            {
                cin>>s;
                integer[s]=0;
            }
        }
        else if(op=="double")
        {
            cin>>k;
            while(k--)
            {
                cin>>s;
                double_[s]=0.0;
            }
        }
        else if(op=="char")
        {
            cin>>k;
            while(k--)
            {
                cin>>s;
                character[s]=0;
            }
        }
        else if(op[0]=='p'&&op[1]=='r'&&op[2]=='i'&&op[3]=='n'&&op[4]=='t'&&op[5]=='(')
        {
            now="";
            for(int i=6;i<op.length()-1;i++)now+=op[i];
            if(integer.count(now))cout<<integer[now];
            else if(double_.count(now))cout<<fixed<<setprecision(6)<<double_[now];
            else if(character.count(now))cout<<character[now];
        }
        else
        {
            cin>>s;
            if(s=="=")
            {
                cin>>s;
                if(integer.count(op))
                {
                    if(integer.count(s))integer[op]=integer[s];
                    else if(double_.count(s))integer[op]=(int)double_[s];
                    else integer[op]=(int)atof(s.c_str());
                }
                else if(double_.count(op))
                {
                    if(double_.count(s))double_[op]=double_[s];
                    else if(integer.count(s))double_[op]=(double)integer[s];
                    else double_[op]=atof(s.c_str());
                }
                else if(character.count(op))
                {
                    if(character.count(s))character[op]=character[s];
                    else character[op]=s[1];
                }
            }
        }
    }
    return 0;
}

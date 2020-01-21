#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
using namespace std;
const int c=10000;
struct myhash{
    struct node {
        long long key;//若key%c相同辅助判重
        string s1;//若key相同辅助判重
        string s2;
        node* next;
    }a[maxn];
    void push(long long x,string s1,string s2) {
        if(a[x%c].key==0) {
            a[x%c].key=x;
            a[x%c].s1=s1;
            a[x%c].s2=s2;
        } else {
            node *tmp=new node();
            tmp->key=x;
            tmp->s1=s1;
            tmp->s2=s2;
            tmp->next=a[x%c].next;//此处相当于head
            a[x%c].next=tmp;
        }
    }
    string found(long long x,string s1) {
        if(a[x%c].key==x&&a[x%c].s1==s1) return a[x%c].s2;
        if(a[x%c].key==0) return "what?";
        else {
            node* tmp=a[x%c].next;
            while(tmp!=NULL) {
                if(tmp->key==x&&tmp->s1==s1) return tmp->s2;
                tmp=tmp->next;
            }
            return "what?";
        }
    }
};
myhash H1,H2;
long long to_num(string str){//以前8位的乘积hash 
    long long ans=1;
    int len=str.length();
    if(len>8) len=8;
    for(int i=0;i<len;i++) ans*=str[i];
    return ans;
}
int main() {
    int t; 
    string str,s1,s2;
    //freopen("hyxzc3.in","r",stdin);
    while(1) {
        int i;
        getline(cin,str);
        if(str=="@END@") break;
        for(i=0; i<str.length(); i++) {
            if(str[i]==']') break;
        }
        s1=str.substr(0,i+1);
        s2=str.substr(i+2,str.length()-i-1);
        H1.push(to_num(s1),s1,s2);
        H2.push(to_num(s2),s2,s1);
    }
    cin>>t;
    getchar();
    while(t--){
        getline(cin,str);
        bool have_kuo=false;
        for(int i=0;i<str.length();i++){
            if(str[i]==']'){
                have_kuo=true;
                break;
            }
        } 
        string tmp;
        if(have_kuo) tmp=H1.found(to_num(str),str);
        else tmp=H2.found(to_num(str),str);
        if(tmp[0]=='['){
            for(int i=1;i<tmp.length()-1;i++)  cout<<tmp[i];
            cout<<endl;
        }
        else cout<<tmp<<endl;
    }
}



#include<iostream>
#include<cstring>
using namespace std;
string word[21];
int same[21][21];
int used[21];
int n, nowlen=0,ans=0;
char start;
int find_same(string a,string b){
	bool flag=true;
	int lena=a.length();
	int k=0;
	for(int i=lena-1;i>=0;i--){
		int slen=lena-i;
		if(a.substr(i,slen)!=b.substr(0,slen)){
			flag=false;
		}
		if(flag==true) return slen;
        else flag=true;//不行就继续
	}
	return 0;
}
void dfs(int t){
	bool flag=false;
	for(int i=1;i<=n;i++){
		if(used[i]==2||same[t][i]==0) continue; 
		if(same[t][i]==word[t].length()||same[t][i]==word[i].length()) continue;
		nowlen+=word[i].length()-same[t][i];
		used[i]++;
		flag=true;
		dfs(i);
		used[i]--;
		nowlen=nowlen-word[i].length()+same[t][i];
	}
	if(flag==false) ans=max(ans,nowlen);
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>word[i];
	cin>>start;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			same[i][j]=find_same(word[i],word[j]); 
		}
	}
	for(int i=1;i<=n;i++){
        if(word[i][0]==start){
            nowlen=word[i].length(); 
            used[i]++;
            dfs(i);
            used[i]=0; 
        } 
    } 
    cout<<ans<<endl; 
}

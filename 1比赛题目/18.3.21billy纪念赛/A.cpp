#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
struct node{
	char v;
	node* lson;
	node* rson;
	node(char c){
		v=c;
		lson=NULL;
		rson=NULL;
	}
};
node* insert(node* root,char a){
	if(root==NULL) return new node(a);
	if(a< (root->v)) root->lson=insert(root->lson,a); 
	else root->rson=insert(root->rson,a);
	return root;
}
void print(node *pos){
	if(pos!=NULL){
		printf("%c",pos->v);
		print(pos->lson);
		print(pos->rson);
	}
}
void del(node *pos){
	if(pos!=NULL){
		del(pos->lson);
		del(pos->rson);
		delete pos;
		pos=NULL;
	}
}
vector<string>vec;
int main(){
	string s;
	while(1){
		vec.clear();
		cin>>s;
		while(s[0]!='*'&&s[0]!='$'){
			vec.push_back(s);
			cin>>s;
		}
		node *root=NULL;
		for(int i=vec.size()-1;i>=0;i--){
			for(int j=0;j<vec[i].length();j++){
				root=insert(root,vec[i][j]);
			}
		}
		print(root);
		del(root);
		if(s[0]=='$') return 0; 
		printf("\n"); 
	}
}

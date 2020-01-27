//洛谷 求先序排列
#include<iostream>
#include<cstring> 
#define maxn 1000
using namespace std;
char in[maxn],post[maxn]; 
int len;
//技巧：后序排列最后一个一定是根
void dfs(int s,int e){
	int t=0;
	if(s>e) return;
    for(int i=len-1;i>=0;i--){
    	for(int j=s;j<=e;j++){
    		if(in[j]==post[i]){
    			t=j;
    			break;
			}
		}
		if(t) break; 
	}
	cout<<in[t];
	dfs(s,t-1);
	dfs(t+1,e);
	return;
}
int main(){
	scanf("%s%*c%s",in,post);//%*c不记录换行） 
	len=strlen(in);
	dfs(0,len-1);
	return 0;
} 

/*解释中序遍历和后序遍历笔算方法
例如中  BDACE
后  DBECA1.由
后序遍历的知道最后一个节点一定是根节点,该例中为A
2.中序中对应的根就是A,推得A为根BD为左子树CE为右子树
3.左子树2个结点右子树也为2个,因为后序遍历是先左再右因此将后序分为两段左DB,右EC
4.而BD由后序遍历知B为根节点，确定左子树的根为B,同理右子树根为C
5.在回到中序中左子树部分 BD (B为根)其右子树为D  左子树部分 根为C右子树为E
如果结点和多的时候判断都是这样递归地进行. 
*/ 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Size 800
#define maxn 50
using namespace std;
struct bign {
    int len,s[Size+5];
    /*
     ���µĹ��캯����C++�����еģ������ǽ��г�ʼ����
     ��ʵ�ϣ�������bign xʱ���ͻ�ִ�������������x.s���㣬����x.len=1��
     ��Ҫ˵�����ǣ���C++�У�������Ҫtypedef�Ϳ���ֱ���ýṹ���������壬����
     ���ṩ���Զ���ʼ�����Ĺ��ܣ������������˵��C++��C���Է��� 
    */
    inline bign() {
        memset(s, 0, sizeof(s));
        len = 1;
    }
    bign(int num) {
        *this = num;
    }
    /*����Ϊconst�����������ǲ��ܶ�const������ֵ���޸�*/
    bign(const char* num) {
        *this = num;
    }
    /*�����ǹ��췽������ʼ��ʱ��ִ����Ӧ�ķ���*/
    bign operator = (int num) {
        char s[Size];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }
    //����������const�ؼ��֣���������x.str()����ı�x��
    string str() const {
        string res = "";
        for(int i = 0; i<len; i++) res = (char)(s[i] + '0') + res;
        if(res=="") res = "0";
        return res;
    }
    void clean() {
        while(len > 1 && !s[len-1]) len--;
    }

    /* ���ز����� */
    bign operator = (const char* num) {
        //����洢���������
        len = strlen(num);
        for(int i = 0; i < len; i++) s[i] = num[len-i-1] - '0';
        return *this;
    }
    bign operator + (const bign& b) const {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; g || i < max(len, b.len); i++) {
            int x = g;
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }
    bign operator * (const bign& b) {
        bign c;
        c.len = len + b.len;
        for(int i = 0; i < len; i++)
            for(int j = 0; j < b.len; j++)
                c.s[i+j] += s[i] * b.s[j];
        for(int i = 0; i < c.len-1; i++) {
            c.s[i+1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }
    bign operator - (const bign& b) {
        bign c;
        c.len = 0;
        for(int i = 0, g = 0; i < len; i++) {
            int x = s[i] - g;
            if(i < b.len) x -= b.s[i];
            if(x >= 0) g = 0;
            else {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }
    bool operator < (const bign& b) const {
        if(len != b.len) return len < b.len;
        for(int i = len-1; i >= 0; i--)
            if(s[i] != b.s[i]) return s[i] < b.s[i];
        return false;
    }
    bool operator > (const bign& b) const {
        return b < *this;
    }
    bool operator <= (const bign& b) {
        return !(b > *this);
    }
    bool operator == (const bign& b) {
        return !(b < *this) && !(*this < b);
    }
    bign operator += (const bign& b) {
        *this = *this + b;
        return *this;
    }
    bign operator -= (const bign& b) {
        *this = *this - b;
        return *this;
    }
};
istream& operator >> (istream &in, bign& x) {
    string s;
    in >> s;
    x = s.c_str();
    return in;
}
ostream& operator << (ostream &out, const bign& x) {
    out << x.str();
    return out;
}

typedef long long ll;
inline bign fast_pow(bign x,ll k){
	bign ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

int n;
bign dp[maxn+5];
bign g[maxn+5];
bign C[maxn+5][maxn+5];
void ini(int n){
	for(int i=0;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	for(int i=1;i<=n;i++) g[i]=fast_pow(2,i*(i-1)/2);
}
int main(){
	ini(maxn);
	for(int i=1;i<=maxn;i++){
		dp[i]=g[i];
		for(int k=1;k<i;k++){
			dp[i]-=C[i-1][k-1]*g[i-k]*dp[k];
		}
	}
	while(scanf("%d",&n)!=EOF&&n!=0){
		cout<<dp[n]<<endl;
	}
}

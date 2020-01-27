#include <iostream>  

#include <string.h>  
using namespace std;  
const int INF = 0x3f3f3f3f;  
struct Monster {  
    int a, b;  
}monster[100005];  
int dp[1005][15];  
int k[1005], p[1005];  
int n, m;  
void complete_packet(int k, int p) {  
    for (int b = 0; b <= 10; ++b) {  
        if (b >= p) {  
            continue;  
      } else {  
            int d = p - b;  
            //生命值小于攻击  
            for (int life = 1; life <= d; ++life) {  
                dp[life][b] = min(dp[life][b], k);  
            }  
            //生命值大于攻击  
            for (int life = d + 1; life <= 1000; ++life) {  
                dp[life][b] = min(dp[life][b], dp[life - d][b] + k);  
            }  
         }  
   }  
}  
int main() {  
      	std::ios::sync_with_stdio(false);   
  int max_b;  
   
     while(cin >> n >> m)
	{  
        max_b = -1;  
        for (int i = 0; i < n; ++i) {  
        
            cin >> monster[i].a >>monster[i].b;
            max_b = max(monster[i].b, max_b);  
        }  
        int flag = 0;  
        for (int i = 0; i < m; ++i) {  
         
             cin >> k[i] >>p[i];
            if (p[i] > max_b) {  
                flag = 1;  
            }  
        }  
        if (!flag) {  
         //   printf("-1\n");  
             cout<<-1<<endl;
            continue;  
        }  
          
        for (int i = 0; i <= 1000; ++i) {  
            for (int j = 0; j <= 10; ++j) {  
                if (i == 0) {  
                    dp[i][j] = 0;  
                } else {  
                    dp[i][j] = INF;  
                }  
            }  
        }  
          
        long long ans = 0;  
          
        for (int i = 0; i < m; ++i) {  
            complete_packet(k[i], p[i]);  
        }  
          
       for (int i = 0; i < n; ++i) {  
            ans += dp[monster[i].a][monster[i].b];  
        }  
          
      
         cout<<ans<<endl;
    }  
}  


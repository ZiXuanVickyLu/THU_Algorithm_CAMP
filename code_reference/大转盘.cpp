#include <iostream>
#include <vector>
 using namespace std;

 int allOne;                //全1 的二进制数，用于二进制“与运算”，allOne=2^(n-1)-1
 vector<bool> vis[2];               //vis : vis[i][u] 表示从u出发值为i的边
 string ans;            //答案

 //计算2^x
 int twoPow(int x)
 {
         return 1 << x;
     }
 //求欧拉回路
void dfs(int u)       //u : 当前所在结点
 {
       for (int i = 0; i < 2; i++)
             {
                 if (!vis[i][u])
                    {
                         int v = ((u << 1) | i) & allOne;       //将u左移一位，然后将最低位置为 i ，再将最高位去掉
                         vis[i][u] = 1;
                         //  递归v，加入数字到ans中
                            dfs(v);
                         ans.push_back('0' + i);
                     }
          }
     }

 // 本函数求解大转盘上的数，你需要把大转盘上的数按顺时针顺序返回
 // n：对应转盘大小，意义与题目描述一致，具体见题目描述。
 // 返回值：将大转盘上的数按顺时针顺序放到一个string中并返回
 string getAnswer(int n)
 {
         //初始化
             allOne = twoPow(n - 1) - 1;
        ans = "";
         for (int i = 0; i < 2; i++)
                vis[i].resize(twoPow(n - 1), 0);
        dfs(0);
         return ans;
     }

 int main() {
         int n;
         scanf("%d", &n);
         cout << getAnswer(n) << endl;
        return 0;
   
}
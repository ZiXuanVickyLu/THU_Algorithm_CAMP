#include <iostream>
#include <vector>
 using namespace std;

 int allOne;                //ȫ1 �Ķ������������ڶ����ơ������㡱��allOne=2^(n-1)-1
 vector<bool> vis[2];               //vis : vis[i][u] ��ʾ��u����ֵΪi�ı�
 string ans;            //��

 //����2^x
 int twoPow(int x)
 {
         return 1 << x;
     }
 //��ŷ����·
void dfs(int u)       //u : ��ǰ���ڽ��
 {
       for (int i = 0; i < 2; i++)
             {
                 if (!vis[i][u])
                    {
                         int v = ((u << 1) | i) & allOne;       //��u����һλ��Ȼ�����λ��Ϊ i ���ٽ����λȥ��
                         vis[i][u] = 1;
                         //  �ݹ�v���������ֵ�ans��
                            dfs(v);
                         ans.push_back('0' + i);
                     }
          }
     }

 // ����������ת���ϵ���������Ҫ�Ѵ�ת���ϵ�����˳ʱ��˳�򷵻�
 // n����Ӧת�̴�С����������Ŀ����һ�£��������Ŀ������
 // ����ֵ������ת���ϵ�����˳ʱ��˳��ŵ�һ��string�в�����
 string getAnswer(int n)
 {
         //��ʼ��
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
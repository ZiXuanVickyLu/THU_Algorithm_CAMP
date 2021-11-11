#include<iostream>
using namespace std;
unsigned long long a[1562505];
typedef unsigned long long ull;
const int SET = 0;
const int CLEAR = 1;
const int TEST = 2;
const int COUNT = 3;
const int SIZE = 4;

struct Operation {
    int type;
    int k;
};

// 代码实现开始
int counting_one(ull a)
{
    int ans = 0;
    for (int i = 0; i < 64; ++i)
        ans += (int)(bool(a & (ull)1 << i));
    return ans;
}
void solve(int n, int m, Operation* operations) {
     long long sizeo = 0;
    for (int i = 0; i < 1562505; i++)
        a[i] = 0;
    for (int i = 0; i < m; i++)
    {
        switch (operations[i].type)
        {
        case SET:
        {
            ull mark = a[operations[i].k / 64];
            if (bool(mark & ((ull)1 << (operations[i].k % 64)))!=0)
                sizeo--;
            a[operations[i].k / 64] |= (ull)1 << (operations[i].k % 64);
            sizeo++;
            break; 
        }

        case CLEAR:
        {
            ull mark = a[operations[i].k / 64];
            if (bool(mark & (ull)1 << (operations[i].k % 64))==0)
                sizeo++;

            a[operations[i].k / 64] &= ~((ull)1 << (operations[i].k % 64));
            sizeo--;
            break;
        }
        case TEST:
        {
            if (a[operations[i].k / 64] & (ull)1 << (operations[i].k % 64))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
            break;
        }

        case COUNT:
        {
            int tmp=counting_one(a[operations[i].k / 64]);
            cout<<tmp<<endl;
            break;
        }
        default:
            cout<<sizeo<<endl;
        }
    }

}

// 代码实现结束
int m;
int main() {
    ios::sync_with_stdio(false);
    int n,  k, type;
    string op;
    cin >> n >> m;
    Operation* ops = new Operation[m];
    for (int i = 0; i < m; ++i) {
        cin >> op;
        if (op == "size") {
            ops[i] = Operation{ SIZE, 0 };
        }
        else {
            cin >> k;
            if (op == "set")
                type = SET;
            else if (op == "clear")
                type = CLEAR;
            else if (op == "test")
                type = TEST;
            else
                type = COUNT;
            ops[i] = Operation{ type, k };
        }
    }
    solve(n, m, ops);
    delete ops;
    return 0;
}

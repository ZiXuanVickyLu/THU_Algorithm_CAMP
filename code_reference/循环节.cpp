#include <cstdio>
#include <cstring>

#define maxl 1000000

/* =========== 代码实现开始 =========== */

char s[maxl + 10];
int Next[maxl + 10];
// s, len: 输入字符串（题目中的c）及长度
// 返回值：题目中 a 串的最短长度
int solve(char* s, int len)
{
	int t= Next[0] = -1;
	int j = 0;
	while (j < len - 1)
	{
		if(t<0||s[j]==s[t])
		{
			j++; t++;
			Next[j] = t;
		}
		else
			t = Next[t];
	}
	
	int k = len-1;
	if (s[k] != s[Next[k]])
		return len;
	else
	{
		while (Next[k] != 0)k--;
		if (s[Next[k]] != s[k])
			k++;
		if (s[Next[k + 1]] != s[k + 1])
			k++;

		return k;
	}
		
}

	/* =========== 代码实现结束 =========== */


	int main()
	{
		int len;
		scanf("%d", &len);
		scanf("%s", s,len+4);
		printf("%d\n", solve(s, len));
			return 0;
	}
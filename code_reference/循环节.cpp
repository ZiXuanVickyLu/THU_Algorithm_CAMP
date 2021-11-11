#include <cstdio>
#include <cstring>

#define maxl 1000000

/* =========== ����ʵ�ֿ�ʼ =========== */

char s[maxl + 10];
int Next[maxl + 10];
// s, len: �����ַ�������Ŀ�е�c��������
// ����ֵ����Ŀ�� a ������̳���
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

	/* =========== ����ʵ�ֽ��� =========== */


	int main()
	{
		int len;
		scanf("%d", &len);
		scanf("%s", s,len+4);
		printf("%d\n", solve(s, len));
			return 0;
	}
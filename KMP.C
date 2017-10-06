#include "KMP.h"

void getNext(String T, int *next)
{
	int i = 1;			//i指向后缀
	int j = 0;			//j指向前缀
	next[1] = 0;

	while (i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int indexKMP(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getNext(S, next);

	while (i <= S[0] && j <= T[0])
	{
		if (0 == j || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}

	if (j > T[0])
		return (i - T[0]);
	else
		return 0;
}
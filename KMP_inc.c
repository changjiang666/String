#include "KMP_inc.h"

void getNextval(String T, int *nextval)
{
	int i = 1;			//i指向后缀
	int j = 0;			//j指向前缀
	nextval[1] = 0;

	while (i < T[0])
	{
		if (0 == j || T[i] == T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

int indexKMP_inc(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int nextval[255];
	getNextval(S, nextval);

	while (i <= S[0] && j <= T[0])
	{
		if (0 == j || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = nextval[j];
	}

	if (j > T[0])
		return (i - T[0]);
	else
		return 0;
}
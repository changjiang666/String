#include "BF.h"


//S[0] = strlen(S), T[0] = strlen(T)
int Index(String S, String T, int pos)
{
	int i = pos;		//i -> S
	int j = 1;			//j -> T
	while (i <= S[0] && j <= T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return (i - T[0]);
	else
		return 0;
}
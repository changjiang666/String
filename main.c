#include "BF.h"
#include "KMP.h"
#include "KMP_inc.h"
#include <stdio.h>

main(void)
{
	char S[] = " hello, world";
	char T[] = " rld";
	S[0] = 12;
	T[0] = 3;
	printf("%d ", indexKMP_inc(S, T, 3));
	system("pause");
	return 0;
}
#include <stdio.h>
#include <errno.h>
#include "rnx.h"

int main()
{
	char str[20]="30400920.05n";
	rdrnx_obs(str);
	printf("test\n");
	return 0;
}
#include <stdio.h>
#include <string.h> 

int rdrnx_obs(char fname[])
{
	char str[255];
	int a;
	FILE *fp=NULL;
	char subtext[14];
	fp=fopen(fname,"r");
	if (fp==NULL)
	{
		printf("can't load file");
		return 1;
	}
	do
	{	
		fgets(str,255,(FILE*)fp);
		printf("%s",str);
		memcpy(subtext,&str[60],13);
		a=strcmp(subtext,"END OF HEADER");
	}while(!feof(fp)&&a!=0);
	fclose(fp);
	return 0;
}
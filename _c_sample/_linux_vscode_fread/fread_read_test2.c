/*读取由 fwrite（}范例的执行结果*/
#include <stdio.h>

#define nmemb 3
struct test
{
	char name[20];
	int size;
} s [nmemb];

void main()
{
	FILE* stream = NULL;
	int i;
	stream =fopen("test2.txt","r");
	
	if(stream != NULL)
	{
		fread(s,sizeof(struct test), nmemb, stream);
		fclose(stream);
		for (i =0; i< nmemb; i++)
		{
			printf("name[%d]=%-20s : size[%d]=%d\n",i ,s[i].name, i, s[i].size);
		}
	}

}
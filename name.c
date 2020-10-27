#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i=0,j=0,k;
	char abc[26][7][16];
	char line[16];
	FILE *fp=fopen("abc.txt","r");
	
	i=0,j=0,k=0;
	while((fgets(line,16,fp))!=NULL)
	{
		if(j>7)
		{
			j=0;
			i++;
		}
		if(!strcmp(line,"\n"))
			printf(" ");
		
		else
		{
			k=0;
			while(k<strlen(line))
			{
				if(line[k]=='\n')
					line[k]=' ';
				k++;
			}		
			strcpy(abc[i][j],line);
		}
		j++;


	}
	
	fclose(fp);
	char name[1000];
	printf("enter your name:\n");
	scanf("%s",name);
	fp=fopen("name.txt","w+");
	i=0,j=0;
	while(i<7)
	{
		j=0;
		while(j<strlen(name))
		{
			fputs(abc[name[j]-97][i],fp);
			j++;
		
		}
		fputs("\n",fp);
		i++;

	
	
	}
	fseek(fp,0,SEEK_SET);
	while((fgets(name,1000,fp))!=NULL)
	{
		printf("%s",name);
	}
	
	fclose(fp);
	
		
}

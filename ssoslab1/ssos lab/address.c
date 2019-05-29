#include<stdio.h>
#include<string.h>
int main()
{
	char op[3],arg1[3],arg2[3],res[3];
	FILE *fp1,*fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s%s",res,arg1,op,arg2);
		if(strcmp(op,"+")==0)
		{
			fprintf(fp2,"\nld R0,%s",arg1);
			fprintf(fp2,"\nld R1,%s",arg2);
			fprintf(fp2,"\nadd R0,R0,R1");
			fprintf(fp2,"\nst %s,R0",res);
		}
		if(strcmp(op,"-")==0)
		{
			fprintf(fp2,"\nld R0,%s",arg1);
			fprintf(fp2,"\nld R1,%s",arg2);
			fprintf(fp2,"\nsub R0,R0,R1");
			fprintf(fp2,"\nst %s,R0",res);
		}
		if(strcmp(op,"*")==0)
		{
			fprintf(fp2,"\nld R0,%s",arg1);
			fprintf(fp2,"\nld R1,%s",arg2);
			fprintf(fp2,"\nmul R0,R0,R1");
			fprintf(fp2,"\nst %s,R0",res);
		}
		if(strcmp(op,"/")==0)
		{
			fprintf(fp2,"\nld R0,%s",arg1);
			fprintf(fp2,"\nld R1,%s",arg2);
			fprintf(fp2,"\ndiv R0,R0,R1");
			fprintf(fp2,"\nst %s,R0",res);
		}
		if(strcmp(op,"=")==0)
		{
			fprintf(fp2,"\nld R0,%s",arg1);
			fprintf(fp2,"\nst %s,R0",res);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
		
		
		
		

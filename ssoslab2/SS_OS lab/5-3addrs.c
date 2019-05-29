#include<stdio.h>
#include<string.h>
int main()
{
	char op[3],arg1[3],arg2[3],res[3];
	FILE *fp1,*fp2;
	fp1=fopen("pg5inputfile.txt","r");
	fp2=fopen("pg5outputfile.txt","w");
while(!feof(fp1))
	{
		fscanf(fp1,"%s%s%s%s",res,arg1,op,arg2);
		if((strcmp(op,"+"))==0)
		{
			fprintf(fp2,"\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nADD R3,R0,R1");
			fprintf(fp2,"\n\nST %s,R3",res);
		}
		if((strcmp(op,"-"))==0)
		{
			fprintf(fp2,"\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nSUB R3,R0,R1");
			fprintf(fp2,"\n\nST %s,R3",res);
		}
		if((strcmp(op,"*"))==0)
		{
			fprintf(fp2,"\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nMUL R3,R0,R1");
			fprintf(fp2,"\n\nST %s,R3",res);
		}
		if((strcmp(op,"/"))==0)
		{
			fprintf(fp2,"\nLD R0,%s",arg1);
			fprintf(fp2,"\nLD R1,%s",arg2);
			fprintf(fp2,"\nDIV R3,R0,R1");
			fprintf(fp2,"\n\nST %s,R3",res);
		}
		if((strcmp(op,"="))==0)
		{
			fprintf(fp2,"\nLD R0,%s",arg1);
			fprintf(fp2,"\n\nST %s,R0",res);
		}
	}
fclose(fp1);
fclose(fp2);
}


#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
typedef struct subscriber {
	char no[10];
	char name[50];
	int dur;
	//int date;
	//int timef;
	char from[30];
	char to[30];
}subscriber;
void addrecords();
void listrecords();
void modifyrecords();
void deleterecords();
void searchrecords();
int main() {
	int ch;
	do {
	printf("\t 1 : Adding new records.\n \t 2 : Listing of records");
	printf("\n\t 3 : Modifying records. \t ");
	printf("\n\t 4 : Searching records.");
	printf("\n\t 5 : Deleting records.\n\t 6 : Exit Program\n");
	printf("Enter choice");
	scanf("%d", &ch);
	switch(ch) {
		case 1 : addrecords();
			   break;
	//	case 2 : listrecords();
		//		 break;
		//case 3 : modifyrecords();
		//	 break;
		
	//	case 4 : searchrecords();
	//		 break;
		//case 5 : deleterecords();
		//	 break;
		case 6 :  exit(0);
		default : printf("Wrong choice");
		}
		}while( ch != 6);
	
	return 0;
}
void addrecords() {
	subscriber t[10];
	int n, i;
	FILE *fp;
	fp = fopen("dat1.txt","w");
	printf("Enter the no. of structures");
	scanf("%d\n", &n);
	printf("Enter in the format:\n1. number\n 2. name\n 3. dur(in mins) \n 4. from\n 5. to\n");
	for(i = 0; i < n; i++) {
		scanf("%[^\n]s  %[^\n]s  %d %[^\n]s %[^\n]s", t[i].no, t[i].name, &t[i].dur, t[i].from, t[i].to);
		fwrite(&t[i],sizeof(t[i]),1,fp);
	}
	fclose(fp);
}

/*void listrecords() {
	subscriber t[10];
	int i;
	FILE *fp;
	if((fp=fopen("main1.txt","r"))==NULL)
		exit(0);
	printf(" Number\t\t Name\t\t\tdur\t\tfrom\t\tto\n");
	while(fread(&t[i],sizeof(subscriber),1,fp)==1)
	{
		printf("%s\t\t%s\t\t\t%d\t\t%s\t\t%s\n", t[i].no, t[i].name, t[i].dur, t[i].from, t[i].to);
	}
	printf("\n");
	
	fclose(fp);
}
void deleterecords() {
	FILE *fp,*fd;
	int flag=1, i;
	char phoneno[10];
	subscriber t[10];
	if((fd=fopen("temp.txt","w"))==NULL)
	exit(0);
	if((fp=fopen("dat1.txt","r"))==NULL)
	exit(0);
	printf("Enter the phone number to be deleted from the Database");
	scanf("%s",phoneno);
	while(fread(&t[i],sizeof(subscriber),1,fp)==1)
	{
		if(strcmp(t[i].no,phoneno)==0)
		{       flag=0;
			continue;

		}
		else
			fwrite(&t[i],sizeof(subscriber),1,fd);
	}
	if(flag==1)
		printf(" Record having phone number %s not found",phoneno);
	remove("dat1.txt");
	rename("temp.txt","file1.txt");
	printf("Record having  %s no is deleted ",phoneno);
	fclose(fp);
	fclose(fd);
}
*/

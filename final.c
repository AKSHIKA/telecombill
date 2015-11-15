/*****************************************************************************
 * Copyright (C) Akshika Borwankar.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include"final.h"
#define LINES 1000
#define MAX 1000
int a[MAX], count = 0;
int main(int argc, char *argv[]) {
	int ch;
	printf("\t\t	TELECOM BILLING SYSTEM\n");
	do { 
	printf("--------------------------------------------------------------------------------\n");
	printf(" \t\t\t\tMENU\n");
	printf("\t\t 1 : List Caller Detailed Record(CDR)\n");
	printf("\t\t 2 : Sort and Print CDR ");
	printf("\n\t\t 3 : Searching CDR");
	printf("\n\t\t 4 : Print Rate Sheet");
	printf("\n\t\t 5 : Print Outgoing Statement");
	printf("\n\t\t 6: Exit\n");
	printf("\t\t  Enter choice:");
	scanf("%d", &ch);
	printf("--------------------------------------------------------------------------------\n");
	switch(ch) {
		case 1 : listcdr();
			 break;
		case 2 : sortcdr();
			 printcdr();
			 break;
		case 3 : searchcdr();
			 break;
		case 4 : prate();
			 break;
		case 5 : sort(a);
			 system("clear");
        		 amount();
        	 	 amount1();
        	 	 amount2();
			break;
		case 6 : system("clear");
			 exit(0);
		default : printf("Wrong choice");
		}
	}while( ch != 6);
	
	
       return 0;
}
void see(char *x, int len) {
	int i, cc = 0, j, r = 0, k;
	char str[1000], str1[10], c[30] = "a";
	data d;
	strcpy(str, x);	
	for(i = 0; i < len; i++) {
		if(str[i] == ',') { 
			for(j = i + 1; j < len; j++) {
				if(str[j] != ',')
					cc = cc * 10 + str[j] - '0';
				else 
					break;
			}
		break;
		}
	}
	d.cc = cc;
	i = 0;
	while(str[i] != ' ') {
		c[i] = str[i];
		i++;
	}
	
	strcpy(d.city, c);
	for(i = len-1; i > 0; i--) {
		if(str[i] != ',' )
			str1[r++] = str[i];
		else
			break;
		
	}
	r = atoi(str1);
	d.rate = r;
	for(i = j; i < len - 2 ; i++) {
		while(str[i] == ',' || str[i] == ' ') {
			int aa = 0;
			for(k = i + 1; k < len - 2; k++) {
				if(str[k] != ',')
					aa = aa * 10 + str[k] - '0';
				else 
					break;
			}
			if(aa > 0) {
				d.ac = aa;
				store(d);
				a[count++] = aa;
				
				
			}
			i = i + 1;
		}
		
	}
}
void store(data x) {
	int h = hash(x.cc);
	data *tmp;
	tmp = (data*)malloc(sizeof(data));
	*tmp = x;
	tmp->next =ht[h] ;
	ht[h] = tmp;
}
void print() {
	int i;
	data *p;
	for(i = 0; i < SIZE; i++) {
		printf(" %d ", i);
		p = ht[i];
		while(p) {
			printf("\t%d %d %d\t\n", p->cc, p->ac, p->rate);
			p = p->next;
		}printf("\n");
	}
	
}
void init() {
	int i;
	for(i = 0; i < SIZE; i++)
		ht[i] = NULL;
		
}
int hash(int key) {
	int i = key % SIZE;
	return i;
}
data *search(int cc, int aa) {
	int h = hash(cc);
	int s = asearch(aa);
	data *p = ht[h];
	data *t = ht[h];
	while(p) {
		if((cc == p->cc) && (s == p->ac)) {
			t = p->next;
			while(t) {                                                    // for more than one match
				if((cc == t->cc) && (s == t->ac)) 
					printf("%d %d %d\n", t->cc, t->ac, t->rate);
				 t = t->next;
			}
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void sort(int a[]) {
	int i, j, temp;
	for(i = 0; i < count; i++) 
		for(j = 0; j < (count-1)-i; j++) {
			if(a[j]  > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
}
int asearch(int aa) { 
	int j, temp;
	for( j = 0; j < count; j++) {
		if(aa < a[j])
			break;
		temp = a[j];
		
	}
	return temp;
}
void amount() {
	FILE *fp;
	char str[10];
	int amt1 = 0, amt2 = 0, amt3 = 0, ch;
	data *t;
	subscriber s;
	fp = fopen("carr1.txt", "r");
	if(fp == NULL) {
		perror("open failed");
		return ;
	}
	while(fscanf(fp, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) {
		int cc = 0, aa = 0;
		strcpy(str, s.edno);
		if(str[0] == '9') {
			int k = 0;
			while(k != 2) {
				cc = cc * 10 + str[k] - '0';
				k++;
			}
			while(k != 4) {
				aa = aa * 10 + str[k] - '0';
				k++;
			}
		}	
		if(str[0] == '3') {
			int k = 0;
			while(k != 3) {
				cc = cc * 10 + str[k] - '0';
				k++;
			}
			while(k != 6) {
				aa = aa * 10 + str[k] - '0';
				k++;
			}
		}
		t = search(cc, aa);
		if(t) { if(!strcmp(t->city, "Afghanistan"))
			amt1 = amt1 + (t->rate * s.dur);
			if(!strcmp(t->city, "Albania"))
			amt2 = amt2 + (t->rate * s.dur);
			if(!strcmp(t->city, "United"))
			amt3 = amt3 + (t->rate * s.dur);
		}
		else 
			amt1 = amt1 + 0;
			amt2 = amt2 + 0;
			amt3 = amt3 + 0;
			  
	} 
	ch = 1;
	printbill(amt1, amt2, amt3, ch); 
	fclose(fp);   
} 
void amount1() {
	FILE *fp;
	char str[10];
	int amt1 = 0, amt2 = 0, amt3 = 0, ch;
	data *t;
	subscriber s;
	fp = fopen("carr2.txt", "r");
	if(fp == NULL) {
		perror("open failed");
		return ;
	}
	while(fscanf(fp, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) {
		int cc = 0, aa = 0;
		strcpy(str, s.edno);
		if(str[0] == '9') {
			int k = 0;
			while(k != 2) {
				cc = cc * 10 + str[k] - '0';
				k++;
			}
			while(k != 4) {
				aa = aa * 10 + str[k] - '0';
				k++;
			}
		}	
		if(str[0] == '3') {
			int k = 0;
			while(k != 3) {
				cc = cc * 10 + str[k] - '0';
				k++;
			}
			while(k != 6) {
				aa = aa * 10 + str[k] - '0';
				k++;
			}
		}
		t = search(cc, aa);
		if(t) { if(!strcmp(t->city, "Afghanistan"))
			amt1 = amt1 + (t->rate * s.dur);
			if(!strcmp(t->city, "Albania"))
			amt2 = amt2 + (t->rate * s.dur);
			if(!strcmp(t->city, "United"))
			amt3 = amt3 + (t->rate * s.dur);
		}
		else 
			amt1 = amt1 + 0;
			amt2 = amt2 + 0;
			amt3 = amt3 + 0; 
	}  
	ch = 2;
	printbill(amt1, amt2, amt3, ch);
	fclose(fp);   
} 
void amount2() {
	FILE *fp;
	char str[10];
	int amt1 = 0, amt2 = 0, amt3 = 0, ch;
	data *t;
	subscriber s;
	fp = fopen("carr3.txt", "r");
	if(fp == NULL) {
		perror("open failed");
		return ;
	}
	while(fscanf(fp, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) {
		int cc = 0, aa = 0;
		strcpy(str, s.edno);
		if(str[0] == '9') {
			int k = 0;
			while(k != 2) {
				cc = cc * 10 + str[k] - '0';
				k++;
			}
			while(k != 4) {
				aa = aa * 10 + str[k] - '0';
				k++;
			}
		}	
		if(str[0] == '3') {
			int k = 0;
			while(k != 3) {
				cc = cc * 10 + str[k] - '0';
				k++;
			}
			while(k != 6) {
				aa = aa * 10 + str[k] - '0';
				k++;
			}
		}
		t = search(cc, aa);
		if(t) { if(!strcmp(t->city, "Afghanistan"))
			amt1 = amt1 + (t->rate * s.dur);
			if(!strcmp(t->city, "Albania"))
			amt2 = amt2 + (t->rate * s.dur);
			if(!strcmp(t->city, "United"))
			amt3 = amt3 + (t->rate * s.dur);
		}
		else 
			amt1 = amt1 + 0;
			amt2 = amt2 + 0;
			amt3 = amt3 + 0;  
	}
	ch = 3;
	printbill(amt1, amt2, amt3, ch);
	fclose(fp);   
} 

void listcdr() {
	FILE *fp;
	subscriber s;
	fp = fopen("dat1.csv","r");
	if(fp == NULL) {
		perror("open failed");
		return ;
	}
	printf("\tCallingno\tCalledno\tDate\t\tTime  Duration  Incomingroute  Outgoingroute\n");
	while(fscanf(fp, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) 
	printf("\t%s\t%s\t%s\t%d\t%d\t%s\t\t%s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
	fclose(fp);
}

void sortcdr() {
	FILE *fp;
	FILE *fd;
	subscriber s;
	int ch;
	fp = fopen("dat1.csv","r");
	if(fp == NULL) {
		perror("open failed");
		return ;
	}
	while(fscanf(fp, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) {
		if(!strcmp(s.to, "carrier1"))
			ch = 1;	
		if(!strcmp(s.to, "carrier2"))
			ch = 2;
		if(!strcmp(s.to, "carrier3"))
			ch = 3;	
		switch(ch) {
				case 1: if(!searchsort(s, 1)) {
						fd = fopen("carr1.txt", "a");
						fprintf(fd, "%s %s %s %d %d %s %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to );
						
					}
					break;
				case 2: if(!searchsort(s, 2)) {
						fd = fopen("carr2.txt", "a");
						fprintf(fd, "%s %s %s %d %d %s %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to );
						
					}
					break;
				case 3:if(!searchsort(s, 3)) {
						fd = fopen("carr3.txt", "a");
						fprintf(fd, "%s %s %s %d %d %s %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to );
						
					}
					break;
		}
	}
	fclose(fp);
}
int searchsort(subscriber t, int ch) {
	FILE *fr;
	int flag = 0;
	subscriber s;
	switch(ch) {
		case 1:fr = fopen("carr1.txt", "r");
			break;
		case 2:fr = fopen("carr2.txt", "r");
			break;
		case 3:fr = fopen("carr3.txt", "r");
			break;
	}
	if(fr == NULL) {
		perror("open failed");
		return 0;
	}
	while(fscanf(fr, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) {
		if(!strcmp(s.ingno, t.ingno))
			if(!strcmp(s.edno, t.edno))
				if(s.time == t.time)
					if(s.dur == t.dur)
						if(!strcmp(s.date, t.date))
							if(!strcmp(s.in, t.in)) {
								if(!strcmp(s.to, t.to)) {
									flag = 1;
									goto aa;
								}
								else
									flag = 0;
							}
	}	
	aa:
	fclose(fr);
	return flag;
}
void searchcdr() {
	char str[20], st[20];
	int a, ch, flag = 1;
	FILE *fr;
	subscriber s;
	printf("Search on the basis of?\n");
	scanf("%s", str);
	if(!strcmp("callingno", str)) {
		printf("Enter the calling no:\n");
		scanf("%s", st);
		ch = 1;
	}
	if(!strcmp("calledno", str)) {
		printf("Enter the called no:\n");
		scanf("%s", st);
		ch = 2;
	}
	if(!strcmp("date", str)) {
		printf("Enter the date:\n");
		scanf("%s", st);
		ch = 3;
	}
	if(!strcmp("incomingroute", str)) {
		printf("Enter the incoming route:\n");
		scanf("%s", st);
		ch = 4;
	}
	if(!strcmp("outgoingroute", str)) {
		printf("Enter the outgoing route:\n");
		scanf("%s", st);
		ch = 5;
	}
	if(!strcmp("time", str)) {
		printf("Enter the time:\n");
		scanf("%d", &a);
		ch = 6;
	}
	if(!strcmp("duration", str)) {
		printf("Enter the duration:\n");
		scanf("%d", &a);
		ch = 7;
	}
	fr = fopen("dat1.csv","r");
	if(fr == NULL) {
		perror("open failed");
		return ;
	}
	while(fscanf(fr, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) {
		switch(ch) {
			case 1: if(!strcmp(st, s.ingno)) {
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
			case 2: if(!strcmp(st, s.edno)) {
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
			case 3: if(!strcmp(st, s.date)) {
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
			case 4: if(!strcmp(st, s.in)){
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
			case 5: if(!strcmp(st, s.to)) {
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
			case 6: if(a == s.time) {
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
			case 7: if(a == s.dur) {
					printf("%s  %s  %s  %d  %d  %s  %s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
					flag = 2;
				}
				break;
		}
	}
	if(flag == 1)
		printf("NOT FOUND\n");
	fclose(fr);
}
void printbill(int amt1, int amt2, int amt3, int ch) {
	printf("\n\n\t\t-----------------------------------------------------------------------------------------------\n");
	printf("\t\t|         		     AB TELECOM PVT. LTD.                                             |\n");
	if(ch == 1)  
	printf("\t\t|              	        OUTGOING STATEMENT OF CARRIER1                                        |\n");
	if(ch == 2)
	printf("\t\t|                       OUTGOING STATEMENT OF CARRIER2                                        |\n");
	if(ch == 3)
	printf("\t\t|                       OUTGOING STATEMENT OF CARRIER3                                        |\n");
	printf("\t\t|	CITY		TIME PERIOD		AMOUNT($)			              |\n");
	printf("\t\t|	AFGHANISTAN	1-JAN TO 30-JAN   	%d					      |\n", amt1);
	printf("\t\t|	ALBANIA		1-JAN TO 30-JAN	        %d					      |\n", amt2);
	printf("\t\t|	UNITED STATES	1-JAN TO 30-JAN 	%d					      |\n", amt3);
	printf("\t\t-----------------------------------------------------------------------------------------------\n");
	printf("\t\t|	TOTAL					$%d					      |\n", amt1 + amt2 +amt3);	
	printf("\t\t-----------------------------------------------------------------------------------------------\n");
	
}
void printcdr() {
	FILE *fr, *fd;
	subscriber s;
	fd = fopen("print.txt", "r");
	int i;
	while(fscanf(fd,"%d", &i) != -1) {
		switch(i) {
			case 1:fr = fopen("carr1.txt", "r");
				printf("\n\t\t\t\tCARRIER 1:\n");
				break;
			case 2:fr = fopen("carr2.txt", "r");
				printf("\n\t\t\t\t CARRIER 2:\n");
				break;
			case 3:fr = fopen("carr3.txt", "r");
				printf("\n\t\t\t CARRIER 3:\n");
				break;
		}
		if(fr == NULL) {
			perror("open failed");
			return ;
		}
		printf("---------------------------------------------------------------------------------\n");
		printf("\tCallingno\tCalledno\tDate\t\tTime  Duration Incomingroute  Outgoingroute\n");
		while(fscanf(fr, "%s %s %s %d %d %s %s", s.ingno, s.edno, s.date, &s.time, &s.dur, s.in, s.to ) != -1) 
		printf("\t%s\t%s\t%s\t%d\t%d\t%s\t\t%s\n", s.ingno, s.edno, s.date, s.time, s.dur, s.in, s.to);
	}
}
void prate() {
	char str[1000], *x[LINES]; 
	int  total = 0, len;
	init();
	FILE *fp = fopen("sample.csv", "r");
	if(fp == NULL) {
		perror("open failed");
		return ;
	}
	printf(" 	RATE SHEET FOR CARRIERS \n");
	while(fgets(str, sizeof(str), fp) != NULL) {
		len  = strlen(str);
		x[total] = malloc(len);
		str[len] = '\0';
		strcpy(x[total], str);
		printf("\t%s", x[total]);
		see(str, len);
		total = total + 1;
		
	}	
}
		


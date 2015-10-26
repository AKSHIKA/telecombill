#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#define LINES 1000
char *mid(char *, int, int);
char *left(char *, int);
int main(int argc, char *argv[]) {
	char str[1000], *x[LINES], *b[1000], *c[1000], *y[1000], *p[1000], xtr[1000], *p1[1000], upl[1000], upr[1000], upr1[1000], *tr[1000];
	int A = 0, B = 0, j = 0, t = 0, r[1000], r1[1000], its = 0, k = 0, l = 0, i = 0, g = 0, g1 = 0, a = 0, i1 = 0,lpp2,lpp1,up,pr,pl;
	printf("FEF");	
	int n, total = 0, len;
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("open failed");
		return errno;
	}
	while(fgets(str, sizeof(str), fp) != NULL) {
		len  = strlen(str);
		x[total] = malloc(len);
		str[len] = '\0';
		strcpy(x[total], str);
		printf("%s", x[total]);
		total = total + 1;
		
	}
        printf("%d", total);
	aaa:
		strcpy(str, x[A]);   //aaa(x[2]);
		if(str[0] == '-')
			goto inthestring;
		else
			goto notinthestring;

	inthestring:
		
		strcpy(xtr, x[A]);
		 l = strlen(xtr);
		printf("%d", l);
		for(its = 1; its < l; its++) {                             // x does not start from 0
		
			strcpy(c[0], mid(x[A], its, 1));
			if(strcmp(c[0],"+") == 0) {
				k = i;
				goto inthestring1;
			}
		}
	end2:
		A = A + 1;
		if(A <= total)
			goto aaa;
		A = 0;
		for(i = 0; i < (B-1); i++) {
			if(b[i] != " ") {
				c[A] = b[i];
				A = A + 1;
			}
		i = 0;
		j = 0;
		t = 1;
	notinthestring:
		b[B] = x[A];
		B = B + 1;
		goto end2;

	inthestring1:
		strcpy(b[B], mid(x[A], 1, k-1));
		strcpy(b[B+1], mid(x[A], k+1, strlen(x[A]-k)));
		B = B + 2;
		goto end2;
		
	
	
	inser2:
		if(strcmp(left(c[i], 1), "-"));
		goto inser;

	inser:
		if(strcmp(left(c[i+1], 1), "-") == 0) {
			p[j] = mid(c[i], 2, strlen(c[i]-1));
			r[j] = t;
			t = t+1;
			j = j+1;
			goto inser1;
		}
		g = i;
		g1 = g+1;
	top:
		if(strcmp(left(c[g1], 1), "-") != 0) {
		strcpy(p1[0], mid(c[g], 2, strlen(c[g]-1)));
		strcpy(p[j],strcat(p1[0], c[g1]));
		r[j] = t;
		j = j+1;
		goto ppp;
	        }
		t = t+1;
		i = g1;
		goto inser;

	ppp:
		g1 = g1+1;
		if(g1 <= a-1)
			goto top;
		else
			goto top1;
	inser1:
		i = i + 1;
		if(i <= B - 1)
			goto inser2;

	top1:
		i = 0;
		i1 = 0;

	ground:
		l = strlen(p[i]);
		for(k = 1; k < l; k++) {
			if(strcmp(mid(p[i], k, 1), "-") == 0)
				goto ground1;
		}
		r1[i1] = r[i];
		p1[i1] = p[i];
		i1 = i1 + 1;
	ground2:
		i = i + 1;
		if(i <= B - 1)
			goto ground;
		else
			goto sss;

	ground1:
		strcpy(upl,left(p[i], k - 1));
		lpp1 = strlen(upl);
		strcpy(upr, mid(p[i], k+1, l-k));
		lpp2 = strlen(upr);
		strcpy(upr1,strcat(left(upl, lpp1-lpp1),upr));
		pl = atoi(upl);
		pr = atoi(upr1);
		for(up = pl; up < pr; up++) {
			strcpy(p1[i1], tr[up]);
			r1[i1] = r[i];
			i1 = i1 + 1;
		}
		goto ground2;
	}
	sss:
		for( i = 0; i < i1-1; i++)
			printf("%d,%s",r1[i],p1[i]);
	return 0;
}
char *mid(char *x,  int l, int pos) { 
	int c = 0;
	char sub[100], st[100], *u;
	strcpy(st, x);                                //strcpy(a[0], left(x[1], 3)); 
	while(c < l) {
		sub[c]  = st[pos+c-1];
		c++;                                       //pos see
	}
	sub[c] = '\0';
	//printf("%s\n", sub);
	u = sub;
	return u;
}
char *left(char *x,  int l) { 
	int c = 0;
	char sub[100], st[100], *u;
	strcpy(st, x);                                //strcpy(a[0], left(x[1], 3)); 
	while(c < l) {
		sub[c]  = st[c];
		c++;
	}
	sub[c] = '\0';
	//printf("%s\n", sub);
	u = sub;
	return u;
}

		
	

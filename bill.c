#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#define LINES 1000000
int main(int argc, char *argv[]) {
	int r[10000000], r1[1000000], a = 0, b = 0, i = 0, total = 0;
	char p[1000000], p1[1000000], c[1000000], x[LINES][1000], str[1000], y[LINES][1000];
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("open failed");
		return errno;
	}
	n = read(fp, str, 1000);
	str[n] = "\0";
	while(fgets(str, sizeof str, fp)) {
		strcpy(x[total], str);
		total++;
	}
	fclose(fp);
	return 0;
}
	
void aaa() {
	if(strcmp(x[a][0],"-") == 0)
		inthestring();
	else
		notinthestring();
}
void inthestring() {
	for(i = 1; i < strlen(x[a]; i++) {
		c = mid(x[a], i, 1);
		if(c == "+") {
			k = i;
			inthestring1();
		}
		i++;
}

void inthestring1() {
	y[b] = mid(x[a], 1, k-1);
	y[b+1]  = mid(x[a], k+1, strlen(x[a]-k));
	b = b+2;
	end1();
}

void notinthestring() {
	y[b] = x[a];
	b = b+1;
	end1();
}

void inser2() {
	if(strcmp(left(c[i], 1), "-")
		inser();
}

void inser() {
	if(strcmp(left(c[i+1], 1), "-") == 0) {
		p[j] = mid(c[i], 2, strlen(c[i]-1);
		r[j] = t;
		t = t+1;
		j = j+1;
		inser1();
	}
	g = i;
	g1 = g+1;
}

void top() {
	if(strcmp(left(c[g1], 1), "-") != 0) {
		p1 = mid(c[g], 2, strlen(c[g]-1));
		p[j] = p1 + c[g1];
		r[j] = t;
		j = j+1;
		ppp();
	}
	t = t+1;
	i = g1;
	inser();
}

void ppp() {
	g1 = g1+1;
	if(g1 <= a-1)
		top();
	else
		top1();
}
void end1() {
	a = a+1;
	if(a <= total)
		aaa();
	a = 0;
	for(i = 0; i< b-1; i++) {
		if(strcmp(y[i], " ") != 0) {
			c[a] = y[i];
			a = a+1;
	}
	i = 0;
	j = 0;
	t = 1;
}
void inser1() {
	i = i+1;
	if(i <= b-1)
		inser2();
}
void top1() {
	i = 0;
	i1 = 0;
}
void ground() {
	l = strlen(p[i]);
	for(k = 1; k < l;k++) {
		if(strcmp(mid(p[i], k, 1), "-") == 0)
			ground1();
	}
	r1[i1] = r[i];
	p1[i1] = p[i];
	i1 = i1 + 1;
}
void ground2() {
	i = i + 1;
	if(i <= b-1)
		ground();
	else
		sss();
}
void ground1() {
	upl = left(p[i], k - 1);
	lpp1 = strlen(upl);
	upr = mid(p[i], k+1, l-k);
	lpp2 = strlen(upr);
	upr1 = left(upl, lpp1-lpp1)+upr;
	upl = atoi(upl)
	upr = atoi(upr1);
	for(up = upl; up < upr; up++) {
		p1[i1] = strr[up];
		r1[i1] = r[i];
		i1 = i1 + 1;
	}
	ground2();
}
void sss() {
	for( i = 0; i < i1-1; i++)
		printf("%d,%s",r1[i],p1[i]
}
char mid(str[d], pos, len) {
	char sub[d][];
	int c = 0;
	while(c < len) {
		sub[d][c] = str[d][pos+c-1];
		c++;
	}
	sub[c] = '\0';
	return sub;
}
char left(str[d], len) {
	char sub[d][];
	while(c < len) {
		sub[d][c]  = str[d][c];
		c++;
	}
	sub[c] = '\0';
	return sub;
}

	
		
		
	

		
		
	
	
	

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
#define SIZE 7
typedef struct data {
	char city[30];
	int cc;
	int ac;
	int rate;
	struct data *next;
}data;
typedef struct subscriber {
	char ingno[11];
	char edno[10];
	int time;
	int dur;
	char date[10];
	char in[10];
	char to[10];
}subscriber;

void listcdr();
void searchcdr();
int searchsort(subscriber , int);
void sortcdr();
void printbill(int, int, int, int);
void see(char *, int);
void prate();
void store(data x);
void print();
void init();
int hash(int);
data *search(int, int);
data *ht[SIZE];	
int asearch(int aa);
void sort(int a[]);
void printcdr();
void amount();
void amount1();
void amount2();


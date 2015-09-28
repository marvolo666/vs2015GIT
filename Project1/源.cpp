#include<stdio.h>
#include<stdlib.h>

void spirit(int *a,int b[]);
void non(int k, int *p);
int compare(int *a, int *b);
void d2num(int *a, int *b);
void print(int *a,int m);
int main() {
	char temp; int mark;
	int orgnums[10] = { 0 };
	int dbnums[10] = { 0 };
	int orgnum[25] = { 0 };
	int dbnum[22] = { 0 };
	
	{
		int i = 0;
	
		temp = getchar(); 
		for (; temp == '0';)temp = getchar();
		
				
		for (; i < 21; i++) {
			if (temp == '\n') {
				mark = i;
				orgnum[i] = -1;
				break;
			}
				orgnum[i] = temp - '0'; 
				temp = getchar();
		}
	}

	spirit(orgnum, orgnums);
	d2num(orgnum, dbnum);
	spirit(dbnum, dbnums);
	if (compare(dbnums, orgnums)) {
		printf("yes\n");
	}
	else printf("no\n");

	print(dbnum, mark);
	
/*	{int i, j, k,a=orgnum,*b=orgnums;
//	printf("*b  %d", *b);
	for (i = 0, j = 10; i < 20; i++) {
		if (a%j != a) {
			k = a%j; 
			non(k, b);
			a = (int)(a / j);
		}


	}

		printf("%d", orgnums[3]);	
		
	}
	*/	


	system("pause");
	return 0;
	
}
void d2num(int *a, int *b) {
	int i = 21, res = 0,j=0;
	for (; i >= 0; i--) {
		if (*(a + i) == -1) {
			; break;
		} 
	}

	if (*a > 4) j = 1;
	*(b + i + j) = -1; i--;
	for (; i >= 0; i--) {
		*(b + i + j) = (*(a + i) * 2 + res) % 10;
		res = (*(a + i) * 2 + res) / 10;

	}
	
		if (j == 1)*b = res;
}

void print(int *a,int m) {
	int i = 0,j=1;
	if (*(a + m) == -1)j=0;
	for (; i < m+j;i++) {
		printf("%d", *(a + i));
	}
	printf("\n");
	
}
void spirit(int *a, int b[]) {
	int i, j, k;
	for (i = 0, j = 10; i < 21; i++) {
		if (*(a + i) == -1)break;
		non(*(a + i), b);
	}

}

void non(int k, int *p){
	switch (k)
	{
	case 0:(*p)++; break;
	case 1:(*(p+1))++; break;
	case 2:(*(p+2))++; break;
	case 3:(*(p+3))++; break;
	case 4:(*(p+4))++; break;
	case 5:(*(p+5))++; break;
	case 6:(*(p+6))++; break;
	case 7:(*(p+7))++; break;
	case 8:(*(p+8))++; break;
	case 9:(*(p+9))++; break;
	default:
		break;
	}
}
int compare(int *a, int *b) {
	int res = 1,i=0;
	for (; i < 11; i++, a++, b++) {
		if (*a != *b)return 0;
	}
	return 1;
}
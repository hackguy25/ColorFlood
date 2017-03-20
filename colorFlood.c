#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "barve.h"

char *polja;
int size;
int s2;
int stanje;
int igralec;
int poljPrvega;
int poljDrugega;
int barva1;
int barva2;

void nastaviBarvo (char barva) {
	switch(barva) {
		
		case 1:
			printf(L_RED);
			break;
		case 2:
			printf(YLW);
			break;
		case 3:
			printf(L_GRN);
			break;
		case 4:
			printf(L_CYN);
			break;
		case 5:
			printf(BLU);
			break;
		case 6:
			printf(L_PRP);
			break;
		default:
			printf(BREZ);
			break;
	}
}

void generirajPolja() {
	
	for (int i = 0; i < s2; i++) {
		
		polja[i] = random() % 6 + 1;
	}
	
	poljPrvega = 1;
	poljDrugega = 1;
}

char varenVnos() {
	
	char vnos = getchar();
	
	while (vnos == '\n') {
		vnos = getchar();
	}
	
	return vnos;
}

void zamenjajIgralca() {
	
	if (igralec == 1) {
		
		igralec = 2;
	}
	else {
		igralec = 1;
	}
}

int preveriKoncnost() {

	if (poljPrvega + poljDrugega < s2) {
		return 1;
	}
	
	return 2;
}

void zacetniZaslon() {
	
	printf(CLEAR);
	printf(OSEMDESET_ZA_TRIDESET);
	
	for (int i = 0; i < 34; i++) {
		putchar(' ');
	}
	
	printf(L_RED); printf("C"); printf(YLW); printf("o"); printf(L_GRN); printf("l");
	printf(L_CYN); printf("o"); printf(L_BLU); printf("r ");
	printf(L_PRP); printf("F"); printf(L_RED); printf("l"); printf(YLW); printf("o");
	printf(L_GRN); printf("o");	printf(L_CYN); printf("d");
	printf(BREZ); printf("\n"); printf("\n");
	
	for (int i = 0; i < 15; i++) {
		putchar(' ');
	}
	
	printf("Made by: Blaž Rojc (https://github.com/hackguy25)\n");
	
	printf("\n\n\n");
	
	for (int i = 0; i < 10; i++) {
		putchar(' ');
	}
	
	printf("Input 1 to start new game (2 players).\n");
	
	for (int i = 0; i < 10; i++) {
		putchar(' ');
	}
	
	printf("Input x to quit anytime.\n");
	
	for (int i = 0; i < 20; i++) {
		putchar('\n');
	}
}

void igralniZaslon() {
	
	printf(CLEAR);
	
	for (int i = 0; i < 12 - size / 2; i++) {
		putchar('\n');
	}
	
	for (int i = 0; i < 36; i++) {
		putchar(' ');
	}
	
	printf("Player %d\n\n", igralec);
	
	for (int vrstica = 0; vrstica < size; vrstica++) {
		for (int i = 0; i < 40 - size; i++) {
			putchar(' ');
		}
		for (int stolpec = 0; stolpec < size; stolpec++) {
			nastaviBarvo(polja[vrstica * size + stolpec]);
			printf(KVAD);
		}
		printf("\n");
	}
	
	printf(BREZ);
	
	for (int i = 0; i < 13 - (size + 1) / 2; i++) {
		putchar('\n');
	}
	
	printf("Colors - 1: "); nastaviBarvo(1); printf(KVAD); nastaviBarvo(0);
	printf(", 2: "); nastaviBarvo(2); printf(KVAD); nastaviBarvo(0);
	printf(", 3: "); nastaviBarvo(3); printf(KVAD); nastaviBarvo(0);
	printf(", 4: "); nastaviBarvo(4); printf(KVAD); nastaviBarvo(0);
	printf(", 5: "); nastaviBarvo(5); printf(KVAD); nastaviBarvo(0);
	printf(", 6: "); nastaviBarvo(6); printf(KVAD); nastaviBarvo(0);
	printf("\n");
}

void koncniZaslon() {
	
	printf(CLEAR);
	
	for (int i = 0; i < 12 - size / 2; i++) {
		putchar('\n');
	}
	
	if (igralec == 0) {
		
		for (int i = 0; i < 34; i++) {
			putchar(' ');
		}
		
		printf("It's a draw!\n\n");
	}
	else {
		
		for (int i = 0; i < 33; i++) {
			putchar(' ');
		}
		
		printf("Player %d wins!\n\n", igralec);
	}
	
	for (int vrstica = 0; vrstica < size; vrstica++) {
		for (int i = 0; i < 40 - size; i++) {
			putchar(' ');
		}
		for (int stolpec = 0; stolpec < size; stolpec++) {
			nastaviBarvo(polja[vrstica * size + stolpec]);
			printf(KVAD);
		}
		printf("\n");
	}
	
	printf(BREZ);
	
	for (int i = 0; i < 13 - (size + 1) / 2; i++) {
		putchar('\n');
	}
	
	printf("Input x to quit.\n");
}

void naNovo () {
	switch (stanje) {
		
		case 0:
			zacetniZaslon();
			break;
		case 1:
			igralniZaslon();
			break;
		case 2:
			koncniZaslon();
			break;
		default:
			printf(CLEAR);
			printf("Something went wrong somewhere! Input x to exit.\n");
			break;
	}
}

int preveriVeljavnost (char vnos) {
	
	vnos -= 48;
	
	if (vnos == barva1) {
		if (igralec == 1) {
			return 2;
		}
		else {
			return 1;
		}
	}
	else if (vnos == barva2) {
		if (igralec == 1) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else {
		return 0;//#kul #čuj//
	}
}

int floodFill (int x, int y, char target, char replace) {
	
	int idx = y * size + x;
	
	if (x > size - 1 || y > size - 1 || x < 0 || y < 0 || polja[idx] != target) {
	
		return 0;
	}
	
	if (polja[idx] == replace) {
		
		return 1;
	}
	
	polja[idx] = replace;
	int vrni = 1;
	
	vrni += floodFill(x-1, y, target, replace);
	vrni += floodFill(x, y-1, target, replace);
	vrni += floodFill(x+1, y, target, replace);
	vrni += floodFill(x, y+1, target, replace);
	
	return vrni;
}

void zamenjajBarvo (char vnos) {
	
	if (igralec == 1) {
		poljPrvega = floodFill(0, 0, barva1, vnos);
		barva1 = vnos;
	}
	else {
		poljDrugega = floodFill(size - 1, size - 1, barva2, vnos);
		barva2 = vnos;
	}
}

void dobiZmagovalca() {
	
	if (poljPrvega < poljDrugega) {
		igralec = 2;
	}
	else if (poljPrvega > poljDrugega) {
		igralec = 1;
	}
	else {
		igralec = 0;
	}
}

int main() {
	
	zacetniZaslon();
	printf("\n");
	
	srandom(clock() % 4000000000);
	
	char vnos = varenVnos();
	stanje = 0;
	
	while(vnos != 'x') {
		
		if (stanje == 0 && vnos == '1') {
			
			naNovo();
			
			printf("Input number of fields in each dimension (2 - 24):\n");
			scanf("%d", &size);
			
			while (size < 2 || size > 24) {
				
				naNovo();
				printf("Invalid size! Input number of fields in each dimension (2 - 24):\n");
				scanf("%d", &size);
			}
			
			s2 = size * size;
			
			polja = malloc(s2 * sizeof(char));
			
			generirajPolja();
			
			barva1 = polja[0];
			barva2 = polja[s2 - 1];
			
			igralec = 1;
			stanje = 1;
			
			igralniZaslon();
			putchar('\n');
		}
		else if (stanje == 1 && vnos >= '1' && vnos <= '6') {
			if (preveriVeljavnost(vnos) == 0) {
				
				zamenjajBarvo(vnos - '0');
				stanje = preveriKoncnost();
				
				if (stanje == 1) {
					
					zamenjajIgralca();
					naNovo();
					printf("\n");
				}
				else if (stanje == 2) {
					
					dobiZmagovalca();
					koncniZaslon();
					printf("\n");
				}
			}
			else if (preveriVeljavnost(vnos) == 1) {
				naNovo();
				printf("Invalid input! You cannot choose your opponent's color.\n");
			}
			else if (preveriVeljavnost(vnos) == 2) {
				naNovo();
				printf("Invalid input! You cannot choose your current color.\n");
			}
			else {
				naNovo();
				printf("Invalid input! Something went wrong.\n");
			}
		}
		else {
			
			naNovo();
			printf("Invalid input! You chose %c.\n", vnos);
		}
		
		vnos = varenVnos();
	}
	
	printf(BREZ);
	printf(CLEAR);
	printf(OSEMDESET_ZA_STIRIINDVAJSET);
	
	return 0;
}

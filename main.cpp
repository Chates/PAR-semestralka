#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

unsigned int n; // Pocet uzlu v grafu
unsigned int min_rez = INT_MAX;

unsigned int hodnotaRezu(int ** graph, bool *b);
void minHran(int **graph, int b_count, bool *b);

int main () {
    FILE *fr;
    unsigned int c, i, j; // Pomocne promenne, idexy
	
	
    if ((fr = fopen("/Volumes/Macintosh HDD 2/graf8_4.txt", "r")) != NULL) {
		
        fscanf(fr, "%d", &n); // Nacteni poctu uzlu v grafu do promenne n
		fgetc(fr); // odskoci znak konce radky
        //printf("%d", n);
		
		//int graph[n][n];
		
		 int **graph = new int*[n];
		 for (i=0; i<n; i++) {
		 graph[i] = new int[n];
		 }
		 
		
        for (i = 0; i < n; i++) {
			j = 0;
            while ((c = getc(fr)) != '\n') {
				
				
				if (i <= j) { // jen pro horni trojuhelnikovou matici a diagonalu
					graph[i][j] = c - 48;
					if (graph[i][j] == 1) {
						graph[i][j] = random() %255 + 1;
					}
					graph[j][i] = graph[i][j];
				}
				
                printf("%d ", graph[i][j]);
				j++;
            }
            putchar('\n');
        }
        fclose(fr);
		
		bool b[n];
		for (i=0; i<n; i++) {
			b[i] = false;
		}
		minHran(graph, 0, b);
		
    } else {
        printf("Soubor s grafem se nepodarilo otevrit");
    }
	
	//int graphTest[100][100];
	//sequence(graphTest);
	printf("%d",min_rez);

    return 0;
}

void minHran(int **graph, int b_count, bool *b) {
    // n = rozmer, pocet hran
	
    // init hodnoty
    // n = pocet uzlu, b_count = 0
    // b = pole dirty bitu; oznacuje, ktere uzly predavame do dalsi iterace (T = predavame)
	
    int i;
    for (i = 0; i < (n - b_count); i++) {
		
        if (b_count != 0) { // vime, ze nemame prvni iteraci
			// , tudiz provadime vypocet
            // ... (aktualizace min
            if (min_rez > hodnotaRezu(graph, b)) {
                min_rez = hodnotaRezu(graph, b);
            }
			
			
        }
		
        // pridavame uzel do dalsi iterace rekurze
        b[i] = true;
		
        // nova iterace rekurze; stejny graf; mame uzel navic
        minHran(graph, b_count + 1, b);
		
		
    }
	
	
}

unsigned int hodnotaRezu(int ** graph, bool *b) {
	
    int i,j;
    unsigned int total = 0;
    for (i = 0; i < n; i++) { // projedeme vsechny radky
		
        if (b[i] == true) { // resime jen spravne radky
			
            for (j = 0; j < n; j++) {
				
                if (b[j] == false) total += graph[i][j]; // vynechavame sloupce
				
            }
			
        }
		
    }
	
    return (total);
	
}












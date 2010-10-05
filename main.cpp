#include <iostream>
#include <stdio.h>

using namespace std;

unsigned int n; // Pocet uzlu v grafu
long min = 0;



int main () {    
	FILE *fr;
    unsigned int c, i, j; // Pomocne promenne, idexy

	
    if ((fr = fopen("/Volumes/Macintosh HDD 2/graf20_10.txt", "r")) != NULL) {
		
        fscanf(fr, "%d", &n); // Nacteni poctu uzlu v grafu do promenne n
		fgetc(fr); // odskoci znak konce radky
        //printf("%d", n);
		
		int graph[n][n];
		/*
        int **graph = new *int[n];
		for (i=0; i<n; i++) {
			graph[i] = new int[n];
		}
		 */
		
        for (i = 0; i < n; i++) {
			j = 0;
            while ((c = getc(fr)) != '\n') {				
				
				
				if (i <= j) { // jen pro horni trojuhelnikovou matici a diagonalu
					graph[i][j] = c - 48;
					if (graph[i][j] == 1) {
						graph[i][j] = rand() % 255 + 1;
					}
					graph[j][i] = graph[i][j];
				}
				
                printf("%d ", graph[i][j]);
				j++;
            }
            putchar('\n');
        }
        fclose(fr);
		
		
    } else {
        printf("Soubor s grafem se nepodarilo otevrit");
    }
	
	//int graphTest[100][100];
	//sequence(graphTest);
	
    return 0;
}










#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <time.h>

#include "mergequick.h"

/**
 * El procediment particio, anirà ordenant fragments de l'array segons els cursors rebuts.
 * @param: El procediment rebrà l'array a ordenar i els cursors per fer-ho.
 * @return No te retorn ja que és un procediment i els paràmetres són passats per referència.
 *
 */

void particio (int *a, int i, int j, int *s, int *t) {
	int mig, pivot, tmp;

	*s=i;
	*t=j;
	mig = (i+j)/2;
	pivot = a[mig];

	while ( *s <= *t) {

		while (a[*s] < pivot ) {
			*s = *s+1;
		}

		while (a[*t] > pivot) {
			*t=*t-1;
		}

		if ( *s < *t) {
			tmp = a[*s];
			a[*s] = a[*t];
			a[*t] = tmp;
			*s = (*s)++;
			(*t)--;
		} else if ( *s == *t) {
			(*s)++;
			(*t)--;
		} else if ( *s > *t) {
			}

		}
}

/**
 * El procediment Merge, ordenarà una part de l'array que rebrà segona els cursors ( i,j)
 * @param: Rebrà l'array a ordenar i els cursors per saber quin troç ha d'ordenar. A més, rebrà un array auxiliar per poder fer la
 * seva tasca.
 * @return No te retorn ja que es tracta d'un procediment i els paràmetres són passats per referència.
 */
void merge (int *a, int i, int mig, int j,int *b) {

	int k1, k2, cursor, kr;
	k1 = i;
	k2 = mig+1;
	cursor = 0;

	while((k1 <= mig) && (k2 <= j)) {
		if( a[k1] <= a[k2]){
			b[cursor] = a[k1];
			k1 = k1+1;
			cursor = cursor+1;
		}
		if (a[k1] > a[k2]) {
			b[cursor] = a[k2];
			k2 = k2+1;
			cursor = cursor+1;
		}
	}
	while ( k1 <= mig) {
		b[cursor] = a[k1];
		k1 = k1+1;
		cursor = cursor+1;
	}
	while (k2 <= j) {
		b[cursor] = a[k2];
		k2 = k2+1;
		cursor = cursor+1;
	}

	cursor = 0;
	kr = i;


	while (kr <= j) {
		a[kr] = b[cursor];
		kr = kr+1;
		cursor = cursor+1;
	}

}
/**
 * Aquest procediment, al igual que el mergesort anirà partin l'array en trossos més petits segons els cursors que rebi. A més,
 * anirà cridant a Merge un cop arribat al cas trivial.
 * @param: El procediment rep l'arry a partir i els cursors que li inidicaran com fer-ho.
 * @return No te retorn ja que és un procediment i tots els paràmetres son passats per referència.
 * @see particio
 */

void Quicksort (int *a, int i, int j){
 	int s, t;

 	if(i<j){
 		particio (a,i,j, &s, &t);
 		Quicksort(a,i,t);
 		Quicksort(a,s,j);
 	}
}

/**
 * El procediment OrdenaMerge anirà partint l'array que rep en trossos més petits fins arribar al cas trivial (i=j).
 * Un cop arribat al cas trivial per cada crida, aquest procediment anirà cridant a merge.
 * @param: El procediment rebrà l'array fraccionar, els cursors que li indicaran com ha de partir-lo i un array auxiliar que serà
 * enviat a merge.
 * @see merge
 *
 */
void ordenaMerge(int *a, int i, int j,int *b ){

	int mig;
	if (i < j){
		mig = (i + j)/2;
		ordenaMerge(a, i, mig,b);
		ordenaMerge (a, mig+1, j,b);
		merge (a, i, mig, j,b);

	}
}

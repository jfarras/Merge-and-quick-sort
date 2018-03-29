/**
 * @mainpage
 * Aquesta �s la documentaci� del projecte MergeQuick. Aquest projecte consisteix en la creaci� d'una API per poder utilitzar-la en
 * futurs projectes i aix� simplificar la tasca.
 * @author Jordi Farr�s.
 * @date  18/12/2012
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <ctype.h>
#include <time.h>
#include "mergequick.h"

/**
 * El main, ser� la funci�o des d'on es faran les crides a les diferents funcionaitats de la nostre API d'ordenaci�( funcionalitats
 * del mergesort i quicksort).
 * @param: La funci� rep els par�metres que s'introdueixen per l�nea de comandes ( algorisme d'ordenaci�, mida array)
 * @see getopt
 *
 */


int main(int argc, char **argv) {

	int mida, qflag=0, mflag=0,nflag, *a,aleatori,i, *b;
    int index;
    int c;
    opterr = 0;
    char *cvalue = NULL;
    srand(time(NULL));
    /**
     * La funci� getopt ens permetr� tractar els par�metres que s'introdueixen per linia de comandes.
     * @param: la funcio rebr� els par�metres de la linia de comandes ( nom executable, algorisme d'ordenaci�, dimensi� array)
     * @return La funci� retorna el/s car�cter/s entrat/s.
     */
	while ((c = getopt (argc, argv, "qmn:")) != -1){

		switch (c){
	    		case 'q':
	    			qflag = 1;
	    			break;
	    		case 'm':
	    			mflag = 1;
	    			break;
	            case 'n':
	            	if (!qflag && !mflag){
	            		//quicksort;
	            	}
	            	nflag=1;
	            	cvalue =optarg;
	            	mida = atoi(cvalue);
	            	break;
	            case '?':
	            if (optopt == 'n')
	            fprintf (stderr, "Option -%c requires an argument.\n", optopt);
	            else if (isprint (optopt))
	            fprintf (stderr, "Unknown option `-%c'.\n", optopt);
	            else
	            fprintf (stderr,
	                        "Unknown option character `\\x%x'.\n",
	                        optopt);
	             return 1;
	           default:
	             abort ();
	           }
		}
	a =(int *)malloc(sizeof(int)*mida);
	if (a==NULL){
		printf("ERROR!\n");
	}else{
		printf("\nARRAY INICIAL:\n\n");
		for(i = 0;i<mida;++i){
			a[i] = aleatori= rand() % 100;
			printf("%d ",a[i]);
		}
		if(qflag) {
			Quicksort(a,0,mida-1);
			printf("\n\nORDENAT PER QUICK\n\n");
			for(i=0;i<mida;++i){
				printf("%d ",a[i]);
			}
		}
		if(mflag){
				b =(int *)malloc(sizeof(int)*mida);
				if ( b == NULL){
					printf("Error de mem�ria\n");
				}
				ordenaMerge(a, 0, mida-1,b);
				printf("\n\nORDENAT PER MERGE:\n\n");
				for(i=0;i<mida;++i){
					printf("%d ",a[i]);
				}
			}
			else{
				Quicksort(a,0,mida-1);
				printf("\n\nORDENAT PER QUICK:\n\n");
				for(i=0;i<mida;++i){
					printf("%d ",a[i]);
				}
			}
	}
	return 0;
}

/**
 * @mainpage
 * Aquesta és la documentació del projecte MergeQuick. Aquest projecte consisteix en la creació d'una API per poder utilitzar-la en
 * futurs projectes i així simplificar la tasca.
 * @author Jordi Farràs.
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
 * El main, serà la funciço des d'on es faran les crides a les diferents funcionaitats de la nostre API d'ordenació( funcionalitats
 * del mergesort i quicksort).
 * @param: La funció rep els paràmetres que s'introdueixen per línea de comandes ( algorisme d'ordenació, mida array)
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
     * La funció getopt ens permetrà tractar els paràmetres que s'introdueixen per linia de comandes.
     * @param: la funcio rebrà els paràmetres de la linia de comandes ( nom executable, algorisme d'ordenació, dimensió array)
     * @return La funció retorna el/s caràcter/s entrat/s.
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
					printf("Error de memòria\n");
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

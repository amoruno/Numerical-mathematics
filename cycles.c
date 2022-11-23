/* AITOR MORUNO */
/* 04MAY2022 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, n, j, *aux, *p, inicial, EsCicle, b, k, suma;

    printf("Dona el tamany de la permutació {0,1,...,n-1}\n");
    scanf("%d", &n);
    
    /* Reserva memoria dinàmica */
    p = (int *)malloc(n*sizeof(int));
    aux = (int *)malloc(n*sizeof(int));
    
    printf("Introdueix la permutacio\n");
    suma = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &p[i]);
        suma += p[i];
    }
    
    /* Mirar si es permutacio o no */
    if(suma != n*(n-1)/2){
        printf("La permutació no és correcta\n");
        exit(1);
    }
    for(i = 0; i < n; i++){
        if(p[i] != -1){
            inicial = p[i];
            b = inicial;
            aux[0] = inicial;
            EsCicle = 0;
            j = 1;
            
            while(EsCicle == 0 && j < n){
                b = p[b];
                if(inicial == b){
                    EsCicle = 1;
                }else{
                    aux[j] = b;
                    j++;
                }
            }
            
            if(EsCicle == 1){
                printf("El cicle es: \n");
                for(k = 0; k < j; k++){
                    printf("%d \n", aux[k]);
                    p[aux[k]] = -1;
                }
            }
        }
    }
    free(aux);
    free(p);
    return 0;
}

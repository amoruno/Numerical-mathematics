# Aitor Moruno 
# 15JUL2022

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double dist(int, double *, double *y);
double f(int, int, double **, double *);
int iter(int, int, double **, double *, double *, double);

int main(void){
	double *x, **q, h = 10e-1, prec = 10e-6, valor, fx;
	char filename[30], fileresults[30];
	FILE *fp;
	int n, m, i, j, itermax = 1000, k = 0, funciona;

	printf("Give the name of the file\n");
	scanf("%s", filename);

	/* Open file */
	fp = fopen(filename
		   , "r");
	if(fp == NULL){
		printf("Error opening file");
		exit(1);
	}
	fscanf(fp, "%d %d", &n, &m);
	
	/* Dynamic memory allocation for matrix q */
	q = (double **)malloc(m*sizeof(double *));
	if(q == NULL){
		printf("Dynamic memory allocation of q failed");
		fclose(fp);
		exit(1);
	}
	for(i = 0; i < m; i++){
		q[i] = (double *)malloc(n*sizeof(double));
		if(q[i] == NULL){
			printf("Dynamic memory allocation for q failed in vector q[%d]", i);
			fclose(fp);
			exit(1);
		}
		for(j = 0; j < n; j++){
			fscanf(fp, "%lf", &q[i][j]);
		}
	}
	fscanf(fp, "%s", fileresults);
	fclose(fp);

	/* Dynamic memory allocation for x */
	x = (double *)malloc(n*sizeof(double));
	if(x == NULL){
		printf("Error in memory allocation for x");
		exit(1);
	}
	
	/* Open file to print results */

	fp = fopen(fileresults, "w");
	if(fp == NULL){
		printf("Error opening file with results");
		exit(1);
	}
	
	/* Initial approximation of the solution */
	fprintf(fp, "iter k=%d x:", k);
	for(i = 0; i < n; i++){
		valor = 0;
		for(j = 0; j < m; j++){
			valor += q[j][i];
		}
		x[i] = valor/m;
		fprintf(fp, " %le,", x[i]);
	}
	fx = f(m, n, q, x);	
	fprintf(fp, " fx = %le\n", fx);

	/* Iterative method */
	
	while (k < itermax && h >= prec){
		funciona = iter(m, n, q, x, &fx, h);
		if(funciona == 1){
			k += 1;
			fprintf(fp, "h = %le\n", h);
			fprintf(fp, "iter k = %d x:", k);
			for(i = 0; i < n; i++){
				fprintf(fp, " %le,", x[i]);			
			}
			fprintf(fp, " fx= %le\n", fx);
		}
		else{
			h = h/10;
			while(h >= prec && funciona == 0){
				funciona = iter(m, n, q, x, &fx, h);
				if(funciona == 1){
					k += 1;
					fprintf(fp, "h = %le\n", h);
					fprintf(fp, "iter k = %d x:", k);
					for(i = 0; i < n; i++){
						fprintf(fp, " %le,", x[i]);
					}	
					fprintf(fp, " fx=%le\n", fx);
					}
				else{
					h = h/10;
				}
			}
	        }
	}
	if(h < prec){
		fprintf(fp, "S'ha pogut obtenir l'aproximació amb precisió desitjada ja que h = %le < %le = prec\n", h, prec);
		fprintf(fp, "La solució trobada x:");
		for(i = 0; i < n; i++){
			fprintf(fp, " %le,", x[i]);
		}
		fprintf(fp, " fx = %le", fx);
	}
	fclose(fp);
	/* Alliberem tota la memoria */
	free(x);
	for(i = 0; i < n; i++){
		free(q[i]);
	}
	free(q);
	return 0;
}

double dist(int n, double *x, double *y){
	double distancia = 0;
	int i;
	for(i = 0; i < n; i++){
		distancia += (x[i]-y[i])*(x[i]-y[i]);		
	}
	return pow(distancia, 0.5);
}

double f(int m, int n, double **q, double *x){
	double suma = 0, *qvector;
	int i, j;	

	qvector = (double *)malloc(n*sizeof(double));
	if(qvector == NULL){
		printf("No hi ha memoria per guardar q");
		exit(1);
	}
	
	for(i = 0; i < m; i++){
		/* Copiem q[m][·] al vector qvector[] */
		for(j = 0; j < n; j++){
			qvector[j] = q[i][j];
		}
		/* Calculem la distancia entre q[j] i x */
		suma += dist(n, x, qvector);
	}
	free(qvector);
	return suma;
}

int iter(int m, int n, double **q, double *x, double *fx, double h){
	double *z;
	int k, i, j, signe = 1;

	z = (double *)malloc(n*sizeof(double));
	if(z == NULL){
		printf("Error amb memoria de z");
		exit(1);
	}
	/* Initialize z to x */
	z = x;
	for(k = 0; k < 2*n; k++){
		i = k/2;
		z[i] += signe*h;	
		if(f(m, n, q, z) < f(m, n, q, x)){
			/* New approximation z */
			for(j = 0; j < n; j++){
				x[j] = z[j];
			}
			*fx = f(m, n, q, z);
			free(z);
			return 1;
		}
		/* Undo change on z */
		z[i] -= signe*h;
		/* Next iteration will change sign */
		signe = -1*signe;
	}
	free(z);
	return 0;
}

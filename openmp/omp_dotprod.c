#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define THREADS 4
#define TAMANHO_BASE 2000000
#define REPETICOES 2000

typedef struct{
    double *a;
    double *b;
    double c;
    int wsize;
    int repeat;
} dotdata_t;
dotdata_t dotdata;

/* TEMPO E FILL */
long wtime(){
   struct timeval t;
   gettimeofday(&t, NULL);
   return t.tv_sec*1000000 + t.tv_usec;
}
void fill(double *a, int size, double value){
   int i;
   for (i = 0; i < size; i++) {
      a[i] = value;
   }
}

void *dotprod_worker(){
   int i, k;
   int offset = omp_get_thread_num();
   double *a = dotdata.a;
   double *b = dotdata.b;
   int wsize = dotdata.wsize;
   int start = offset*wsize;
   int end = start + wsize;
   double mysum;

  #pragma omp parallel for // MODIFICAÇÃO DO OMP
   for (k = 0; k < dotdata.repeat; k++) {
      mysum = 0.0;
      for (i = start; i < end ; i++)  {
         mysum += (a[i] * b[i]);
      }
   }
   dotdata.c += mysum;
}

void InitOMP(int nthreads){
   omp_set_num_threads(nthreads);
   #pragma omp parallel
   {
      dotprod_worker();
   }
}

void ManagerThread(int nthreads, int wsize, int repeat){

   long start_time, end_time;

   dotdata.a = (double *) malloc(wsize*nthreads*sizeof(double));
   fill(dotdata.a, wsize*nthreads, 0.01);

   dotdata.b = (double *) malloc(wsize*nthreads*sizeof(double));
   fill(dotdata.b, wsize*nthreads, 1.0);

   dotdata.c = 0.0;

   dotdata.wsize = wsize;
   dotdata.repeat = repeat;

   start_time = wtime();
   InitOMP(nthreads);
   end_time = wtime();

   printf("%f\n", dotdata.c);
   printf("%d thread(s), tamanho = %i, repeticoes = %d, %ld usec\n", nthreads, wsize, repeat, (long) (end_time - start_time));
   fflush(stdout);

   free(dotdata.a);
   free(dotdata.b);
}

int main(){
   ManagerThread(THREADS, (int) TAMANHO_BASE/THREADS, REPETICOES);
}



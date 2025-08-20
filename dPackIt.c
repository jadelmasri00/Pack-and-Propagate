#include<stdio.h>
#include<stdlib.h>

int **AL;
int *deg;
int n,e;
int *seeds;

int maxDeg(int *col)
{
   int i=0, md = 0, s, mi = -1;

   while(i<n && (seeds[i] == 1 || col[i] != 0))
      i++;
   s=i;
   if(s == n || seeds[s] == 1 || col[s] != 0)
      return -1; 
   mi = s; 
   md = deg[s];
   for(i=s; i<n; i++)
      if(seeds[i] == 0 && col[i] == 0 && deg[i] > md){md=deg[i];mi=i;}
   return mi;
}

int packIt(int *crs, int d)
{
   int x,v,w,i,j,*col, *Q, count = 0, first = 0, last = 0;
   Q = (int *) malloc(n * sizeof(int));
   col = (int *) malloc(n * sizeof(int));
   for(i=0;i<n;i++){
      Q[i] = 0;
      col[i] = 0;
      }
   x = maxDeg(col);
   while(x != -1) {
      Q[last++] = x;
      col[x] = 1;
      crs[count++] = x;
      seeds[x] = 1;
      while(first < last){ //!Q.isEmpty()
         v = Q[first++];// v = Q.poll(); or Dequeue()
         if(col[v] <= d){
            for(j=0; j < deg[v]; j++){
               w = AL[v][j];
               if(col[w] == 0){
                  Q[last++] = w; //Q.offer(w);
                  col[w] = 1+col[v];
                  }
               }
            }
         }
      x = maxDeg(col);
      }
   free(Q); free(col);
   return count;
}

int main(int argc, char **argv)
{
   int i,j,u,v,d,count, *pk;
   float p;
   FILE *fp;
   
   if(argc != 3){
      printf("USAGE: %s <input_file> <distance_between_packing_vertices>\n",argv[0]);
      exit(1);
      }
   d = atoi(argv[2]);
   if ((fp = fopen(argv[1], "r")) == NULL){
      fprintf(stderr, "Can't open file %s\n", argv[1]);
      exit(1);
      }
   fscanf(fp, "%d %d", &n,&e);
   if((AL = (int **) malloc(n * sizeof(int *))) == NULL){
      fprintf(stderr, "Cannot malloc for AL\n");
      exit(1);
      }
   deg = (int *) malloc(n * sizeof(int));
   pk = (int *) malloc(n * sizeof(int));
   seeds = (int *) malloc(n * sizeof(int));
   
   for(i=0;i<n;i++){
      AL[i] = (int *) malloc(n * sizeof(int));
      deg[i] = 0;
      seeds[i] = 0;
      pk[i] = -1; 
      for(j = 0; j < n; j++)
         AL[i][j] = 0;
      }
   for(i = 0; i < e; i++){
      fscanf(fp,"%d %d", &u, &v);
      AL[u][deg[u]++] = v;
      AL[v][deg[v]++] = u;
      }
   count = packIt(pk,d);
   for(i=0;i<count;i++)
      printf("%d ",pk[i]);
   printf("\n");
}

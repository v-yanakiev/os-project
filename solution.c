#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[]) {
   printf("%d",argc);
   FILE *fp = fopen(argv[3], "ab+");
   for(int i =1;i<argc-1;i++){
      if(system(argv[i])==-1){
         printf("Command \"%s\" failed!", argv[i]);
      }else{
         char toAppend[21];
         strcat(toAppend,argv[i]);
         strcat(toAppend,"\n");
         fputs(toAppend,fp);
      }
   }
   printf("\n");
   fclose(fp);
   return 0;
}
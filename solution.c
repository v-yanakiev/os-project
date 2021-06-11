#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[]) {
   FILE *fp = fopen(argv[3], "ab+");
   for(int i =1;i<argc-1;i++){
      int returnCode=system(argv[i])==-1;
      if(returnCode==-1){
         printf("Command \"%s\" failed!", argv[i]);
         printf("\n");
      }else{
         char toAppend[21];
         strcat(toAppend,argv[i]);
         strcat(toAppend,"\n");
         fputs(toAppend,fp);
      }
   }
   fclose(fp);
   return 0;
}
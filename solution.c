#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int main(int argc, char *argv[]) {
   printf("%d",argc);
   char firstCommand[20],secondCommand[20],fileName[20];
   strcpy(firstCommand,argv[1]);
   strcpy(secondCommand,argv[2]);
   strcpy(fileName,argv[3]);
   FILE *fp = fopen(fileName, "ab+");
   if(system(firstCommand)==-1){
      printf("Command \"%s\" failed!", firstCommand);
   }else{
      char toAppend[21];
      strcat(toAppend,firstCommand);
      strcat(toAppend,"\n");
      fputs(toAppend,fp);
   }
   if(system(secondCommand)==-1){
      printf("Command \"%s\" failed!", secondCommand);
   }else{
      char toAppend[21];
      strcat(toAppend,secondCommand);
      strcat(toAppend,"\n");
      fputs(toAppend,fp);
   }
   printf("\n");
   fclose(fp);
   return 0;
}
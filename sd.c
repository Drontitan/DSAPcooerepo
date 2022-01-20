#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct studentdata{
   char name[100];
};

void readfile(int n)
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    struct studentdata p[10];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s",&p[i].name);
            fputs("\n", fp);
            printf("%s\n", p[i].name);
        }
    }
fclose(fp);
}

void search( int n)
{
    FILE *fp;
    fp = fopen("input.txt", "r+");
    struct studentdata p[10];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
   const char name[10];
    int j=0;
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s",&p[i].name);
        fputs("\n", fp);
         char ch ='@';
        char *ptr;
        ptr = strchr(p[i].name , ch );
        printf("%s ",ptr);
        if(ptr==NULL){
           fprintf(fp,"%s\n","ERROR");
        }
        else{
             fprintf(fp,"%s\n",p[i].name);
        }
    }
    fclose(fp);
}

int main(){
    struct studentdata p[50];
     readfile(10);
     search(10);
    return 0;
}
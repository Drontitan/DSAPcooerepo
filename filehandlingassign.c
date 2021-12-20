#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct studentdata{
   int roolno;
   char name[100];
   char div[100];
   char address[100];
};

void acceptdata(struct studentdata dt[])
{       int a;
       printf("Enter the number of students you want to insert\n");
       scanf("%d",&a);
    for (int i = 0; i < a; i++)
    {
        printf("Enter the student rollnumber\n");
        scanf("%d",&dt[i].roolno);
        printf("Enter the  student name\n");
        scanf("%s", dt[i].name);
        printf("Enter the  student divison\n");
        scanf("%s",dt[i].div);
        printf("Enter the  student address\n");
        scanf("%s",dt[i].address);

    }
    FILE *fp;
    fp = fopen("cppsassignment.txt", "a");
    if (fp == NULL)
    {
        printf("The file open got errored");
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            fprintf(fp, "%d %s %s %s\n", dt[i].roolno, dt[i].name, dt[i].div, dt[i].address);
        }
    }
    fclose(fp);
}
void readfile(int n)
{
    FILE *fp;
    fp = fopen("cppsassignment.txt", "r");
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
            fscanf(fp, "%d %s %s %s",&p[i].roolno,&p[i].name,&p[i].div,&p[i].address);
            fputs("\n", fp);
            printf("%d %s %s %s\n", p[i].roolno, p[i].name, p[i].div, p[i].address);
        }
    }
fclose(fp);
}

void search( int n)
{
    FILE *fp;
    fp = fopen("cppsassignment.txt", "r");
    struct studentdata p[10];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    char name[20];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d %s %s %s", &p[i].roolno, &p[i].name, &p[i].div, &p[i].address);
        fputs("\n", fp);
    }
    printf("Enter the name of player ");
    scanf("%s", name);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(p[i].name, name) == 0)
        {
            printf("%d %s %s %s", p[i].roolno, p[i].name, p[i].div, p[i].address);
        }
    }
    fclose(fp);
}
void delete ()
{
  
    FILE *fp;
    fp = fopen("cppsassignment.txt", "r");
    FILE *f2;
    f2 = fopen("data.txt", "w");
    struct studentdata p;
    
    if (fp == NULL || f2 == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        char name[20];
        printf("Enter the name of player ");
        scanf("%s", name);
        while (fscanf(fp, "%d %s %s %s\n", &p.roolno, &p.name, &p.div, &p.address) != EOF)
        {
            if (strcmp(p.name, name) != 0){
                fprintf(f2, "%d %s %s %s\n", p.roolno, p.name, p.div, p.address);
                fputs("\n", f2);
            }
        }
    }
    fclose(fp);
    fclose(f2);
    FILE *f1;
    f1 = fopen("cppsassignment.txt", "w");
    FILE *ftemp;
    ftemp = fopen("data.txt", "r");
    
    if (f1 == NULL || ftemp== NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        while (fscanf(ftemp, "%d %s %s %s\n", &p.roolno, &p.name, &p.div, &p.address) != EOF)
        {
                fprintf(f1, "%d %s %s %s\n", p.roolno, p.name, p.div, p.address);
                fputs("\n", f2);
        
        }
    }
    fclose(f1);
    fclose(ftemp);
    remove("data.txt");
}


int main(){
    struct studentdata p[50];
    int n,a;
    printf("enter the total number of students\n");
    scanf("%d",&n);
    int r=1;
     while(r){
    printf("Entre the choice you want \n1.acceptdata\n2.readfile\n3.search\n4.delete\n5.exit\n");
     scanf("%d",&a);
     switch (a)
     {
     case 1:
         acceptdata(p);
         break;
     case 2:
         readfile(n);
         break;
     case 3:
         search(n);
         break;
     case 4:
         delete ();
         break;
     case 5:
         exit(0);
         break;
     default:
         break;
     }
     printf("\nDo you want to perform another operation (1) or (0)\n");
     scanf("%d", &r);
     }
    
    return 0;
}
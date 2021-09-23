#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORBIDDEN_NAME "X AE A-XII"

/* Theo Tardy */

void ask_name ();
void ask_mark ();
void best_mark_control ();
void worst_mark_control ();

int main(int argc, char *argv[]) {

char name[99]=""; 
char best_student[99]="";
char worst_student[99]=""; 
float mark=0;
float best_mark=0;
float worst_mark=20;
float cumulative_mark=0;
int student_count=0;

    while (strcmp(name,FORBIDDEN_NAME))
    {

        ask_name(name);
        if (feof(stdin))
            break;
        if (strcmp(name,FORBIDDEN_NAME)==0)
            break;

        ask_mark(&mark);
        if (feof(stdin))
            break;
        
        if ((mark<=20)&&(mark>=0))
        {
            best_mark_control(&mark, &best_mark, best_student, name);
            worst_mark_control(&mark, &worst_mark, worst_student, name);
            student_count++;
            cumulative_mark += mark;
        }else printf("note non comprise entre 0 et 20\n");
    }
        printf("\nLa meilleure note est : %.2f detenue par : %s\n",best_mark,best_student);
        printf("La pire note est : %.2f detenue par : %s\n",worst_mark,worst_student);
        printf("La moyenne de la classe est : %f\n",cumulative_mark/student_count);
}   


void ask_name (char name[99])
{
    printf("Tapez le prenom :\n");
    scanf(" %[^\n]",name);
}

void ask_mark (float *mark)
{
    printf("Tapez la note :\n");
    scanf("%f",mark);
}

void best_mark_control (float *mark, float *best_mark, char best_student[99], char name[99])
{
    if ((*mark > *best_mark))
    {
        *best_mark = *mark;
        strcpy(best_student,name);
    } 
}

void worst_mark_control (float *mark, float *worst_mark, char worst_student[99], char name[99])
{
    if ((*mark < *worst_mark))
    {
        *worst_mark = *mark;
        strcpy(worst_student,name);
    }
}
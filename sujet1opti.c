#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRENOM_INTERDIT "X AE A-XII"

/* Theo Tardy*/

int main(int argc, char *argv[]) {
		
char prenom[99]="";
char meilleureleve[99]="";
char pireeleve[99]="";
float note=0;
float meilleurenote=0;
float pirenote=20;
int i=0;
int compteureleve=0;
float moyenne=0;
float cumulnote=0;
int fin=0;


while (strcmp(prenom,PRENOM_INTERDIT))
{
	printf("\nTapez le prenom :\n");	
    scanf(" %[^\n]",prenom);
   	if (feof(stdin))
        break;

   	printf("Tapez la note :\n");
    scanf("%f",&note);
	if(feof(stdin))
        break;
		

	if ((note<=pirenote)&&(note>=0))
		{
            pirenote=note;
            strcpy(pireeleve,prenom);
		}
	
	if ((note>=meilleurenote)&&(note<=20))
		{
            meilleurenote=note;
            strcpy(meilleureleve,prenom);
		}

	compteureleve++;
	cumulnote=cumulnote+note;
	moyenne=cumulnote/compteureleve;
	
}

	printf("\nLa meilleure note est : %.2f detenue par : %s \n",meilleurenote,meilleureleve);
	printf("La pire note est : %.2f detenue par : %s \n",pirenote,pireeleve);
	printf("La moyenne de la classe est : %f\n",moyenne);

	return 0;
}
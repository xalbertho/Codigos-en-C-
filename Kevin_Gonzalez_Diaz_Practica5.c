/* Materia:  Programacion estructurada
   Practica: Matrices                       No.     5
   Alumno:   Gonzalez Diaz Kevin Ezequiel   Boleta: 2021640256 */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    int f,c,i,suma,total;
    float CANDIDATOA,CANDIDATOB,CANDIDATOC,CANDIDATOD;
    int votosa=1847,votosb=269,votosc=2433,votosd=113,votost;
    int columna[5];
    int A[5][4]= {{194,48,206,45},
                  {180,20,320,16},
                  {221,90,140,20},
                  {432,50,821,14},
                  {820,61,946,18}};
printf("---------------------------------------------------------\n");
printf("\t\t\tELECCIONES\n");
printf("---------------------------------------------------------\n");
printf("CANDIDATO A    CANDIDATO B    CANDIDATO C    CANDIDATO D");
printf("\n\n");
for(f=0;f<=4;f++)
{
for(c=0;c<=3;c++)
    printf("%d             " , A[f][c]);
    printf("\n");
}
printf("---------------------------------------------------------\n");
for(c=0;c<=3;c++)
{
    suma=0;
    for(f=0;f<=4;f++)
    {
        suma+=A[f][c];
    }
    columna[c]=suma;
}
printf("************** Numero de votos recibidos ****************\n\n");
for(i=0;i<4;i++)
{
    printf("%d",columna[i]);
    printf("\t       ");
}
printf("\n");

total = (A[0][1]+A[0][2]+A[0][3]+A[0][4]+A[1][1]+A[1][2]+A[1][3]+A[1][4]+A[2][1]+A[2][2]+A[2][3]+A[2][4]+A[3][1]+A[3][2]+A[3][3]+A[3][4]+A[4][1]+A[4][2]+A[4][3]+A[4][4])-1653;

printf("\n\tVotos totales: %d\n",total);

CANDIDATOA=(votosa*100)/total;printf("\n");printf("Candidato A obtuvo: \t%.2f porciento de votos\n",CANDIDATOA);
CANDIDATOB=(votosb*100)/total;printf("Candidato B obtuvo: \t%.2f porciento de votos\n",CANDIDATOB);
CANDIDATOC=(votosc*100)/total;printf("Candidato C obtuvo: \t%.2f porciento de votos\n",CANDIDATOC);
CANDIDATOD=(votosd*100)/total;printf("Candidato D obtuvo: \t%.2f porciento de votos\n",CANDIDATOD);

printf("\n");

if((CANDIDATOA>50) || (CANDIDATOA<=50) && (CANDIDATOA>CANDIDATOB) && (CANDIDATOA>CANDIDATOC) && (CANDIDATOA>CANDIDATOB)) {printf("\tEL GANADOR ES EL CANDIDATO A");}
if((CANDIDATOB>50) || (CANDIDATOB<=50) && (CANDIDATOB>CANDIDATOA) && (CANDIDATOB>CANDIDATOC) && (CANDIDATOB>CANDIDATOD)) {printf("\tEL GANADOR ES EL CANDIDATO B");}
if((CANDIDATOC>50) || (CANDIDATOC<=50) && (CANDIDATOC>CANDIDATOA) && (CANDIDATOC>CANDIDATOB) && (CANDIDATOC>CANDIDATOD)) {printf("\tEL GANADOR ES EL CANDIDATO C");}
if((CANDIDATOD>50) || (CANDIDATOD<=50) && (CANDIDATOD>CANDIDATOA) && (CANDIDATOD>CANDIDATOC) && (CANDIDATOD>CANDIDATOB)) {printf("\tEL GANADOR ES EL CANDIDATO D");}

votost=(total*50)/100;

while(votost<=50){

if((CANDIDATOA<=votost) || (CANDIDATOA<CANDIDATOB) || (CANDIDATOA<CANDIDATOC) || (CANDIDATOA<CANDIDATOD)){printf("Se realizara una segunda ronda...");printf("Candidato A pasa a la segunda ronda");}
if((CANDIDATOB<=votost) || (CANDIDATOB<CANDIDATOC) || (CANDIDATOB<CANDIDATOD) )  {printf("Se realizara una segunda ronda...");printf("Candidato B pasa a la segunda ronda");}
if((CANDIDATOC<=votost) || (CANDIDATOC<CANDIDATOB) || (CANDIDATOC<CANDIDATOD) )  {printf("Se realizara una segunda ronda...");printf("Candidato C pasa a la segunda ronda");}
if((CANDIDATOD<=votost) || (CANDIDATOD<CANDIDATOB) || (CANDIDATOD<CANDIDATOC) )  {printf("Se realizara una segunda ronda...");printf("Candidato D pasa a la segunda ronda");}}

return 0;
}













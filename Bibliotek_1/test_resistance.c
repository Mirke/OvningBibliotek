/* Test av bibliotek 1 av Daniel Rincon*/

#include<stdio.h>
#include<stdlib.h>
#include "resistance.h"

int main()
{
  printf("Ange koppling[S,P]: ");
  char conn;
  scanf("%c",&conn);

  printf("Antal komponenter: ");
  int count;
  scanf("%d",&count);

  float* array = calloc(count,sizeof(int));
  for(int i = 0;i < count;i++)
  {
    printf("Komponent %d i ohm: ",i+1);
    scanf("%f",array+i);
  }
  
  printf("Ersättningsresistans: %.1f ohm\n",calc_resistance(count,conn,array)); // Skriv resultat med 1 decimal
  free(array);
  return 0;
}

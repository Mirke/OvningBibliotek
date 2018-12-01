// Electrotest c fil
#include "electrotest.h"

int main(void){


  printf("Ange koppling[S,P]: ");
  char conn;
  scanf("%c",&conn);

  printf("Antal komponenter: \n");
  int count;
  scanf("%d",&count);

  float* array = calloc(count,sizeof(int));
  for(int i = 0;i < count;i++)
    {
      printf("Komponent %d i ohm: ",i+1);
      scanf("%f",array+i);
    }
  float res = calc_resistance(count,conn,array);
  printf("Ersättningsresistans: %.1f ohm\n",calc_resistance(count,conn,array)); // Skriv resultat med 1 decimal

  printf("Ange spänningen: ");
  float voltage;
  scanf("%f",&voltage);
  float res2 = calc_power_r(voltage, res);

  printf("Effekt: \n %.2f W\n",res2);

  free(array);

return 0;
}

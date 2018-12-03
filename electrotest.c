// Electrotest c fil
#include "electrotest.h"

#define MAXINPUT 30

int main(void){
  char input[MAXINPUT]; // Används för att läsa input med fgets

  char conn;
  do{
    printf("Ange koppling[S,P]: ");
    fgets(input,MAXINPUT,stdin);
    conn = *input; // Bara intresserade av första karaktären
    if(conn != 'S' && conn != 'P'){
      printf("Koppling får endast vara S eller P, försök igen!\n");
      conn = 0;
    }
  } while(conn == 0);

  int count;
  do{
    printf("Antal komponenter: ");
    fgets(input,MAXINPUT,stdin);
    count = atoi(input);
    if(count < 1){
      printf("Antal komponenter får inte vara mindre än 1, försök igen!\n");
    }
  } while(count < 1);
  
  float* array = calloc(count,sizeof(float));
  for(int i = 0;i < count;i++){
    do{
      printf("Komponent %d i ohm: ",i+1);
      fgets(input,MAXINPUT,stdin);
      *(array+i) = atof(input);
      if(*(array+i) < 0){
	printf("Resistanser får inte vara negativa, försök igen!\n");
      }      
    } while(*(array+i) < 0);
  }

  float res = calc_resistance(count,conn,array);
  if(res == -1)
    printf("Nåt gick fel i beräkningen, konstigt...\n");
  else
    printf("Ersättningsresistans: %.1f ohm\n",res); // Skriv resultat med 1 decimal

  printf("Ange spänningen: ");
  float voltage;
  scanf("%f",&voltage);
  float res2 = calc_power_r(voltage, res);

  printf("Effekt: \n %.2f W\n",res2);

  free(array);

return 0;
}

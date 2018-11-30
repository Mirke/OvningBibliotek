/* Test av bibliotek 1 av Daniel Rincon*/

#include<stdio.h>
#include<stdlib.h>
#include "resistance.h"

#define MAXINPUT 30

int main(){
  printf("Test av funktionen calc_resistance!\n");
  printf("-----------------------------------\n");
  
  float test[] = {100,200,300};
  printf("Normalfall Seriell: calcresistance(3,'S',{100,200,300}) = %f\n",calc_resistance(3,'S',test));
  printf("Normalfall Parallell: calcresistance(3,'P',{100,200,300}) = %f\n",calc_resistance(3,'P',test));
  printf("Fel kopplingstyp: calcresistance(3,'D',{100,200,300}) = %f\n",calc_resistance(3,'D',test));

  test[1] = 0;
  printf("Normalfall Parallell (en resistans = 0): calcresistance(3,'P',{100,0,300}) = %f\n",calc_resistance(3,'P',test));
  printf("Mindre än 1 komponent: calcresistance(0,'S',{100,0,300}) = %f\n",calc_resistance(0,'S',test));

  test[1] = -200;
  printf("Negativ resistans på komponenter: calcresistance(3,'S',{100,-200,300}) = %f\n",calc_resistance(3,'S',test));
  printf("NULL-pekare till komponenter: calcresistance(3,'S',NULL) = %f\n",calc_resistance(3,'S',NULL));
  printf("\n");
  
  printf("Tillämpning av calc_resistance!\n");
  printf("-------------------------------\n");
  
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

  float replace_res = calc_resistance(count,conn,array);
  if(replace_res == -1)
    printf("Nåt gick fel i beräkningen, konstigt...\n");
  else
    printf("Ersättningsresistans: %.1f ohm\n",replace_res); // Skriv resultat med 1 decimal

  free(array);
  return 0;
}

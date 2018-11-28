#include "e_resistance.h"

int main(){
  float *p;
  char input[20];
  float flinput;

  do{
    printf("Ersättningsresistans:\n");
    fgets(input,21,stdin);
    flinput = atof(input);
    if(flinput<1)
      printf("Minsta tillåtna värdet är 1\n");

  }while(flinput<1);

  p = malloc(3*sizeof(float));
  int count = e_resistance(flinput,p);

  for(int i=0;i<count;i++){
    if(i)
      printf(", ");
    printf("%.2f", p[i]);

  }
  printf("\n");
  free(p);
}

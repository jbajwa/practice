#include <stdio.h>

void print_byte( char * a , int len){
	for (int i =0; i < len; i++)
    printf("Pointer %p, value %x \n", (a+i) , *(a+i));
}

int main(){

  int x = 12345;
  print_byte( (char*) &x , sizeof(int));
  // Doing same locally using a char ptr pointing to 1st byte of x
  char * ptr = (char *)  &x;
  for (int i =0; i< (sizeof(int)) ; i++)
     printf("Pointer %p, value %x \n", (ptr +i), *(ptr +i));
  return 0;
}

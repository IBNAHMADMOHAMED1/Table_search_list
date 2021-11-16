#include <stdio.h>
#include <stdlib.h>
int i,j;
int find(float [], float missing, int length);
void print_list(float list[], int length);
void sort(float [], int length);
float * get_list(int *length);

int main() {
   int length;
   float *list = get_list(&length);
   print_list(list, length);
   sort(list, length);
   print_list(list, length);
   printf("what you want to search for: ");
   float missing;
   scanf("%f", &missing);
   int missing_index = find(list , missing, length);
   if (missing_index == -1) puts("not found !!");
   else printf("first occcurance in index %d \n", missing_index);
   free(list);
   return 0;
}


int find( float list[], float missing, int length) {

   for (i=0; i<length; i++)
      if(list[i] == missing) return i;
   return -1;
}

void print_list(float list[], int length) {
   for( i=0; i<length; i++)
      printf("%.2f\t", list[i]);
   printf("\n");
}

void sort(float list[], int length) {
   int i=0, checker=1;
   while(checker) {
      checker = 0;
      for(j=0; j<length-i-1; j++){
         if(list[j] > list[j+1]) {
            float tmp = list[j];
            list[j] = list[j+1];
            list[j+1] = tmp;
            checker++;
         }
      }
      i++;
   }
}

float * get_list(int *length) {
   float *list = malloc(0);
   float number;
   int i=0;
   puts("enter elements (enter -1 to end) :  ");
   while(1) {
      scanf("%f", &number);
      if(number == -1)
         break;
      list = realloc(list, 4*(i+1));
      list[i++] = number;
   }
   *length = i;
   return list;
}

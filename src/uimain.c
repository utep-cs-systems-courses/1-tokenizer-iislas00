#include <stdio.h>
#define SIZE 200

int main(){
 char str[SIZE];
 
 while(1){
   printf("'q' to QUIT\n> ");
   fgets(str, sizeof(str), stdin);
   printf("$ %s", str);

   if(str[0] == 'q'){
     goto done;
   }
     
 }done:
  
 return 0;
}

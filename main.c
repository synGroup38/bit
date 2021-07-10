#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#define READ 0x01
#define WRITE 0x02

void pipe(uint8_t opts){

   if(opts & READ){
      printf("pipe open with read permission \n");
   }

   if(opts & WRITE){
      printf("pipe open with write permission \n"); 
   }

}

void clearBit(uint8_t bitNumber , uint32_t *bitField){
   (*bitField) &= ~(0x01 << bitNumber);
}

void setBit(uint8_t bitNumber , uint32_t *bitField){
   (*bitField) |= (0x01 << bitNumber);  
}

bool checkBit(uint8_t bitNumber, uint32_t* bitField){
   uint32_t field = *bitField; 
   int shift = 31 - bitNumber; 
   field = field << shift;
   uint32_t mask = 1; 
   mask = mask << 31; 
   if (field & mask){
      return true; 
   }
   return false; 
}

void printBin(uint32_t *bitField){
   for (int i = 0 ;i < 31 ; i++ ){
      if(checkBit(i,bitField)){
         printf("+"); 
      }else{
         printf("."); 
      }
   }
   printf("\n");

}
int main(){

   uint32_t field = WRITE ; 
   pipe(READ|WRITE); 
   printf("field before clear: %i \n",field); 
   clearBit(1,&field);
   printf("field after clear: %i \n",field);
   setBit(1,&field); 
   printf("field after set: %i \n",field); 
   if(checkBit(1,&field)){
      printf("bit 1 is set \n");
   }
   printBin(&field); 
   return 0; 
}

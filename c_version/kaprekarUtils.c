#include<stdlib.h>
#include<stdio.h>
#include<math.h>

#include "kaprekarUtils.h"

int isKaprekar(int n) {

  if(n < 1) {
    return 0;
  }

  int i = 1;
  //compute the square
  long square = n*(long)n;
  //compute the number of digits of the square
  int numDigits = (int)(log10(n) + 1);
  long modulus = 1; //originally 0
  long first, second;

  //increase the modulus by a factor of 10
  modulus = pow(10,numDigits);

  //split the square into two parts
  first = square/modulus;
  second = (square-(first*modulus));
  
  //test if the split makes a Kaprekar number
  //the second part cannot be zero and if
  //the sum of the two parts is equal to n, then it is
  if(second > 0 && n == first + second) {
    return 1; //true
  }
  //to account for some numbers that have 
  //zeros at the end of first number, divide by ten
  else if(first % 10 == 0){
    //some have more than 1 zero so you run until no more zeros
    while(first % 10 == 0){
      first /= 10;
      second = (square-(first*modulus*pow(10,i)));
      if(second > 0 && n == first + second) {
        return 1; //true
      //zero will cause infinit loop, so if zero it's false
      }else if(first == 0){
        return 0;
      }
      //account for dividing by ten again, 
      //ups modulus by factor of 10
      i++;
    }
  }
//}
return 0;
  
}

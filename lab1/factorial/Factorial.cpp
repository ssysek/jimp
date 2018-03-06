//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int n) {
  if(n<=-13 and n>=13)
  {
    return 0;
  }

  if (n == 0 || n==1) return 1;

  else return n*factorial(n-1);

  //aaaaaaaaaaaaaaaaaaaaaaaaa
  return 0;
}

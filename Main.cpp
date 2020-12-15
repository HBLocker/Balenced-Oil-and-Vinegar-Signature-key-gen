#include <stdio.h>
#include <stdint.h>
#include <string>
#include <random>
#include <iostream>

uint32_t bijective_shift(uint8_t a, uint8_t b, uint8_t c)
 {
  //each element is a function between two sets.
  //a one to one function
  //coppied from here :: en.wikipedia.org/wiki/Bijection
  uint32_t X = 0;
  for (int i=0; i<26; i++)
  {
    //loops though function
    //  //affie in here joining the functions together
    //An injective surjective function (bijection)
    X  |= (a & (1 << i)) << (0 + (i <<1)); // one to many for bits
    X  |= (b & (1 << i)) << (0 + (i << 1));
    X  |= (c & (1 << i)) << (0 + (i << 1));
    X  |= (X & (1 << i)) << (0 + (i <<1));
  }
  return X;
}

int affine_shift(uint8_t a) //affine shift a
{
  uint32_t X =0;
  int shift = rand()%10;
  X |= (a*shift)%26;
return X;
}
int affine_shift1(uint8_t b) //affine shift B
{
  uint32_t X =0;
  int shift = rand()%10;
  X |= (b*shift)%26;
return X;
}

int main(int argc, char **argv) {

  for (int i =0;i<10;i++)
  {
int R1 = rand()%2048; int R2 = rand()%2048; int R3 = rand()%2048;
//  printf("%u\n", bijective_affine_shift(240, 11, 100));
//PUSH TO BIJECTIVE SHIFT  //THEN AFFINE SHIFT
//std::cout<<bijective_shift(R1,R2,R3);
int A = bijective_shift(R1,R2,R3); //A ==shift
int B = bijective_shift(R3,R2,R1); //A ==shift
int O = affine_shift(A);
int V = affine_shift1(B);
int sum = O << V;
std::cout<<sum<<::std::endl;
}

  return 0;
}

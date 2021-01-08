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
long N=999999999;
long randNumber;
long X;
for(long i=0;i<N;i++)
randNumber=i+rand();
X = (a*randNumber)%26; //modlo alaphbet?

return X;
}

int affine_shift1(uint8_t b) //affine shift a
{
long M=999999999;
long randNumber;
long X;
long equation;
for(long i=0;i<M;i++)
randNumber=i+rand();
X = (b*randNumber)%26; //modlo alaphbet?

return X;
}

int main(int argc, char **argv) {
  for (int i =0;i<128;i++) //paper denoted as n
  {
int R1 = rand()%2048; int R2 = rand()%2048; int R3 = rand()%2048;
//  printf("%u\n", bijective_affine_shift(240, 11, 100));
//PUSH TO BIJECTIVE SHIFT  //THEN AFFINE SHIFT
//std::cout<<bijective_shift(R1,R2,R3);
int A = bijective_shift(R1,R2,R3); //A ==shift
int B = bijective_shift(R3,R2,R1); //A ==shift
int K1 = A+B;
 //1.0 KN+V shift -> KN+ v;
int O = affine_shift(K1);
int V = affine_shift1(A>>B);
int sum = (O + V); //fixed not shifted but O AND vinigar
std::cout<<sum;
}

  return 0;
}

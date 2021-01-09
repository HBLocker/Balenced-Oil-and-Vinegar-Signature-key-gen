#include <stdio.h>
#include <stdint.h>
#include <string>
#include <random>
#include <iostream>
#include <time.h>
#include <math.h>
#include <functional>
//// random int
unsigned long long Randomize()
{
    unsigned long long randnumber = 0;
    int digits[20];

    for (int i = 19; i >= 1; i--)
    {
      digits[i]=rand()%10;
    }
    for(int i=19; i>=1; i--)
    {
       unsigned long long power = pow(10, i-1);

        if (power%2 != 0 && power != 1)
            power++;

        randnumber += power * digits[i];
    }
return randnumber;
}
////
uint32_t bijective_shift(long a, long b, long c)
 {
  //each element is a function between two sets.
  //a one to one function
  //coppied from here :: en.wikipedia.org/wiki/Bijection
  uint32_t X = 0;
  for (int i=0; i<26; i++)
  {
     //loops though function
     //affie in here joining the functions together
     //An injective surjective function (bijection)
    //alfine function denoted as  E(x) = (ax+b)mod M (encryption decryption isnt stated for the key gen)
   //paper states it is the following K^2
    X  |= (a & (1 << i)) << (0 + (i <<1)); // one to many for bits
    X  |= (b & (1 << i)) << (0 + (i << 1));
    X  |= (c & (1 << i)) << (0 + (i << 1));
    X  |= (X & (1 << i)) << (0 + (i <<1));
  }
  return X;
}

int affine_shift(long a) //affine shift a
{
  srand(time(NULL));
  uint32_t B= Randomize()%10000000+10000000;
  uint32_t C = Randomize()%10000000+10000000;
  uint32_t E = Randomize()%10000000+10000000;
  for  (int i = 0;i<a;i++) //length N
  {
  a = (C + (a *E + B%26));
  return a;
  }
}

int affine_shift1(uint32_t b) //affine shift a
{
  uint32_t B= Randomize()%10000000+10000000;
  uint32_t C = Randomize()%10000000+10000000;
  uint32_t E = Randomize()%10000000+10000000;
  for (int j =0;j<b;j++)
  {
  b= (C+ (b *E + B%26));
  return b;
}
}

void sk()
{
  uint32_t R1 = Randomize()%2048; uint32_t R2 = Randomize()%2048; uint32_t R3 = Randomize()%2048;
  //  printf("%u\n", bijective_affine_shift(240, 11, 100));
  //PUSH TO BIJECTIVE SHIFT  //THEN AFFINE SHIFT
  //std::cout<<bijective_shift(R1,R2,R3);
  uint32_t A = bijective_shift(R1,R2,R3); //A ==shift
  uint32_t B = bijective_shift(R3,R2,R1); //A ==shift
  int K = (R1+R2+R3);  //2.2
   //1.0 KN+V shift -> KN+ v;
  uint32_t O = affine_shift(K); //Oil 2.2--final
  //vinigar
  uint32_t V = bijective_shift(A+B, A+B, A+B); //
  std::cout<< (O + V);
}
void pk()
{
  uint32_t R1 = Randomize()%2048; uint32_t R2 = Randomize()%2048; uint32_t R3 = Randomize()%2048;
  //  printf("%u\n", bijective_affine_shift(240, 11, 100));
  //PUSH TO BIJECTIVE SHIFT  //THEN AFFINE SHIFT
  //std::cout<<bijective_shift(R1,R2,R3);
  uint32_t A = bijective_shift(R1,R2,R3); //A ==shift
  uint32_t B = bijective_shift(R3,R2,R1); //A ==shift
  uint32_t K = (R1+R2+R3);  //2.2
   //1.0 KN+V shift -> KN+ v;
  uint32_t O = affine_shift(K); //Oil 2.2--final
  //vinigar
  uint32_t V = bijective_shift(A+B, A+B, A+B); //

  std::cout<< (V+O*-1);
}
int main(int argc, char **argv) {
  std::cout<<"        "<<std::endl;
  for (int i = 0;i<5;i++)
  {
  sk();
  }
  std::cout<<"        "<<std::endl;

  for (int i = 0;i<5;i++)
  {
  pk();
  }
  return 0;
}

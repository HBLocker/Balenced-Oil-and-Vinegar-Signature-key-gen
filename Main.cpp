#include <stdio.h>
#include <stdint.h>
#include <string>
uint32_t bijective(uint8_t a, uint8_t b, uint8_t c)
 {
  //each element is a function between two sets.
  //a one to one function
  //coppied from here :: en.wikipedia.org/wiki/Bijection
  uint32_t X = 0;
  for (int i=0; i<16; i++)
  {
    //loops though function
    //An injective surjective function (bijection)
    X |= (a & (1 << i)) << (0 + (i <<1)); // one to many for bits

    X |= (b & (1 << i)) << (0 + (i << 1));

    X |= (c & (1 << i)) << (0 + (i << 1));

    X |= (X & (1 << i)) << (0 + (i <<1));
  }
  return X;
}
//affine functions in mathermatics basicly flip the values upside down via rotationhttps://math.stackexchange.com/questions/3102058/affine-cypher-find-function-and-plaintext
//////not sure if correct ^^
/// https://math.asu.edu/sites/default/files/affine.pdf

#define Affine_fun (Y,S,F)(   \
  Y = %26 << S << F \ //NOT FINISHED 
)




int main(int argc, char **argv) {
  printf("%u\n", bijective(10, 17, 23));
  return 0;
}

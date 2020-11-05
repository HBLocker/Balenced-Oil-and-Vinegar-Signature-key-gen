#include<bits/stdc++.h>
#include <stdio.h>
#include <functional>
#include <math.h>
#include <time.h>
#include <fstream>
#define mat_elem(a, y, x, n) (a + ((y) * (n) + (x)))

using namespace std;


#undef A
static int a =7;
static int b =6;
std::hash<std::string> hash_fn;
//alfine function denoted as  E(x) = (ax+b)mod M (encryption decryption isnt stated for the key gen)
//paper states it is the following K^2
string affine(string m) {
   string c = "";
   for (int i = 0; i < m.length(); i++) {
      if(m[i]!=' ')
         c = c + (char) ((((a * (m[i]-'A') ) + b) % 26) + 'A');
      else
         c += m[i];
   }
   return c;
};
// H{0,1}^n -> {0,1}
int  bijective_hash(int val) {
  int z = rand()%10;
  int l = rand()%10;
    val = ((val*z) + l) & 0x7FFFFFFF;
    val ^= (val>>15);
    val ^= (val>>8);
    val ^=(val>>3);
    return val;
}
//signature defined here chose random values of V
void gauss_eliminate(int i,int j)
{

 //https://en.cppreference.com/w/cpp/numeric/math/erfc 

}

int main(void)
{
int d;

ofstream secret;
secret.open ("private.txt"); //secret key
for (int j=0;j<2048;j++)
  {
int random = 1;
std::string msg = std:: to_string(random);
string c = affine(msg);
int hash = (int) hash_fn(c);
int final =  bijective_hash(hash); //vin + oil
secret  << final;
}

secret.close();
ofstream Public;
Public.open("public.txt");
for (int p=0;p<2048;p++)
  {
int random = rand()%10000;
std::string msg = std:: to_string(random);
string c = affine(msg);
int hash = (int) hash_fn(c);
int final = bijective_hash(hash);
expm1(final); //vin plua oil ^-1
Public  << final;
}

return 0;
}

# Oil and Vinegar-Signature-key-gen
<h1> 
  This is a proof of concept!
  </h1>
Basic example  of a balanced oil and vinegar signature scheme
The scheme is an advanced scheme based on previous schemes, this crypto scheme incorporated the use of asymmetric signatures.
Vinegar>Oil for this scheme, Both vinegar and oil and random values within the algorithms. 
The concept being addressed is that of having a cipher being used with no trapdoor, allowing the key to be computed. 

The main concepts of this paper are split into different sections:
Generate key:
The key generation is based on the functions being “K=F^Q  which defines this key generation as a polynomial for the key generation. 
Public Key:
The public key is an element of K ^oil^vinegar which is just random values of unknowns for the public key generation. 
Signature verification:
The public, signature, x of Y is valid and all the public key values are met. The result of this is secret. 


The main issue found is that there can be an attack on calculating the randomness of the oil and the vinegar. This can be done to separate both variables. The attack has two definitions:

Ref def 3.1 -3.4 
The scheme can also be broken as shown in the paper under section “how to find O” which denotes that the bijective can be broken and if it is inverted when being calculated the values can be guessed proving that the random function is not effective. 

The proposed theory in the paper outlines an algorithm to successfully randomise the use of quadratic equations in N^2 for unknowns. 
Section 9 of the paper covers two schemes which can be used for the improved varieties of Oil and Vinegar. 
The secret key in the paper has been improved by splitting it up into two main parts, the bijective function is now one part then the function of s is then calculated to be bigger than oil, making the randomness of the bijective create more unknowns. The public key length was also changed; this was done by only using the homogeneous part of the calculation to determine the key length of the public key for the equation. Overall the paper devised a scheme which can’t be broken compared to its predecessor. 

The framework was to create an unbalanced vinegar and oil scheme, this is to create a lot more random values where keys are being generated.

The results of the study show that each of the added functions to the equations causes a concrete parameter for the vinegar and oil scheme. The added functions were values to the polynomial scheme which increased the randomness of the values thus increasing the size of the public key which can’t be attacked unlike the previous version of this scheme. The same applies to the secret key which can’t be attacked with the inverse attack on the bijection function. 

As this paper was written in 1999 it is somewhat old but provides a good foundation for the is the scheme which has been adapted for now post QR which rainbow heavily relies on. 


The main argument of the paper is that to prove that an added function to the scheme can make it concrete showing that this method of key generation is efficient and can be used for a standard of cryptography


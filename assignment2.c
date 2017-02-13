// CMPT 295 Assignment 2 Four-bit Full Adder
// DO NOT include a main function in your final submission.

#include <stdio.h>

typedef char bit;

// Adders return a sum and carry-out. Sum may be multiple bits in size, but carry-out is
// always one bit in size.
typedef struct
{
    int sum;
    bit carryOut;
} adderReturn;

// Implements the half adder logic from class.
// PRE: the bits to be added are in the least significant bit of x and y
// POST: the sum and carry-out of adding the two bits is returned
adderReturn halfAdder(bit x, bit y)
{
		adderReturn output;
		output.sum = x^y;
		output.carryOut = x&y;

		return output;
}

// Implements the full adder logic from class, using two half-adders.
// PRE: the bits to be added are in the least significant bit of x, y, and carryIn
// POST: the sum and carry-out of adding the three bits is returned
adderReturn fullAdder(bit x, bit y, bit carryIn)
{
  adderReturn result = halfAdder(x, y);
  adderReturn resultFinal = halfAdder(result.sum, carryIn);
  resultFinal.carryOut = resultFinal.carryOut | result.carryOut;
  return resultFinal;
}

// Implements a four-bit full adder using multiple calls to the fullAdder function.
// PRE: the least significant four-bits of a and b contain the numbers to be added,
//      and the least significant bit of carryIn contains the carry-in to be used
// POST: the four-bit sum and single-bit carry-out is returned. Note that the carry-out
//       signals whether overflow occurred.


adderReturn fourBitAdder(int a, int b, bit carryIn)
{

  bit final[4];

  // if we're dealing with base 10 numbers, we need to convert them to base 2
  bit x[4], y[4]

  // for(int i = 3; i >= 0; i--){
  //  if((a & (1 << i)) != 0){
  //    x[i] = 1;
  //  }else{
  //    x[i] = 0;
  //  }
  // }
  //
  // for(int i = 3; i >= 0; i--){
  //  if((b & (1 << i)) != 0){
  //    y[i] = 1;
  //  }else{
  //    y[i] = 0;
  //  }
  // }

  for (int i = )

  printf("x[0]: %d\n", x[0]);
  printf("x[1]: %d\n", x[1]);
  printf("x[2]: %d\n", x[2]);
  printf("x[3]: %d\n", x[3]);

  printf("y[0]: %d\n", y[0]);
  printf("y[1]: %d\n", y[1]);
  printf("y[2]: %d\n", y[2]);
  printf("y[3]: %d\n", y[3]);

  adderReturn output;
  adderReturn output0 = fullAdder(x[0], y[0], 0);
  printf("sum0: %d\n", output0.sum);
  final[0] = output0.sum;
  adderReturn output1 = fullAdder(x[1], y[1], output0.carryOut);
  printf("sum1: %d\n", output1.sum);
  final[1] = output1.sum;
  adderReturn output2 = fullAdder(x[2], y[2], output1.carryOut);
  printf("sum2: %d\n", output2.sum);
  final[2] = output2.sum;
  adderReturn output3 = fullAdder(x[3], y[3], output2.carryOut);
  printf("sum3: %d\n", output3.sum);
  final[3] = output3.sum;


  strtol(final, NULL, 2);
  printf("FINAL SUM: %d\n", final);
  output.carryOut = output3.carryOut;

  return output;
  }

int main() {
  adderReturn t = fourBitAdder(12, 2, 0);
  //printf("T SUM: %d\n", t.sum);
}

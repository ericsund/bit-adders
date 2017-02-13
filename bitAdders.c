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
  resultFinal.carryOut = resultFinal.carryOut || result.carryOut;
  return resultFinal;
}

// Implements a four-bit full adder using multiple calls to the fullAdder function.
// PRE: the least significant four-bits of a and b contain the numbers to be added,
//      and the least significant bit of carryIn contains the carry-in to be used
// POST: the four-bit sum and single-bit carry-out is returned. Note that the carry-out
//       signals whether overflow occurred.
adderReturn fourBitAdder(int a, int b, bit carryIn)
{
  adderReturn output;
  output.sum = 0;

  //string together the fullAdders
  //for each call to fullAdder, we're grabbing the individual bits from these
  //numbers by using bitwise operators
  adderReturn fa0 = fullAdder((a & 0x1), (b & 0x1), carryIn);
  if (fa0.sum == 1) {output.sum += 1;}

  adderReturn fa1 = fullAdder((a & 0x2) >> 1, (b & 0x2) >> 1, fa0.carryOut);
  if (fa1.sum == 1) {output.sum += 2;}

  adderReturn fa2 = fullAdder((a & 0x4) >> 2, (b & 0x4) >> 2, fa1.carryOut);
  if (fa2.sum == 1) {output.sum += 4;}

  adderReturn fa3 = fullAdder((a & 0x8) >> 3, (b & 0x8) >> 3, fa2.carryOut);
  if (fa3.sum == 1) {output.sum += 8;}

  //if the last carryout is 1, then we've overflowed
  if (fa3.carryOut == 1) {
    printf("%s\n", "Overflow overflow!  Can't represent this sum with 4 bits.");
  }

  return output;
}

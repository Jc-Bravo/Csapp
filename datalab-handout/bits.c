/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * Jiangcan 2019011325
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrarzy integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif                                                                                                                                                                                                                                                                                                                                    
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4 110 101 100
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
/* (~x)|(~y) */
  return ~((~x)|(~y));
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
// use n<<3 to calculate n times 3
   return (x>>(n<<3))&(0xff);

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  //easy
  return (x>>n)&(0xffffffff>>n);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) { 
// for two, like 3,   
// for four like 0b1111,((15&0b0101)+(15&1010>>1))>>2+(((15&0b0101)+(15&1010>>1))&0b11)=0b100
// and for 32 just like that
    int result = 0;
    int even_32 = (0xaaaaaaaa&x)>>1;
    int odd_32 = (0x55555555&x);
    int sum_32 = odd_32 + even_32;
    even_32 = (0xcccccccc&sum_32)>>2;
    odd_32 = (0x33333333&sum_32);
    sum_32 = odd_32 + even_32;//8???4?????????4?????????????????????????????????
    result = (sum_32 & 0b1111) + (sum_32>>4 & 0b1111)+ (sum_32>>8 & 0b1111)+ (sum_32>>12 & 0b1111)+ (sum_32>>16 & 0b1111)+ (sum_32>>20 & 0b1111)+ (sum_32>>24 & 0b1111)+(sum_32>>28 & 0b1111);
    return result;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  //the diff for 0 is the sigh for -0 is 0 not 1
  int reverse = ~x+1;   
  int first_place = (x|reverse)>>31;
  return ((~first_place) >> 31)&1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) { 
//represent x as 2's complement,then compare with n
//need be care with 1<<31
int is_32 = n>>5;// return 1 while n = 32
int nbit_min = 1 << 31;
int nbit_max = (1 << n >> 1) & (~nbit_min);
x += nbit_max;  
return (!(x>>n))|is_32;  
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  //+2^n
  int sign = !(x>>31);//get posi or neg
  sign = !!sign;
  sign = ~sign+1;
  int pos_div = x>>n;
  int neg_div = (x+(1<<n)+(~1+1))>>n;
  return (sign&pos_div)|(~sign&neg_div);

}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x+1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  // 0 or neg
  int is_0 = !(((~x+1)|x)>>31);//is 1 if is 0
  int is_neg = x>>31;
  return !(is_0|is_neg);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  //sub then compare with 0
  //be careful with ==
  //compare posi&neg
  int x_neg_y_posi = (x>>31&(!(y>>31)))&1;
  int x_posi_y_neg = !((y>>31&(!(x>>31)))&1);
  int sub = x + (~y);
  int sign = (sub>>31)&1;
  return (sign|x_neg_y_posi)&x_posi_y_neg;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    unsigned int r = 0, t;

    t = ((~((x >> 16) + ~0)) >> 27) & 0x10;
    r |= t, x >>= t;
    t = ((~((x >>  8) + ~0)) >> 28) &  0x8;
    r |= t, x >>= t;
    t = ((~((x >>  4) + ~0)) >> 29) &  0x4;
    r |= t, x >>= t;
    t = ((~((x >>  2) + ~0)) >> 30) &  0x2;
    r |= t, x >>= t;

    return (r | (x >> 1));
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  //check NaN (?infinity)
    int test = uf|0x80000000;
    test = test>>23;
    test = ~test;
    if (((0xff800000^uf)<<1) &&(!test))return uf;
    unsigned sign = 1<<31;
    uf = sign + uf;
    return uf;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    if (!x)
        return 0;
    int e = 158;
    int mask = 1<<31;
    int sign = x&mask;
    int frac;
    if (x == mask)
        return mask | (158<<23);
    if (sign)
        x = ~x + 1;
    while (!(x&mask)) {
        x = x<<1;
        e = e -1;
    }
    frac = (x&(~mask)) >> 8;
    if (x&0x80 && ((x&0x7F) > 0 || frac&1))
        frac = frac + 1;
    return sign + (e<<23) + frac;

}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  // 4case.
  int e = (uf >> 23) & 0xFF;
  if(!(e ^ 0xFF)) 
      return uf;
  if(!e) 
      return  (uf & 0x80000000) | (uf << 1);  // Denormalized Case
  if(!(e ^ 0xFE))
      return (uf & 0x80000000) | (e << 23);  // Overflow Case
  uf = uf + (1 << 23); // Normalized Case
  return uf;
}

#include <stdio.h>
#include "BigMathLib.h"
#include "TestBigMathLib.h"
#include "CheckBigMathLibResult.h"
#include "Messages.h"

void TestGcd() {

	printf(TEST_GCD_MESSAGE);

	element a[NUM_SIZE] = {0x12345678};
	element b[NUM_SIZE] = {0x87654321};
	element result[NUM_SIZE];

	printf("a: ");
	printConsoleBE(a);

	printf("b: ");
	printConsoleBE(b);

	Gcd(a, b, result);

	printf("result: ");
	printConsoleBE(result);

	return;
}

void TestGcdExtended() {

	printf(TEST_GCD_EXTENDED_MESSAGE);

	element a[NUM_SIZE] = { 0x12345678 };
	element b[NUM_SIZE] = { 0x87654321 };
	element x[NUM_SIZE];
	element y[NUM_SIZE];
	element result[NUM_SIZE];

	printf("a: ");
	printConsoleBE(a);

	printf("b: ");
	printConsoleBE(b);

	GcdExtended(a, b, result, x, y);

	printf("result: ");
	printConsoleBE(result);

	printf("x: ");
	printConsoleBE(x);

	printf("y: ");
	printConsoleBE(y);

	printf(CHECK_GCD_EXTENDED_RESULT_MESSAGE);

	BOOL checkResult = checkGcdExtendedResult(a, b, x, y, result);
	proccessCheckResult(checkResult);

	return;
}

void TestInverse() {

	printf(TEST_INVERSE_MESSAGE);
	
	element a[NUM_SIZE] = { 0x4 };
	element m[NUM_SIZE] = { 0x9 };
	element result[NUM_SIZE];

	printf("a: ");
	printConsoleBE(a);

	printf("m: ");
	printConsoleBE(m);

	inverse(a, m, result);

	printf("result: ");
	printConsoleBE(result);

	printf(CHECK_INVERSE_RESULT_MESSAGE);

	BOOL checkResult = checkInverseResult(a, m, result);
	proccessCheckResult(checkResult);

	return;
}
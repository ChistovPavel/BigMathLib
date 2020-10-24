#include "BNumber.h"
#include "BGcd.h"
#include "Compare.h"
#include "BDiv.h"
#include "BMul.h"
#include "BSub.h"
#include "BDiv.h"

/************************************************************/
/*	������ ����� static �������								*/
/************************************************************/

/************************************************************/
/*	������� ���������� ��� ���� ����� (a, b) ����������		*/
/*															*/
/*	void Gcd(IN p_element a,								*/
/*			 IN p_element b,								*/
/*			 OUT p_element result);							*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element a 	- ������ �����							*/
/*	p_element b		- ������ �����							*/
/*															*/
/*	�������� ���������:										*/
/*															*/
/*	p_element result	- ������, � ������� ����� 			*/
/*						  ������� ���						*/
/*															*/
/************************************************************/

static void GcdR(IN p_element a,
		  		 IN p_element b,
				 OUT p_element result);

/************************************************************/
/*	������� ������������ ���������� ������������ ���������	*/
/*	�������													*/
/*															*/
/*	������� ���������: a * x + b * y = (a, b)				*/
/*															*/
/*	void GcdExtendedR(IN p_element a,						*/
/*					  IN p_element b,						*/
/*					  OUT p_element result,					*/
/*					  OUT p_element x,						*/
/*					  OUT p_element y);						*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element a 		- ������ �����						*/
/*	p_element b			- ������ �����						*/
/*															*/
/*	�������� ���������:										*/
/*															*/
/*	p_element result	- ������, � ������� ����� �������	*/
/*						  ���								*/
/*	p_element x			- ������, � ������� ����� �������� 	*/
/*						  ��������� ����� x					*/
/*	p_element y			- ������, � ������� ����� ��������	*/
/*						  ��������� ����� y					*/
/*															*/
/************************************************************/

static void GcdExtendedR(IN p_element a,
						 IN p_element b,
						 OUT p_element result,
						 OUT p_element x,
						 OUT p_element y);

/************************************************************/
/*	����� ����� static �������								*/
/************************************************************/

void Gcd(IN p_element a,
		 IN p_element b,
		 OUT p_element result)  {
	
	element _a[NUM_SIZE];
	element _b[NUM_SIZE];

	memset(_a, 0, NUM_SIZE * sizeof(element));
	memset(_b, 0, NUM_SIZE * sizeof(element));

	memcpy(_a, a, NUM_SIZE * sizeof(element));
	memcpy(_b, b, NUM_SIZE * sizeof(element));

	CompareAndSwap(_a, _b);

	GcdR(_a, _b, result);
}

void GcdExtended(IN p_element a,
			     IN p_element b,
				 OUT p_element result,
				 OUT p_element x,
				 OUT p_element y) {

	element _a[NUM_SIZE];
	element _b[NUM_SIZE];

	memset(_a, 0, NUM_SIZE * sizeof(element));
	memset(_b, 0, NUM_SIZE * sizeof(element));

	memcpy(_a, a, NUM_SIZE * sizeof(element));
	memcpy(_b, b, NUM_SIZE * sizeof(element));

	BOOL swapResult = CompareAndSwap(_a, _b);

	GcdExtendedR(_a, _b, result, x, y);

	if (swapResult == True) {
		Swap(x, y);
	}
}

/************************************************************/
/*	������ ����� static �������								*/
/************************************************************/

static void GcdR(IN p_element a,
	IN p_element b,
	OUT p_element result) {
	element r[NUM_SIZE];
	element q[NUM_SIZE];

	unsigned int zero = 0;

	int i = 0;

	Div(a, b, r, q);

	if (Compare(q, &zero, NUM_SIZE, 1) == 0) {
		memset(result, 0, NUM_SIZE * sizeof(element));
		memcpy(result, b, NUM_SIZE * sizeof(element));
		return;
	}

	GcdR(b, q, result);
}

static void GcdExtendedR(IN p_element a,
						 IN p_element b,
						 OUT p_element result,
						 OUT p_element x,
 						 OUT p_element y) {

	element r[NUM_SIZE];
	element q[NUM_SIZE];
	element tmp[NUM_SIZE * 2];
	element newX[NUM_SIZE];

	unsigned int zero = 0;

	memset(tmp, 0, NUM_SIZE * sizeof(element));
	memset(newX, 0, NUM_SIZE * sizeof(element));

	Div(a, b, r, q);

	if (Compare(q, &zero, NUM_SIZE, 1) == 0) {
		memset(result, 0, NUM_SIZE * sizeof(element));
		memset(x, 0, NUM_SIZE * sizeof(element));
		memset(y, 0, NUM_SIZE * sizeof(element));
		x[0] = 0;
		y[0] = 1;
		memcpy(result, b, NUM_SIZE * sizeof(element));
		return;
	}

	GcdExtendedR(b, q, result, x, y);

	memcpy(newX, y, NUM_SIZE * sizeof(element));
	Mul(y, r, tmp);
	Sub(x, tmp, y);
	memcpy(x, newX, NUM_SIZE * sizeof(element));
	return;
}

/************************************************************/
/*	����� ����� static �������								*/
/************************************************************/
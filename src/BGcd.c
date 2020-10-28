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

	ZEROING(_a);
	ZEROING(_b);

	COPY(a, _a);
	COPY(b, _b);

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

	ZEROING(_a);
	ZEROING(_b);

	COPY(a, _a);
	COPY(b, _b);

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

	int i = 0;

	Div(a, b, r, q);

	if (Compare(q, &zero, NUM_SIZE, ZERO_SIZE) == 0) {
		ZEROING(result);
		COPY(b, result);
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

	memset(tmp, 0, NUM_SIZE * 2 * sizeof(element));
	ZEROING(newX);

	Div(a, b, r, q);

	if (Compare(q, &zero, NUM_SIZE, ZERO_SIZE) == 0) {
		ZEROING(result);
		ZEROING(x);
		ZEROING(y);
		x[0] = 0;
		y[0] = 1;
		COPY(b, result);
		return;
	}

	GcdExtendedR(b, q, result, x, y);

	COPY(y, newX);
	Mul(y, r, tmp);
	Sub(x, tmp, y);
	COPY(newX, x);
	return;
}

/************************************************************/
/*	����� ����� static �������								*/
/************************************************************/
#include "BNumber.h"
#include "BGcd.h"
#include "Compare.h"
#include "BDiv.h"

/************************************************************/
/*	������ ����� static �������								*/
/************************************************************/

/************************************************************/
/*	 ������� �������� � ������ �����						*/
/*															*/
/*	 static void CompareAndSwitch(IN OUT p_element a,		*/
/*								  IN OUT p_element b);		*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element a		- ������ �����							*/
/*	p_element b		- ������ �����							*/
/*															*/
/*	�������:												*/
/*															*/
/*	- ���� b ������ a, �� a ����� ��������					*/
/*	  � b, � b ����� �������� � a							*/
/*	- ���� a ������ b, �� ������� ��������� �� �����		*/
/*	  �����������											*/
/*															*/
/************************************************************/

static void CompareAndSwitch(IN OUT p_element a,
							 IN OUT p_element b);

/************************************************************/
/*	����� ����� static �������								*/
/************************************************************/

void Gcd(IN p_element a,
		 IN p_element b,
		 OUT p_element result)  {
	
	CompareAndSwitch(a, b);

	element r[NUM_SIZE];
	element q[NUM_SIZE];
	element zero[NUM_SIZE];
	
	int i = 0;
	memset(zero, 0, NUM_SIZE * sizeof(element));

	Div(a, b, r, q);

	if (Compare(q, zero, NUM_SIZE, NUM_SIZE) == 0) {
		memcpy(result, b, NUM_SIZE * sizeof(element));
		return;
	}

	Gcd(b, q, result);
}

/************************************************************/
/*	������ ����� static �������								*/
/************************************************************/

static void CompareAndSwitch(IN OUT p_element a,
							 IN OUT p_element b) {
	int result = Compare(a, b, NUM_SIZE, NUM_SIZE);

	if (result == -1) {
		int i = 0;
		for (i = 0; i < NUM_SIZE; i++) {
			a[i] ^= b[i] ^= a[i] ^= b[i];
		}
	}
}

/************************************************************/
/*	����� ����� static �������								*/
/************************************************************/
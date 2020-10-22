#ifndef BGCD_H
#define BGCD_H

/************************************************************/
/*	������� ���������� ��� ���� ����� (a, b)				*/
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

LIB(void) Gcd(IN p_element a,
			  IN p_element b,
			  OUT p_element result);

/************************************************************/
/*	������� ���������� ���������� �����, ������������ 		*/
/*	������� ��������� ���									*/
/*															*/
/*	������� ���������: a * x + b * y = (a, b)				*/
/*															*/
/*	void GcdExtended(IN p_element a,						*/
/*					 IN p_element b,						*/
/*					 OUT p_element result,					*/
/*					 OUT p_element x,						*/
/*					 OUT p_element y);						*/
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

LIB(void) GcdExtended(IN p_element a,
					  IN p_element b,
					  OUT p_element result,
					  OUT p_element x,
					  OUT p_element y);

#endif
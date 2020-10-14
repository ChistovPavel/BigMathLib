#ifndef BGCD_H
#define BGCD_H

/************************************************************/
/*	������� ���������� ��� ���� �����						*/
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

#endif
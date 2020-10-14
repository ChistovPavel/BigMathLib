#ifndef COMPARE_H
#define COMPARE_H

/************************************************************/
/*	 ������� ��������� ���� �����, �������� ��������� ����	*/
/*															*/
/*	 int Compare(IN p_element valueL,						*/
/*				 IN p_element valueM,						*/
/*				 IN unsigned int sizeL,						*/
/*				 IN unsigned int sizeM);					*/
/*															*/
/*	������� ���������:										*/
/*															*/
/*	p_element valueL 		- ������ �������				*/
/*	p_element valueM		- ������ �������				*/
/*	unsigned int  sizeL		- ����� ������� ��������		*/
/*	unsigned int  sizeM		- ����� ������� ��������		*/
/*															*/
/*	������������ ��������:									*/
/*															*/
/*	-1	- ������ ������� ������ ������� ��������			*/
/*	 0	- ������ � ������ ������� �����						*/
/*	 1	- ������ ������� ������ ������� ��������			*/
/*															*/
/************************************************************/

LIB(int) Compare(p_element valueL, p_element valueM, unsigned int sizeL, unsigned int sizeM);


#endif
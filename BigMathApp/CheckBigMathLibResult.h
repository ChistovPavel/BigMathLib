#ifndef CHECKBIGMATHLIBRESULT_H
#define CHECKBIGMATHLIBRESULT_H

#define CHECK_PASSED "�������� ��������"
#define CHECK_NOT_PASSED "�������� �� ��������"

BOOL checkGcdExtendedResult(IN p_element a, 
							IN p_element b, 
							IN p_element x, 
							IN p_element y, 
							IN p_element d);

void proccessCheckResult(IN BOOL checkResult);

#endif
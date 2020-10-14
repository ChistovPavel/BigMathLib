#include "BNumber.h"
#include "BSum.h"

void Sum(IN p_element valueL, 
		 IN p_element valueM, 
		 OUT p_element out)
{
	int i = NUM_SIZE;
	while (--i >= 0) out[i] = 0;
	element d = 0;
	unsigned long long s;
	for (int i = 0; i < NUM_SIZE; i++)
	{
		s = (unsigned long long) valueL[i] + valueM[i] + d;
		out[i] = s;
		d = s >> (sizeof(element) * BYTE_LEN);
	}
}

void Increment(IN OUT p_element valueL)
{
	element one[NUM_SIZE];
	element _out[NUM_SIZE];
	memset(one, 0, NUM_SIZE * sizeof(element));
	one[0] = 1;
	Sum(valueL, one, _out);
	memcpy(valueL, _out, NUM_SIZE * sizeof(element));
}
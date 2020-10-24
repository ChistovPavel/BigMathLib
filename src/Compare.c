#include "BNumber.h"
#include "Compare.h"

 int Compare(IN p_element first,
			IN p_element second,
			IN unsigned int size1,
			IN unsigned int size2)
{
	unsigned int size = size1 > size2 ? size1 : size2;

	int i = 0, result = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (size1 > i && size2 > i)
		{
			if (first[i] > second[i]) { result = 1; break; }
			else if (first[i] < second[i]) { result = -1; break; }
		}
		else if (size1 < size)
		{
			if (second[i] > 0) { result = -1; break; }
		}
		else if (size2 < size)
		{
			if (first[i] > 0) { result = 1; break; }
		}
	}

	return result;
}

BOOL CompareAndSwap(IN OUT p_element a,
			        IN OUT p_element b) {
	int result = Compare(a, b, NUM_SIZE, NUM_SIZE);

	if (result == -1) {
		Swap(a, b);
		return True;
	}
	return False;
}

void Swap(IN OUT p_element a,
		  IN OUT p_element b) {
	int i = 0;
	for (i = 0; i < NUM_SIZE; i++) {
		a[i] ^= b[i] ^= a[i] ^= b[i];
	}
}
#include <iostream>
#include <string.h>
using namespace std;

/**
 *	���ַ���תΪ int-����
 */
 int stoi(string str)
 {
	char buf[64];
	if (str.length() <= 64) 
	{
		strcpy(buf, str.c_str());
	} else {
		return 0; /*	���	*/
	}

	return atoi(buf);
 }
#include <stdio.h>

int main()
{ 
	char i = 1;
	//int flag = 1;
	//while(i || flag==1)

	while(i)
	{
	printf("i = %d\n", i++);
	}
	printf("i = %d (pēc cikla)\n", i);

	// 127 (dec) -> 0111 1111
	//              1000 0000 -> (char) -128
	//             (1)000 0000 -> - (zīme)
	//invertēšana     111 1111
	//             +         1
	//		1000 0000 -> 2^7 = 128
	//			  -> -128

	//predējā operācija 1111 1111
	//		 (-)0000 0000
	//		  +        1
	//		  -> -1 

	return 0;
}

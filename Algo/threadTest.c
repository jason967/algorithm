#include<stdio.h>
#include<Windows.h>	
#include<process.h>

unsigned _stdcall Thread_ABC(void *arg)
{
	while (1)
	{
		printf("A");
		Sleep(1000);
	}
}

int main()
{
	_beginthreadex(NULL, 0, Thread_ABC, 0, 0, NULL);
	while (1) {
		printf("B");
		Sleep(2000);
	}
	return 0;
}
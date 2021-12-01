#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_COUNT 3

void function1(int *);  /* function1 prototype */
void function2(int *);	/* function2 prototype */

int main()
{

	pid_t return_value;
	int num = 12;

	return_value = fork();

	if (return_value < 0) {
		printf("ERROR in fork: child not created. Exiting!\n");
		exit (0);
	}
	else if (return_value == 0){
		function1(&num);
		printf("\n   Num = %d\n\n", num);
		printf("***function1 PROCESS IS DONE ***\n\n");
	}
	else{
		function2(&num);
		printf("\n   Num = %d\n\n", num);
		printf("***function2 PROCESS IS DONE***\n\n");
	}

	return 0;
}

void function1(int *intParam)
{
	int i;
	pid_t pid;

	pid = getpid();

	for (i = 1; i <= MAX_COUNT; i++) {
		printf ("\nThis line is from function1, value =  %d, pid = %d\n\n", i, pid);
		usleep (500); /* system call to sleep for 500 microseconds */
	}
}

void function2(int *intParam)
{
	int i;
	pid_t pid;

	pid = getpid();

	for(i=1; i <= MAX_COUNT; i++) {
		printf("\n\t\tThis line is from function2, value = %d, pid = %d\n\n", i+5, pid);
		usleep (350); /* system call to sleep for 350 microseconds */
	}
	*intParam = *intParam + 12;
}

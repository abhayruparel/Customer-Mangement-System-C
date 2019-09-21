#include "stdio.h"
#include "string.h"
#include "stdlib.h"
void print() {
	int loginChoice;
	char ch;
	loginStart:
	system("cls"); // system("clear"); for linux
	printf("******Available login options******\n");
	printf("Press 1 for Owner\nPress 2 for Customer\nPress 3 to exit\n");
	scanf("%d",&loginChoice);
	switch(loginChoice) {
		case 1: printf("Onwer login page");
				break;
		case 2: printf("Customer login page:");
				break;
		case 3: printf("Thank you!");
				sleep(3);
				break;
		default: printf("Invalid chocie. Try again.");
				 //print();
				 fflush(stdin);
				 goto loginStart;
	}
}
int main()
{
	print();
	return 0;

}

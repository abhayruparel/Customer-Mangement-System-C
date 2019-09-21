#include "stdio.h"
#include "string.h"
void print() {
	int loginChoice;
	loginStart:
	system("clear"); // system("clear"); for linux
	printf("******Available login options******\n");
	printf("Press 1 for Owner\nPress 2 for Customer\nPress 3 to exit\n");
	scanf("%d",&loginChoice);
	switch(loginChoice) {
		case 1: printf("Onwer login page");
				break;
		case 2: printf("Customer login page:");
				break;
		case 3: printf("Thank you!");
				getchar();
				break;
		default: printf("Invalid chocie. Try again.\n");
				 goto loginStart;
	}
}
int main()
{
	print();
	return 0;

}	

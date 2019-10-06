//Rambhai Software - No clever tagline ever needed
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
void ownerLogin();
int validateUser();
void displayProjects();

struct projectDetail {
	char name[50];
	int isActive;
}project[10];
void optLogin() {
	int loginChoice;
	char ch;
	loginStart:
	system("cls"); // system("clear"); for linux
	printf("******Available login options******\n");
	printf("Press 1 for Owner Login\nPress 2 to display all projects\nPress 3 to exit\n");
	scanf("%d",&loginChoice);
	switch(loginChoice) {
		case 1: printf("Onwer login page");
				ownerLogin();
				break;
		case 2: displayProjects();
				break;
		case 3: printf("Thank you!");
				sleep(3);
				break;
		default: printf("Invalid chocie. Try again.");
				sleep(3);
				 //print();
				 fflush(stdin);
				 goto loginStart;
	}
}
void ownerLogin() {
	char ch[50];
	char pw[50];
	int back;
	int s;
	system("cls");
	printf("You have selected Owner as login\n\nPress 1 to continue\n\nAnything else to go back if this was a mistake.");
	scanf("%d",&back);
	if (back != 1) {
		optLogin();// go back
	}
	lab: fflush(stdin);
	printf("Enter Username:");
	scanf("%[^\n]%*c",ch);
	printf("Enter Password:");
	scanf("%[^\n]%*c",pw);
	s=validateUser(ch,pw);
}
void displayProjects() {
	int i;
	strcpy(project[0].name,"Abhay's site");
	project[0].isActive=1;
	strcpy(project[1].name,"Aditya Sir's Site");
	project[1].isActive=1;
	strcpy(project[2].name,"WhiteWashing");
	project[2].isActive=1;
	strcpy(project[3].name,"RamBhai Pro");
	project[3].isActive=1;
	strcpy(project[4].name,"Shyamlalbhai more pro");
	project[4].isActive=1;
	for (i=0;i<5;i++) {
		printf("project name%d:%s\n",i,project[i].name);
		
	}
	
}
int validateUser(char ch[],char pw[]) {
	printf("Inside validateUser() %s and %s values are caught",ch,pw);
	return 0;
}
int main()
{
	optLogin();
	return 0;
}

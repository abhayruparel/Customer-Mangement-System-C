//Rambhai Software - No clever tagline ever needed
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
void ownerLogin();
int validateUser();
void displayProjectsT7();
void displayGoodsT8();
struct projectDetail {
	char name[50], contractor[50];
	int isActive;
}project[5];
struct productDetails {
	char brand_name[50], item_name[50];
	float price;
	int quantity, isAvailable;
}item[10];
void optLogin() {
	int loginChoice;
	char ch;
	loginStart:
	system("cls"); // system("clear"); for linux
	printf("************Available login options************\n");
	printf("Press 1. for Owner Login\nPress 2. Display all the active projects being handled by the contractor named \"Mohan\" or \"Shyamlal\"\nPress 3. Display all the items which are currently available in the stock\nPress 4 to exit\n");
	scanf("%d",&loginChoice);
	switch(loginChoice) {
		case 1: printf("Onwer login page");
				ownerLogin();
				break;
		case 2: displayProjectsT7();
				break;
		case 3: displayGoodsT8();
				break;
		case 4: printf("Thank you!");
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
void displayProjectsT7() {
	int i;
	strcpy(project[0].name,"Abhay's site");
	strcpy(project[0].contractor,"Abhay");
	project[0].isActive=1;
	strcpy(project[1].name,"Mohan Site");
	strcpy(project[1].contractor,"Mohan");
	project[1].isActive=1;
	strcpy(project[2].name,"WhiteWashing");
	strcpy(project[2].contractor,"Mohan");
	project[2].isActive=1;
	strcpy(project[3].name,"Shyamlal");
	strcpy(project[3].contractor,"Shyamlal");
	project[3].isActive=1;
	strcpy(project[4].name,"Shyamlalbhai more pro");
	strcpy(project[4].contractor,"Shyamlal");
	project[4].isActive=1;
	printf("Projects of mohan\n");
	for (i=0;i<5;i++) {
		if ( strcmp (project[i].contractor,"Mohan") == 0 ) {
			printf("project name%d:%s\n",i,project[i].name);
		}
	}
	printf("Projects of Shyamlal\n");
	for (i=0;i<5;i++) {
		if ( strcmp (project[i].contractor,"Shyamlal") == 0 ) {
			printf("project name%d:%s\n",i,project[i].name);
		}
	}
	
}
void displayGoodsT8() {
	int i;
	printf("Available gooods are:\n");
	printf("Item name | Item Brand | Item Price | Quantity available\n");
	for (i=0;i<10;i++) {
		if ( item[i].quantity > 0) {
			item[i].isAvailable=1;
		}
		else {
			item[i].isAvailable=0;
		}
		if ( item[i].isAvailable==1) {
			printf("%s | %s | %.2f | %d\n",item[i].item_name,item[i].brand_name,item[i].price,item[i].quantity);
		}
	}
}
int validateUser(char ch[],char pw[]) {
	printf("Inside validateUser() %s and %s values are caught",ch,pw);
	return 0;
}
int main()
{
	strcpy(item[0].brand_name,"asian paints");
	strcpy(item[0].item_name,"Teflon Coated Paint blue color");
	item[0].price=300.00;
	item[0].quantity=30;
	optLogin();
	return 0;
}

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
	system("clear"); // system("cls"); for windows
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
void search(char itemSearch[],char brandSearch[],int quantitySearch) {
	int i;
	int na=0;
	for (i=0; i<10; i++) {
		if(strcmp(item[i].brand_name,brandSearch)==0 && strcmp(item[i].item_name,itemSearch)==0) {
			if ( item[i].quantity >= quantitySearch) {
				item[i].isAvailable=1;
			}
			else {
				item[i].isAvailable=0;
			}
			if (item[i].isAvailable==1) {
				printf("Requested Item details are:\n");
				printf("Item #%d:\n",i+1);
				printf("Item name | Item Brand | Item Price | Quantity available\n");
				printf("%s | %s | %.2f | %d\n",item[i].item_name,item[i].brand_name,item[i].price,item[i].quantity);
				float total_cost;
				total_cost=item[i].price * quantitySearch;
				printf("Total cost of requested items is %.2f",total_cost);
			}
			else {
				printf("Insufficient stock.\nGoing To Main menu");
				sleep(2);
				optLogin();
			}

		}
		else {
			na++;
		}
	}
	if(na==10) {
		printf("Product not found. Going back to login page");
		optLogin();
		sleep(2);
	}
}
void ownerLogin() {
	char ch[50];
	char pw[50],brandSearch[20],itemSearch[20];
	int back;
	int s;
	system("cls");
	printf("You have selected Owner as login\n\nPress 1 to continue\n\nAnything else to go back if this was a mistake.\n");
	scanf("%d",&back);
	if (back != 1) {
		optLogin();// go back
	}
	tryAgain:	fflush(stdin);
	printf("Enter Username:");
	scanf("%[^\n]%*c",ch);
	printf("Enter Password:");
	scanf("%[^\n]%*c",pw);
	s=validateUser(ch,pw);
	if (s==1) {
		printf("\nEnter Brand Name which you requrire:");
		scanf("%[^\n]%*c",brandSearch);
		printf("Enter item Name require:");
		scanf("%[^\n]%*c",itemSearch);
		printf("Enter Required quantity:");
		int quantitySearch;
		scanf("%d",&quantitySearch);
		search(itemSearch,brandSearch,quantitySearch);
	}
	else {
		printf("Incorrect credentials! Please try again.");
		sleep(1);
		goto tryAgain;
	}
	
}
int validateUser(char ch[],char pw[]) {
//	printf("Inside validateUser() %s and %s values are caught",ch,pw);
	if (strcmp(ch,"admin")==0 && strcmp(pw,"12345")==0) {
		return 1;
	}
	return 0;
}
void displayProjectsT7() {
	int i;

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
	printf("if you would like to exit press 1\n Else press anything else");
	scanf("%d",i);
	
	if(i==1){
	exit(0);
	}
	else {
		optLogin();
	}
	
}
int main()
{
	//available items, didnt get them for user as it made literally 0 sense.!
	// Also i beleive this stored in a file or database for better execution
	// item 0
	strcpy(item[0].brand_name,"asian paints");
	strcpy(item[0].item_name,"Teflon Coated Paint blue color");
	item[0].price=300.00;
	item[0].quantity=30;
	// item 1
	strcpy(item[1].brand_name,"asian paints");
	strcpy(item[1].item_name,"Brush");
	item[1].price=300.00;
	item[1].quantity=0;
	// item 2
	strcpy(item[2].brand_name,"asian paints");
	strcpy(item[2].item_name,"Teflon Coated Paint blue color");
	item[2].price=800.00;
	item[2].quantity=50;
		// item 3
	strcpy(item[3].brand_name,"asian paints");
	strcpy(item[3].item_name,"Teflon Coated Paint blue color");
	item[3].price=800.00;
	item[3].quantity=50;
		// item 4
	strcpy(item[4].brand_name,"asian paints");
	strcpy(item[4].item_name,"Teflon Coated Paint blue color");
	item[4].price=800.00;
	item[4].quantity=50;
		// item 5
	strcpy(item[5].brand_name,"asian paints");
	strcpy(item[5].item_name,"Teflon Coated Paint blue color");
	item[5].price=800.00;
	item[5].quantity=50;
	// item 6
	strcpy(item[6].brand_name,"asian paints");
	strcpy(item[6].item_name,"Teflon Coated Paint blue color");
	item[6].price=800.00;
	item[6].quantity=50;
	// item 7
	strcpy(item[7].brand_name,"asian paints");
	strcpy(item[7].item_name,"Teflon Coated Paint blue color");
	item[7].price=800.00;
	item[7].quantity=50;
		// item 8
	strcpy(item[8].brand_name,"asian paints");
	strcpy(item[8].item_name,"Teflon Coated Paint blue color");
	item[8].price=800.00;
	item[8].quantity=50;
		// item 9
	strcpy(item[9].brand_name,"asian paints");
	strcpy(item[9].item_name,"Teflon Coated Paint blue color");
	item[9].price=800.00;
	item[9].quantity=50;
	
	//projects assign
	//project[0]
	strcpy(project[0].name,"Abhay's site");
	strcpy(project[0].contractor,"Abhay");
	project[0].isActive=1;
	//project[1]
	strcpy(project[1].name,"Mohan Site");
	strcpy(project[1].contractor,"Mohan");
	project[1].isActive=1;
	//project[2]
	strcpy(project[2].name,"WhiteWashing");
	strcpy(project[2].contractor,"Mohan");
	project[2].isActive=1;
	//project[3]
	strcpy(project[3].name,"Shyamlal");
	strcpy(project[3].contractor,"Shyamlal");
	project[3].isActive=1;
	//project[4]
	strcpy(project[4].name,"Shyamlalbhai more pro");
	strcpy(project[4].contractor,"Shyamlal");
	project[4].isActive=1;
	// assignment of projects and items complete
	
	optLogin();
	return 0;
}

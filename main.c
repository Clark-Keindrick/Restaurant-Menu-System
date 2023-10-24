#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

char* foodmenu();
char* soupmenu();
char* dessertMenu();
char* drinksMenu();
char selectMainOption();
void viewMenuProducts();
void dispmenu();
void displayOrderList();
void addOrderToList(char* product_name, int numOfOrders, float price, float subtotalPrice);
float foodSelector(char choice);
float soupSelector(char choice);
float dessertSelector(char choice);
float drinksSelector(char choice);
float computeSubTotal(float price, int qty);
float getTotalBill();
int checkAmount(float payment, float bill);
void takeOrder();
int acceptPayment();
int selectMenu();
int getQtyOrder();
int getPaymentType();
int printBill(float totalBill, int paymentType, float amountPaid, float discounts, float change);
void exit();



typedef struct Order
{
    char* name;
    float price;
    int qty;
    float subtotal;
}

orderList;
orderList orders[20];
int ordertaken = 0;


int main()
{
    char selectMain;

    do{
	selectMain = selectMainOption();
	if (selectMain == 'a' || selectMain == 'A')
		{
            takeOrder();
        }
		else if (selectMain == 'b' || selectMain == 'B')
		{
            displayOrderList();
        }
		else if(selectMain == 'c' || selectMain == 'C')
		{
            if (acceptPayment() == 0)
            	selectMain = 'x';
        }
    }
	while (selectMain != 'x' && selectMain != 'X');
    system("cls");
    exit(0);

    return 0;
}

char selectMainOption()
{
  system("cls");
  printf("              ==============================          \n");
  printf("                 CHALMA Seafood Restaurant          \n ");
  printf("             ==============================          \n\n");

  printf("\t\tEnter [A] -> View Menu\n");
  printf("\t\tEnter [B] -> View Order\n");
  printf("\t\tEnter [C] -> Pay Bill\n");
  printf("\t\tEnter [x] -> Exit\n\n");

  printf("              ==============================          \n");
  time_t t;   // not a primitive datatype
  time(&t);
  printf("\t\t %s", ctime(&t));
  printf("              ==============================          \n\n");
  printf("\t      Please Enter Your Choice: ");
    while (1)
	{
        char c = getchar();
       if (c == 'a' || c == 'b' || c == 'c' || c == 'x' || c == 'A' || c == 'B' || c == 'C' || c == 'X')
		{
            return c;
        }
        else if (c != '\n')
        {
            system("cls");
        	printf("\n\t\t!!! Sorry Invalid Input !!!\n");
        	exit(0);
		}
    }
}

void dispmenu() ///Display the Restaurant Menu
{
  system("cls");
  printf("\t            ==============================          \n");
  printf("\t                Restaurant Menu   \n");
  printf("\t            ==============================          \n\n");

  printf("\t\t\tEnter [A] -> FOOD\n");
  printf("\t\t\tEnter [B] -> SOUP\n");
  printf("\t\t\tEnter [C] -> DESSERT\n");
  printf("\t\t\tEnter [D] -> DRINKS\n");
  printf("\t\t\tEnter [X] -> Go back to Main menu\n");
}

int selectMenu()
{
  char c;
     printf("\n\t\t\tEnter Menu Selection: ");
    while (1)
	{
        c = getchar();
        if (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'x' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'X')
		{
            break;
        }
        else if (c != '\n')
        {
        	printf("\n!!! ERROR INPUT !!!\n");
        	sleep(1);
        	dispmenu();
		}
    }

    return c;
}

char* foodmenu() ///Food Menu Screen
{
  char* food;
  system("cls");
  printf("\t            ==============================          \n");
  printf("\t                    Food Menu   \n");
  printf("\t            ==============================          \n\n");

  printf("\t   [1] Calamares w/ rice                          - P 250 \n");
  printf("\t   [2] Baked Scallops w/ rice                     - P 350 \n");
  printf("\t   [3] Grilled stuffed squid w/ rice              - P 350 \n");
  printf("\t   [4] Garlic buttered shrimp w/ rice             - P 250 \n");
  printf("\t   [5] Seared Salmon                              - P 300 \n");
  printf("\t   [X] Back To Main-Menu         ");
  printf("\n\n \t   Enter your choice here : ");

    char c;
    do
	{
		scanf("%c", &c);
        c = getchar();

        if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X') {
        	printf("\n!!! ERROR INPUT !!!\n");
		}
    }
	while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X');

    switch (c)
	{
        case '1':
            food = "1Calamares w/ rice\t\t\t\t";
            break;
        case '2':
            food = "2Baked Scallops w/ rice\t\t\t";
            break;
        case '3':
            food = "3Grilled stuffed squid w/ rice\t\t\t";
            break;
        case '4':
            food = "4Garlic buttered shrimp w/ rice  \t\t\t";
            break;
        case '5':
            food = "5Seared Salmon\t\t\t";
            break;
        default:
            food = "x";
    }

    return food;
}
float foodSelector(char choice)
{
    float price = 0.0;
    printf("FOOD SELECTED:  ");

    switch (choice)
	{
        case '1':
            printf("Calamares w/ rice \n");
            price = 250.0;
            break;
        case '2':
            printf("Baked Scallops w/ rice \n");
            price = 350.0;
            break;
        case '3':
            printf("Grilled stuffed squid w/ rice \n");
            price = 350.0;
            break;
        case '4':
            printf("Garlic buttered shrimp w/ rice n");
            price = 250.0;
            break;
        case '5':
            printf("Seared Salmon \n");
            price = 300.0;
            break;
    }

    return price;
}

char* soupmenu() /// Soup Screen Menu
{
  char* soup;

  system("cls");
  printf("\t               ==============================          \n");
  printf("\t                        Soup Menu   \n");
  printf("\t               ==============================          \n\n");

  printf("\t   [1] Fish Soup                     - P 300 \n");
  printf("\t   [2] Gumbo Soup                    - P 320 \n");
  printf("\t   [3] Clam Chowder                  - P 350 \n");
  printf("\t   [4] Cream of Crab Soup            - P 350 \n");
  printf("\t   [5] Seafood Miso Soup             - P 400 \n");
  printf("\t   [X] Back To Main-Menu               \n");
  printf("\n\n \t   Enter your choice here : ");

    char c;
    do
	{
		scanf("%c", &c);
        c = getchar();

        if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X') {
        	printf("\n!!! ERROR INPUT !!!\n");
		}
    }
	while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X');

	switch(c)
	{
        case '1':
            soup = "1Fish Soup\t\t\t";
            break;
        case '2':
            soup = "2Gumbo Soup \t\t\t";
            break;
        case '3':
            soup = "3Clam Chowder\t\t\t";
            break;
        case '4':
            soup = "4Cream of Crab Soup \t\t\t";
            break;
        case '5':
            soup = "5Seafood Miso Soup \t\t\t";
            break;
        default:
            soup = "x";
    }

    return soup;
}

float soupSelector(char choice)
{
    float price = 0.0;
    printf("Soup Selected: ");

    switch (choice)
	{
        case '1':
            printf("Fish Soup\t\t\t\t\n");
            price = 300.00;
            break;
        case '2':
            printf("Gumbo Soup \t\t\t\n");
            price = 320.00;
            break;
        case '3':
            printf("Clam Chowder\t\t\t\n");
            price = 350.00;
            break;
        case '4':
            printf("Cream of Crab Soup \t\t\t\n");
            price = 350.00;
            break;
        case '5':
            printf("Seafood Miso Soup \t\t\t\n");
            price = 400.00;
            break;
    }

    return price;
}

char* dessertMenu() /// Dessert Menu Screen
{
  char* dessert;
  system("cls");

  printf("\t               ==============================          \n");
  printf("\t                        Dessert Menu   \n");
  printf("\t               ==============================          \n\n");
  printf("\t   [1] Mixed Fruits                  - P 99 \n");
  printf("\t   [2] Mango Sago                    - P 99 \n");
  printf("\t   [3] Almond w/ buko Pandan         - P 99 \n");
  printf("\t   [4] Plain Black Gulaman           - P 99 \n");
  printf("\t   [5] Mango Graham Shake            - P 150 \n");
  printf("\t   [X] Back To Main-Menu               \n");
  printf("\n\n \t   Enter your choice here : ");

    char c;
    do
	{
		scanf("%c", &c);
        c = getchar();

        if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X') {
        	printf("\n!!! ERROR INPUT !!!\n");
		}
    }
	while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X');

       switch(c)
	{
        case '1':
            dessert = "1Mixed Fruits \t\t\t\t\n";
            break;
        case '2':
            dessert = "2Mango Sago  \t\t\t\n";
            break;
        case '3':
            dessert = "3Almond w/ buko Pandan\t\t\t\n";
            break;
        case '4':
            dessert = "4Plain Black Gulaman \t\t\t\n";
            break;
        case '5':
            dessert = "5Mango Graham Shake \t\t\t\n";
            break;
        default:
            dessert = "x";
    }

    return dessert;

}

float dessertSelector(char choice)
{
    float price = 0.0;
    printf("Dessert Selected: ");

    switch (choice)
	{
        case '1':
            printf("Mixed Fruits\t\t\t\n");
            price = 99.00;
            break;
        case '2':
            printf("Mango Sago \t\t\t\n");
            price = 99.00;
            break;
        case '3':
            printf("Almond w/ buko Pandan\t\t\t\n");
            price = 99.00;
            break;
        case '4':
            printf("Plain Black Gulaman \t\t\t\n");
            price = 99.00;
            break;
        case '5':
            printf("Mango Graham Shake \t\t\t\n");
            price = 150.00;
            break;
    }

    return price;
}

char* drinksMenu() ///Drinks Menu Screen
{

  char* drinks;
  system("cls");

  printf("\t            ==============================          \n");
  printf("\t                    Drinks Menu   \n");
  printf("\t            ==============================          \n\n");

  printf("\t   [1] ICE TEA                             - P 80 \n");
  printf("\t   [2] FRESH BUKO                          - P 80 \n");
  printf("\t   [3] CALAMANSI JUICE                     - P 65 \n");
  printf("\t   [4] Assorted SoftDrinks in Can          - P 65 \n");
  printf("\t   [5] GRAPE JUICE                         - P 60 \n");
  printf("\t   [X] Back To Main-Menu         ");
  printf("\n\n \t   Enter your choice here : ");


    char c;
    do
	{
		scanf("%c", &c);
        c = getchar();

        if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X') {
        	printf("\n!!! ERROR INPUT !!!\n");
		}
    }
	while (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != 'x' && c != 'X');

       switch(c)
	{
        case '1':
            drinks = "1Mixed Fruits \t\t\t\t";
            break;
        case '2':
            drinks = "2FRESH BUKO   \t\t\t";
            break;
        case '3':
            drinks = "3CALAMANSI JUICE   \t\t\t";
            break;
        case '4':
            drinks = "4Assorted SoftDrinks in Can  \t\t\t";
            break;
        case '5':
            drinks = "5GRAPE JUICE  \t\t\t";
            break;
        default:
            drinks = "x";

    }

    return drinks;
}

float drinksSelector(char choice)
{
    float price = 0.0;
    printf("Drinks selected:  ");

    switch (choice)
	{
        case '1':
            printf("Mixed Fruits\n");
            price = 80.0;
            break;
        case '2':
            printf("FRESH BUKO  \n");
            price = 80.0;
            break;
        case '3':
            printf("CALAMANSI JUICE \n");
            price = 65.0;
            break;
       case '4':
            printf("Assorted SoftDrinks in Can\n");
            price = 65.0;
            break;
        case '5':
            printf("GRAPE JUICE \n");
            price = 60.0;
            break;
    }

    return price;
}

int getQtyOrder()
{
    int qty;

    printf("Enter quantity: ");
    scanf("%d", &qty);

    return qty;
}

float computeSubTotal(float price, int qty)
{
    return (float) qty * price;
}

void takeOrder()
{
   char selectedMenu;

    do
	{
        dispmenu();

        selectedMenu = selectMenu();
        char* item;
        float price, subtotal;
        int qty;

         if (selectedMenu != 'x' && selectedMenu != 'X')
		{
            if (selectedMenu == 'a' || selectedMenu == 'A')
			{
                item = foodmenu();

                if (item[0] == 'x' || item[0] == 'X') {
					continue;
				}

                price = foodSelector(item[0]);
            }
			else if (selectedMenu == 'b' || selectedMenu == 'B')
			{
                item = soupmenu();

                if (item[0] == 'x' || item[0] == 'X') {
					continue;
				}

                price = soupSelector(item[0]);
            }

            else if (selectedMenu == 'c' || selectedMenu == 'C')
			{
                item = dessertMenu();

                if (item[0] == 'x' || item[0] == 'X') {
					continue;
				}

                price = dessertSelector(item[0]);
            }
            else if (selectedMenu == 'd' || selectedMenu == 'D')
			{
                item = drinksMenu();

                if (item[0] == 'x' || item[0] == 'X')  {
					continue;
				}

                price = drinksSelector(item[0]);
            }

            qty = getQtyOrder();
            subtotal = computeSubTotal(price, qty);
            item++;

            addOrderToList(item, qty, price, subtotal);
        }
	}
	while (selectedMenu != 'x' && selectedMenu != 'X');
}

void addOrderToList(char* product_name, int numOfOrders, float price, float subtotalPrice)
{
    orderList Order;
    Order.name = product_name;
    Order.price = price;
    Order.qty = numOfOrders;
    Order.subtotal = subtotalPrice;

    orders[ordertaken] = Order;
    ordertaken++;
}

void displayOrderList()
{
	int i;

	system("cls");

	if (ordertaken == 0) {
 printf("             =================================          \n");
  printf("                No orders has been made yet          \n ");
  printf("            =================================          \n\n");

	} else {
		printf(" \n  ::::::::::::::::::::::::::  |ORDER LIST|  :::::::::::::::::::::::::: \n");
        printf("\nPRODUCT NAME \t\t\t\t     QTY \t\t PRICE \t\t SUBTOTAL\n");
		float totalPrice = 0.0;

		for (i = 0; i < ordertaken; i++)
		{
        printf("[%d] %s%d\t\t%.2f\t\t%.2f\n", i+1, orders[i].name, orders[i].qty, orders[i].price, orders[i].subtotal);
			totalPrice += orders[i].subtotal;
		}

              printf("\n\n===================================          ");
           	  printf("\nYour total bill amount is P %f\n", totalPrice);
              printf("====================================          \n");
	}
	  printf("\n\n              Press X to go back: ");

	while (getchar() != 'X' && getchar() != 'x');
}

 int getPaymentType() {
	system("cls");

	printf(" \n           ::::::::::::::::::::::::::  |BILLING SECTION|  ::::::::::::::::::::::::::     \n\n");
	printf("\t\t\tChoose payment type:\n");
	printf("\t\t\t[1] Cash\n");
	printf("\t\t\t[2] Card\n");
    printf("\n\t\t\tEnter: ");
	while (1)
	{
        char c = getchar();
        if (c == '1' || c == '2')
		{
            return c;
        }
        else if (c != '\n')
        {
        	printf("\n!!! ERROR INPUT !!!\n");
		}
    }

}

 float getTotalBill()
 {
	int i;
	float totalPrice;
	for (i = 0; i < ordertaken; i++) {
		totalPrice += orders[i].subtotal;
	}

	system("cls");
	printf(" \n           ::::::::::::::::::::::::::  |BILLING SECTION|  ::::::::::::::::::::::::::     ");
	printf("\n                               ===================================          ");
    printf("\n                               Your total bill amount is P %f\n", totalPrice);
    printf("                              ====================================          \n");

    return totalPrice;
}
int acceptPayment()
{
	if (ordertaken > 0) {

        float bill = getTotalBill();

        printf("\nDo you want to Continue? Y-yes || N-no: ");
        char choice;

        while (1)
		{
			choice = getchar();
			if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
			{
			    break;
			}
			else if (choice != '\n')
			{
			    system("cls");
			    printf("\n!!! SORRY INVALID INPUT !!!\n");
			    selectMainOption();
			}
		}

		if (choice == 'N' || choice == 'n') {
			return 1;
		}
        int type = getPaymentType();

        system("cls");

       printf(" \n           ::::::::::::::::::::::::::  |BILLING SECTION|  ::::::::::::::::::::::::::     ");
	   printf("\n                               ===================================          ");
       printf("\n                               Your total bill amount is P %f", bill);
       printf("\n                              ====================================          \n");

        float payment;

        do
        {
        	printf("\nEnter payment: Php ");
        	scanf("%f", &payment);

        	if (payment < bill) {
        		printf("!!! INSUFFICIENT AMOUNT !!!\n\n");
			}

		} while (payment < bill);

		float change = payment-bill;


		printBill(bill, type, payment, 0, change);

		printf("Your CHANGE is P %.2f \n", change);
		printf("Wait a second.... receipt is coming\n");
		printf("->->->Enter any key to leave the RESTAURANT<-<-<-");

		getch();

		system("cls");
		exit(0);
		return 0;
	  } else {
		 printf("             =================================          \n");
         printf("                No orders has been made yet          \n ");
         printf("            =================================          \n\n");
		return 1;
	}
}

int printBill(float totalBill, int paymentType, float amountPaid, float discounts, float change) {
	FILE *billFile;

	billFile = fopen("bill.txt", "w");

	if (billFile != NULL) {
		if (paymentType == 1) {
			fprintf(billFile, "PAYMENT TYPE: CASH\n");
		} else {
			fprintf(billFile, "PAYMENT TYPE: CARD\n");
		}
        fprintf(billFile, "====================================          \n");
		fprintf(billFile, "||    TOTAL BILL   ***  Php %f  ||\n", totalBill);
		fprintf(billFile, "||    AMOUNT PAID  *** Php %f   ||\n", amountPaid);
		fprintf(billFile, "||    DISCOUNTS    *** Php %f   ||\n", discounts);
		fprintf(billFile, "||  ----------------------------  ||\n");
		fprintf(billFile, "||     CHANGE      ***  Php %f  ||\n", change);
		fprintf(billFile,  "====================================          \n");
	}

	fclose(billFile);
	return 0;
}
void exit(back)  /// Exit Screen
{
  printf("\n\n\t===============CSR==================          ");
  printf("\t\t \n    Thanks for choosing CHALMA Seafood Restaurant\n\n");
  printf("\t     We hope to see you again!  \n");
  printf("\t====================================  \n");
  getch();
  system("cls");
  selectMainOption();
}




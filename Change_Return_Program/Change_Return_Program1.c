#include <stdio.h>
#include <string.h>
#include <math.h>


char UserInput[256];

int main(int argc, char *argv[])
{


	//Amount of coins we'll give to the customer
	int NumberOfQuarters = 0;
	int NumberOfDimes = 0;
	int NumberOfNickles = 0;
	int NumberOfPennies = 0;

	float CustomMoney;
	float charge;
	float change;
	int PurchaseItem;
	

	//items in vending machine
	float Snickers = 2.50f;
	float KitKat = 1.75f;
	float Walkers = 3.75f;
	float Smarties = 2.85f;
	float Fanta = 1.25f;
	float CocaCola = 1.50f;

	//display welcome message
	printf("*** Welcome to The Vending Machine ***\n");

	printf("Here is what we have in store\n");

	printf("Snickers: $%.2f\n", Snickers);
	printf("KitKat: $%.2f\n", KitKat);
	printf("Walkers: $%.2f\n", Walkers);
	printf("Smarties: $%.2f\n", Smarties);
	printf("Fanta: $%.2f\n", Fanta);
	printf("CocaCola: $%.2f\n", CocaCola);

	//picking the item from the vending machine
	printf("Please press the following numbers for your desired item\n");
	printf("1: Snickers\n");
	printf("2: KitKat\n");
	printf("3: Walkers\n");
	printf("4: Smarties\n");
	printf("5: Fanta\n");
	printf("6: CocaCola\n");

	//now input the  customer choice
	if(fgets(UserInput, sizeof(UserInput), stdin)) {
		if(1 == sscanf(UserInput, "%d\n", &PurchaseItem)) {
		}
	}

	//Now set the PurchaseItem to the item the customer has chosen 
	switch(PurchaseItem) {
		case 1 :
			charge = Snickers;
			break;
		case 2 : 
			charge = KitKat;
			break;
		case 3 : 
			charge = Walkers;
			break;
		case 4 :
			charge = Smarties;
			break;
		case 5 :
			charge = Fanta;
			break;
		default :
			charge = CocaCola;
			break;
	}


	// ask the as customer to pay the owe amount
	printf("The item cost is: $%.2f\n", charge);
	printf("Please insert :   $%.2f\n", charge);
	if(fgets(UserInput, sizeof(UserInput), stdin)) {
		if(1 == sscanf(UserInput, "%f\n", &CustomMoney)) {
		}
	}

	//Calculate the change
	change = CustomMoney - charge;
	printf("The Vending Machine owes you: $%.2f\n", change);


	// calculate the amount of coins i need to give to the 
	// customer
	while(change > 0.00) {
		if(change >= 0.25) {
			change = change - 0.25;
			NumberOfQuarters++;
		}
		else if(change < 0.25 && change >= 0.10) {
			change = change - 0.10;
			NumberOfDimes++;
		}
		else if(change < 0.10 && change >= 0.05) {
			change = change - 0.05;
			NumberOfNickles++;
			
		}
		else {
			NumberOfPennies = (change + (0.01 / 2.00)) / 0.01;
			change = change - 0.01;
			NumberOfPennies;
	
			
		}
	}

	printf("Here is your change\n");
	printf("Amount of Quarters is X %d\n", NumberOfQuarters);
	printf("Amount of Dimes is X %d\n", NumberOfDimes);
	printf("Amount of Nickles is X %d\n", NumberOfNickles);
	printf("Amount of Pennies is X %d\n", NumberOfPennies);	

	return 0;
}
			
			 

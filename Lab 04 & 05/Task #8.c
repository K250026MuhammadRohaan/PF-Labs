#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	float loanAmount, rate, emi, totalAmount, simpleInterest;
	int time, interestType;
    printf("\n\t\t\t\t----------  MONTHLY INSTALLMENT (EMI) CALCULATOR FOR LOAN  ----------\n\n");


    printf("\nEnter the loan amount (in rupees): ");
    scanf("%f", &loanAmount);
    printf("\nEnter the time (in years): ");
    scanf("%d", &time);
    printf("\nEnter the rate of interest (annual in %%): ");
    scanf("%f", &rate);
    printf("\n\nEnter the interest type: \n1. Simple Interest \n2. Compound Interest:\n\n");
    scanf("%d", &interestType);


	switch(interestType)
	{
		case 1:
			simpleInterest = (loanAmount * rate * time) / 100.0;
        	totalAmount = loanAmount + simpleInterest;
        	emi = totalAmount / (time * 12);
        	break;
        	
        case 2:
        	totalAmount = loanAmount * pow((1 + rate / 100.0), time);
        	emi = totalAmount / (time * 12);
        	break;
        
        default:
        	printf("\n\n\nInvalid Input.\n");
        	break;
	}
	

    printf("\n\nThe Monthly Installment (EMI) is: %.2f rupees per month\n", emi);

	printf("\n");
	getch();
	return 0;
}


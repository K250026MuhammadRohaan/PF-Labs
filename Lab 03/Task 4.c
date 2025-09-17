#include <stdio.h>
#include <conio.h>
int main (void)
{
	float basic_salary, HRA, DA_Gross, Gross_Salary;
	printf("\n\t\t\t----------  GROSS SALARY CALCULATOR  ----------\n\n");
	
	printf("\nEnter your Basic Salary (in PKR):  ");
	scanf("%f", &basic_salary);
	
	HRA = basic_salary * 0.10;
	DA_Gross = basic_salary * 0.05;
	Gross_Salary = basic_salary + HRA + DA_Gross;
	
	printf("\n\nYour Gross Salary is:  PKR %.2f", Gross_Salary);
	
	getch();
	return 0;
}

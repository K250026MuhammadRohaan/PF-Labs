#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
	int a,b,c, discr;
	printf("\n\t\t\t\t------------ QUADRATIC EQN. ROOTS CHECKER ------------\n");
	
	printf("\nEnter the co-efficient of x^2 (a) in your quad. eqn. :  ");
	scanf("%d", &a);
	printf("\nEnter the co-efficient of x (b) in your quad. eqn. :  ");
	scanf("%d", &b);
	printf("\nEnter the constant (c) in your quad. eqn. :  ");
	scanf("%d", &c);
	
	discr = pow(b,2) - ( 4 * a * c);
	
	if(discr > 0)
		printf("\n\n\nSince the discriminant is %d > 0, \nthe roots of your quadratic eqn. (%d)x^2 + (%d)x + (%d) are:  REAL & DISTINCT\n", discr, a, b, c); 
	else if(discr == 0)
		printf("\n\n\nSince the discriminant is %d = 0, \nthe roots of your quadratic eqn. (%d)x^2 + (%d)x + (%d) are:  REAL & EQUAL\n", discr, a, b, c);
	else if(discr < 0)
		printf("\n\n\nSince the discriminant is %d < 0, \nthe roots of your quadratic eqn. (%d)x^2 + (%d)x + (%d) are:  IMAGINARY\n", discr, a, b, c);	
		
	getch();
	return 0;
}

#include <stdio.h>
#include <conio.h>
#include <math.h>
#define PI 3.142857

int main()
{
	int shape, calc;
	float radius, length, width, base, height, a,b,c;
	printf("\n\t\t\t\t------------ GEOMETRY CALCULATOR ------------\n");
	
	printf("\nChoose a Shape: \n1. Circle \n2. Rectange \n3. Triangle\n\n");
	scanf("%d", &shape);
	
	switch(shape)
	{
		case 1:
			printf("\n\nChoose what you want to calculate: \n1. [Area] \n2. [Perimeter]\n\n");
			scanf("%d", &calc);
			
			switch(calc)
			{
				case 1:
					printf("\nEnter the radius of the circle (in meters): ");
					scanf("%f", &radius);
					printf("\n\nThe Area of the circle is:  %.2f square meters", PI * pow(radius,2));
					break;
					
				case 2:
					printf("\nEnter the radius of the circle (in meters): ");
					scanf("%f", &radius);
					printf("\n\nThe Perimeter of the circle is:  %.2f meters", 2 * PI * radius);
					break;
				
				default:	
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
			
		case 2:
			printf("\n\nChoose what you want to calculate: \n1. [Area] \n2. [Perimeter]\n\n");
			scanf("%d", &calc);
			
			switch(calc)
			{
				case 1:
					printf("\nEnter the length of rectangle (in meters): ");
					scanf("%f", &length);
					printf("\nEnter the witdth of rectangle (in meters): ");
					scanf("%f", &width);
					printf("\n\nThe Area of the rectangle is:  %.2f square meters", length * width);
					break;
					
				case 2:
					printf("\nEnter the length of rectangle (in meters): ");
					scanf("%f", &length);
					printf("\nEnter the witdth of rectangle (in meters): ");
					scanf("%f", &width);
					printf("\n\nThe Perimeter of the rectangle is:  %.2f meters", 2 * (length + width));
					break;
				
				default:	
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
			
		case 3:
			printf("\n\nChoose what you want to calculate: \n1. [Area] \n2. [Perimeter]\n\n");
			scanf("%d", &calc);
			
			switch(calc)
			{
				case 1:
					printf("\nEnter the length of base of triangle (in meters): ");
					scanf("%f", &base);
					printf("\nEnter the height of triangle (in meters): ");
					scanf("%f", &height);
					printf("\n\nThe Area of the triangle is:  %.2f square meters", (1/2) * base * height);
					break;
					
				case 2:
					printf("\nEnter the length of side a (in meters): ");
					scanf("%f", &a);
					printf("\nEnter the length of side b (in meters): ");
					scanf("%f", &b);
					printf("\nEnter the length of side c (in meters): ");
					scanf("%f", &c);
					printf("\n\nThe Perimeter of the triangle is:  %.2f meters", a+b+c );
					break;
				
				default:	
				printf("\n\nINVALID INPUT");
				break;
			}
			break;
			
			
		default:
			printf("\n\nINVALID INPUT");
			break;
	}
	
	printf("\n");
	
	getch();
	return 0;
}

#include <stdio.h>
#include <conio.h>

int main()
{
	int n1, n2, n3, ans;
	
	printf("\n\nEnter your first number:  ");
	scanf(" %d", &n1);
	printf("\nEnter your second number:  ");
	scanf(" %d", &n2);
	printf("\nEnter your third number:  ");
	scanf(" %d", &n3);
	
	if(n1 < n2 && n1 < n3)
		ans = n1;
	else if(n2 < n1 && n2 < n3)
		ans = n2;
	else if(n3 < n1 && n3 < n2)
		ans = n3;
		
	printf("\n\n\nThe smallest number, of the three, is:  %d\n", ans);
	
	getch();
	return 0;
}

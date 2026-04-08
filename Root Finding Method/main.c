#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int menu() {
	
	int choice = 0;
	
	// Menu
	printf("The function is f(x)=-x^3 - 3x^2 + 2\n\n");
	printf("== Which Root Finding Method to use? ==\n");
	printf("[1] False Position Method\n");
	printf("[2] Newton Raphson\n");
	printf("[5] Exit\n>>> ");
	scanf("%d", &choice);
	
	return choice;
}

// The mathematical function hardcoded
double mathfunc(double x) {
	return -pow(x, 3) - 3*pow(x, 2) + 2;
}

// The first derivative of the mathematical function hardcoded
double diffmathfunc(double x) {
	return -3*pow(x, 2) - 6*x;
}

// Formula used for False Position Method
double FPM_approx(double left, double right) {
	return (left*mathfunc(right) - right*mathfunc(left))/(mathfunc(right) - mathfunc(left));
}

// Formula used for Newton-Raphson Method
double NRM_approx(double point) {
	return point-(mathfunc(point))/(diffmathfunc(point));
}

double falseposition() {
	// Variables
	double left;
	double right;
	double newpoint;
	int iter=20;
	
	// User input
	system("cls");
	printf("== False Position Method ==\n");
	printf("\nEnter left interval endpoint (float): ");
	scanf("%lf", &left);
	printf("\nEnter right interval endpoint (float): ");
	scanf("%lf", &right);
	printf("\nSpecify the maximum number of iterations (integer): ");
	scanf("%d", &iter);

	// Loop
	system("cls");
	printf("== False Position Method ==\n\n");
	printf("Initial Interval: [%.4f,%.4f]\tMax Iterations: %d\n", left, right, iter);
	printf("-----------------------------------------\n");
	printf("Iter\tInterval\t\tApproximation\n");
	for(int i=0; i<iter; i++) {	
		newpoint = FPM_approx(left,right);
		printf("%d\t[%.4f , %.4f]\t%.4f\n", i, left, right, newpoint);
		
		if(mathfunc(left)*mathfunc(newpoint) < 0) {
			right = newpoint;
		} else if(mathfunc(right)*mathfunc(newpoint) < 0) {
			left = newpoint;
		} else if (mathfunc(newpoint) == 0) {
			printf("\nAnswer is here!\n");
		} else {
			printf("\nError\n");
		}	
	}
}

double newtonraphson() {
	// Variables
	double point;
	int iter=20;
	
	// User input
	system("cls");
	printf("== Newton-Raphson Method ==\n");
	printf("\nEnter initial point (float): ");
	scanf("%lf", &point);
	printf("\nSpecify the maximum number of iterations (integer): ");
	scanf("%d", &iter);
	
	system("cls");
	printf("== Newton-Raphson Method ==\n\n");
	printf("Initial Point: %.4f\tMax Iterations: %d\n", point, iter);
	printf("-----------------------------------------\n");
	printf("Iter\tApproximation\n");
	printf("0\t%.4f\n", point);
	for (int i=0; i<iter; i++) {
		point = NRM_approx(point);
		printf("%d\t%.4f\n", i+1, point);
	}
}

int main() {
	int choice = menu();
	if(choice == 1) {
		falseposition();
	} else if(choice == 2) {
		newtonraphson();
	}
	
    return 0;

}
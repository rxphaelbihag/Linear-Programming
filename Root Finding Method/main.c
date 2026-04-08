#include <stdio.h>
#include <math.h>

double func(double x) {
	return -pow(x, 3) - 3*pow(x, 2) + 2;
}

double approx(double a, double b) {
	return (a*func(b) - b*func(a))/(func(b) - func(a));
}


int main() {
	
	//	Define variables
	double a = -0.925;
	double b = 200.0;
	int iter = 10;
	
	for(int i=0; i<iter; i++) {
		
		double c = approx(a,b);
		
		if(func(a)*func(c) < 0) {
			b = c;
		} 
		else if(func(b)*func(c) < 0) {
			a = c;
		}
		else if (func(c) == 0) {
			printf("Answer is here!");
		}
		else {
			printf("Error");
		}
		
		printf("A: %.6f \tB: %.6f \tC: %.6f\n", a, b, c);	
	}
	
    return 0;

}
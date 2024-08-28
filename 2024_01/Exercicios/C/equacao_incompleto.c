#include <stdio.h>
#include <math.h>

void calcular_raizes(double a, double b, double c){
    double delta = 0.0;
    double x1 = 0.0, x2 = 0.0;

    delta = b*b - 4*a*c;

    if(delta >= 0 && a != 0 && b != 0 && c != 0){
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);

        printf("%.1lf\nx1 = %.1lf\nx2 = %.1lf", delta, x1, x2);
    } else{
        printf("%.1lf Nao existem raizes", delta);
    }

}

int main(void){
    double a = 0.0, b = 0.0, c = 0.0;

    scanf("%lf %lf %lf", &a, &b, &c);
    
    calcular_raizes(a, b, c);

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define Nx 5
#define Ny 4
#define Nz 6

void vvod(float x[], int n, char name); 
void analiz(float x[], int n, float t, float *sum, float *avg); 

int main() 
{
    system("chcp 65001");

    float x[Nx], y[Ny], z[Nz], sum, avg, t;

    printf("Введіть граничне число t: ");
    scanf("%f", &t);

    vvod(x, Nx, 'x');
    vvod(y, Ny, 'y');
    vvod(z, Nz, 'z');

    analiz(x, Nx, t, &sum, &avg);
    printf("Масив x: сума = %.2f, середнє = %.2f\n", sum, avg);

    analiz(y, Ny, t, &sum, &avg);
    printf("Масив y: сума = %.2f, середнє = %.2f\n", sum, avg);

    analiz(z, Nz, t, &sum, &avg);
    printf("Масив z: сума = %.2f, середнє = %.2f\n", sum, avg);

    return 0;
}

void vvod(float x[], int n, char name) 
{
    int i;

    for (i = 0; i < n; i += 1) 
    {
        printf("Введіть %c[%d]: ", name, i);
        scanf("%f", &x[i]);
    }
}

void analiz(float x[], int n, float t, float *sum, float *avg) 
{
    int i, count = 0;
    *sum = 0;

    for (i = 0; i < n; i += 1) 
    {
        if (x[i] < t) 
        {
            *sum += x[i];
            count += 1;
        }
    }

    if (count > 0)
    {
        *avg = *sum / count;
    }

    else
    {
        *avg = 0;
    }
}

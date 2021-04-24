#include <iostream>

void A(double *n, double *u, double *d, double *l, int i);
void B(double *n, double *r, double *b, double *u, double *l, int i);
void Thomas_algorithm(double *u, double *d, double *l, double *b, int matrix_dim);

int main()
{

    double u[] = {1.0 / 2.0, 1.0 / 4.0, 1.0 / 6.0, 1.0 / 8.0, 1.0 / 10.0};
    double d[] = {10.0, 20.0, 30.0, 30.0, 20.0, 10.0};
    double l[] = {1.0 / 3.0, 1.0 / 5.0, 1.0 / 7.0, 1.0 / 9.0, 1.0 / 11.0};

    double b[] = {
        31,
        165.0 / 4.0,
        917.0 / 30.0,
        851.0 / 28.0,
        3637.0 / 90.0,
        332.0 / 11.0};

    Thomas_algorithm(u, d, l, b, 6);
}

void Thomas_algorithm(double *u, double *d, double *l, double *b, int matrix_dim)
{
    int N = matrix_dim;

    double n[N];
    double r[N];
    double x[N];

    n[0] = d[0];
    r[0] = b[0];

    for (int i = 1; i < N; i++)
    {
        A(n, u, d, l, i);
        B(n, r, b, u, l, i);
    }


    // Result: 
    x[N - 1] = r[N - 1] / n[N - 1];
    for (int i = N - 1; i >= 0; i--)
        x[i] = (r[i] - u[i] * x[i + 1]) / n[i];


    // Print result
    for(int i=0 ; i < N; i++)
        std::cout<<x[i]<<" ";
}

void A(double *n, double *u, double *d, double *l, int i)
{
    n[i] = d[i] - (l[i - 1] * u[i - 1]) / n[i - 1];
}
void B(double *n, double *r, double *b, double *u, double *l, int i)
{
    r[i] = b[i] - (l[i - 1] * r[i - 1]) / n[i - 1];
}

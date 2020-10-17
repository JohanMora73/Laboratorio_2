#include <iostream>

using namespace std;
void fun_c(double *a, int n, double *promedio, double *suma);

int main()
{
    double array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    double promedio = 0, suma = 0;
    fun_c(array, 10, &promedio, &suma);
    cout << "El promedio es: " << promedio << " y la suma: " << suma << endl;

    return 0;
}

void fun_c(double *a, int n, double *promedio, double *suma){
    int i;
    *suma = 0.0;
    for (i = 0; i < n; i++){
      *suma += *(a + i);
    }
    *promedio = *suma / n;
}

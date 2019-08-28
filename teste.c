#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

/*Calcular média*/

/*Linear*/
int power2(int n){
    if (n == 0)
        return 1;
    return 2 * power2(n - 1);
}

/*Logarítimico*/
int power2b(int n){
    int r;
    if (n < 2)
        return (n + 1);
    if (n % 2 == 0){
        r = power2b(n / 2);
        return r * r;
    }
    r = power2b(n - 1) / 2;
    return 2 * r * r;
}

int main(void) {
    struct timeval antes, depois;
    double t_antes, t_depois;

    int a = 0;
    double media = 0.0;
    double result = 0.0;

    while (a < 5){
        gettimeofday(&antes, NULL);
        power2b(1000);
        gettimeofday(&depois, NULL);
        t_antes = antes.tv_sec + antes.tv_usec / 1000000.0;
        t_depois = depois.tv_sec + depois.tv_usec / 1000000.0;

        printf("%.20lf\n",  t_depois - t_antes);
        media = media + (t_depois - t_antes);
        a++;
        }  
    result = media / 5.0;
    printf("\nMedia: %.20lf ", result);
    return 0;
}

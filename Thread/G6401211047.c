#include <stdio.h>
#include <pthread.h>
#define N 16

int sum = 0;
int temp = 0;
void *allsum(void *arg)
{
    for (int i = 0; i < 4; i++)
    {
        sum += ((int *)arg)[temp++];
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t[N];
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};

    for (int i = 0; i < 4; i++)
        pthread_create(&t[i], NULL, allsum, &A);
    for (int i = 0; i < 4; i++)
        pthread_join(t[i], NULL);

    printf("%d\n", sum); /* 954      */
    return 0;
}
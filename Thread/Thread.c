#include <stdio.h>
#include <pthread.h>
#define N 16

int sum = 0;
void *array_first_sum(void *arg)
{
    int arrsum = 0;
    int *getArr = (int *)arg;
    for (int i = 0; i < N; i++)
    {
        arrsum += getArr[i];
    }
    sum += arrsum;
    pthread_exit(NULL);
}

int main()
{
    pthread_t t;
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};
    pthread_create(&t, NULL, array_first_sum, A);
    pthread_join(t, NULL);

    printf("%d\n", sum); /* 954      */
    return 0;
}
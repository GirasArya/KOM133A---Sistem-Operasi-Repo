#include <stdio.h>
#include <pthread.h>
#define N 16

int sum = 0;
int sec_sum = 0;
void *array_first_sum(void *arg)
{
    int arrsum = 0;
    int *getArr = (int *)arg;
    for (int i = 0; i < N / 2; i++)
    {
        arrsum += getArr[i];
    }
    sum += arrsum;
    pthread_exit(NULL);
}

void *array_second_sum(void *arg)
{
    int arrsum = 0;
    int *getArr = (int *)arg;
    for (int i = N / 2; i < N; i++)
    {
        arrsum += getArr[i];
    }
    sec_sum += arrsum;
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};
    pthread_create(&t1, NULL, array_first_sum, A);
    pthread_create(&t2, NULL, array_second_sum, A);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("%d\n", sum + sec_sum); /* 954      */
    return 0;
}
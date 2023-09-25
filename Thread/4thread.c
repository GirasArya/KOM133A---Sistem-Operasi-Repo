#include <stdio.h>
#include <pthread.h>
#define N 16

int sum = 0;
int sec_sum = 0;
int third_sum = 0;
int fourth_sum = 0;
void *allsum(void *arg, int i)
{
    if (i == 0)
    {
        void *array_first_sum(void *arg)
        {
            int arrsum = 0;
            int *getArr = (int *)arg;
            for (int i = 0; i < N / 4; i++)
            {
                arrsum += getArr[i];
            }
            sum += arrsum;
            pthread_exit(NULL);
        }
    }
    else if (i == 1)
    {
        void *array_second_sum(void *arg)
        {
            int arrsum = 0;
            int *getArr = (int *)arg;
            for (int i = N / 4; i < N / 2; i++)
            {
                arrsum += getArr[i];
            }
            sec_sum += arrsum;
            pthread_exit(NULL);
        }
    }
    else if (i == 2)
    {
        void *array_third_sum(void *arg)
        {
            int arrsum = 0;
            int *getArr = (int *)arg;
            for (int i = N / 2; i < N * 3 / 4; i++)
            {
                arrsum += getArr[i];
            }
            sec_sum += arrsum;
            pthread_exit(NULL);
        }
    }
    else if (i == 4)
    {
        void *array_fourth_sum(void *arg)
        {
            int arrsum = 0;
            int *getArr = (int *)arg;
            for (int i = N * 3 / 4; i < N; i++)
            {
                arrsum += getArr[i];
            }
            sec_sum += arrsum;
            pthread_exit(NULL);
        }
    }
}

int main()
{
    pthread_t t[N];
    int A[N] = {68, 34, 64, 95, 35, 78, 65, 93,
                51, 67, 7, 77, 4, 73, 52, 91};

    for (int i = 0; i < N; i++)
        pthread_create(&t[i], NULL, allsum(NULL, i), &A[i]);
    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    printf("%d\n", sum); /* 954      */
    return 0;
}
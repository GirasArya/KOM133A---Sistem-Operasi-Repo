#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void ding(int sig)
{
    pid_t child = fork();
    if (child == 0)
    {
        while (1)
        {
            puts("giras");
            sleep(1);
        }
    }
    else
    {
        sleep(2);
        kill(child, SIGTERM);
    }
}

int main()
{
    pid_t child = fork();
    if (child == 0)
    {
        while (1)
        {
            puts("giras");
            sleep(1);
        }
    }
    else
    {
        sleep(5);
        kill(child, SIGTERM);
        signal(SIGALRM, ding);
        alarm(3);
        // puts("waiting...");
        pause();
    }
    return 0;
}
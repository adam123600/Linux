#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define LICZBAPOTOMKOW 20

int main(int argc, char** argv)
{

    int opt = -1;
    opterr = 0;
    float nSize;
    int nFlag = -1;

    siginfo_t infop;

    while((opt = getopt(argc, argv, "N:")) != -1)
    {
        switch(opt)
        {
            case 'N':
                nSize = strtof(optarg, NULL);
                nFlag = 1;
                break;
            default:
                printf("Nieodpowiedni argument: %c\n", optopt);
                continue;
        }
    }

    if (nFlag == -1 )
    {
        printf("Aby wlaczyc:\n./a.out -N <float>\n");
        exit(EXIT_FAILURE);
    }

    printf("Nsize wynosi: %.2f\n", nSize);

    int i = 0;

    char buffer[20];
    sprintf(buffer, "%f", nSize);

    while( i < LICZBAPOTOMKOW )
    {

        if( fork() == 0 )
        {
            printf("Potomek numer: %d\n", getpid());
            //infop.si_pid = getpid();
            execl("./potomek.out", "potomek.out", buffer, (char*)NULL);
        }
        i++;
    }

    int s;

    while(1)
    {

        s = waitid(P_ALL, 0, &infop,  WEXITED);
        printf("Zakonczony: %d\n", infop.si_pid);

       // sleep(1);

        if( s == -1 )
            break;
    }


    return 0;
}
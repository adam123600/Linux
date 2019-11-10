#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL) + getpid()); // dodanie getpid zeby nie bylo tych samych statusow
    int statusLosowy = rand() % 33;

    float czasSpania = strtof(argv[1], NULL) / 9;
    //float czasSpania = strtof(argv[1], NULL);
    char buffer[20];

    sprintf(buffer, "%f", czasSpania);

    printf("Spie- POTOMEK\n");
    sleep(czasSpania);

    if ( statusLosowy == 32 )
    {
        printf("Wylosowano status 32!\n");
        abort();
    }


    else
    {
        printf("Zwrocony status: %d\n", statusLosowy);
        //exit(statusLosowy);
        //exit(EXIT_SUCCESS);
        return statusLosowy;
    }

}
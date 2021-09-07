#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define MSGSIZE 16
char* msg1 = "hello";
int main(){
int pid;
int p[2];
pipe(thePipe);
pid = fork();

if(pid > 0)
{
char inbuf[MSGSIZE];
char p[2];
write(p[1], msg1, MSGSIZE);
printf("Parent say: %s",msg1);
}

else if (pid == 0)
{
    read(p[0], inbuf, MSGSIZE);
printf("Child Process ID: %d",pid);
}
}
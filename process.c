#include <stdio.h>
#include <unistd.h>
int main()
{
int pid;
pid=fork();
printf("BIM 4th semester\n");
printf("Name: Sudhan Kandel");
printf("Roll No: 1");
if(pid==0)
printf("Child process and pid =%d\n",getpid());
else
printf("Parent process and pid =%d\n",getpid());
}
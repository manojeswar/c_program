#include<stdio.h>
#include<unistd.h>

int main()
{
int pid, ppid;

printf("Value of pid:%d  ppid:%d\n", getpid(), getppid());

while(1);

return 0;
}

#include<stdio.h>
#include<unistd.h>

int main()
{
int pip[2];

if (pipe(pip) == -1)
{
  printf("Pipe Creation Error\n");
}

printf("Value of pip[0] reading pipe : %d\n",pip[0]);
printf("Value of pip[1] reading pipe : %d\n",pip[1]);

while(1);
return 0;
}

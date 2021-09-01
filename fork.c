#include<stdio.h>
#include<unistd.h>

int main()
{

int fd = 0;

fd = fork();

if (fd < 0)
	printf("Error forking\n");
else 
	printf("forked successfully :%d\n",fd);

while(1);

return 0;

}

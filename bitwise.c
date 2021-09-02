#include<stdio.h>

void is_bit_set(int *data, int pos)
{
	if ( *data & (1<<pos) )
		printf("Value set as position: %d\n", pos);

	return;
}

void set_bit(int *data, int pos)
{
	*data = *data | (1<<pos) ;
	return;
}

void unset_bit(int *data, int pos)
{
	*data = *data & ~(1<<pos) ;
	return;
}

void toggle_bit(int *data, int pos)
{
	*data = *data ^ (1<<pos) ;
	return;
}

int main()
{
	int data = 5;
	is_bit_set(&data,0);
	is_bit_set(&data,1);
	is_bit_set(&data,2);
	printf("Value of data : %d\n",data);

	set_bit(&data,3);
	printf("Value of data : %d\n",data);

	unset_bit(&data,3);
	printf("Value of data : %d\n",data);

	toggle_bit(&data,3);
	printf("Value of data : %d\n",data);

	return 0;
}

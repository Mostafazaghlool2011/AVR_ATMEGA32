/*
		Author			: 	Mostafa Zaghlool
		Date			:	21/10/2023
		Description		:	Task (5)
*/


#include <stdio.h>

int linear_search(int array[], int size, int val);


int main(void)
{
	int arr[12] = {4,5,2,7,15,11,2,8,6,13,8,6};
	int result = linear_search(arr, 12, 7);
	if(result != -1)
	{
		printf("The 7 value is found in index of %d.",result);
	}
	else
	{
		printf("The 7 value is not found.");
	}
}


int linear_search(int array[], int size, int val)
{
	int ReturnValue;
	for(int i = 0; i < size; i++)
	{
		if(array[i] == val)
		{
			ReturnValue = i;
			break;
		}
		else
		{
			if(i == (size - 1))
			{
				ReturnValue = -1;
			}
		}
	}
	return ReturnValue;
}
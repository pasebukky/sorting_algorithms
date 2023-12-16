/**
* swap - a function to swap two elements in an array
*
* @a: the first element
* @b: the second element
*/


void swap(int *a, int *b) 
{
	int temp;
    
	temp = *a;
	*a = *b;
	*b = temp;
}

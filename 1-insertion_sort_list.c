#include "sort.h"
/**
* insertion_sort_list - a function that sorts a doubly linked list
* of integers in ascending order using the Insertion sort algorithm
*
* @list: a pointer to a pointer that holds the address of a linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp, *j;

	/* Error handling: make sure list is not NULL */
	if (list == NULL || *list == NULL)
		return;
	/* let head point to the head of the linked list */
	head = *list;

	/* temp should point to the first element in the unsorted sublist */
	temp = head->next;
	/* loop through the unsorted sublist */
	while (temp != NULL)
	{
		/* j points to the element behind temp and compares them */
		j = temp->prev;
		/* insert current element into it's position in the sorted sublist */
		while (j != NULL && j->n > temp->n)
		{
			/* swap temp with j */
			j->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = j;

			temp->prev = j->prev;
			temp->next = j;

			if (j->prev != NULL)
				j->prev->next = temp;
			else
				head = temp;

			j->prev = temp;
			j = temp->prev;
			*list = head;
			print_list(*list);
		}
		/* move to the next element in the unsorted sublist */
		temp = temp->next;
	}
}

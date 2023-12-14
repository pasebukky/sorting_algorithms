#include "sort.h"
/**
* main - entry point
* @n: number..
*
* Description: a function that prints the alphabet
* Return: 0 (success)
*/

void insertion_sort_list(listint_t **list) {
    listint_t *head, *temp, *j;

    if (list == NULL || *list == NULL) {
        return;
    }

    head = *list;
    temp = head->next;

    while (temp != NULL) {
        j = temp->prev;

        while (j != NULL && j->n > temp->n) {
            j->next = temp->next;

            if (temp->next != NULL) {
                temp->next->prev = j;
            }

            temp->prev = j->prev;
            temp->next = j;

            if (j->prev != NULL) {
                j->prev->next = temp;
            } else {
                head = temp;
            }

            j->prev = temp;

            j = temp->prev;
        }

        temp = temp->next;
    }

    *list = head;
}

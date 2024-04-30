#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int compare(int a, int b)
{
	return (a <= b);
}

int main(void)
{
	// Create a linked list
	t_list *head = malloc(sizeof(t_list));
	head->data = 3;
	head->next = malloc(sizeof(t_list));
	head->next->data = 1;
	head->next->next = malloc(sizeof(t_list));
	head->next->next->data = 2;
	head->next->next->next = NULL;

	// Print the original list
	printf("Original list: ");
	for (t_list *current = head; current != NULL; current = current->next)
        	printf("%d ", current->data);
	printf("\n");

	// Sort the list using the sort_list function
	head = sort_list(head, compare);
	printf("Sorted list: ");
	for (t_list *current = head; current != NULL; current = current->next)
        	printf("%d ", current->data);
	printf("\n");

	// Free allocated memory
	while (head != NULL)
	{
		t_list *temp = head;
		head = head->next;
		free(temp);
	}
	return 0;
	}

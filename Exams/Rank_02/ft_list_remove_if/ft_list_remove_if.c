#include <stdlib.h>
#include <stdio.h>


typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

/*void print_list(t_list *list) {
    while (list) {
        printf("%d -> ", *(int *)list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int cmp(void *a, void *b) {
    int *int_a = (int *)a;
    int *int_b = (int *)b;
    return (*int_a - *int_b);
}*/

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;

	if (begin_list == NULL || *begin_list == NULL)
		return;

	cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		//cur = *begin_list;
		ft_list_remove_if(&cur->next, data_ref, cmp);
	}
}

/*int main() 
{ 
    t_list *head = malloc(sizeof(t_list));
    t_list *second = malloc(sizeof(t_list));
    t_list *third = malloc(sizeof(t_list));
    
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data1 = 1;
    *data2 = 2;
    *data3 = 3;

    head->data = data1;
    head->next = second;

    second->data = data2;
    second->next = third;

    third->data = data3;
    third->next = NULL;

    printf("Original list: ");
    print_list(head);

    int data_to_remove = 2;
    ft_list_remove_if(&head, &data_to_remove, cmp);

    printf("Modified list: ");
    print_list(head);

    // Free the remaining list
    while (head) {
        t_list *temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}*/

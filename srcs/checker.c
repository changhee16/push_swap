#include "../includes/push_swap.h"
#include <stdio.h>

void	check_stack(t_info	*info)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = info->top_a;
	tmp_b = info->top_b;

	printf("check a\n");
	if (tmp_a)
{
	while(tmp_a)
	{
		printf("%d\n", tmp_a->data);
		tmp_a = tmp_a->next;
	}
}
	printf("check b\n");
	if (tmp_b)
	{
	while(tmp_b)
	{
		printf("%d\n", tmp_b->data);
		tmp_b = tmp_b->next;
	}
	printf("top_b: %d bot_b: %d\n", info->top_b->data, info->bot_b->data);
	}
}

void    check_sort_arr(t_info   *info)
{
    int i;

    i = 0;
    printf("start\n"); 
    while (i < info->arr_num)
    {
        printf("%d\n", info->arr[i]);
        i++;
    }
    printf("end\n");
}

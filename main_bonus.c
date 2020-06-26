/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 16:16:46 by vvaucoul          #+#    #+#             */
/*   Updated: 2020/06/25 15:28:10 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libasm.h"
#include "libasm_bonus.h"

/*
**	Colors
*/

#define RESET "\x1b[0m"
#define BRIGHT "\x1b[1m"
#define DIM "\x1b[2m"
#define UNDERSCORE "\x1b[4m"
#define BLINK "\x1b[5m"
#define REVERSE "\x1b[7m"
#define HIDDEN "\x1b[8m"

#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

#define BOLD_BLACK "\x1b[40m"
#define BOLD_RED "\x1b[41m"
#define BOLD_GREEN "\x1b[42m"
#define BOLD_YELLOW "\x1b[43m"
#define BOLD_BLUE "\x1b[44m"
#define BOLD_MAGENTA "\x1b[45m"
#define BOLD_CYAN "\x1b[46m"
#define BOLD_WHITE "\x1b[47m"

void 	printf_list(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		printf("list->data [%d] : %s\n", i, lst->data);
		lst = lst->next;
		++i;
	}
}

void	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
		free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

void 	test_ft_lists()
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("42born2code");
	list.next = &list_next;
	list_next.data = strdup("test");
	list_next.next = &list_last;
	list_last.data = strdup("0123456789");
	list_last.next = NULL;
	printf(BRIGHT GREEN "\n\t--ft_list_size\n" RESET);
	printf("list content:\n");
	printf_list(&list);
	printf("%d (from first %d)\n", ft_list_size(&list), 3);
	printf("%d (from second %d)\n", ft_list_size(&list_next), 2);
	printf("%d (NULL %d)\n", ft_list_size(NULL), 0);
	printf("%d (from last %d)\n", ft_list_size(&list_last), 1);
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);

	printf(BRIGHT GREEN "\n\t--ft_list_push_front\n" RESET);
	t_list	*push_test = &list;
	ft_list_push_front(&push_test, strdup("42born2code"));
	printf("added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("0123456789"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("42born2code"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf(BRIGHT GREEN "\n\t--ft_list_remove_if\n" RESET);
	ft_list_push_front(&push_test, strdup("42born2code"));
	ft_list_push_front(&push_test, strdup("test01"));
	ft_list_push_front(&push_test, strdup("test02"));
	ft_list_push_front(&push_test, NULL);
	printf("before:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	printf("nothing removed:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "42born2code", &strcmp, &free);
	ft_list_remove_if(&push_test, "test01", &strcmp, &free);
	ft_list_remove_if(&push_test, "test02", &strcmp, &free);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	ft_list_remove_if(&push_test, NULL, &strcmp, &free);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf(BRIGHT GREEN "\n\t--ft_list_sort\n" RESET);
	ft_list_push_front(&push_test, strdup("test02"));
	ft_list_push_front(&push_test, strdup("42born2code"));
	ft_list_push_front(&push_test, strdup("0123456789"));
	ft_list_push_front(&push_test, strdup("test01"));
	ft_list_push_front(&push_test, strdup("test03"));
	ft_list_push_front(&push_test, strdup("test04"));
	ft_list_push_front(&push_test, strdup("test05"));
	ft_list_push_front(&push_test, strdup("test06"));
	ft_list_push_front(&push_test, strdup("test07"));
	ft_list_push_front(&push_test, strdup("test08"));
	ft_list_push_front(&push_test, strdup("test09"));
	printf("before:\n");
	printf_list(push_test);
	ft_list_sort(&push_test, &strcmp);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("sort NULL:\n");
	ft_list_sort(NULL, &strcmp);
	ft_list_sort(&push_test, &strcmp);
	printf("-done\n");
}

void test_atoi_base_result(int r1, int r2)
{
	if (r1 != r2)
	{
		printf(BRIGHT RED "\t\tERROR\n\n");
		exit (EXIT_SUCCESS);
	}
	return ;
}

int		main(int argc, char **argv)
{
	test_ft_lists();
	return (0);
}

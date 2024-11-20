/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:29:38 by kotkobay          #+#    #+#             */
/*   Updated: 2024/11/20 11:16:36 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *s);
void		sort_three_elements(t_stacks *s);
void		sort_four_or_five_elements(t_stacks *s);
void		radix_sort(t_stacks *s);
void		parse_numbers(t_stacks *s);
void		create_indices(t_stacks *s);
void		initialize_stacks(int argc, char **argv, t_stacks *s);
void		free_with_message(t_stacks *s, char *msg);
void		check_duplicates(t_stacks *s, int i);
int			is_array_sorted(t_stacks *s);
int			ft_atol(const char *n, t_stacks *s);
t_stacks	*initialize_stack_and_arguments(int argc, char **argv);
void		merge_arguments(int argc, char **argv, t_stacks *s);
void		validate_all_arguments(int argc, char **argv);
int			is_invalid_sign(char current, char next);

#endif
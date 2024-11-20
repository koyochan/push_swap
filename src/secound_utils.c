/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secound_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:58:14 by kotkobay          #+#    #+#             */
/*   Updated: 2024/11/20 11:11:04 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_and_exit(char *str)
{
	write(1, "Error\n", 6);
	free(str);
	exit(1);
}

t_stacks	*initialize_stack_and_arguments(int argc, char **argv)
{
	t_stacks	*s;

	validate_all_arguments(argc, argv);
	s = malloc(sizeof(*s));
	if (!s)
		exit(1);
	initialize_stacks(argc, argv, s);
	merge_arguments(argc, argv, s);
	return (s);
}

int	is_invalid_sign(char current, char next)
{
	if ((current == '-' || current == '+') && (next == '\0' || next == ' '))
		return (1);
	return (0);
}

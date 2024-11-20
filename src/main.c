/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kotkobay <kotkobay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 20:28:21 by kotkobay          #+#    #+#             */
/*   Updated: 2024/11/20 11:05:38 by kotkobay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	validate_single_argument(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_isdigit(arg[i])) && (arg[i] != ' ') && (arg[i] != '-'
				&& arg[i] != '+'))
			free_with_message(NULL, "Error\n");
		if (is_invalid_sign(arg[i], arg[i + 1]))
			free_with_message(NULL, "Error\n");
		i++;
	}
}

static void	validate_multiple_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			free_with_message(NULL, "Error\n");
		while (argv[i][j])
		{
			if ((!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
					&& argv[i][j] != '-' && argv[i][j] != '+')
				|| ((argv[i][j] == '-' || argv[i][j] == '+') && !argv[i][j
					+ 1]))
				free_with_message(NULL, "Error\n");
			j++;
		}
	}
}

void	validate_all_arguments(int argc, char **argv)
{
	if (argc == 2)
		validate_single_argument(argv[1]);
	else
		validate_multiple_arguments(argc, argv);
}

void	merge_arguments(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->join_args = ft_strdup(tmp);
	if (s->join_args == NULL)
		free_with_message(s, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;

	if (argc == 1)
	{
		exit(1);
	}
	else
		s = initialize_stack_and_arguments(argc, argv);
	parse_numbers(s);
	check_duplicates(s, 0);
	create_indices(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_or_five_elements(s);
	else
		radix_sort(s);
	check_duplicates(s, 1);
	free_with_message(s, "Error\n");
	return (0);
}

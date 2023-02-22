//
// Created by vfries on 2/21/23.
//

#include <stdio.h>
#include <sys/errno.h>
#include <limits.h>
#include "libft.h"

static int	check_argument_count(int argc);
static int	fill_args(int argc, char **argv, int *args);

int	main(int argc, char **argv)
{
	int	args[5];

	if (check_argument_count(argc) < 0 || fill_args(argc, argv, args) < 0)
		return (0);
	for (int i = 0; i < 5; i++)
		printf("%d   ", args[i]);
}

static int	check_argument_count(int argc)
{
	if (argc < 5 || argc > 6)
	{
		printf("Bad number of arguments:\n");
		printf("\t./philo number_of_philosophers time_to_die ");
		printf("time_to_eat time_to_sleep ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
		return (-1);
	}
	return (0);
}

static int	fill_args(int argc, char **argv, int *args)
{
	int			i;
	long long	tmp;

	errno = 0;
	i = 0;
	while (++i < argc)
	{
		tmp = ft_atoll(argv[i]);
		if (tmp > INT_MAX || tmp < 0)
		{
			printf("Inputted arguments can't be above INT_MAX or below 0\n");
			return (-1);
		}
		args[i - 1] = (int)tmp;
	}
	if (errno == EINVAL)
	{
		printf("Inputted arguments need to be numbers\n");
		return (-1);
	}
	if (argc == 5)
		args[4] = -1;
	return (0);
}

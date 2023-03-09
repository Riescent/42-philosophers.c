#include <sys/errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include "not_libft.h"

#include "philo_time.h"
#include "print_state_change.h"

static int	check_argument_count(int argc);
static int	fill_args(int argc, char **argv, int *args);

int	main(int argc, char **argv)
{
	int	args[5];
	struct timeval	start_time;

	if (check_argument_count(argc) < 0 || fill_args(argc, argv, args) < 0)
		return (0);
	gettimeofday(&start_time, NULL);
	print_state_change(FORK, get_timestamp(start_time), 0);
	usleep(1000);
	print_state_change(EAT, get_timestamp(start_time), 0);
	usleep(4000);
	print_state_change(SLEEP, get_timestamp(start_time), 0);
	usleep(4000);
	print_state_change(THINK, get_timestamp(start_time), 0);
	usleep(4000);
	print_state_change(DIE, get_timestamp(start_time), 0);
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

#include <pthread.h>
#include "this_is_not_my_libft.h"

#include "philosophers.h"
#include "print_state_change.h"
#include "arguments.h"

int	main(int argc, char **argv)
{
	int				args[5];
	int 			return_value;
	t_philosopher 	*philosophers;
	pthread_mutex_t	print_mutex;

	if (pthread_mutex_init(&print_mutex, NULL) != 0)
		return (ft_putstr_fd("Failed to init print mutex\n", STDERR_FILENO), 1);
	if (check_argument_count(argc) < 0 || fill_args(argc, argv, args) < 0)
		return (2);
	philosophers = init_philosophers(args, &print_mutex);
	if (philosophers == NULL)
	{
		ft_putstr_fd("init_philosophers() failed\n", STDERR_FILENO);
		return (3);
	}
	return_value = run_philosopher(philosophers);
	destroy_philosophers(philosophers);
	return (return_value);
}

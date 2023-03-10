#include <stdlib.h>
#include <pthread.h>

#include "this_is_not_my_libft.h"
#include "philosophers.h"

static int				add_philosopher(t_dlist **philosophers,
							const int args[5], const int id);
static t_philosopher	*init_philosopher(const int args[5], const int id);
static void				init_left_forks(t_dlist *philosophers);

t_dlist	*init_philosophers(const int args[5])
{
	t_dlist	*philosophers;
	ssize_t	i;

	philosophers = NULL;
	i = args[0] + 1;
	while (--i >= 1)
	{
		if (add_philosopher(&philosophers, args, i) < 0)
		{
			ft_dlstclear(&philosophers, &free);
			return (NULL);
		}
	}
	ft_dlst_reverse(&philosophers);
	init_left_forks(philosophers);
	return (philosophers);
}

static int	add_philosopher(t_dlist **philosophers, const int args[5],
				const int id)
{
	t_dlist			*new_node;
	t_philosopher	*philosopher;

	philosopher = init_philosopher(args, id);
	new_node = ft_dlstnew(philosopher);
	if (philosopher == NULL || new_node == NULL)
	{
		free(philosopher);
		free(new_node);
		return (-1);
	}
	ft_dlstadd_front(philosophers, new_node);
	return (0);
}

static t_philosopher	*init_philosopher(const int args[5], const int id)
{
	t_philosopher	*philosopher;

	philosopher = malloc(sizeof(*philosopher));
	if (philosopher == NULL)
		return (NULL);
	if (pthread_mutex_init(&philosopher->thread_should_stop_mutex, NULL) != 0
		|| pthread_mutex_init(&philosopher->right_fork_mutex, NULL) != 0)
	{
		destroy_philosopher(philosopher);
		return (NULL);
	}
	philosopher->thread_should_stop = false;
	philosopher->id = id;
	philosopher->time_to_die = args[1];
	philosopher->time_to_eat = args[2];
	philosopher->time_to_sleep = args[3];
	philosopher->number_of_times_to_eat = args[4];
	philosopher->times_eaten = 0;
	return (philosopher);
}

static void	init_left_forks(t_dlist *philosophers)
{
	t_philosopher	*first_philosopher;
	t_philosopher	*philosopher;
	t_philosopher	*next_philosopher;

	first_philosopher = philosophers->content;
	while (philosophers->next != NULL)
	{
		philosopher = philosophers->content;
		next_philosopher = philosophers->next->content;
		next_philosopher->left_fork_mutex = &philosopher->right_fork_mutex;
		philosophers = philosophers->next;
	}
	philosopher = philosophers->content;
	first_philosopher->left_fork_mutex = &philosopher->right_fork_mutex;
}

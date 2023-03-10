#include <pthread.h>

#include "philosophers.h"
#include "print_state_change.h"
#include "philo_time.h"

static void	set_all_threads_should_stop_to_true(t_dlist *philosophers);
static void	set_thread_should_stop_to_true(t_dlist *philosopher_node);

int	philosopher_dies(t_philosopher *philosopher,
		t_dlist *philosopher_node, const struct timeval time_to_die)
{
	set_all_threads_should_stop_to_true(philosopher_node);
	print_state_change(DIE, get_timestamp(philosopher->start_time, time_to_die),
					   philosopher->id);
	return (-1);
}

static void	set_all_threads_should_stop_to_true(t_dlist *philosophers)
{
	t_dlist	*cursor;

	cursor = philosophers;
	while (cursor != NULL)
	{
		set_thread_should_stop_to_true(cursor);
		cursor = cursor->next;
	}
	cursor = philosophers->previous;
	while (cursor != NULL)
	{
		set_thread_should_stop_to_true(cursor);
		cursor = cursor->previous;
	}
}
static void	set_thread_should_stop_to_true(t_dlist *philosopher_node)
{
	t_philosopher	*philosopher;

	philosopher = philosopher_node->content;
	pthread_mutex_lock(&philosopher->thread_should_stop_mutex);
	philosopher->thread_should_stop = true;
	pthread_mutex_unlock(&philosopher->thread_should_stop_mutex);
}

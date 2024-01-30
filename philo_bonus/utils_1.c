#include "philo.h"

int     ft_take_forks(t_philo *philo)
{
    sem_wait(philo->arg->forks);
    print_status(philo, 'f');
    sem_wait(philo->arg->forks);
    print_status(philo, 'f');
    
    return (0);
}

int     ft_eat(t_philo *philo)
{

    print_status(philo, 'e');
    philo->last_eat = get_time();
    ft_usleep(philo->arg->time_to_eat);
    sem_post(philo->arg->forks);
    sem_post(philo->arg->forks);

    return (0);
}

int     ft_sleep(t_philo *philo)
{
    print_status(philo, 's');
    ft_usleep(philo->arg->time_to_sleep);
    print_status(philo, 't');
    return (0);
}

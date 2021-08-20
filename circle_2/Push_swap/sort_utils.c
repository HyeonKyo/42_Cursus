#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

int		small_num(int n1, int n2)
{
	if (n1 <= n2)
		return (n1);
	return (n2);
}

int		find_max(int len, int *arr)
{
	int	i;
	int	max;

	max = arr[0];
	i = 0;
	while (++i < len)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

int		find_min(int len, int *arr)
{
	int	i;
	int	min;

	min = arr[0];
	i = 0;
	while (++i < len)
		if (arr[i] > min)
			min = arr[i];
	return (min);
}
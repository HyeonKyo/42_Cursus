#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	before_bios(t_sort *repo, t_ll bios)
{
	int	i;

	i = 0;
	while (i < repo->size)
		repo->arr[i++] -= bios;
}

void	radix_sort(t_deque *deq, t_sort *repo, t_ll bios, int max)
{
	int	i;
	int	digit;

	digit = find_digit_len(bios + max);
	putin_data_in_array(deq, repo, bios);
	i = 1;
	while (i <= digit)
		pre_sorting(repo, i++);
	before_bios(repo, bios);
}

void	choose_pivot1(t_pivot *piv, t_sort *repo)
{
	int	a;
	int	b;
	int	c;
	int	tmp;

	c = repo->size - 1;
	tmp = c % 3;
	if (tmp == 0)
		a = c / 3;
	else if (tmp == 1)
		a = (c + 2) / 3;
	else
		a = (c + 1) / 3;
	b = (c * 2) / 3;
	if (b - a > c - b + 1 && a + 1 != b)
		a++;
	else if (b - a < c - b + 1 && b - 1 != a)
		b--;
	if (repo->size < 15)
		b = c - 3;
	if (repo->size < 12)
		b = c - 2;
	if (a == b)
		a--;
	piv->sml = repo->arr[a];
	piv->big = repo->arr[b];
}

void	choose_pivot2(t_pivot *piv, t_sort *repo)
{
	int	a;
	int	b;
	int	c;

	c = repo->size - 1;
	a = c / 3;
	b = (c * 2) / 3;
	if (b - a > c - b + 1 && b - 1 != a)
		b--;
	else if (a - 1 < b - a && a + 1 != b)
		a++;
	if (repo->size < 12)
		b = c - 2;
	if (a == b)
		a--;
	piv->sml = repo->arr[a];
	piv->big = repo->arr[b];
}

void	choose_pivot3(t_pivot *piv, t_sort *repo)
{
	int	a;
	int	b;
	int	c;
	int	tmp;

	c = repo->size - 1;
	a = c / 3;
	tmp = (c * 2) % 3;
	if (tmp == 0) 
		b = c * 2 / 3;
	else if (tmp == 1)
		b = (c * 2 + 2) / 3;
	else
		b = (c * 2 + 1) / 3;
	if (b - a + 1 == c - b && b + 1 != c)
		b++;
	if (b - a > a - 1 && a + 1 != b)
		a++;
	piv->sml = repo->arr[a];
	piv->big = repo->arr[b];
	//case3 = a > b >== c (b와 c가 같을 수 없을 땐 b가 하나 더 많게)
	//1 ~ 14까지일 때 sml : 7, big : 11
	//1 ~ 13까지일 때 sml : 6, big : 10
	//1 ~ 12까지일 때 sml : 5, big : 9
	//1 <= a < sml은 pb만 하는 블록이므로 가장 크게
	//sml <= b < big과 big <= c는 ra, rb를 각각 실행하므로
	//마지막에 rrr로 동일한 작업을 하도록 개수를 최대한 맞춰줌.
	//but, 이 방법은 첫번째 퀵소트 시에는 오히려 비효율적
	//
}

void	clear_repo(t_sort *repo)
{
	if (repo && repo->arr)
		free(repo->arr);
	if (repo)
		free(repo);
}

void	pre_sort(t_deque *deq, int len, t_pivot *piv)
{
	int	max;
	int	min;
	t_ll	bios;
	t_sort	*repo;

	search_stack(deq, len, &max, &min);
	repo = make_repository(len);
	bios = 0;
	if (min < 0)
		bios = -1 * min;
	radix_sort(deq, repo, bios, max);
	if (deq->case_num == 1)
		choose_pivot1(piv, repo);
	else if (deq->case_num == 2)
		choose_pivot2(piv, repo);
	else
		choose_pivot3(piv, repo);
	clear_repo(repo);
}
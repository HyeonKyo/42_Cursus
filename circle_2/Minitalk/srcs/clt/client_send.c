#include "minitalk.h"

void	send_len(unsigned int str_len)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	info.num = str_len;
	send_message(info.arr, 4);
}

static void	send_bit(char c, int mask_num)
{
	int	ret;
	int	bit_mask;

	bit_mask = return_mask_number(mask_num);
	ret = 0;
	if (c & bit_mask)
		ret = kill(g_server_pid, SIGUSR2);
	else
		ret = kill(g_server_pid, SIGUSR1);
	if (ret < 0)
		sigerror();
}

static void	send_all_bits(char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		usleep(120);
		send_bit(c, i--);
		pause();
	}
}

void	send_message(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		send_all_bits(str[i]);
}

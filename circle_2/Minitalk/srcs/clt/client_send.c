#include "minitalk.h"

void	send_len(int str_len)
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

static void	send_eight_bits(char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		send_bit(c, i--);
		pause();
		usleep(50);
	}
}

void	send_message(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		send_eight_bits(str[i]);
}

void	send_string(char *str, int len)
{
	send_message(str, len);
	g_flag = 1;
}

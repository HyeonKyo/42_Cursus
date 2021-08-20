#include <sys/time.h>
#include <stdio.h>

int main()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	printf("\033[1;37msec : %ld, mcsec : %d\n", tv.tv_sec, tv.tv_usec);
	printf("\033[1;31msec : %ld, mcsec : %d\n", tv.tv_sec, tv.tv_usec);
	printf("\033[0;32msec : %ld, mcsec : %d\n", tv.tv_sec, tv.tv_usec);
	return (0);
}

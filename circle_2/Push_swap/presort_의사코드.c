/*
가장 큰 pre_sort함수 (덱, 기준값, 피봇 구조체 주소)
{
	변수 : bios, digit, max, min
1. check_stack()(정렬할 길이, max, min값)
인자 : 덱, 기준값, max주소, min주소 / 초기min값은 정수 최대, max는 정수 최소값
리턴 : len
변수 : len, cur
cur을 이용해 덱의 top부터 반복문 돌면서
데이터와 min, max를 비교하며 바꿔주고
len++(len 초기값 = 0)
len리턴

2. 구조체 안의 정수형 배열에 len만큼 할당.
			size에 len을 넣어줌.

3. min값이 음수라면 bios = min x -1

4. radix_sort(덱, 구조체 배열, bios)
{
	digit = max + bios의 자리수
	배열에 덱의 data + bios를 넣어줌.
	i = 1부터
	while i <= digit
		sorting(배열, bios, i(현재 자릿수))
	before_bios();
}

4.1 n번째 자릿수 리턴 함수(long long n, dg)
{
	i = 1
	while (i < dg)
		n / 10;
	return (n % 10)
}

4.2 큐 생성 함수(static t_queue *queue, i)
{
	queue[i] = malloc(t_queue)
	queue[i]->fst = malloc(t_qu_lst)
	queue[i]->last = queue[i]->fst
	queue[i]->size = 0 
	memset(queue->fst)
}

4.3 insert_queue(str[i], queue, dg)
{
	if (queue[dg] == 0)
		큐생성함수()
	else
		cur = malloc(t_qu_list)
		queue[dg]->last->next = cur
		queue[dg]->last = queue[dg]->last->next
	queue[dg]->last->data = str[i];
	queue[dg]->size++;
}

4.4 pull_queue(배열, queue)
{
	i, j
	while (i < 10)
	{
		cur = queue[i]->fst
		while (cur)
			배열[j++] = cur->data;
	}
}

4.5 clear_queue(queue[10])
{
	while i < 10
	{
		cur = queue[i]->head
		while (cur)
		{
			tmp = cur->next
			free(cur)
			cur = tmp
		}
	}
}

5. sorting(배열, bios, i(현재 자릿수))
{
	i선언
	static queue[10] -> 0부터 9에 queue의 주소를 할당
	queue = malloc(10 x t_queue *)
	while 배열의 끝까지
	{
		last = str[i]의 자릿수 리턴값
		insert_queue(str[i], queue, last)
	}
	pull_queue(배열, queue);
	clear_queue();
}

6. before_bios(배열, bios)
{
	while (i < size)
		배열[i] -= bios
}

7. 배열에서 최적 피봇 값 2개 선정 함수
	choose_pivot(pivot구조체 주소)
}
*/
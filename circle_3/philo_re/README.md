# Philosopher

## 프로그램 설명

OS의 DeadLock의 대표적 문제인 식사하는 철학자를 프로그램으로 구현한 것이다.

### 규칙

![https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/220px-An_illustration_of_the_dining_philosophers_problem.png](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/220px-An_illustration_of_the_dining_philosophers_problem.png)

- 각 철학자는 양 손에 포크를 들어야 식사를 할 수 있다.
- 각 철학자는 먹고 자고 생각한다.
- 행동 중간에 다른 행동을 할 수 없다.
    
    ex) 먹는 시간 200ms가 지나기 전에 자거나 생각할 수 없음.
    
- 식사를 마치면 수명이 리셋 된다. 즉, 먹는 도중 수명 시간이 지난다면 죽게 된다.

### 고려 사항

이 과제는 한 철학자가 포크를 집으면 다른 철학자는 해당 포크를 집을 수 없도록 만들어야 한다. 이는 OS에서 공유 자원을 2개의 쓰레드가 점유하지 못하도록 하여 문제를 예방하는 것과 비슷하다. 따라서 포크를 Mutex로 만들고, 포크를 집는 행위를 Mutex Lock을 하도록 하여서 이를 구현하였다.

철학자는 1번부터 숫자로 표현하는데, 처음 철학자 생성 시 홀수 철학자와 짝수 철학자가 먹는 시간의 차이를 주는 것 만으로도 점유 대기 시간을 크게 줄이고 DeadLock도 발생하지 않았다.

하지만, 기본적으로 DeadLock의 해결 방안은 DeadLock의 4가지 필요 조건 중 하나를 깨는 것이다. 따라서 추가적인 DeadLock 방지 조치를 추가하였다. 먼저 코프만 교수의 DeadLock의 4가지 필요 조건은 다음과 같다.

1. 상호배제(Mutual exclusion) : 프로세스들이 필요로 하는 자원에 대해 배타적인 통제권을 요구한다.
2. 점유대기(Hold and wait) : 프로세스가 할당된 자원을 가진 상태에서 다른 자원을 기다린다.
3. 비선점(No preemption) : 프로세스가 어떤 자원의 사용을 끝낼 때까지 그 자원을 뺏을 수 없다.
4. 순환대기(Circular wait) : 각 프로세스는 순환적으로 다음 프로세스가 요구하는 자원을 가지고 있다.

이 중, 순환 대기 조건을 만족하지 못하도록 하는 로직을 추가하여 DeadLock을 확실하게 예방하였다. 그 로직은 한 철학자가 왼쪽 포크를 집었는데, 왼쪽 철학자가 왼쪽 포크를 집은 상태라면 다시 포크를 내려놓는 로직이다.

## 실행 화면

1. 잘못된 인자에 대한 예외 처리 및 정상 실행
<img src=./image/do.gif />

2. 수명이 다 한 철학자의 죽음 처리
<img src=./image/die.gif />
# Minitalk

## 프로그램 설명

2개의 프로세스 간 문자열 통신(Unix Signal을 이용한 IPC)을 수행하는 과제이다. server 프로세스를 실행하면 본인의 PID를 출력한다. client 프로세스의 실행 인자로 server PID와 전송할 문자열을 넣어주면 문자열이 server 프로세스로 전송된다.

Unix의 Signal중 SIGUSR1, SIGUSR2 만을 이용하여 문자열을 전송하는 것이 과제의 조건이었다. 때문에 문자열을 비트 단위로 나누고, 0bit는 SIGUSR1으로, 1bit는 SIGUSR2로 나타내었다. 또한, 문자열이 잘 전송됐다면 server에서 client에 모든 문자열을 잘 받았다는 Signal을 보내준다. 이를 바탕으로 client는 전송 완료 메시지를 출력한다.

그리고 각종 예외 처리도 추가하였다.

- 프로그램 실행 시 Input 인자가 잘못된 경우
- Signal이 유실 된 경우
- 1개의 server로 다른 client가 동시에 문자열을 보내는 경우

각각의 경우에 에러 메시지를 띄우게 된다. 이러한 경우들을 검증하기 위해 2가지 검증 로직을 추가하였다.

1. 모든 비트를 전송할 때 server에서 정상 or 실패 Signal을 client에 응답
2. 처음 문자열을 전송하기 전 문자열의 길이(4bytes)를 먼저 전송

## 실행 방법

1. 프로젝트 clone 
2. makefile이 있는 디렉토리에서 `make` 명령어 수행
3. `./server` 명령어로 server 프로세스 실행 → server의 PID가 출력
4. 또 다른 터미널을 띄우고, `./client [server PID] “[전송할 문자열]”` 명령어로 server에 문자열을 전송한다.

## 실행 화면
<img src=./image/invoke.gif />

## 예외 처리

**여러 Client가 동시에 문자열 전송 시 Signal Error 출력**

<img src=./image/interrupt.gif />

**Input 인자 예외 처리**

<img src=./image/input_error.gif />

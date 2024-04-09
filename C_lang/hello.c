#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ctrlc_handler(int sig) {
  char c;
  printf("\n진짜 끌래? [y/n] ");
  c = getchar();

  if (c == 'y' || c == 'Y') {
    exit(0);
  } else {
    printf("계속...www1111111\n");
  }
}

void sigusr1_handler(int sig) { printf("SINUSR1 signal 수신받음.\n"); }

int main() {
  signal(SIGINT, ctrlc_handler);
  printf("실행중... 끄려면 컨트롤 + C\n");

  while (1) {
    sleep(1);
  }

  return 0;
}
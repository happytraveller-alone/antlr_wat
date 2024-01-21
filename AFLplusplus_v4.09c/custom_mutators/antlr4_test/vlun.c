#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char buffer[50];

  printf("Please enter a string:\n");
  fgets(buffer, 50, stdin);

  // Remove newline character
  buffer[strcspn(buffer, "\n")] = 0;

  // Check string length
  if (strlen(buffer) != 19) {
    printf("The length of the input string is incorrect.\n");
    return 0;
  }

  if (strcmp(buffer, "(13574)visit{fafav}") == 0) {
    printf("Triggering crash...\n");
    raise(SIGSEGV); // Trigger crash
  } else {
    printf("The input string is: %s\n", buffer);
  }

  return 0;
}

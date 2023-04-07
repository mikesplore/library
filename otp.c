#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rando() {
    srand(time(NULL));
    return rand() % 9000 + 1000;
}

int main() {
    int otp = rando();
    int guess;
    printf("Your OTP is: %d\n", otp);
    printf("Enter OTP: ");
    scanf("%d", &guess);

    if (guess == otp) {
        printf("OTP is correct\n");
    } else {
        printf("OTP is incorrect\n");
    }
    return 0;
}

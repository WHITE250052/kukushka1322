#include"lr.h"
#include<stdio.h>
#define N 3
int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}
int is_palindrome(char *word, int start, int end) {
        while (start < end) {
            if (word[start] != word[end]) {
                return 0;
            }
            start++;
            end--;
        }
        return 1;
    }
int sum_of_digits(int num) {
    if (num == 0) {
        return 0;
    }
    return num % 10 + sum_of_digits(num / 10);
}
void input_array(int arr[N][N]) {
    printf("vvedite elementi massiva %d x %d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_array(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void rotate_array(int arr[N][N]) {
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = arr[i][j];
            arr[i][j] = arr[N - 1 - j][i];
            arr[N - 1 - j][i] = arr[N - 1 - i][N - 1 - j];
            arr[N - 1 - i][N - 1 - j] = arr[j][N - 1 - i];
            arr[j][N - 1 - i] = temp;
        }
    }
}
int lab1(){
 float P;
 int A,B,C;
 printf("Vvedite znachenie dla A,B,C\n ");
 scanf("%d%d%d",&A,&B,&C);
 P=((float)A*B+C*C)/(B*C+(float)A);
 printf("P= %.3f", P);
 return 0;
}
int lab2() {
 double x, epsilon, sum, term, a, b, factorial;
 int sign, n;
 printf("Vvedite x and epsilon: ");
 scanf("%lf %lf", &x, &epsilon);
 sign = 1;
 sum = 0;
 a = x;
 b = 1;
 factorial = 1;
 for (n = 1; ; n += 2) {
 term = a / b;
 if (term <= epsilon) {
 break;
 }
 sum = sum + term * sign;
 sign *= -1;
 a = a * x * x;
 for (int i = 1; i <= n; i++) {
 factorial = factorial * i;
 }
 b = factorial;
 }
 printf("Symma = %lf\n", sum);
 return 0;
}
int lab3(){
    char text[1000];
    int gl, sogl, words;
    char c;
    printf("Vvedite text: ");
    gl = sogl = words = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                if (isVowel(c)) {
                    gl++;
                } else {
                    sogl++;
                }
            }
        } else {
            if (sogl < gl) {
                words++;
            }
            gl = sogl = 0;
        }
    }
    if (sogl < gl) {
        words++;
    }
    printf("Kolichestvo slov: %d\n", words);
    return 0;
}
int lab4(){
    void remove_palindromes(char *string) {
    int start = 0, end, i = 0;
    while (string[i]) {
        if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t' || string[i] == '\0') {
            end = i - 1;
            if (!is_palindrome(string, start, end)) {
                for (int j = start; j <= end; j++) {
                    printf("%c", string[j]);
                }
                printf(" ");
            }
            start = i + 1;
        }
        i++;
    }
}
    char input_string[100];
    fgets(input_string, sizeof(input_string), stdin);

    printf("Rezyltat: ");
    remove_palindromes(input_string);
    return 0;
}
int lab5(){
    int numbers[10];
    printf("Vvedite 10 chisel:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }
    int max_number = numbers[0];
    int max_sum = sum_of_digits(max_number);

    for (int i = 1; i < 10; i++) {
        int current_sum = sum_of_digits(numbers[i]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
            max_number = numbers[i];
        }
    }

    printf("Chislo s naibolshei symoi cifr: %d\n", max_number);

    return 0;
}
int lab6(){
    int arr[N][N];
    input_array(arr);
    printf("\nIshodniy massiv:\n");
    print_array(arr);

    rotate_array(arr);

    printf("\nPovernyt massiv  90 gradysov po chasovoi strelki:\n");
    print_array(arr);

    return 0;
}
int lab7(){
    long long num, result = 0;
    int count1 = 0, count0 = 0;

    printf("Enter a long number: ");
    scanf("%lld", &num);

    // Count the number of 1s and 0s in the number
    long long temp = num;
    while(temp > 0) {
        int digit = temp % 10;
        if(digit == 1) {
            count1++;
        } else if(digit == 0) {
            count0++;
        }
        temp /= 10;
    }

    // Place all 1s at the beginning of the result
    for(int i = 0; i < count1; i++) {
        result = result * 10 + 1;
    }

    // Add the rest of the digits to the result
    temp = num;
    while(temp > 0) {
        int digit = temp % 10;
        if(digit != 0 && digit != 1) {
            result = result * 10 + digit;
        }
        temp /= 10;
    }

    // Place all 0s at the end of the result
    for(int i = 0; i < count0; i++) {
        result = result * 10;
    }

    printf("Transformed number: %lld\n", result);

    return 0;
}

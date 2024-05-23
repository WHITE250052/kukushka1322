#include"lr.h"
#include<stdio.h>
#include <stdlib.h>
#define N 3
#define K 3
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
int count_digits(int num) {
 if (num == 0) {
 return 0;
 }
 return 1 + count_digits(num / 10);
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
void dectobin(long long number) {
    if(number == 0) {
        printf("0");
        return;
    }
    long result = 0;
    int pos = 31;
    while(number > 0) {
        if(number % 2 == 1) {
            result = result | ((long)1 << pos);
            pos--;
        }
        number /= 2;
    }
    for(int i = 31; i >= 0; i--) {
        printf("%ld", (result >> i) & 1);
    }
}
int is_vowel(char c) {
 return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
 c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
void remove_palindromes(char *string) {
 int start = 0, end, i = 0;
 while (string[i]) {
 if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t' || string[i] == '\0') {
 end = i - 1;
 if (is_palindrome(string, start, end)) {
 for (int j = start; j <= end; j++) {
 if (is_vowel(string[j])) {
 printf("%c", (string[j] >= 'a' && string[j] <= 'z') ? string[j] - 32 :
string[j] + 32);
 } else {
 printf("%c", string[j]);
 }
 }
 } else {
 for (int j = start; j <= end; j++) {
 printf("%c", string[j]);
 }
 }
 printf(" ");
 start = i + 1;
 }
 i++;
 }
}
void Pyzir(int arr[N][K]) {
 int temp;
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 for (int k = 0; k < N; k++) {
 for (int l = 0; l < K; l++) {
 if (arr[k][l] > arr[i][j]) {
 temp = arr[k][l];
 arr[k][l] = arr[i][j];
 arr[i][j] = temp;
 }
 }
 }
 }
 }
}
int lab1(){
 float P,A,B,C;
 printf("Vvedite A,B,C\n");
 scanf("%f%f%f",&A,&B,&C);
 P=(A*B+C*C)/(B*C+A);
 printf("P= %f",P);
 return 0;
}
int lab11(){
 float P;
 int A,B,C;
 printf("Vvedite A,B,C\n ");
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
int lab21() {
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
 printf("symma = %lf\n", sum);
 return 0;
}
int lab3(){
    char text[1000];
    int gl, sogl, words;
    char c;
    printf("Vvedite text: ");
    gl = sogl = words = 0;
    while ((c = getchar()) != '\n') {
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
int lab41() {
 char input_string[100];
 printf("Stroka: ");
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
int lab51() {
 int numbers[10];
 printf("Vvedite 10 chisel:\n");
 for (int i = 0; i < 10; i++) {
 scanf("%d", &numbers[i]);
 }
 int max_number = numbers[0];
 int max_sum = sum_of_digits(max_number);
 int max_num_digits = count_digits(max_number);
 for (int i = 1; i < 10; i++) {
 int current_sum = sum_of_digits(numbers[i]);
 int current_num_digits = count_digits(numbers[i]);
 if (current_sum > max_sum || (current_sum == max_sum &&
current_num_digits > max_num_digits)) {
 max_sum = current_sum;
 max_number = numbers[i];
 max_num_digits = current_num_digits;
 }
 }
 printf("Chislo s max symmoi cifor i naibolshem kol cifor: %d\n", max_number);
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

int lab61() {
 int arr[N][K];

 printf("Vvedite %d elementa dla massiva razmerom %d x %d:\n",
N * K, N, K);

 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 scanf("%d", &arr[i][j]);
 }
 }

 printf("\nIshodniy massiv:\n");
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 printf("%d ", arr[i][j]);
 }
 printf("\n");
 }

 Pyzir(arr);

 printf("\nOtsortirovanni:\n");
 for (int i = 0; i < N; i++) {
 for (int j = 0; j < K; j++) {
 printf("%d ", arr[i][j]);
 }
 printf("\n");
 }
 return 0;
}
int lab7() {
    long number;
    printf("Chislo: ");
    scanf("%ld", &number);

    printf("Dvoichnoe predstavlenie chisla %ld s 1 v nachale: ", number);
    dectobin(number);

    return 0;
}

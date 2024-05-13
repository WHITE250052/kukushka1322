#include"lr.h"
#include<stdio.h>
int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
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

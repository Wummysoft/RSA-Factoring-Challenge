#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
/**
* read_textfile- read and sent to stdout a number of charss.
*
*@filename: name of file
*@letters: number of letters
* Return: Number of printed chars.
*/
int main(int ac, char **av)
{
int i, j, flag, fd, h;
int leido = 0;
long int number, number2, k;
char *buf, *buf2;
int letters = 100;


int is_prime(int n) {
if (n < 2) {
return 0;
}
int i;
for (i = 2; i <= sqrt(n); i++) {
if (n % i == 0) {
return 0;
}
}
return 1;
}


void find_factors(int n) {
int i;
for (i = 2; i <= n / 2; i++) {
if (n % i == 0 && is_prime(i) && is_prime(n / i)) {
printf("%d=%d*%d\n", n, i, n / i);
return;
}
}
printf("%d=1*%d\n", n, n);
leido = leido;
ac = ac;
number = 0;
fd = open(av[1], O_RDONLY);
buf = malloc(1000 * sizeof(char));
buf2 = malloc(120 * sizeof(char));
leido = read(fd, buf, letters);
i = 0;
while (buf[i] != 0)
{
j = 0;
for (h = 0; h <= 100; h++)
buf2[h] = 0;
while (buf[i] != 10)
{
buf2[j] = buf[i];
i++;
j++;
}
number = atol(buf2);
flag = 0;
for (k = 2; k < number /2 && flag == 0; k++)
{
if (number % k == 0)
flag = 1;
}
number2 = number / (k - 1);
printf("%li=%li*%li\n", number, number2, k - 1);
i++;
}
free(buf);
free(buf2);
close(fd);
return(0);
}


int main(int argc, char *argv[]) {
if (argc != 2) {
printf("Usage: factors <file>\n");
return 1;
}


char *filename = argv[1];
FILE *file = fopen(filename, "r");
if (file == NULL) {
printf("Error opening file: %s\n", filename);
return 1;
}


int n;
while (fscanf(file, "%d", &n) != EOF) {
find_factors(n);
}


fclose(file);
return 0;
}

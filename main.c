int SumOfSquares(int n);   // <- add this prototype to fix implicit declaration warning

int main(void) {
    int s = SumOfSquares(5);
    return 0;
}

int SumOfSquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}
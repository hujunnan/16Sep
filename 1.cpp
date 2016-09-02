 #include<stdio.h>
int main() {
    int a[17], c[17];
    long n;
    int b = 0;
    while((scanf("%ld", &n)) != EOF) {
        if (n >= -32768 && n <= 32767){
       
        for(b = 0; b < 16; b++) {
            a[b] = 0;
        }
        if (n >= 0) {
            b = 15;
            while (n > 0) {
                a[b] = n % 2;
                n /= 2;
                b--;
            }
        } else {
            n = -1 * n;
            b = 15;
            while (n > 0) {
                a[b] = n % 2;
                n /= 2;
                b--;
            }
            for (b = 0; b < 16; b++) {
                if(a[b] == 0) a[b] = 1;
                else a[b] = 0;
            }
            c[15] = (a[15] + 1) / 2;
            a[15] = (a[15] + 1) % 2;
            for(b = 14; b >= 0; b--) {
                c[b] = (a[b] + c[b+1]) / 2;
                a[b] = (a[b] + c[b+1]) % 2;
            }
        }
        for(b = 0; b < 16; b++){
            printf("%d", a[b]);
        }
        printf("\n");
        }
    }
}

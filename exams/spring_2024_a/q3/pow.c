#include <stdio.h>

int power(int x, int y);

int main() {
    int x = 3, y = 2;

    printf("result: %d", power(x,y));
}

int power(int x, int y) {

    if (y == 0)
        return 1;

    int XpowYmin1 = power(x, y - 1);
    int XpowY = 0;

    for (int i = 0; i < x; i++)
        XpowY += XpowYmin1;
    return XpowY;
}


// POWER:
//     if (y != 0) goto SKIP_IF
//     return 1;

//     SKIP_IF:
//         int XpowYmin1, XpowY, i;
//         XpowYmin1 = POWER(x, y - 1);
//         XpowY = 0;

//         FOR:
//             i = 0;
//             if (!(i < x)) goto END_FOR
//             XpowY = XpowY + XpowYmin1;
//             i++;
//             goto FOR;
        
//         END_FOR:
//             return XpowY;

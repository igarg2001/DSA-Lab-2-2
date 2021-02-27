#include <stdio.h>

int bits;

void g()
{
    int goa;
    printf("Goa:%u\n", &goa);
}
void p()
{
    int pilani;
    printf("Pilani:%u\n", &pilani);
}
void h()
{
    int hyd;
    printf("Hyderabad:%u\n", &hyd);
}
void d()
{
    int dub;
    printf("Dubai:%u\n", &dub);
}

int main() {
    p();
    g();
    h();
    d();
    printf("bits:%u\n",&bits);
}
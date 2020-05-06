void swap(long *xp, long *yp) {
    long t0 = *xp;
    long t1 = *yp;
    *xp = t1;
    *yp = t0;
}

int main() {
   long x = 123L;
   long y = 456L;
   swap(&x, &y);
}


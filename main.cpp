#include <iostream>
#include <cstdlib>
using namespace std;

int findOrder(uint32_t x, uint32_t module) {
    int r = 1;
    uint64_t tmp = x % module;
    while(tmp != 1) {
        tmp *= x;
        tmp %= module;
        r++;
    }
    return r;
}

int64_t gcd(int64_t a, int64_t b) {
    a = abs(a);
    b = abs(b);
    if(b == 0) {
        return a;
    } else {
        int64_t r = a % b;
        while(r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
} // возвращает НОД (a, b)

uint32_t modPow(uint32_t base, uint32_t exp, uint32_t m) {
    if(exp == 0) {
        return 1;
    }
    uint64_t tmp = modPow(base, exp/2, m);
    if(exp % 2 == 0) {
        return (tmp * tmp) % m;
    } else {
        return ((tmp * tmp) % m ) * base % m;
    }
} // returns (base ^ exp) mod m

unsigned shor(unsigned N) {
    if(N % 2 == 0)
        return 2;
    unsigned x, y, r;
    while (true) {
        x = rand() % N;
        if (gcd(x, N) != 1)
            return x;
        r = findOrder(x, N);
        y = gcd(N, modPow(x, r / 2, N) + 1);
        if (N % y == 0 && y != 1 && y != N)
            return y;
    }
}

int main() {
    unsigned N;
    cout << "enter a number"<<endl;
    cin >> N;
    cout << shor(N)<<" is a divider"<<endl;
    return 0;
}

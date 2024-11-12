
const int mod = 1000000007 ; 
const int N = 200005;
 
int fact[N + 1];
int inv[N + 1];
int spf[N + 1];
bool isprime[N + 1] ;

int expo(int a, int b, int m = mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
}
 
int mod_inv(int a, int b = mod)
{
    return expo(a, b - 2, b);
}
 
int mod_add(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
 
int mod_mul(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
 
int mod_sub(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
 
int mod_div(int a, int b, int m = mod)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
 
int ncr(int n, int r)
{
    return (((fact[n] * inv[n - r]) % mod) * inv[r]) % mod;
}
 
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
 
int lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}
 
void sieve()
{
    spf[0] = 1;
    spf[1] = 1;
    for (int i = 2; i < N; i++)
        spf[i] = i;
    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
 
void calallprime()
{
    for (int i = 0; i <= N; i++)
        isprime[i] = true;
    isprime[1] = false;
    for (int i = 2; i < N + 1; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j < N + 1; j += i)
                isprime[j] = false;
        }
    }
}
 
void precompute()
{
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        inv[i] = expo(fact[i], mod - 2);
    }
}
 

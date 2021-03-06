/** My solution is based on the code at http://www.codechef.com/viewsolution/2237620. */
 
#include <iostream>
using namespace std;
 
int factorial[1000005];
 
/** Return (x * y) mod 1000000007. */
int MUL(int x, int y)
{
    return (int)(((unsigned long long)x * (unsigned long long)y) % 1000000007);
}
 
/** Return (x ^ y) mod 1000000007. */
int power(int x, int y)
{
    if (y == 0)
        return 1;
    
    int t = power(x, y / 2);
	
    if (y % 2 == 0)
        return MUL(t, t);
    else
        return MUL(x, MUL(t, t));
}
 
int main()
{
    /** Pre-compute factorial[0..1000004]. */
    factorial[0] = 1;
    for (int i = 1; i < 1000005; ++i)
        factorial[i] = MUL(factorial[i - 1], i);
 
    int T;
    cin >> T;
    while ( T-- )
    {
        int N, M;
        cin >> N >> M;
 
        int ans = factorial[M - N + 1];
        ans = MUL(ans, power(M - N, ((2 * N - M) >> 1)));
        ans = MUL(ans, power(M - N + 1, ((2 * N - M - 1) >> 1)));
    
        cout << ans << endl;
	}
    return 0;
}
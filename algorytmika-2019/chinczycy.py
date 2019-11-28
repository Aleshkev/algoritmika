def extended_euclidean(a, b):  # → (g, x, y) żeby ax + by = g = gcd(a, b).
    if a == 0: return b, 0, 1
    g, x, y = extended_euclidean(b % a, a)
    return g, y - (b // a) * x, x


def solve(m_1, m_2, a_1, a_2):
    g, x_1, x_2 = extended_euclidean(m_1, m_2)
    assert g == 1
    return (a_1 * m_2 * x_2 + a_2 * m_1 * x_1) % (m_1 * m_2)  # (Źródło: internet.)


print(solve(*map(int, input().split())))

#include <bits/stdc++.h>

using namespace std;


template<typename Target, typename _Source> Target bitwise_cast(_Source x) {
    //static_assert(sizeof(Target) >= sizeof(_Source), "Behold upon ");
    return *((Target *)(&x));
}

template<typename T> struct every : iterator<forward_iterator_tag, T> {
    typedef int64_t Index;
    Index i;

    every &operator++() {
        i++;
        cout << "i++" << " = " << setprecision(10) << bitwise_cast<T>(i) << endl;
        return *this;
    }
    bool operator!=(const every<T> &o) {
        cout << i << " != " << o.i << " -- ";
        cout << setprecision(10) << bitwise_cast<T>(i);
        cout << " != " << setprecision(10) << bitwise_cast<T>(o.i);
        cout << " ? " << (i != o.i) << endl;
        return i != o.i;
    }
    every(T x) {
        i = bitwise_cast<Index>(x);
        cout << x << " -> " << i << endl;
    }
    T operator*() {
        //cout << bitwise_cast<double>(ex.i) << " <- " << i << endl;
        return bitwise_cast<double>(i);
    }
    every &operator+=(size_t d) {
        cout << "+= " << d << " = " << setprecision(10) << bitwise_cast<T>(i) << endl;
        i += d;
        return *this;
    }
};

template<typename T> bool get_square(T a, T b) {
    cout << "get_square(" << a << ", " << b << ")" << endl;
    return a * a < b;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cout << bitwise_cast<uint64_t>(45.6789) << '\n';
    cout << bitwise_cast<double>(bitwise_cast<uint64_t>(45.6789)) << '\n';


    every<double> ex(45.6789);

    cout << ex.i << " " << *ex << " " << bitwise_cast<double>(ex.i) << endl;
    cout << endl;

    int m;
    cin >> m;
    cout << *lower_bound(every<int>(0),
                         every<int>(45),
                         m, get_square<int>) << '\n';

    double n;
    cin >> n;
    cout << *lower_bound(every<double>(0),
                         every<double>(45.6789),//sqrt(numeric_limits<double>::max())),
                         n, get_square<double>) << '\n';

    return 0;
}

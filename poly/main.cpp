/*
Copyright (c) <2015> <Nathaniel Wilson>
email: gaudware@gmail.com

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
   claim that you wrote the original software. If you use this software
   in a product, an acknowledgement in the product documentation would be
   appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
   misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
#include <iostream>
#include <vector>
#include <string>

#if __cplusplus < 201103L
    #error "Make Sure To Compile with C++11 or greater"
#endif
///Scope In entire STD namespace
using namespace std;

///Create a Typedef for String List;
typedef vector<string> StringList;

/// C++14 Only
using voidfunc = void (*)();
using i64 = long long int;
void f(long) { cout << "f(long)\n"; }
void f(char *) { cout << "f(char *)\n";}



void Moo()
{
    cout << __PRETTY_FUNCTION__ << endl;
}


std::string format_str_w(std::string s,std::string notation)
{
    auto i = s.size(); /// get the input string size
    std::string ret;  /// initialize an empty string, as a return
    for(auto c:s) /// loop through all elements of string 's'
    {
        i--; /// decrement 'i', for our working number
        ret+=c; /// append 'c' to the return
        if ( ((i%3) == 0)&(i>0) ) /// if 'i' mod 3 equals zero and 'i' is greater than 0
            ret+=notation; /// add notation to return string
    }
    return ret; /// finally return
}

template<int N>
struct absV1 {
    static_assert( N != INT_MIN,"Not Int" );
    static constexpr int value = (N < 0) ? - N: N;
};

/// template meta functions.

template<unsigned M, unsigned N>
struct gcd{
    static int const value = gcd<N,M%N>::value;
};
template<unsigned M>
struct gcd<M,0>{
    static_assert( M != 0u," Value is not Zero");
    static int const value = M;
};
/*
int fib(int x) {
    if (x == 1) {
        return 1;
    } else {
        return fib(x-1)+fib(x-2);
    }
}
 */

//template<int F>
//struct fib{
//    static constexpr int value = fib<F-1>::value + fib<F-2>::value;
//};
//template<int G>
//struct fib<G>{
//    static_assert( G != 1, "Failed");
//    static constexpr int value = G;
//};

//template<int U>
//struct fib<U>{
//    static_assert( U == 1, "Failed");
//    static constexpr int value = 1;
//};
//template<typename _Tp>
//  using fib_v = typename fib<_Tp>::value;

//template<class T>
//struct remove_const {
//    using type = T;
//};



int main()
{
    const int ret = 1;
    //const int nu = fib<30>::value;
    //cout << nu << endl;
    cout <<gcd<982u,125u>::value<<endl;
    cout << absV1<ret>::value << endl;
    cout << format_str_w("1000000000",",") << endl;
    cout << format_str_w("100000000",",") << endl;
    cout << format_str_w("10000000",",") << endl;
    cout << format_str_w("1000000",",") << endl;
    cout << format_str_w("100000",",") << endl;
    cout << format_str_w("10000",",") << endl;
    cout << format_str_w("1000",",") << endl;
    cout << format_str_w("100",",") << endl;
    cout << format_str_w("10",",") << endl;
    cout << format_str_w("1",",") << endl;
    cout << format_str_w("",",") << endl;
    cout << "[\tBegin Fibonacci Test\t]\n";

    /// Initalize Function Pointer
    voidfunc fcc = Moo;

    fcc();

    /// lambda test_func with ambiguity
    auto test_func = [/* Local Passing */](auto a, auto b)->auto{
        if (a>b)
            return a;
        return b;
    };

    /// usage of lambda function
    cout << test_func(1,2) << endl;

    /// C++11 Vector Initialization
    StringList a = {"Test", "Hi"};

    /// C++98 Loop Example
    for(size_t i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << endl;
    }
    cout << endl;

    f(nullptr);

    /// C++11 & C++14 Range Based Loop With Initialized Set Example
    for (auto i : { 100, 200, 300, 400 })
        cout << i << endl;

    /// C++11 & C++14 Range Based Loop Example
    for(auto &i:a)
    {
        cout << i << endl;
    }
    return 0;
}



// core_numeric.h

#pragma once

#include <iostream>
#include <iterator>
#include <concepts>
#include <type_traits>
#include <stdexcept>
#include <utility>

using namespace std;

namespace core_numeric {

template<typename C>
concept Iterable = requires(C c){
    begin(c);
    end(c);
};

template<typename T>
concept Addable = requires(T a, T b){
    { a + b } -> same_as<T>;
};

template<typename T>
concept Subtractable = requires(T a, T b){
    { a - b } -> same_as<T>;
};

template<typename T>
concept Multipliable = requires(T a, T b){
    { a * b } -> same_as<T>;
};

template<typename T>
concept Divisible = requires(T a, T b){
    { a / b } -> same_as<T>;
};

template<typename T>
concept Comparable = requires(T a, T b){
    { a > b } -> convertible_to<bool>;
};

template<Addable T>
T add(T a, T b){
    return a + b;
}

template<Subtractable T>
T sub(T a, T b){
    return a - b;
}

template<Multipliable T>
T mul(T a, T b){
    return a * b;
}

template<Divisible T>
T divi(T a, T b){
    return a / b;
}

template<Iterable C>
size_t count_elements(const C& c){

    size_t n = 0;

    for(const auto& _ : c){
        ++n;
    }

    return n;
}

template<Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& c){

    using T = typename C::value_type;

    T r{};

    for(const auto& x : c){
        r = add(r, x);
    }

    return r;
}

template<Iterable C>
requires Addable<typename C::value_type> &&
         Divisible<typename C::value_type>
auto mean(const C& c){

    using T = typename C::value_type;

    size_t n = count_elements(c);

    if(n == 0){
        throw runtime_error("contenedor vacio");
    }

    T total = sum(c);

    if constexpr(is_integral_v<T>){
        return static_cast<double>(total) / n;
    }
    else{
        return divi(total, static_cast<T>(n));
    }
}

template<Iterable C>
requires Addable<typename C::value_type> &&
         Subtractable<typename C::value_type> &&
         Multipliable<typename C::value_type>
auto variance(const C& c){

    size_t n = count_elements(c);

    if(n == 0){
        throw runtime_error("contenedor vacio");
    }

    auto m = mean(c);

    using R = decltype(m);

    R acc{};

    for(const auto& x : c){

        R d = static_cast<R>(x) - m;
        acc += d * d;
    }

    return acc / n;
}

template<Iterable C>
requires Comparable<typename C::value_type>
auto max(const C& c){

    auto it = begin(c);

    if(it == end(c)){
        throw runtime_error("contenedor vacio");
    }

    auto mayor = *it;
    ++it;

    for(; it != end(c); ++it){

        if(*it > mayor){
            mayor = *it;
        }
    }

    return mayor;
}

template<Iterable C, typename F>
auto transform_reduce(const C& c, F fn){

    using R = decltype(fn(*begin(c)));

    R acc{};

    for(const auto& x : c){
        acc += fn(x);
    }

    return acc;
}

template<typename... T>
requires(sizeof...(T) > 0)
auto sum_variadic(T... v){

    return (v + ...);
}

template<typename... T>
requires(sizeof...(T) > 0)
auto mean_variadic(T... v){

    return (static_cast<double>(v) + ...) / sizeof...(v);
}

template<typename... T>
requires(sizeof...(T) > 0)
auto variance_variadic(T... v){

    double m = mean_variadic(v...);

    return (((static_cast<double>(v) - m) *
             (static_cast<double>(v) - m)) + ...) / sizeof...(v);
}

template<typename T0, typename... Ts>
auto max_variadic(T0 first, Ts... rest){

    auto mayor = first;

    ((mayor = rest > mayor ? rest : mayor), ...);

    return mayor;
}

}
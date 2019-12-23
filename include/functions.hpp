#pragma once

#include <iostream>
#include <tuple> 
#include <type_traits>

#include "point.hpp"
#include "template.hpp"

template<class T>
struct is_point : std::false_type {};

template<class T>
struct is_point<Point<T>> : std::true_type {};

template<class T>
struct is_figure_like_tuple : std::false_type {};

template<class Head, class... Tail>
struct is_figure_like_tuple<std::tuple<Head, Tail...>> :
std::conjunction<is_point<Head>,
        std::is_same<Head, Tail>...> {};

template<class T>
inline constexpr bool is_figure_like_tuple_v =
        is_figure_like_tuple<T>::value;

template<class T,class = void>
struct has_area_method : std::false_type {};

template<class T>
struct has_area_method<T,
        std::void_t<decltype(std::declval<const T>().area())>> :
std::true_type {};

template<class T>
inline constexpr bool has_area_method_v =
        has_area_method<T>::value;

template<class T>
std::enable_if_t<has_area_method_v<T>,
                 decltype(std::declval<const T>().area())>
area(const T& figure) {
    return figure.area();
}


template<class T,class = void>
struct has_print_method : std::false_type {};

template<class T>
struct has_print_method<T,
        std::void_t<decltype(std::declval<const T>().print(std::cout))>> :
        std::true_type {};

template<class T>
inline constexpr bool has_print_method_v =
        has_print_method<T>::value;

template<class T>
std::enable_if_t<has_print_method_v<T>,
                 decltype(std::declval<const T>().print(std::cout))>
print (std::ostream& os, const T& figure) {
    return figure.print(os);
}

template<class T,class = void>
struct has_center_method : std::false_type {};

template<class T>
struct has_center_method<T,
        std::void_t<decltype(std::declval<const T>().center())>> :
        std::true_type {};

template<class T>
inline constexpr bool has_center_method_v =
        has_center_method<T>::value;

template<class T>
std::enable_if_t<has_center_method_v<T>,
                 decltype(std::declval<T>().center()) >
center (const T& figure) {
    return figure.center();
}


// print figure

template<class T>
bool is_triangle(const std::tuple<T,T,T>& tup) {
    return true;
}

template<class T>
bool is_triangle(const T& tup) {
    return true;
}


template<class T>
bool is_square(const std::tuple<T,T,T,T>& tup) {
    auto [a, b, c, d] = tup;
    if (scalarProd(a, b, c) == 0 && dist(a, b) == dist(b, a) &&
        scalarProd(b, c, d) == 0 && dist(b, c) == dist(c, d) &&
        scalarProd(c, d, a) == 0 && dist(c, d) == dist(d, a) &&
        scalarProd(d, a, b) == 0 && dist(d, a) == dist(a, b))
        return true;
    return false;
}

template<class T>
bool is_square(const T& tup) {
    return false;
}


template<class T>
bool is_rectangle(const std::tuple<T,T,T,T>& tup) {
    auto [a, b, c, d] = tup;
    if (scalarProd(a, b, c) == 0 && scalarProd(b, c, d) == 0 && 
        scalarProd(c, d, a) == 0 && scalarProd(d, a, b) == 0 &&
        dist(a, b) == dist(c, d) && dist(b, c) == dist(a, d))
        return true;
    return false;
}

template<class T>
bool is_rectangle(const T& tup) {
    return false;
}

template<class T, std::size_t... N>
auto recursive_print(std::ostream& out, const T& tup, std::index_sequence<N...>) {
    (out << ... << std::get<N>(tup));
}

template<class T>
std::enable_if_t<is_figure_like_tuple_v<T>, void>
print(std::ostream& out, const T& tup) {
    auto constexpr tuple_size = std::tuple_size<T>::value;

    
    if (tuple_size == 3 && is_triangle(tup)) {
        out << "Triangle: " << std::endl;
    }
    else if (tuple_size == 4 && is_square(tup)) {
        out << "Square: " << std::endl;
    }
    else if (tuple_size == 4 && is_rectangle(tup)) {
        out << "Rectangle: " << std::endl;
    }
    else {
        out << "Strange figure: " << std::endl;
    }

    recursive_print(out, tup, std::make_index_sequence<tuple_size>{});
    std::cout << std::endl;
}
// end print figure

// center figure
template<class T, size_t N>
Point<int> recursive_center(const T& tup) {
    if constexpr (N >= std::tuple_size_v<T>) {
            return Point<int>{0,0};
        }
    else {
        return std::get<N>(tup) + recursive_center<T, N+1>(tup) ;
    }
}

template<class T>
std::enable_if_t<is_figure_like_tuple_v<T>, Point<double>>
center(const T& tup) {
    auto constexpr tuple_size = std::tuple_size<T>{}();

    Point<int> center = recursive_center<T, 0>(tup);
    return center / tuple_size; 
}
// end center figure

// shift index sequence
template<size_t N1, size_t ...N2>
std::index_sequence<(N1 + N2)...> shift_sequence(std::index_sequence<N2...>) {
    return {};
}

template<size_t N1, size_t N2>
auto shifted_index_sequence() {
    return shift_sequence<N2>(std::make_index_sequence<N1>{});
}
// end shift index sequence

// area figure
template<typename _T, size_t... _Ix>
double area(const _T& tuple, std::index_sequence<_Ix...>) {
    auto constexpr tuple_size = std::tuple_size<_T>{}();

    using std::get;

    double result = ((get<_Ix>(tuple).x * (get<_Ix + 1>(tuple).y - get<_Ix - 1>(tuple).y)) + ...);
    auto constexpr first = 0;
    auto constexpr last = tuple_size - 1;
    result += get<first>(tuple).x * (get<first + 1>(tuple).y - get<last>(tuple).y);
    result += get<last>(tuple).x * (get<first>(tuple).y - get<last - 1>(tuple).y);
    result /= 2;

    return std::abs(result);
}

template<typename T>
std::enable_if_t<is_figure_like_tuple_v<T>, double>
 area(const T& tuple) {
    auto constexpr tuple_size = std::tuple_size<T>{}();
    return area(tuple, shifted_index_sequence<1, tuple_size - 2>());
}
// end area figure

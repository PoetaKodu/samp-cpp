#pragma once

#include SAMPCPP_PCH

#define HAS_METHOD_TEST(T, MethodName) std::void_t< decltype(std::declval<T>().destroy()) >

template<class T, class = void>
struct has_destroy_method
    : std::false_type{};

template<class T>
struct has_destroy_method<T, HAS_METHOD_TEST(T, destroy) >
    : std::true_type{};

#undef HAS_METHOD_TEST
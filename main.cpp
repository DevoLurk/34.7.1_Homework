#include <iostream>
#include <bits/stdc++.h>

template <typename T> 
concept ComplexConcept = requires(const T t) {{ t.hash() } -> std::convertible_to<long>; 
                                              { t.toString() } -> std::same_as<std::string>;} &&
                         !std::has_virtual_destructor_v<T>;

template <ComplexConcept T> void foo(T val) {};

class Bar
{
public:
    ~Bar(){};
    long hash() const { return 0b0101; };
    std::string toString() const { return "bar"; };
};

int main()
{
    Bar bar; 
    foo(bar);

    return 0;
}
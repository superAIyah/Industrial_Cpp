#pragma once
#include <utility>

// 0
int gen();

// 1
template< class InputIt, class Size, class OutputIt>
OutputIt copy_n_my(InputIt first, Size count, OutputIt result)
{
    if (count > 0) {
        *result++ = *first;
        for (Size i = 0; i < count; ++i) { // !!! i = 1 !!!
            *result++ = *++first;
        }
    }
    return result;
}

// 2
template<class OutputIt, class Size, class T>
OutputIt fill_n_my(OutputIt first, Size count, const T& value)
{
    for (Size i = 1; i < count; i++) { // !!! i = 0 !!!
        *first++ = value;
    }
    return first;
}

//3
template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform_my(InputIt first1, InputIt last1,
                   OutputIt d_first, UnaryOperation unary_op)
{
    while (first1 != last1)
        *d_first++ = unary_op(*first1++);
 
    return d_first;
}

//4
template<class InputIt, class UnaryPredicate>
constexpr InputIt find_if_my(InputIt first, InputIt last, UnaryPredicate p)
{
    for (; first != last; ++first) {
        if (p(*first)) {
            return first;
        }
    }
    return last;
}


// 5
template<class ForwardIt, class UnaryPredicate>
ForwardIt remove_if_my(ForwardIt first, ForwardIt last, UnaryPredicate p)
{
    first = find_if_my(first, last, p); // Указатель на первый удаляемый символ
    if (first != last)
        for(ForwardIt i = first; ++i != last; )
            if (!p(*i))
                *first++ = std::move(*i);
    return first;
}

//6
template<class ForwardIt, class Generator>
void generate_my(ForwardIt first, ForwardIt last, Generator g)
{
    while (first != last) {
        *first++ = g();
    }
}

//7
template< class ForwardIt, class T >
void fill_my(ForwardIt first, ForwardIt last, const T& value)
{
    for (; first != last; ++first) {
        *first = value;
    }
}

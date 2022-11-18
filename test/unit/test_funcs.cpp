#include <iostream>
#include <string>
#include <vector>
#include "funcs.h"
#include <gtest/gtest.h>

TEST(copy_n, string) {
    std::string in = "1234567890";
    std::string out;
 
    copy_n_my(in.begin(), 4, std::back_inserter(out));
    ASSERT_EQ(out, "1234");
}

TEST(copy_n, vectors) {
    std::vector<int> a = {1, 2, 3, 4};
    std::vector<int> b = {1, 0, 0, 4};
    copy_n_my(a.begin() + 1, 2, b.begin() + 1);
    ASSERT_EQ(a, b);
}

TEST(filll_n, vectors) {
    std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    fill_n_my(v1.begin(), 5, -1);
    std::vector<int> ans({-1, -1, -1, -1, -1, 5, 6, 7, 8, 9});
    ASSERT_EQ(v1, ans);
}

TEST(transform, string) {
    std::string s{"hello"};
    transform_my(s.cbegin(), s.cend(),
                s.begin(), // write to the same location
                [](unsigned char c) { return std::toupper(c); });
    ASSERT_EQ(s, "HELLO");
}

TEST(find_if, vector) {
    std::vector<int> v{1, 2, 3, 4};
    int n1 = 3;
    int n2 = 5;
    auto is_even = [](int i){ return i%2 == 0; };
    auto result3 = find_if_my(begin(v), end(v), is_even);
    ASSERT_EQ(*result3, 2);
}

TEST(remove_if, string) {
    std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(remove_if_my(str2.begin(), 
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);}),
               str2.end());
    ASSERT_EQ(str2, "Textwithsomewhitespaces");
}

TEST(generate, vector) {
    std::vector<int> v5(5);
    generate_my(v5.begin(), v5.end(), gen);
    std::vector<int> ans({0, 1, 2, 3, 4});
    ASSERT_EQ(ans, v5);
}

TEST(fill, vector) {
    std::vector<int> v2(5);
    fill_my(v2.begin(), v2.end(), -1);
    std::vector<int> ans({-1, -1, -1, -1, -1});
    ASSERT_EQ(v2, ans);
}
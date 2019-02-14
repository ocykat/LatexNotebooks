#pragma once

#include <string>

namespace util {
    template <typename T>
    void swap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template <typename T>
    T min(T& a, T& b) {
        if (a < b) return a;
        return b;
    }

    template <typename T>
    T max(T& a, T& b) {
        if (a > b) return a;
        return b;
    }

    bool isUpperCase(const char& c) {
        return 'A' <= c && c <= 'Z';
    }

    bool isLowerCase(const char& c) {
        return 'a' <= c && c <= 'z';
    }

    bool isLetter(const char& c) {
        return isUpperCase(c) || isLowerCase(c);
    }

    bool isDigit(const char& c) {
        return '0' <= c && c <= '9';
    }

    std::string removeWhitespaces(std::string s) {
        std::string res;
        for (int i = 0; i < (int) s.length(); i++) {
            if (s[i] == ' ') continue;
            res += s[i];
        }
        return res;
    }

    template <typename T>
    void printArray(T a[], int begin, int end) {
        for (int i = begin; i < end; i++) {
            std::cout << a[i] << ' ';
        }
        std::cout << '\n';
    }

};


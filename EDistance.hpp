// Copyright 2024 Jessica Vu

#include <iostream>
#include <vector>
#include <string>

class EDistance {
 public:
    EDistance(std::string s1, std::string s2);
    static int min3(int a, int b, int c);
    static int penalty(char a, char b);
    int optDistance();
    std::string alignment();
 private:
    std::vector<std::vector<int>> ed_matrix;
    std::string left;
    std::string right;
};

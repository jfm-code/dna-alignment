// Copyright 2024 Jessica Vu

#include "EDistance.hpp"

// can use left.size() to get number of characters
// can use left[2] to access the character

EDistance::EDistance(std::string s1, std::string s2) : left(s1), right(s2) {
    // Initialize the vector
    ed_matrix.resize(s1.size() + 1);
    for (size_t r = 0; r <= s1.size(); r++) {
        ed_matrix[r].resize(s2.size() + 1);
    }
}

int EDistance::min3(int a, int b, int c) {
    return std::min(std::min(a, b), c);
}

int EDistance::penalty(char a, char b) {
    if (a == b)
        return 0;
    else
        return 1;
}

int EDistance::optDistance() {
    int coefficient = 0;
    int left_size = static_cast<int>(left.size());
    int right_size = static_cast<int>(right.size());

    // fill the rightmost column
    for (int r = left_size; r >= 0; r--) {
        ed_matrix[r][right_size] = 2 * coefficient;
        coefficient++;
    }

    // fill the bottom row
    coefficient = 0;
    for (int c = right_size; c >= 0; c--) {
        ed_matrix[left_size][c] = 2 * coefficient;
        coefficient++;
    }

    // fill the rest of the matrix
    for (int r = left_size - 1; r >= 0; r--) {
        for (int c = right_size - 1; c >= 0; c--) {
            int offset = penalty(left[r], right[c]);  // offset will be 0 or 1
            ed_matrix[r][c] = min3(
                ed_matrix[r+1][c+1] + offset,
                ed_matrix[r+1][c]+2,
                ed_matrix[r][c+1]+2);
        }
    }

    // print out the matrix - debug code
    /* std::cout << std::endl;
    for (size_t r = 0; r <= left.size(); r++) {
        for (size_t c = 0; c <= right.size(); c++) {
            printf("%3d ",ed_matrix[r][c]);
        }
        std::cout << std::endl;
    } */

    return ed_matrix[0][0];
}

std::string EDistance::alignment() {
    std::string result = "";
    int left_size = static_cast<int>(left.size());
    int right_size = static_cast<int>(right.size());

    int r = 0, c = 0;
    while (r <= left_size && c <= right_size) {
        int offset = penalty(left[r], right[c]);  // offset will be 0 or 1

        // edge cases
        if (r == left_size && c != right_size) {
            if (ed_matrix[r][c] == ed_matrix[r][c+1]+2) {
                // debug - std::cout << "case 3" << std::endl;
                result += "- ";
                result += right[c];
                result += " 2\n";
                c++;
            }
        } else if (r != left_size && c == right_size) {
            if (ed_matrix[r][c] == ed_matrix[r+1][c]+2) {
                // std::cout << "case 2" << std::endl;
                result += left[r];
                result += " - 2\n";
                r++;
            }
        } else if (r == left_size && c == right_size) {
            break;
        } else {
            if (ed_matrix[r][c] == ed_matrix[r+1][c+1] + offset) {
                // std::cout << "case 1" << std::endl;
                result += left[r];
                result += ' ';
                result += right[c];
                result += ' ';
                result += offset + '0';
                result += '\n';
                r++;
                c++;
            } else if (ed_matrix[r][c] == ed_matrix[r+1][c]+2) {
                // std::cout << "case 2" << std::endl;
                result += left[r];
                result += " - 2\n";
                r++;
            } else if (ed_matrix[r][c] == ed_matrix[r][c+1]+2) {
                // std::cout << "case 3" << std::endl;
                result += "- ";
                result += right[c];
                result += " 2\n";
                c++;
            }
        }
    }
    return result;
}

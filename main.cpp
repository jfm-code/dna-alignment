// Copyright 2024 Jessica Vu

#include <iostream>
#include <SFML/System.hpp>
#include "EDistance.hpp"

int main() {
    sf::Clock clock;
    sf::Time t = clock.getElapsedTime();
    std::string s1, s2, final;
    std::cin >> s1 >> s2;
    EDistance distance(s1, s2);
    std::cout << "Edit distance = " << distance.optDistance() << std::endl;
    final = distance.alignment();
    std::cout << final << std::endl;
    t = clock.getElapsedTime();
    std::cout << "Execution time is " << t.asSeconds() << " seconds" << std::endl;

    return 0;
}

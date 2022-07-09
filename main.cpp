#include <iostream>
#include <string>
#include <random>

std::string generate(int length) {
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string pas;

    int total;

    int from = 0;
    int to = 61;

    for (int i = 0; i < length; i++) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(from, to);

        total = distr(generator);

        char x = letters[total % 62];

        pas += x;
    }

    return pas;
}

int main()
{
    int length;

    std::cout << "How long? ";
    std::cin >> length;

    std::cout << "Your password is: " << generate(length);

    return 0;
}

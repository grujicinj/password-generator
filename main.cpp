#include <iostream>
#include <string>
#include <random>

std::string generate(int length, bool num) {
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lettersnum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    std::string pas;

    int total;

    int from = 0;
    int to = 61;

    for (int i = 0; i < length; i++) {
        std::random_device                  rand_dev;
        std::mt19937                        generator(rand_dev());
        std::uniform_int_distribution<int>  distr(from, to);

        total = distr(generator);

        char x;

        if (num == true) {
            x = lettersnum[total % 62];
        }
        else if (num == false) {
            x = letters[total % 52];
        }

        pas += x;
    }

    return pas;
}

int main()
{
    int length;
    bool num = true;
    std::string n = "z";

    std::cout << "How long? \n";
    std::cin >> length;

    while (n != "y" && n != "n") {
        std::cout << "Numbers? y/n \n";
        std::cin >> n;

        if (n == "y") {
            num = true;
        }
        else if (n == "n") {
            num = false;
        }
        else {
            n = "z";
        }
    }

    std::cout << "Your password is: " << generate(length, num);

    return 0;
}

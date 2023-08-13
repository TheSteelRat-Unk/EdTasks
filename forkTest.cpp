#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int value = 42;
    int* address = &value;

    std::cout << "Адрес переменной до разделения : " << address << std::endl;

    pid_t pid = fork();


    if (pid == 0) {
        std::cout << "Дочерний процесс: Адрес : " << address << std::endl;

        *address = 99;

    } else {

        wait(nullptr);

        std::cout << "Родительский процесс: Адрес : " << address << std::endl;
        std::cout << "Родительский процесс: после изменения : " << *address << std::endl;
    }

    return 0;
}

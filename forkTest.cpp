#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
  
    pid_t pid = fork();
    if (pid == -1) {
        std::cout << "fail" << std::endl;
        return 1;
    }

    if (pid == 0) { 
        close(pipefd[1]); 

        int* receivedAddress;
        read(pipefd[0], &receivedAddress, sizeof(receivedAddress));
        std::cout << "Дочерний процесс: Полученный адрес : "       << receivedAddress  << std::endl;
        std::cout << "Дочерний процесс: Значение переменной до : " << *receivedAddress << std::endl;

        *receivedAddress = 99; 

        close(pipefd[0]); 

    } else { 
        close(pipefd[0]); 

        int value = 42;
        int* address = &value;

        write(pipefd[1], &address, sizeof(address));
        std::cout << "Родительский процесс: Адрес переменной, отправленный в дочерний процесс: " << address << std::endl;
        std::cout << "Родительский процесс: Значение переменной до : " << value << std::endl;

        close(pipefd[1]); 

        wait(nullptr); 

        std::cout << "Родительский процесс: Значение переменной после : " << value << std::endl;
    }

    return 0;
}

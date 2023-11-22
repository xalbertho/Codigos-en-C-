#include <iostream>
#include <bitset>

// Funci�n para aplicar una regla a una c�lula y sus vecinas
bool applyRule(bool left, bool center, bool right, std::bitset<8> rule) {
    int index = (left << 2) | (center << 1) | right;
    return rule.test(index);
}

// Funci�n para mostrar la evoluci�n de un aut�mata celular dado una regla
void runAutomaton(std::bitset<8> rule, int iterations) {
    std::string currentState = "0";
    std::cout << currentState << std::endl;

    for (int i = 0; i < iterations; i++) {
        std::string nextState;
        int size = currentState.size();

        for (int j = 0; j < size; j++) {
            bool left = (j > 0) ? (currentState[j - 1] - '0') : (currentState[size - 1] - '0');
            bool center = currentState[j] - '0';
            bool right = (j < size - 1) ? (currentState[j + 1] - '0') : (currentState[0] - '0');

            nextState += applyRule(left, center, right, rule) ? '1' : '0';
        }

        std::cout << nextState << std::endl;
        currentState = nextState;
    }
}

int main() {
    int iterations = 10;

    // Iterar sobre las 256 reglas
    for (int i = 0; i < 256; i++) {
        std::bitset<8> rule(i);
        std::cout << "Regla " << i << ":" << std::endl;
        runAutomaton(rule, iterations);
        std::cout << std::endl;
    }

    return 0;
}


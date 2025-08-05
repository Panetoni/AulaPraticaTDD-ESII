#include <assert.h>
#include <stdio.h>

using namespace std;

class Dollar {
private:
    int amount;
public:
    Dollar(int amount) {
        this->amount = amount;
    }
    int getAmount() {
        return amount;
    }
    Dollar* times(int multiplier) {
        return new Dollar(amount * multiplier);
    }
    // Sobrecarga do operador de igualdade
    bool operator==(const Dollar& other) const {
        return amount == other.amount;
    }
};

void assertEquals(int expected, int actual) {
    if (expected != actual) {
        printf("Expected %d but got %d\n", expected, actual);
        throw "Test failed";
    }
}

void assertTrue(bool condition) {
    if (!condition) {
        printf("Expected true but got false\n");
        throw "Test failed";
    }
}

void assertFalse(bool condition) {
    if (condition) {
        printf("Expected false but got true\n");
        throw "Test failed";
    }
}

void testMultiplication() {
    Dollar* five = new Dollar(5);
    assertEquals(10, five->times(2)->getAmount());
    assertEquals(15, five->times(3)->getAmount());
    delete five;
}

void testEquality() {
    assertTrue(Dollar(5) == Dollar(5));
    assertFalse(Dollar(5) == Dollar(6));
}

int main() {
    testEquality();
    testMultiplication();
    printf("Test passed!\n");
    return 0;
}

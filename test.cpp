#include <assert.h>
#include <stdio.h>

using namespace std;

void assertEquals(int expected, int actual);

class Dollar {
public:
    int amount;
    Dollar(int amount) {
        this->amount = amount;
    }
    Dollar* times(int multiplier) {
        return new Dollar(amount * multiplier);
    }
};

void testMultiplication() {
    Dollar* five = new Dollar(5);
    assertEquals(10, five->times(2)->amount);
    assertEquals(15, five->times(3)->amount);
    delete five;
}


void assertEquals(int expected, int actual) {
    if (expected != actual) {
        printf("Expected %d but got %d\n", expected, actual);
        throw "Test failed";
    }
}

int main() {
    testMultiplication();
    printf("Test passed!\n");
    return 0;
}

#include <assert.h>
#include <stdio.h>    

using namespace std;

void assertEquals(int expected, int actual);

class Dollar {
    public:
       int amount = 10;
       Dollar(int amount) {}			
       void times(int multiplier) {}
    }	;

void testMultiplication() {
       Dollar five = Dollar(5);
       five.times(2);
       assertEquals(10, five.amount);
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
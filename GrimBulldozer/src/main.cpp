#include <iostream>

#include <stdexcept>

#include "Node.h"
#include "test.h"

using namespace std;

int main(int argc, char **argv) {
    try {
        auto d1 = new gb::Derived1;
        auto d2 = new gb::Derived2;
        auto d3 = new gb::Derived3(d1, d2);

        test(d1);
        test(d2);
        test(d3);

        d1->release();
        d2->release();
        d3->release();

        cout << gb::Node<>::counter << endl;

    } catch (const exception& e) {
        cerr << e.what() << endl;
    }
}

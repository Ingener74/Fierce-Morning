#include "Node.h"

namespace gb {

void Derived1::print() {
    cout << __PRETTY_FUNCTION__ << endl;
}

Derived1::~Derived1() {
}

Derived1::Derived1() {
}

Derived2::Derived2() {
}

Derived2::~Derived2() {
}

void Derived2::print() {
    cout << __PRETTY_FUNCTION__ << endl;
}

Derived3::Derived3(Derived1* arg1, Derived2* arg2) :
        Node(arg1, arg2) {
}

Derived3::~Derived3() {
}

void Derived3::print() {
    cout << __PRETTY_FUNCTION__ << endl;
}

}

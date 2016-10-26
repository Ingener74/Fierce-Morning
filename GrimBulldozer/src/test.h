#ifndef TEST_H_
#define TEST_H_

namespace gb {

template<typename ... Ts>
class Node;

template<typename ... Ts>
void test(Node<Ts...>* n) {
    n->print();
}

}

#endif /* TEST_H_ */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <tuple>
#include <Poco/AutoPtr.h>
#include <Poco/RefCountedObject.h>

namespace gb {

using namespace std;

template<typename ... Args>
class Node: public Poco::RefCountedObject {
public:
    Node(Args* ... args) {
        if (sizeof...(args) != 0)
            m_members = std::make_tuple(Poco::AutoPtr<Args>(args, true)...);
        counter++;
    }

    virtual ~Node() {
        counter--;
    }

    virtual void print();

    std::tuple<Poco::AutoPtr<Args>...> m_members;

    static int counter;
};

class Derived1: public Node<> {
public:
    Derived1();
    virtual ~Derived1();

    virtual void print();
};

class Derived2: public Node<> {
public:
    Derived2();
    virtual ~Derived2();

    virtual void print();
};

class Derived3: public Node<Derived1, Derived2> {
public:
    Derived3(Derived1* arg1, Derived2* arg2);
    virtual ~Derived3();

    virtual void print();
};

template<typename ... Ts>
inline void Node<Ts...>::print() {
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename ... Ts>
int Node<Ts...>::counter = 0;

}

#endif

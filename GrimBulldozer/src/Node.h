#ifndef NODE_H_
#define NODE_H_

#include <tuple>
#include <Poco/AutoPtr.h>
#include <Poco/RefCountedObject.h>

namespace gb {

template<typename ... Args>
class Node: public Poco::RefCountedObject {
public:
    Node(Args* ... args) {
        if (sizeof...(args) != 0)
            m_members = std::make_tuple(Poco::AutoPtr<Args>(args, true)...);
    }

    std::tuple<Args...> m_members;

    virtual ~Node() {
    }
};

class Derived1: public Node<> {
public:
    Derived1() {
    }
    virtual ~Derived1() {
    }
};

class Derived2: public Node<> {
public:
    Derived2() {
    }
    virtual ~Derived2() {
    }
};

class Derived3: public Node<Derived1, Derived2> {
public:
    Derived3(Derived1* arg1, Derived2* arg2) :
            Node(arg1, arg2) {
    }
    virtual ~Derived3() {
    }
};

}

#endif

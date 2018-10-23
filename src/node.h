#ifndef NODE_H
#define NODE_H

#include <memory>

namespace bintree {

    class Node;
    using key_t = int;
    using height_t = int;
    using childptr_t = std::shared_ptr<Node>;
    using parntptr_t = std::weak_ptr<Node>;

    class Node {
    public:
        key_t m_key;
        height_t m_height;
        parntptr_t m_parent;
        childptr_t m_left;
        childptr_t m_right;
    public:
        Node();
        Node(const key_t key);
        Node(const key_t key, const height_t height, const parntptr_t &parent, const childptr_t &left, const childptr_t &right);
    };

}

#endif //NODE_H
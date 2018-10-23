#include "node.h"

namespace bintree {

    Node::Node() : Node{{}, -1, {}, {}, {}} {

    }


    Node::Node(const key_t key) : Node{key, -1, nullptr, nullptr, nullptr} {

    }


    Node::Node(const key_t key, const height_t height, const parntptr_t &parent, const childptr_t &left, const childptr_t &right) :
    m_parent{parent}, m_height{height}, m_left{left}, m_right{right} {

    }


}
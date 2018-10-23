#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include "node.h"

namespace bintree {

    class BinSearchTree {
    private:
        parntptr_t m_root;
    public:
        BinSearchTree() = default;
        BinSearchTree(const key_t key);
    public:
        void Insert(const key_t key);
        void SubInsert(const parntptr_t &parentNode, const key_t key);
        void GetHeightOfNode(const parntptr_t &parentNode);
        void UpdateHeight(const childptr_t &parentNode);
        bool CheckTransfrom(const parntptr_t &parentNode);
        void RightTransfrom(parntptr_t &node);
        void LeftTransfrom(parntptr_t &node);
        void LeftRightTransfrom(parntptr_t &node);
        void RightLeftTransfrom(parntptr_t &node);
        void Transfrom();
        bool ExitEle(const parntptr_t &node, const parntptr_t &findnode);

    };

}

#endif //BINSEARCHTREE_H
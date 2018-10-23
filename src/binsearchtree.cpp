#include "binsearchtree.h"

namespace bintree {
    BinSearchTree::BinSearchTree(const key_t key) : m_root{new Node{key}} {

    }


}


namespace bintree {
    void BinSearchTree::Insert(const key_t key) {
        SubInsert(m_root, key);
    }

    void BinSearchTree::SubInsert(const parntptr_t &parentNode, const key_t key) {
        if(!parentNode){
            childptr_t node(new childptr_t::element_type(key));
            parentNode = node;
            Transfrom(parentNode);
        }
        else{
            if(parentNode->m_key >= key){
                SubInsert(parentNode->m_right, key);
            }
            else{
                SubInsert(parentNode->m_right, key);
            }
        }

    }



    void BinSearchTree::GetHeightOfNode(const parntptr_t &parentNode) {
        return parentNode ? parentNode->m_height : -1;
    }

    void BinSearchTree::UpdateHeight(const childptr_t &parentNode) {
        if(!parentNode)
            return;
        ++(parentNode->m_height);
        UpdateHeight(parentNode->m_parent);
    }

    parntptr_t BinSearchTree::CheckTransfrom(const parntptr_t &parentNode) {
        if(!parentNode)
            return nullptr;
        int dis = GetHeightOfNode(parentNode->m_left) - GetHeightOfNode(parentNode->m_right);
        if(std::abs(dis) > 1)
            return parentNode;
        return CheckTransfrom(parentNode->m_parent);
    }

    void BinSearchTree::RightTransfrom(parntptr_t &node) {
        if(!node)
            return;

        parntptr_t par = node->m_parent;
        if(!par)
            return;

        node->m_parent = par->m_parent;
        if(par->m_parent)
            par->m_parent->m_left = node;
        else
            m_root = node;



        par->m_left = node->m_right;
        if(node->m_right)
            node->m_right->m_parent = par;

        node->m_right = par;
        par->m_parent = node;
    }


    void BinSearchTree::LeftTransfrom(parntptr_t &node) {
        if(!node)
            return;
        
        parntptr_t par = node->m_parent;
        if(!par)
            return;

        node->m_parent = par->m_parent;
        if(par->m_parent)
            par->m_parent->m_right = node;
        else
            m_root = node;

        par->m_right = node->m_left;
        if(node->m_left)
            node->m_left->m_parent = par;

        node->m_left = par;
        par->m_parent = node;

    }


    void BinSearchTree::LeftRightTransfrom(parntptr_t &node) {
        if(!node)
            return;
        parntptr_t par = node->m_parent;
        if(!par)
            return;

        node->m_parent = par->m_parent;
        if(par->m_parent)
            par->m_parent->m_left = node;

        par->m_right = node->m_left;
        if(node->m_left)
            node->m_left->m_parent = par;

        node->m_left = par;
        par->m_parent = node;

        RightTransfrom(node);

    }


    void BinSearchTree::RightLeftTransfrom(parntptr_t &node) {
        if(!node)
            return;
        parntptr_t par = node->m_parent;
        if(!par)
            return;

        node->m_parent = par->m_parent;
        if(par->m_parent)
            par->m_parent->m_right = node;

        par->m_left = node->m_right;
        if(node->m_right)
            node->m_right->m_parent = par;

        node->m_right = par;
        par->m_parent = node;

        LeftTransfrom(node);
    }

    void BinSearchTree::Transfrom(const parntptr_t &node) {
        if(!node)
            return;

        parntptr_t par = CheckTransfrom(node->m_parent);
        if(!par)
            return;

        if(par->m_left) {
            if(ExitEle(par->m_left->m_left), node)
                RightTransfrom(par->m_left);

            if(ExitEle(par->m_left->m_right), node)
                LeftRightTransfrom(par->m_left->m_right);
        }

        if(par->m_right) {
            if(ExitEle(par->m_right->m_right), node)
                LeftTransfrom(par->m_right);

            if(ExitEle(par->m_right->m_left), node)
                RightLeftTransfrom(par->m_right->m_left);
        }
    }


    bool BinSearchTree::ExitEle(const parntptr_t &node, const parntptr_t &findnode) {
        if(!node)
            return false;
        if(!findnode)
            return false;
        if(node == findnode)
            return true;
        return ExitEle(node->m_left, findnode) || ExitEle(node->m_right, findnode);
    }



}
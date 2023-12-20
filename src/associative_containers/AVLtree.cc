#include <iostream>

template < class T >
class TreeNode {
    protected:
        T val_;
        TreeNode *left_;
        TreeNode *right_;
    public:
        TreeNode() : val_(T()), left_(nullptr), right_(nullptr) {}
        explicit TreeNode(T x, TreeNode *left=nullptr, TreeNode *right=nullptr) : val_(x), left_(left), right_(right) {}
        virtual ~TreeNode(){}
};

template < class T >
class AVLTreeNode: public TreeNode < T >
{
  private:
    int balanceFactor_;

  public:
    AVLTreeNode();
    explicit AVLTreeNode( T x, AVLTreeNode<T> *left=nullptr, AVLTreeNode<T> *right=nullptr, int balfac=0): TreeNode<T>(x, left, right), balanceFactor_(balfac){}

    AVLTreeNode<T>* Left() const;
    AVLTreeNode<T>* Right() const;
    T Data() const;

    int GetBalanceFactor();

    // методы класса AVLTree должны иметь доступ к Left и Right
    //friend class AVLTree<T>;
};


template <class T>
AVLTreeNode<T>::AVLTreeNode():TreeNode<T>(), balanceFactor_(0){}

template <class T>
int AVLTreeNode<T>::GetBalanceFactor(){
    return balanceFactor_;
}

template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::Left() const{
    return (AVLTreeNode<T>*)this->left_;
}

template <class T>
AVLTreeNode<T>* AVLTreeNode<T>::Right() const{
    return (AVLTreeNode<T>*)this->right_;
}

template <class T>
T AVLTreeNode<T>::Data() const{
    return this->val_;
}

int main(){

    AVLTreeNode<char> e('E', NULL, NULL, 0);
    AVLTreeNode<char> d('D', NULL, NULL, 0);
    // c = AVLTreeNode<char>('C', &e, NULL, -1);
    // b = AVLTreeNode<char>('B', NULL, &d, 1);
    // a = AVLTreeNode<char>('A', &b, &c, 0);
    AVLTreeNode<char> tree('A', &e, &d);
    AVLTreeNode<char> *n = tree.Left();
    std::cout << n->Data() << '\n';
    return 0;
}

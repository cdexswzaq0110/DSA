#include<iostream>
#include<stdlib.h>
using namespace std;

// �w�q Node �`�I���O�A��ܬ��¾𤤪��@�Ӹ`�I
class Node {
public:
    int info;       // �`�I�s�x�����
    char color;     // 'r' ��ܬ���, 'b' ��ܶ¦�
    Node* left;     // ���l�`�I����
    Node* right;    // �k�l�`�I����
    Node* parent;   // ���`�I����

    // Node ���غc��ơA��l�Ƹ`�I����ƩM����
    Node(int value, Node* neel) {
        info = value;
        color = 'r';   // �s���J���`�I�w�]������
        left = neel;   // ���l�`�I��l���V NIL �`�I
        right = neel;  // �k�l�`�I��l���V NIL �`�I
        parent = neel; // ���`�I��l���V NIL �`�I
    }
};

// �w�q���¾����O�A�ʸ˩Ҧ����¾�ާ@
class RedBlackTree {
private:
    Node* root;   // �𪺮ڸ`�I
    Node* neel;   // �ΨӪ�� NIL �`�I (�Ҧ����l�`�I)

    // ���۾ާ@�A�O�����¾𪺥���
    void leftRotate(Node* x) {
        Node* y = x->right;  // �N x ���k�l�`�I�]�� y
        x->right = y->left;  // �ಾ y �����l�`�I�� x ���k�l�`�I

        if (y->left != neel)
            y->left->parent = x;
        y->parent = x->parent; // �վ� y �����`�I����

        if (x->parent == neel)
            root = y;  // �p�G x �O�ڸ`�I�A��s�ڬ� y
        else if (x == x->parent->left)
            x->parent->left = y;  // �վ� x ���`�I�����l�`�I���V y
        else
            x->parent->right = y; // �վ� x ���`�I���k�l�`�I���V y

        y->left = x;  // �N x �]�� y �����l�`�I
        x->parent = y; // ��s x �����`�I
    }

    // �k�۾ާ@�A�O�����¾𪺥���
    void rightRotate(Node* y) {
        Node* x = y->left;  // �N y �����l�`�I�]�� x
        y->left = x->right; // �ಾ x ���k�l�`�I�� y �����l�`�I

        if (x->right != neel)
            x->right->parent = y;
        x->parent = y->parent; // �վ� x �����`�I����

        if (y->parent == neel)
            root = x;  // �p�G y �O�ڸ`�I�A��s�ڬ� x
        else if (y == y->parent->left)
            y->parent->left = x;  // �վ� y ���`�I�����l�`�I���V x
        else
            y->parent->right = x; // �վ� y ���`�I���k�l�`�I���V x

        x->right = y;  // �N y �]�� x ���k�l�`�I
        y->parent = x; // ��s y �����`�I
    }

    // ���J�ץ��A�O�����¾𪺯S��
    void insertFixup(Node* z) {
        // �� z �����`�I�O����ɡA�i��ץ�
        while (z->parent->color == 'r') {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right; // z �ݷݪ��k�l�`�I

                if (y->color == 'r') { // Case 1: �����`�I�O����
                    z->parent->color = 'b';   // ���`�I�ܶ�
                    y->color = 'b';           // �����`�I�ܶ�
                    z->parent->parent->color = 'r'; // �ݷݸ`�I�ܬ�
                    z = z->parent->parent;     // �~��ץ��ݷݸ`�I
                }
                else {
                    if (z == z->parent->right) {  // Case 2: z �O�k�l�`�I
                        z = z->parent;
                        leftRotate(z);           // ����
                    }
                    z->parent->color = 'b';       // Case 3: z �O���l�`�I
                    z->parent->parent->color = 'r';
                    rightRotate(z->parent->parent); // �k��
                }
            }
            else {
                // �P�W���� if �����蹳�B�z (���`�I�O�k�l�`�I)
                Node* y = z->parent->parent->left;

                if (y->color == 'r') {
                    z->parent->color = 'b';
                    y->color = 'b';
                    z->parent->parent->color = 'r';
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = 'b';
                    z->parent->parent->color = 'r';
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = 'b'; // �ڸ`�I�`�O�¦�
    }

    // �d��𤤪��̤p�`�I
    Node* findMin(Node* x) {
        while (x->left != neel)
            x = x->left;
        return x;
    }

    // ���ǹM�����U���
    void inorderTraversal(Node* x) {
        if (x != neel) {
            inorderTraversal(x->left);  // �M�����l��
            cout << x->info << ", " << x->color << " ";  // ��X�`�I���
            inorderTraversal(x->right); // �M���k�l��
        }
    }

public:
    // �غc��ơA��l�Ƭ��¾�
    RedBlackTree() {
        neel = new Node(0, nullptr); // NIL �`�I�A�Ҧ����l�`�I���O NIL
        neel->color = 'b';  // NIL �`�I�`�O�¦�
        root = neel;        // ��l�Ʈڸ`�I�� NIL
    }

    // ���J�@�ӷs�`�I����¾�
    void insert(int value) {
        Node* z = new Node(value, neel); // �إ߷s�`�I
        Node* y = neel;
        Node* x = root;

        // �d�䴡�J��m
        while (x != neel) {
            y = x;
            if (z->info < x->info)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == neel)
            root = z;
        else if (z->info < y->info)
            y->left = z;
        else
            y->right = z;

        z->left = neel;
        z->right = neel;
        z->color = 'r';  // �s�`�I�]������

        insertFixup(z);  // �ץ����¾𪺥���
    }

    // ���ǹM���A��ܾ𤤩Ҧ��`�I
    void inorder() {
        inorderTraversal(root);  // �եλ��U��ƶi�椤�ǹM��
        cout << endl;
    }

    // �R���ާ@ (�����\��A�i�ھڻݨD�X�i)
    // �j�M�`�I
    Node* search(Node* x, int value) {
        while (x != neel && value != x->info) {
            if (value < x->info)
                x = x->left;
            else
                x = x->right;
        }
        return x;
    }

    // �R���`�I���\��
    void deleteNode(int value) {
        Node* z = search(root, value);
        if (z == neel)
            return;

        Node* y = z;
        Node* x;
        char yOriginalColor = y->color;

        if (z->left == neel) {
            x = z->right;
            transplant(z, z->right);
        }
        else if (z->right == neel) {
            x = z->left;
            transplant(z, z->left);
        }
        else {
            y = findMin(z->right);
            yOriginalColor = y->color;
            x = y->right;

            if (y->parent == z) {
                x->parent = y;
            }
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        if (yOriginalColor == 'b')
            deleteFixup(x);
    }

    void transplant(Node* u, Node* v) {
        if (u->parent == neel)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    void deleteFixup(Node* x) {
        while (x != root && x->color == 'b') {
            if (x == x->parent->left) {
                Node* w = x->parent->right;
                if (w->color == 'r') {
                    w->color = 'b';
                    x->parent->color = 'r';
                    leftRotate(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == 'b' && w->right->color == 'b') {
                    w->color = 'r';
                    x = x->parent;
                }
                else {
                    if (w->right->color == 'b') {
                        w->left->color = 'b';
                        w->color = 'r';
                        rightRotate(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = 'b';
                    w->right->color = 'b';
                    leftRotate(x->parent);
                    x = root;
                }
            }
            else {
                Node* w = x->parent->left;
                if (w->color == 'r') {
                    w->color = 'b';
                    x->parent->color = 'r';
                    rightRotate(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == 'b' && w->left->color == 'b') {
                    w->color = 'r';
                    x = x->parent;
                }
                else {
                    if (w->left->color == 'b') {
                        w->right->color = 'b';
                        w->color = 'r';
                        leftRotate(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = 'b';
                    w->left->color = 'b';
                    rightRotate(x->parent);
                    x = root;
                }
            }
        }
        x->color = 'b';
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    RedBlackTree tree;

    // ���J 1 �� 10 ���`�I
    for (int i = 1; i <= 10; ++i) {
        tree.insert(i);
    }

    cout << "���J�᪺���ǹM��: " << endl;
    tree.inorder();

    // �R���ƭȬ� 4 ���`�I
    tree.deleteNode(4);
    cout << "�R�� 4 ���᪺���ǹM��: " << endl;
    tree.inorder();

    return 0;
}

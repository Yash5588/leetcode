/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(!quadTree1) return quadTree2;
        if(!quadTree2) return quadTree1;
        if(quadTree1->isLeaf == 1 && quadTree2->isLeaf == 1) {
            Node* node = new Node();
            node->isLeaf = 1;
            node->val = quadTree1->val | quadTree2->val;
            return  node;
        }
        if(quadTree1->isLeaf == 1) {
            if(quadTree1->val == 1) return quadTree1;
            return quadTree2;
        }
        if(quadTree2->isLeaf == 1) {
            if(quadTree2->val == 1) return quadTree2;
            return quadTree1;
        }
        //both are not leaves
        Node* root = new Node();
        root->isLeaf = 0;
        root->val = 0;
        Node* topL = intersect(quadTree1->topLeft,quadTree2->topLeft);
        Node* topR = intersect(quadTree1->topRight,quadTree2->topRight);
        Node* bottomL = intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
        Node* bottomR = intersect(quadTree1->bottomRight,quadTree2->bottomRight);
        if(topL->val == 1  && topL->isLeaf == 1 && topR->val == 1 && topR->isLeaf == 1 && bottomL->val == 1 && bottomL->isLeaf == 1 && bottomR->val == 1 && bottomR->isLeaf == 1) {
            root->isLeaf = 1;
            root->val = 1;
            return root;
        }
        root->topLeft = topL;
        root->topRight = topR;
        root->bottomLeft = bottomL;
        root->bottomRight = bottomR;
        return root;
    }
};
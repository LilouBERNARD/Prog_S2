#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        Node *node = new Node; 
        node->left = NULL; 
        node->right = NULL 
    }

	void insertNumber(int value) 
    {
        Node *newnode = new Node; 
        newnode->value = value; 
        if(newnode->value > node->value)
        {
            node->right = newnode; 
        }
        else
        {
            node->left = newnode; 
        }

        // create a new node and insert it in right or left child
    }

	uint height() const	
    {
        int height_left = 0; 
        int height_right = 0; 


        if(node->left && node->right == NULL)
        {
            return 1; 
        }
        else
        {
            if(node->left = NULL)
            {
                height_left = 0; 
            }
            else
            {
                node->left->height(); 
            }
        
            if(node->right = NULL)
            {
                height_right = 0; 
            }
            else
            {
                node->right->height(); 
            }
            if(height_left>=height_right)
            {
                return 1+height_left;
            }
            else
            {
                return 1+height_right; 
            }
        }
        
        // should return the maximum height between left child and
        // right child +1 for itself. If there is no child, return
        // just 1
    }

	uint nodesCount() const 
    {
        int count_left; 
        int count_right; 

        if(node->left = NULL && node->right == NULL)
        {
            return 1; 
        }
        else
        {
            if(node->left = NULL)
            {
                count_left = 0; 
            }
            else
            {
                count_left = node->left->nodesCount();
            }
            if(node->right = NULL)
            {
                count_right = 0;
            }
            else
            {
                count_right = node->right->nodesCount(); 
            }
            
            return 1+count_left+count_right; 
        }
        // should return the sum of nodes within left child and
        // right child +1 for itself. If there is no child, return
        // just 1
        return 1;
	}

	bool isLeaf() const 
    {
        if(node->left == NULL && node->right == NULL)
            return true;
        else 
            return false;
	}



	void allLeaves(Node* leaves[], uint& leavesCount) 
    {
        if(node->left == NULL & node->right == NULL)
        {
            leaves[0] = node; 
        }
        else
        {
            if(node->left = NULL)
            {
                leaves[0] = node->right
            }
        }
        // fill leaves array with all leaves of this tree
	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with inorder travel
	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with preorder travel
	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        // fill nodes array with all nodes with postorder travel
	}

	Node* find(int value) {
        // find the node containing value
		return nullptr;
	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}

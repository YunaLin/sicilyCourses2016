#include <cstdlib>
#include <time.h>
#include <cmath>
#include <iostream>
using namespace std;
#define xfree(p) free(p)

struct AVLTree {
    unsigned int nData;
    struct AVLTree* pLeft;
    struct AVLTree* pRight;
    int nHeight;
};

static int Max(int a, int b)
{
    return (a > b ? a : b);
}

static int Height(struct AVLTree* pNode)
{
    if (NULL == pNode)
        return -1;

    return pNode->nHeight;
}

static struct AVLTree* SingleRotateWithLeft(struct AVLTree* pNode)
{
    struct AVLTree* temp;
    temp = pNode->pLeft;
    pNode->pLeft = temp->pRight;
    temp->pRight = pNode;
    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    temp->nHeight = Max(Height(temp->pLeft), pNode->nHeight) + 1;
    return temp;
}

static struct AVLTree* SingleRotateWithRight(struct AVLTree* pNode)
{
    struct AVLTree* temp;

    temp = pNode->pRight;
    pNode->pRight = temp->pLeft;
    temp->pLeft = pNode;

    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    temp->nHeight = Max(Height(temp->pRight), pNode->nHeight) + 1;

    return temp;
}

static struct AVLTree* DoubleRotateWithLeft(struct AVLTree* pNode)
{
    pNode->pLeft = SingleRotateWithRight(pNode->pLeft);
    return SingleRotateWithLeft(pNode);
}

static struct AVLTree* DoubleRotateWithRight(struct AVLTree* pNode)
{
    pNode->pRight = SingleRotateWithLeft(pNode->pRight);
    return SingleRotateWithRight(pNode);
}


struct AVLTree* insert_tree(unsigned int nData, struct AVLTree* pNode)
{
    if (NULL == pNode)
    {
        pNode = new AVLTree();
        pNode->nData = nData;
        pNode->nHeight = 0;
        pNode->pLeft = pNode->pRight = NULL;
    }
    else if (nData < pNode->nData)    /*插入到左子树中*/
    {
        pNode->pLeft = insert_tree(nData, pNode->pLeft);
        if (Height(pNode->pLeft) - Height(pNode->pRight) == 2)
        {
            if (nData < pNode->pLeft->nData)
            {
                /*插入到了左子树左边, 做单旋转*/
                pNode = SingleRotateWithLeft(pNode);
            }
            else
            {
                /*插入到了左子树右边, 做双旋转*/
                pNode = DoubleRotateWithLeft(pNode);
            }
        }
    }
    else if (nData > pNode->nData)    /*插入到右子树中*/
    {
        pNode->pRight = insert_tree(nData, pNode->pRight);
        if (Height(pNode->pRight) - Height(pNode->pLeft) == 2)
        {
            if (nData > pNode->pRight->nData)
            {
                /*插入到了右子树右边, 做单旋转*/
                pNode = SingleRotateWithRight(pNode);
            }
            else
            {
                /*插入到了右子树左边, 做双旋转*/
                pNode = DoubleRotateWithRight(pNode);
            }
        }
    }
    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    return pNode;
}

void delete_tree(struct AVLTree** ppRoot)
{
    if (NULL == ppRoot || NULL == *ppRoot)
        return;
    delete_tree(&((*ppRoot)->pLeft));
    delete_tree(&((*ppRoot)->pRight));
    xfree(*ppRoot);
    *ppRoot = NULL;
}

void print_tree(struct AVLTree* pRoot)
{
    if (NULL != pRoot) {
      cout << pRoot->nData << " ";
      print_tree(pRoot->pLeft);
      print_tree(pRoot->pRight);
    }
}

int main() {
    int t, n, num;
    cin >> t;
    while (t--) {
      AVLTree* pRoot = NULL;
      cin >> n;
      for (int i = 0; i < n; ++i) {
        cin >> num;
        pRoot = insert_tree(num, pRoot);
      }
      print_tree(pRoot);
      cout << endl;
      delete_tree(&pRoot);
    }
    return 0;
}

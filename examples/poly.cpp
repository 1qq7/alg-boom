/**
 * 实现多项式相加
 * A = 7 + 3x + 9x^8 + 5x^17
 * B = 8x + 22x^7 - 9x^8
*/ 
#include <stdio.h>


typedef struct PNode {
    float coef;
    int expn;
    struct PNode *next;
}PNode, *Polynomial;


void CreatePolyn(Polynomial &P, int n, float* coefs, int* expns)
{
    P = new PNode;
    P->next = nullptr;
    Polynomial p = P;
    for (int i = 0; i < n; i++) {
        PNode* new_node = new PNode;
        new_node->next = p->next;
        p->next = new_node;
        p = new_node;
        new_node->coef = coefs[i];
        new_node->expn = expns[i];
    }
}

void PrintPolyn(Polynomial P)
{
    Polynomial p = P;
    p = p->next;
    // int i = 1;
    while (p) {
        printf("(%f, %d), ", p->coef, p->expn);
        p = p->next;
    }
    printf("\n");
}


void MergePolyn(Polynomial &PA, Polynomial &PB, Polynomial &PC)
{
    /**
     * 当 PA 和 PB 都不是空链表时，判断 PA 和 PB 哪一个链表的头节点的指数值是否相等，
     * 如果不相等，将较小值的节点添加到结果PC里，当一个节点被添加到结果里之后，将对应链表中的节点向后移一位。
     * 如果相等，再判断结点的系数的值之和是否为0。如果是，删除这两个结点，否则，求和后删除其中一个。
    */ 
    PC = new PNode;
    PC->next = nullptr;

    PNode *pa, *pb, *pc, *p;
    pa = PA->next;
    pb = PB->next;
    delete PA;
    delete PB;
    PA = nullptr;
    PB = nullptr;
    pc = PC;

    while (pa && pb) {
        if (pa->expn < pb->expn) {
            pc->next = pa;
            pa = pa->next;
            pc = pc->next;
        } else if (pa->expn == pb->expn) {
            if (pa->coef + pb->coef == 0) {
                p = pa;
                pa = pa->next;
                delete p;
                p = pb;
                pb = pb->next;
                delete p;
            } else {
                pa->coef += pb->coef;
                pc->next = pa;
                pa = pa->next;
                pc = pc->next;
                p = pb;
                pb = pb->next;
                delete p;
            }
        } else {
            pc->next = pb;
            pb = pb->next;
            pc = pc->next;
        }
    }
    pc->next = pa ? pa : pb;
}

int main()
{
    float A_coef[] = {7, 3, 9, 5};
    int A_expn[] = {0, 1, 8, 17};

    float B_coef[] = {8, 22, -9};
    int B_expn[] = {1, 7, 8};

    Polynomial PA, PB, PC;
    CreatePolyn(PA, 4, A_coef, A_expn);
    CreatePolyn(PB, 3, B_coef, B_expn);
    PrintPolyn(PA);
    PrintPolyn(PB);

    MergePolyn(PA, PB, PC);
    PrintPolyn(PC);
}

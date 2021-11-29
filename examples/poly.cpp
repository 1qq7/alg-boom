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
    PC = new PNode;
    PC->next = nullptr;

    PNode *pa, *pb, *pc;
    pa = PA->next;
    pb = PB->next;
    pc = PC->next;

    while (pa && pb) {
        if (pa->expn < pb->expn) {
            // insert pa
            pc->next = pa;
            pa->next = pa
        } else if (pa->expn = pb->expn) {
            if (pa->coef + pb->coef == 0) {
                // free pa, free pb
            } else {
                // insert pa+pb
            }
        } else {
            // insert pb
        }
        pc = pc->next;
    }
    // insert non-nullptr
}

int main()
{
    float A_coef[] = {7, 3, 9, 5};
    int A_expn[] = {0, 1, 8, 17};

    float B_coef[] = {8, 22, -9};
    int B_expn[] = {1, 7, 8};

    Polynomial PA, PB;
    CreatePolyn(PA, 4, A_coef, A_expn);
    CreatePolyn(PB, 3, B_coef, B_expn);
    PrintPolyn(PA);
    PrintPolyn(PB);

}

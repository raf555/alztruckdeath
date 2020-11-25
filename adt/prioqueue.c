#include "prioqueue.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (PrioQueue Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueue Q){
    return ((Tail(Q)+1)%MaxEl(Q) == Head(Q));
}

int NBElmt (PrioQueue Q){
    if (IsEmpty(Q)) return 0;
    return ((Tail(Q) - Head(Q) + MaxEl(Q))%MaxEl(Q))+1;
}

void MakeEmpty (PrioQueue * Q, int Max){
    PrioQueue QTemp;
    QTemp.T = (infotype *) malloc (Max * sizeof(infotype));
    if ((QTemp.T) != NULL){
        MaxEl(QTemp) = Max;
    } else {
        MaxEl(QTemp) = 0;
    }
    Head(QTemp) = Nil;
    Tail(QTemp) = Nil;
    *Q = QTemp;
}

void DeAlokasi(PrioQueue * Q){
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}

void Enqueue (PrioQueue * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
    }
    Tail(*Q) = (Tail(*Q)+1) % MaxEl(*Q);
    InfoTail(*Q) = X;
    int i = Tail(*Q);
    int j = (i + MaxEl(*Q)-1)% MaxEl(*Q);
    infotype temp;
    while (i != Head(*Q) && Prio(Elmt(*Q, i))<Prio(Elmt(*Q, j))){
        
        temp = Elmt(*Q, i);
        Elmt(*Q, i) = Elmt(*Q, j);
        Elmt(*Q, j) = temp;

        i = j;
        j = (i + MaxEl(*Q)-1)% MaxEl(*Q);
    }
}

void Dequeue (PrioQueue * Q, infotype * X){
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        Head(*Q) = (Head(*Q)+1)%MaxEl(*Q);
    }
}

void PrintPrioQueue (PrioQueue Q){
    if (!IsEmpty(Q)){
        printf("(");
        int i, now;
        for (i = 0; i < NBElmt(Q) - 1; i++){
            now = (Head(Q)+i+MaxEl(Q))%MaxEl(Q);
            printf("%c,",Info(Elmt(Q,now)));
        }
        now = (Head(Q)+i+MaxEl(Q))%MaxEl(Q);
        printf("%c",Info(Elmt(Q,now)));
        printf(")");
    }
    printf(",");
}

#include    <stdio.h>

/**   リストの各ノード（要素）  **/
struct Node {
    int     value;      /**<  この要素の値。    **/
    Node *  next;       /**<  次の要素。        **/
};

/**
**    練習用のリストデータを生成する。
**
**  @return     リストの先頭の要素。
**/

Node * initializeList()
{
    Node *  pn1 = new Node();
    pn1->value  = 1;

    Node *  pn2 = new Node();
    pn2->value  = 2;

    Node *  pn3 = new Node();
    pn3->value  = 3;

    Node *  pn4 = new Node();
    pn4->value  = 4;

    Node *  pn5 = new Node();
    pn5->value  = 5;

    //  リストが 3 - 1 - 5 - 4 - 2  となるように初期化する。    //
    pn3->next   = pn1;
    pn1->next   = pn5;
    pn5->next   = pn4;
    pn4->next   = pn2;
    pn2->next   = nullptr;
    return ( pn3 );
}


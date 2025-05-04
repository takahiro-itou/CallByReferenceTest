
#if 0
g++ -g -O0 -o practice.exe List.cpp
exit 0
#endif

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

/**
**    リストを表示する。
**/

void  printList(Node * head)
{
    for ( Node * p = head; p != nullptr; p = p->next ) {
        printf("%d, ", p->value);
    }
    printf("\n");
}


/**
**    課題のソート関数。
**/

Node * sortList(Node * head)
{
    int  flagChange = 0;
    Node * headNew  = head;
    do {
        Node * prev = nullptr;      //  入れ替えるためには p の一個前が必要になる。 //
        for ( Node * p = headNew; p->next != nullptr; p = p->next ) {
            Node * next = p->next;
            //  p と next の value を比べて、                       //
            //  順番になっていなければ入れ替える (バブルソート）    //
            if ( p->value > next->value ) {
                if ( p == headNew ) {
                    //  先頭では例外処理をする。    //
                    p->next = next->next;
                    next->next = p;
                    //  新しい先頭を記録する。      //
                    headNew = next;
                } else {
                    p->next = next->next;
                    next->next = p;
                    prev->next = next;
                }
                ++ flagChange;
            }
            prev = p;
        }
    } while (flagChange > 0);

    return ( headNew ;
}


/**
**    エントリポイント。
**/

int main(int argc, char * argv[])
{
    Node * head = initializeList();
    printList(head);

    return ( 0 );
}

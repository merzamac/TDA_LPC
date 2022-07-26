#include <stdio.h>
#include <stdlib.h>

/* TDA LISTA SIN NODE CABECERA 
 
    struct list       1º nodo           2º nodo
          |              |                 |
    +------+---+     +---+---+       +----+------+
    |size=2| o----->|  2  | o-----> |  3 | NULL |
    +-----+----+     +---+---+       +----+------+  

*/
typedef struct Node  // creamos nuestra estructura tipo nodo
{
    int data;
    struct Node *next;
}node;

typedef struct List // creamos nuestra estructura tipo lista, dentro ella tiene un dato tipo nodo
{
    int list_size;
    struct Node * list_head;// aqui guardaremos la direccion de mi primer nodo
}list;

void printList(list *l)
{   node * aux;
    aux = l->list_head;
    printf("\n");
    while (aux != NULL)
    {   /* code */
        printf("%d-->",aux->data);
        aux = aux->next;
    }
    printf("||\n");
}
void insertarl(list *l,int data,int pos)
{   //variables tipo nodo 
    node *aux;
    node * new_node;

    //inicio
    aux = l->list_head;

    if (pos == 1)
    {
        /* agregar el primer valor a la lista*/
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = aux;
        l->list_head = new_node;
        l->list_size = 1 + l->list_size;

    }else if((pos >= 2) && (pos <= (l->list_size + 1)))
    {
        for (int i = 2; i < pos; i++)
        {
            /* code */
            aux = aux->next;
        }
        new_node = (node*)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = aux->next;
        aux->next = new_node;
        l->list_size = l->list_size + 1;
    }
    
}
void vacial(list *l) 
{   
    l->list_size = 0;
    l->list_head = NULL;

}

int main()
{
    list l;

    vacial(&l);
    insertarl(&l,4,1);
    insertarl(&l,1,1);
    insertarl(&l,3,2);
    insertarl(&l,2,2);
    insertarl(&l,5,5);
    printList(&l);
    printf("Longitud: %d\n\n",l.list_size);
    

    system("pause");
    return 0;
}

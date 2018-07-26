#include <stdlib.h>
#include "list.h"

List_t List_new (void *data, List_t tail)
{
  List_t p = malloc (sizeof (*p));
  p->data = data;
  p->next = tail;
  return p;
}

List_t Con_List (List_t head, List_t tail)
{
  List_t link_point = head;
  while((link_point) && (link_point->next)){
    link_point = link_point->next;
  }
  link_point->next = tail;
  return head;
}

List_t List_rev (List_t l)
{
  List_t p = 0;
  while (l){
    p = List_new (l->data, p);
    l = l->next;
  }
  return p;
}


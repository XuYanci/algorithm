//
//  XYCycleLinkList.c
//  XYAlogrithmExercise
//
//  Created by SUGAR Dev on 2020/9/27.
//  Copyright © 2020 Yanci. All rights reserved.
//

#include "XYCycleLinkList.h"

struct list_head {
    struct list_head *prev, *next;
};

/* Get an entry from the list
 *  ptr - the address of this list_head element in "type"
 *  type - the data type that contains "member"
 *  member - the list_head element in "type"
 */
#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member)

/* Get each entry from a list
 *  pos - A structure pointer has a "member" element
 *  head - list head
 *  member - the list_head element in "pos"
 *  type - the type of the first parameter
 */
#define list_for_each_entry(pos, head, member, type)            \
    for (pos = list_entry((head)->next, type, member);        \
         &pos->member != (head);                \
         pos = list_entry(pos->member.next, type, member))

#define list_for_each_entry_safe(pos, n, head, member, type)        \
    for (pos = list_entry((head)->next, type, member),        \
         n = list_entry(pos->member.next, type, member);    \
         &pos->member != (head);                \
         pos = n, n = list_entry(n->member.next, type, member))

#define list_empty(entry) ((entry)->next == (entry))

static inline void list_init(struct list_head *entry)
{
    entry->prev = entry->next = entry;
}

static inline void list_add(struct list_head *entry, struct list_head *head)
{
    entry->next = head->next;
    entry->prev = head;

    head->next->prev = entry;
    head->next = entry;
}

static inline void list_add_tail(struct list_head *entry,
    struct list_head *head)
{
    entry->next = head;
    entry->prev = head->prev;

    head->prev->next = entry;
    head->prev = entry;
}

static inline void list_del(struct list_head *entry)
{
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
    entry->next = entry->prev = NULL;
}

static inline void list_cut(struct list_head *list, struct list_head *head)
{
    if (list_empty(head))
        return;

    list->next = head->next;
    list->next->prev = list;
    list->prev = head->prev;
    list->prev->next = list;

    list_init(head);
}

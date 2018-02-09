#include <stdio.h>
#include <stdlib.h>

struct node {
    int from;
    int to;
    int len;
    struct node* next;
};

int city_num, road_num, c1, c2;
struct node* city[500] = { NULL };
struct node* stack[1000];
int top = 0;
int emerg[500];
int minlen = 99999999, maxemerg = 0;
int pathnum = 0;

struct node *init_node(int to);
struct node *choose_node(struct node *np);

int main(void)
{
    int i;
    struct node *np, *mp;
    int pathnum, emergnum, currlen, curremerg;

    while (scanf("%d %d %d %d", &city_num, &road_num, &c1, &c2) != EOF) {
    
        for (i = 0; i < city_num; i++) {
            scanf("%d", &emerg[i]);
        }
        for (i = 0; i < road_num; i++) {
            struct node *tmp1 = (struct node *)malloc(sizeof(struct node));
            struct node *tmp2 = (struct node *)malloc(sizeof(struct node));
            scanf("%d %d %d", &tmp1->from, &tmp1->to, &tmp1->len);
            tmp1->next = city[tmp1->from];
            city[tmp1->from] = tmp1;

            tmp2->from = tmp1->to;
            tmp2->to = tmp1->from;
            tmp2->len = tmp1->len;
            tmp2->next = city[tmp2->from];
            city[tmp2->from] = tmp2;
        }

        top = 0;
        pathnum = 0;
        emergnum = emerg[c1];
        currlen = 0;
        curremerg = emerg[c1];
        stack[top++] = city[c1];
        np = stack[top - 1];
        // printf("fdsfsd\n");
        while (top != 0) {
            if (np == NULL) {
                top--;
                if (top == 0) break;
                np = stack[top - 1];
                currlen -= np->len;
                curremerg -= emerg[np->to];
                np = choose_node(np->next);
                stack[top - 1] = np;
                continue;
            }
            if (np->to != c2) {
                mp = init_node(np->to);
                if (mp != NULL) {
                    stack[top++] = mp;
                    currlen += np->len;
                    curremerg += emerg[np->to];
                    np = mp;
                } else {
                    np = np->next;
                }
            } else {
                currlen += np->len;
                curremerg += emerg[c2];
                if (currlen < minlen) {
                    minlen = currlen;
                    pathnum = 1;
                    maxemerg = curremerg;
                } else if (currlen == minlen) {
                    pathnum++;
                    if (maxemerg < curremerg) maxemerg = curremerg;
                }

                currlen -= np->len;
                curremerg -= emerg[c2];
                top--;
                np = choose_node(np->next);
                stack[top++] = np;
            }
        }

        printf("%d %d\n", minlen, maxemerg);

        // free
        for (i = 0; i < city_num; i++) {
            np = city[i];
            while (1) {
                if (np != NULL) {
                    mp = np->next;
                    free(np);
                    np = mp;
                } else {
                    break;
                }
            }
        }
        memset(city, NULL, 500);
    }
    return 0;
}

struct node *init_node(int to)
{
    struct node *np = city[to];
    int i, j;
    int tag = 1;

    while (1) {
        for (j = 0; j < top; j++) {
            if (stack[j]->from == np->to) {
                tag = 0;
                break;
            }
        }
        if (tag == 0) {
            np = np->next;
            if (np == NULL) {
                return NULL;
            }
            tag = 1;
        } else {
            break;
        }
    }
    return np;
}

struct node *choose_node(struct node *np)
{
    int i;
    int tag = 1;
    if (np == NULL) {
        return NULL;
    }
    while (1) {
        for (i = 0; i < top; i++) {
            if (stack[i]->from == np->to) {
                tag = 0;
                break;
            }
        }
        if (tag == 0) {
            np = np->next;
            if (np == NULL) return NULL;
            tag = 1;
        } else {
            break;
        }
    }
    return np;
}
/**
 * problem.c
 * 
 * author: Duc
 * 
 * Algorithm Complexity: O(n)
 * 
 * */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "../lib/list.h"

int main()
{
    int test_case_number;
    scanf("%d", &test_case_number);

    while (test_case_number--)
    {
        int n;
        int k;
        int tmp;
        scanf("%d %d", &n, &k);
        bool delete_friend = false;

        list_t friend_list = create_linked_list();

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            friend_list.add_first(&friend_list, tmp);
        }

        for (int i = 0; i < (friend_list.size - 1); i++)
        {
            if (friend_list.get(&friend_list, i) < friend_list.get(&friend_list, i+1))
            {
                friend_list.list_remove(&friend_list, i);
                delete_friend = true;
                break;
            }
        }
        if (delete_friend == false)
        {
            friend_list.remove_last(&friend_list);
        }

        for (int i = 0; i < (friend_list.size); i++)
        {
            printf("%d ", friend_list.get(&friend_list, i));
        }
    }

    return 0;
}
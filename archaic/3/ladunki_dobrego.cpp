#include <bits/stdc++.h>
#define sizey 50
#define elif else if

using namespace std;

int siz, asks, in_a, in_b;
short graf[sizey][sizey];
short order[sizey];
short order_check[sizey];
int to_go[sizey];
int is_connected[sizey];
///int to_compare[sizey];
///int solve[sizey];
int * to_compare = new int[sizey];
int * solve = new int[sizey];
bool compare_solves(int * comp1, int * comp2)
{
    for(int i = 1; i < siz; ++i)
    {
        if(comp2[i] > comp1[i]) return true;
        if(comp2[i] < comp1[i]) return false;
    }
    return false;
}

void coping(int * to, int * from)
{
    for(int i = 0; i < siz; ++i)
    {
        to[i] = from[i];
    }
}

void do_change_if_less(int * com1, int * com2)
{
    if(compare_solves(com2, com1)) coping(com1, com2);
}

void solve_f(int * solve, int lvl = 1)
{
    int * comparable = new int[sizey];
    if(is_connected[order[lvl]] == 0)
    {
        solve[order[lvl]] = 1;
        if(lvl + 1 < siz)
        {
            coping(comparable, solve);
            solve_f(comparable, lvl + 1);
            do_change_if_less(solve, comparable);
        }
    }
    else
    {
        bool is[] = {false, false, false};
        int * solve_copy = new int[sizey];
        for(int i = 0; i < siz; ++i)
        {
            solve_copy[i] = solve[i];
            if(graf[order[lvl]][i] == 1)
            {
                if(solve[i] <= 3)
                {
                    is[solve[i] - 1] = true;
                }
            }
        }
        /*printf("%d ", lvl);
        for(int i = 0; i < siz; ++i)
        {
            printf("%c", 'A' - 1 + solve_copy[i]);
        }
        printf("\n");*/
        if (lvl + 1 >= siz)
        {
            if (!is[0]) solve[order[lvl]] = 1;
            else if (!is[1]) solve[order[lvl]] = 2;
            else if (!is[2]) solve[order[lvl]] = 3;
            else
            {
                solve[1] = 999;
            }
            //coping(solve, solve_copy);
        }
        else
        {
            coping(solve, to_compare);
            if(!is[0])
            {
                solve_copy[order[lvl]] = 1;
                coping(comparable, solve_copy);
                solve_f(comparable, lvl + 1);
                do_change_if_less(solve, comparable);
            }
            if(!is[1])
            {
                solve_copy[order[lvl]] = 2;
                coping(comparable, solve_copy);
                solve_f(comparable, lvl + 1);
                do_change_if_less(solve, comparable);
            }
            if(!is[2])
            {
                solve_copy[order[lvl]] = 3;
                coping(comparable, solve_copy);
                solve_f(comparable, lvl + 1);
                do_change_if_less(solve, comparable);
            }
        }
        delete [] solve_copy;
    }
    /*printf("X%d ", lvl);
    for(int i = 0; i < siz; ++i)
    {
        printf("%c", 'A' - 1 + solve[i]);
    }
    printf("\n");*/
    delete [] comparable;
}

int main()
{
    scanf("%d %d", &siz, &asks);
    for(int i = 0; i < asks; ++i)
    {
        scanf("%d %d", &in_a, &in_b);
        --in_a;
        --in_b;
        graf[in_a][in_b] = 1;
        graf[in_b][in_a] = 1;
        is_connected[in_a] = 1;
        is_connected[in_b] = 1;
    }
    ///order[0] = 0;
    order_check[0] = 1;
    for(int i = 0; i < siz; ++i)
    {
        to_go[i] = graf[0][i];
        solve[i] = 999;
        to_compare[i] = 999;
    }
    int ordering = 1;
    while(ordering < siz)
    {
        int i_want_there = -1;
        for(int i = 0; i < siz; ++i)
        {
            if(to_go[i] == 1 && order_check[i] == 0)
            {
                i_want_there = i;
                break;
            }
        }
        if(i_want_there == -1)
        {
            for(int i = 0; i < siz; ++i)
            {
                if(order_check[i] == 0)
                {
                    i_want_there = i;
                    break;
                }
            }
            if(i_want_there == -1) break;
        }
        order[ordering] = i_want_there;
        order_check[i_want_there] = 1;
        ++ordering;
        for(int i = 0; i < siz; ++i)
        {
            if(graf[i_want_there][i] == 1)
            {
                to_go[i] = 1;
            }
        }
    }
    /*for(int i = 0; i < siz; ++i)
    {
        printf("%d", order[i] + 1);
    }
    printf("\n");*/
    solve[0] = 1;
    solve_f(solve);
    bool j = true;
    for(int i = 0; i < siz; ++i)
    {
        if(solve[i] >= 10)
        {
            printf("NIE");
            j = false;
            break;
        }
    }
    if(j)
    {
        for(int i = 0; i < siz; ++i)
        {
            printf("%c", 'A' - 1 + solve[i]);
        }
    }
    delete [] solve;
    delete [] to_compare;
    return 0;
}

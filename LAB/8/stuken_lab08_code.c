#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRUCT_SIZE 32
#define MAXLEN 128

struct LNode
{
    int id;
    char *NAME;
    char *MANUFACTURER;      /**/
    int RAM;                 /*number of ram*/
    int NUMBER_OF_CORES;     /*number of cores in cpu*/
    float CPU_FREQUENCY;     /**/
    int STORAGE_CAPACITY[2]; /*capacity for each element of memory*/
    float PRICE;             /*price in thousands of rubles*/
    int WINDOWS_LICENSE_KEY[3];
    struct LNode *next;
};

struct LHead
{
    int count;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LNode Node;
typedef struct LHead Head;

Head *make_head()
{
    Head *ph = NULL;
    ph = (Head *)malloc(sizeof(Head));
    if (ph != NULL)
    {
        ph->count = 0;
        ph->first = NULL;
        ph->last = NULL;
    }
    return ph;
}

Node *create_node(char **str)
{
    Node *new_node = NULL;
    new_node = (Node *)malloc(sizeof(Node));
    if (new_node)
    {
        new_node->id = 1;
        new_node->NAME = str[0];
        new_node->MANUFACTURER = str[1];
        new_node->RAM = atoi(str[2]);
        new_node->NUMBER_OF_CORES = atoi(str[3]);
        new_node->CPU_FREQUENCY = atof(str[4]);
        new_node->PRICE = atof(str[5]);
        new_node->WINDOWS_LICENSE_KEY[0] = atoi(str[6]);
        new_node->WINDOWS_LICENSE_KEY[1] = atoi(str[7]);
        new_node->WINDOWS_LICENSE_KEY[2] = atoi(str[8]);
        new_node->next = NULL;
    }
    return new_node;
}

void add_first(Node *new_node, Head *my_head)
{
    if (my_head && new_node)
    {
        my_head->first = new_node;
        my_head->last = new_node;
        my_head->count++;
    }
}

Node *select_by_id(Head *my_head, int n)
{
    Node *q;
    int k;
    q = my_head->first;
    k = my_head->count; /* last node id */
    if ((n > 0) && (n <= k))
    {
        while ((q->id) != n)
            q = q->next;
    }
    else
        q = NULL;
    return q;
}

char **simple_split(char *str, int length, char sep)
{
    char **str_array = NULL;
    int i, j, k, m;
    int key, count;
    for (j = 0, m = 0; j < length; j++)
    {
        if (str[j] == sep)
            m++;
    }

    key = 0;
    str_array = (char **)malloc((m + 1) * sizeof(char *));
    if (str_array != NULL)
    {
        for (i = 0, count = 0; i <= m; i++, count++)
        {
            str_array[i] = (char *)malloc(length * sizeof(char));
            if (str_array[i] != NULL)
                key = 1;
            else
            {
                key = 0;
                i = m;
            }
        }
        if (key)
        {
            k = 0;
            m = 0;
            for (j = 0; j < length; j++)
            {
                if (str[j] != sep)
                    str_array[m][j - k] = str[j];
                else
                {
                    str_array[m][j - k] = '\0';
                    k = j + 1;
                    m++;
                }
            }
        }
    }
    return str_array;
}

void insert_after(Head *my_head, Node *new_node, Node *current_node)
{
    int n;
    if (my_head && new_node && current_node)
    {
        n = my_head->count + 1;
        if (current_node->next == NULL)
        {
            current_node->next = new_node;
            my_head->last = new_node;
        }
        else
        {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
        new_node->id = n;
        my_head->count = n;
    }
}

void print(Head *H){
    Node *S;
    S=H->first;
    for(int i=0;i<7;i++){
        printf("|%i|%s|%s|\n", S->id, S->NAME, S->MANUFACTURER);
        S=S->next;
    }
}

int main()
{
    Head *H = NULL;
    Node *S = NULL;
    Node *S0 = NULL;
    char s1[MAXLEN], **s2 = NULL, sep;
    int slen, number,position;
    FILE *fp;
    H = make_head();
    printf("enter id:\n");
    scanf("%i", &number);
    printf("enter position:\n");
    scanf("%i",&position);
    fp = fopen("data7.csv", "r");
    if (fp != NULL)
    {
        sep = ';';
        for (int i = 0; i < 6; i++)
        {
            fgets(s1, MAXLEN, fp);
            slen = strlen(s1);
            s1[slen - 1] = '\0';
            slen = strlen(s1);
            s2 = simple_split(s1, slen, sep);
            if (s2 != NULL)
            {
                S = create_node(s2);
                if (S0 == NULL)
                    H->first = S;
                else
                    S0->next = S;
                H->count++;
                S->id = H->count;
                S0 = S;
            }
            else
                puts("Error at data reading!");
        }
        H->last = S;
        fclose(fp);
    }
    Node *target_node = select_by_id(H,number);
    printf("%s\n",target_node->NAME);
    Node *node_after = select_by_id(H,position);
    printf("%s\n",node_after->NAME);
    insert_after(H,node_after,target_node);

    print(H);

    return 0;
}

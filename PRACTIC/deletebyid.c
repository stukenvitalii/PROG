void delete_by_id(Head *my_head, int id)
{
    Node *tmp = my_head->first;
    while (tmp)
    {
        if (tmp->id == id && tmp == my_head->first && tmp->next)
        {
            my_head->first = tmp->next;
        }
        else if (tmp->next && tmp->next->next && tmp->next->id == id)
        {
            tmp->next = tmp->next->next;
        }
        else if (tmp->next && tmp->next->id == id)
        {
            free(tmp->next);
            tmp->next = NULL;
        }
        tmp = tmp->next;
    }
}
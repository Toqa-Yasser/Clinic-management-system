struct node
{
    int id;
    string name, gender;
    short unsigned int age;
    node* next;
}; 
class patient {
    
    node *head;
public:
    patient()
    {
        head = NULL;
    }
    void create_new_node(int id, string name, string gender, int age)
    {
        node* new_item = new node;
        if (head == NULL)
        {
            new_item->id = id;
            new_item->name = name;
            new_item->gender = gender;
            new_item->age = age;
            new_item->next = NULL;
        }
        else
        {
            new_item->id = id;
            new_item->name = name;
            new_item->gender = gender;
            new_item->age = age;
            new_item->next = head;
        }
        head = new_item;
    }
    node * search(int id)
    {
        for (node* temp = head; temp != NULL; temp = temp->next)
        {
            if (id == temp->id)
            {
                return  temp;
            }
        }
        return NULL;
    }
    node* top()
    {
        return head;
    }
    void delete_node(int id)
    {
        node* temp;
        if (head->id==id)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
        for (temp = head; temp->next != NULL; temp = temp->next)
        {
            if (id == temp->next->id)
            {
                break;
            }
        }
        node* del;
        del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
};


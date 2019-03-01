#include <iostream>
#include <string>

using namespace std;

int id1 = 0;

class Symble_info
{
private:
    string name;
    string type;
public:
    int row, col;
    Symble_info *next;
    Symble_info *prev;
    Symble_info()
    {
        next = NULL;
        prev = NULL;
    }
    ~Symble_info()
    {
        delete next;
        delete prev;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }

    void setType(string type)
    {
        this->type = type;
    }
    string getType()
    {
        return type;
    }
};

int hash_func(string key, int size)
{
    int slot = 0;
    for(int i = 0; i < key.size(); i++)
    {
        slot += (int)key[i];
        slot = slot % size;
    }
    return slot;
}

class Scope_table
{
public:
    int id;
    Symble_info **curr, *table;
    Scope_table *parentScope;
    int *elem;
    int size;
    Scope_table(int n, int newid)
    {
        id = newid;
        size = n;
        elem = new int[n];
        curr = new Symble_info*[n];
        table = new Symble_info[n];
        for(int i = 0; i < n; i++)
        {
            elem[i] = 0;
            curr[i] = &table[i];
        }
        table[0].setName("header1");
        table[1].setName("header2");
        table[2].setName("header3");
        table[3].setName("header4");
        table[4].setName("header5");
        table[5].setName("header6");
        table[6].setName("header7");
        parentScope = NULL;
    }

    Symble_info* LookUp(string key)
    {
        int slot = hash_func(key, size);
        Symble_info *temp = NULL;
        for(temp = &table[slot]; temp->next != NULL; temp = temp->next)
        {
            if(temp->next->getName() == key)
            {
                return temp->next;
            }
        }
        return NULL;
    }

    bool Insert(string name, string type)
    {
        if(LookUp(name) != NULL)
        {
            cout << "<" << name << " , " << type << "> already exists in current ScopeTable\n";
            return false;
        }
        int slot = hash_func(name, size);
        Symble_info *obj = new Symble_info();
        obj->setName(name);
        obj->setType(type);
        obj->row = slot;
        obj->col = elem[slot];
        elem[slot]++;
        curr[slot]->next = obj;
        obj->prev = curr[slot];
        curr[slot] = curr[slot]->next;
        cout << "Inserted in Scope Table # " << id << " at position " << obj->row << ", " << obj->col << endl;
        return true;
    }

    bool Delete(string name)
    {
        Symble_info *temp = LookUp(name);
        if(temp != NULL)
        {
            if(temp->next != NULL)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

            }
            else if(temp->next == NULL)
            {
                temp->prev->next = NULL;
                curr[temp->row] = temp->prev;
            }
            elem[temp->row]--;
            cout << "Found in Scope Table # " << id << " at position : " << temp->row << ", " << temp->col << endl;
            cout << "deleted entry at " << temp->row << ", " << temp->col  << " from current scope table" <<  endl;
            return true;
        }
        else
        {
            cout << "NOT FOUND\n";
            cout << name << " NOT FOUND\n";
            return false;
        }
    }

    void Print()
    {
        cout << "Scope Table # " << id << endl;
        for(int i = 0; i < size; i++)
        {
            cout << i << " -->  ";
            Symble_info *temp = NULL;
            {
                for(temp = &table[i]; temp->next != NULL; temp = temp->next)
                {
                    cout << "< " << temp->next->getName() << " : " << temp->next->getType() << " >  ";
                }
            }
            cout << endl;
        }
    }
};

class Symbol_Table
{
public:
    Scope_table *currentScope;
    Symbol_Table()
    {
        currentScope = NULL;
    }
    ~Symbol_Table()
    {
        delete currentScope;
    }
    void EnterScope(int n)
    {
        id1++;
        Scope_table *block = new Scope_table(n, id1);
        if(id1 > 0)
        {
            block->parentScope = currentScope;
        }
        currentScope = block;
        if(id1 > 1)
            cout << "New scope with id " << id1 << " created\n";
    }
    void ExitScope()
    {
        Scope_table *temp = currentScope;
        cout << "ScopeTable with id " << id1 << " removed\n";
        id1--;
        if(id1 == 0)
        {
            currentScope = NULL;
        }
        else
        {
            currentScope = currentScope->parentScope;
        }
        delete [] temp;
    }
    bool Insert(string name, string type)
    {
        bool flag = currentScope->Insert(name, type);
        if(flag)
        {
            return true;
        }
        return false;
    }

    bool Remove(string key)
    {
        bool flag = currentScope->Delete(key);
        if(flag)
            return true;
        return false;
    }

    Symble_info *LookUp(string key)
    {

        Scope_table *temp = currentScope;
        int i = id1;
        while(i != 0)
        {
            Symble_info *found = temp->LookUp(key);
            if(found != NULL)
            {
                cout << "Found in Scope Table # " << currentScope->id << " at position : " << found->row << ", " << found->col << endl;
                return found;
            }
            i--;
            if(temp->parentScope != NULL)
                temp = temp->parentScope;
        }
        cout << "Not Found\n";
        return NULL;
    }
    void printCurrent()
    {
        currentScope->Print();
    }
    void printAll()
    {
        int i = id1;
        Scope_table *temp = currentScope;
        while(i != 0)
        {
            temp->Print();
            i--;
            temp = temp->parentScope;
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Symbol_Table *SymbolTable = new Symbol_Table();
    SymbolTable->EnterScope(n);
    char command;
    while(cin >> command)
    {
        string name, type;
        switch(command)
        {
        case 'I':
            cin >> name >> type;
            SymbolTable->Insert(name, type);
            break;
        case 'L':
            cin >> name;
            SymbolTable->LookUp(name);
            break;
        case 'D':
            cin >> name;
            SymbolTable->Remove(name);
            break;
        case 'P':
            char option;
            cin >> option;
            if(option == 'A')
            {
                SymbolTable->printAll();
                break;
            }
            else if(option == 'C')
            {
                SymbolTable->printCurrent();
                break;
            }
        case 'S':
            SymbolTable->EnterScope(n);
            break;
        case 'E':
            SymbolTable->ExitScope();
            break;
        }
    }

    return 0;
}



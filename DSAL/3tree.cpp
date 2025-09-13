//3 tree book chapters sections subsections

#include<iostream>
#include<string>
using namespace std;
struct node
{
    char name[20];
    int num;
    node* child[3];
};

class tree
{
    public:
    node *root;
    void creation();
    void display();
};

void tree::creation()
{
    node *nnode=new node;
    root=nnode;
    cout<<"enter book name: ";
    cin>>nnode->name;
    cout<<"enter number of chapters: ";
    cin>>nnode->num;

    for(int i=0;i<(nnode->num);i++)
    {
        (nnode->child[i])=new node;
        cout<<"enter name of chapter: ";
        cin>>nnode->child[i]->name;

        cout<<"enter number of section: ";
        cin>>nnode->child[i]->num;
        
        for(int j=0;j<(nnode->child[i]->num);j++)
        {
            (nnode->child[i]->child[j])=new node;
            cout<<"name of section: ";
            cin>>(nnode->child[i]->child[j])->name;
            cout<<"number of subsection: ";
            cin>>nnode->child[i]->child[j]->num;

            for(int k=0;k<(nnode->child[i]->child[j]->num);k++)
            {
                (nnode->child[i]->child[j]->child[k])=new node;
                cout<<"name of subsection: ";
                cin>>nnode->child[i]->child[j]->child[k]->name;
            }
        }
    }
}

void tree::display()
{
    node *nnode=new node;
    nnode=root;
    cout<<"book: "<<nnode->name<<endl;

    for(int i=0;i<(nnode->num);i++)
    {
        cout<<"\tchapter "<<i+1<<": "<<nnode->child[i]->name<<"\n";

        for(int j=0;j<(nnode->child[i]->num);j++)
        {
            cout<<"\t\tsection "<<j+1<<": "<<nnode->child[i]->child[j]->name<<"\n";

            for(int k=0;k<(nnode->child[i]->child[j]->num);k++)
            {
                cout<<"\t\t\tsubsection "<<k+1<<": "<<nnode->child[i]->child[j]->child[k]->name<<"\n";
            }
        }
    }
}
int main()
{
    tree t1;
    t1.creation();
    t1.display();
    return 0;
}
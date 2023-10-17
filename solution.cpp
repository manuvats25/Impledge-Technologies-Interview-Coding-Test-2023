#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int count;

struct Node
{
    struct Node *children[26];
    bool eow;
};

struct Node *getNode(void)
{
    struct Node *root = new Node;

    root->eow = false;

    for (int i = 0; i < 26; i++)
        root->children[i] = NULL;

    return root;
}

void insert(struct Node *root, string key)
{
    struct Node *curr = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
            curr->children[index] = getNode();

        curr = curr->children[index];
    }

    curr->eow = true;
}

bool search(struct Node *root, string key)
{
    struct Node *curr = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!curr->children[index])
            return false;

        curr = curr->children[index];
    }

    return (curr != NULL && curr->eow);
}

bool wordBreak(string key, Node *root)
{
    int size = key.length();
    if (size == 0)
        return true;
    for (int i = 1; i <= size; i++)
    {
        string FirstPart = key.substr(0, i);
        string SecPart = key.substr(i, size - 1);
        if (search(root, key.substr(0, i)) && wordBreak(SecPart, root))
        {
            count = count + 1;
            return true;
        }
    }

    return false;
}
int main()
{
    string filename = "textfile.txt"; // enter the file name

    string myText, first_ans = "", second_ans = "";
    struct Node *root = getNode();
    ifstream MyReadFile(filename);
    while (getline(MyReadFile, myText))
    {

        insert(root, myText);
    }
    MyReadFile.close();

    ifstream MyReadFiletocheck(filename);
    while (getline(MyReadFiletocheck, myText))
    {
        count = 0;
        wordBreak(myText, root);
        if (count > 1)
        {
            if (myText.length() > first_ans.length())
            {
                second_ans = first_ans;
                first_ans = myText;
            }
            else if (myText.length() > second_ans.length())
                second_ans = myText;
        }
    }
    MyReadFile.close();

    cout << "First Longest : " << first_ans << endl;
    cout << "Second Longest : " << second_ans << endl;

    return 0;
}
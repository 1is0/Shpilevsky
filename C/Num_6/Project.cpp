#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

struct Tree
{
    char* word;
     Tree* left;
     Tree* right;
    int amount;
};

void ToLowerCase(char*& str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
}

 void insert( char* word, Tree*& root)
 {
     if (root)
     {
         if (!strcmp(word, root->word))
         {
             root->amount++;
             return;
         }

         if (strcmp(word, root->word) < 0)
         {
             if (root->left)
             {
                 insert( word, root->left);
             }

             else
             {
                 root->left = (Tree*)malloc(sizeof(Tree));
                 root->left->amount = 1;
                 root->left->word = word;
                 root->left->left = NULL;
                 root->left->right = NULL;
             }
         }

         else
         {
             if (root->right)
             {
                 insert(word, root->right);
             }

             else
             {
                 root->right = (Tree*)malloc(sizeof(Tree));
                 root->right->amount = 1;
                 root->right->word = word;
                 root->right->left = NULL;
                 root->right->right = NULL;
             }
         }
     }

     else
     {
         Tree* item = (Tree*)malloc(sizeof(Tree));
         if (!item)
         {
             printf("Out of memory");
             exit(0);
         }

         item->left = NULL;
         item->right = NULL;
         item->word = word;
         item->amount = 1;

         root = item;
     }
 }

 void Delete(Tree* root)
 {  
     if (root)
     {
         Delete(root->left);
         Delete(root->right);
         free(root);
     }
}

void Print(struct Tree* root)
{
    if (!root) return;
    

    Print(root->left);
    if (root->word) printf("%s - %d\n", root->word, root->amount);
    Print(root->right);
}

void Size(Tree* node,int& count)
{
    if (!node)
        return ;
    Size(node->left,count);
    count++;
    Size(node->right,count);
}

Tree* MakeTree(int* arr, char** str, int first, int last)
{
    if (!last)
    {
        return nullptr;
    }

    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->amount = arr[first + last / 2];
    temp->word = str[first + last / 2];

    int lastl = last / 2;
    int lastr = last -lastl - 1;

    temp->left = MakeTree(arr, str, first, lastl);
    temp->right = MakeTree(arr, str, first + lastl + 1, lastr);
    return temp;

}

void ToArray(Tree* root, int* arr, char** str, int& index)
{
    if (root->left)
    {
        ToArray(root->left, arr, str, index);
    }

    str[index][strlen(root->word)] = '\0';
    strcpy(str[index], root->word);
    arr[index] = root->amount;

    index++;    
    if (root->right)
    {
        ToArray(root->right, arr, str, index);
    }

    for (int j = 0; j < index; j++)
    {
        for (int k = j + 1; k < index; k++)
        {
            if (arr[j] < arr[k])
            {
                int temp = arr[k];
                arr[k] = arr[j];
                arr[j] = temp;

                char* buf = str[k];
                str[k] = str[j];
                str[j] = buf;
            }
        }
    }
}

void Balance(Tree*& root)
{
    int amount = 0;
    Size(root, amount);
    int* arr = (int*)malloc((amount) * sizeof(int));
    char** temp = (char**)malloc((amount) * sizeof(char*));
    for (int i = 0; i < amount; i++)
    {
        temp[i] = (char*)malloc(20 * sizeof(char));
    }

    int size = 0;
    ToArray(root, arr, temp, size);


    Delete(root);

    root = MakeTree(arr, temp, 0, size);
   
}

void Task(FILE* file, Tree*& root)
{

    char* temp;

    int count = 0;
    rewind(file);
    while (!feof(file))
    {
        count++;
        char c = fgetc(file);
        if (c == ' ')
        {
            temp = (char*)malloc(count * sizeof(char));

            fseek(file, -count, SEEK_CUR);
            fgets(temp, count, file);

            temp[count - 1] = '\0';
            ToLowerCase(temp);

            insert(temp, root);

            //free(temp);
            count = 0;
            fgetc(file);
        }
        if (ispunct(c))
        {
            temp = (char*)malloc(count * sizeof(char));

            fseek(file, -count, SEEK_CUR);
            fgets(temp, count, file);

            temp[count - 1] = '\0';
            insert(temp, root);

            count = 0;
            fgetc(file);
            fgetc(file);
        }
    }

    Balance(root);
    Print(root);

    fclose(file);

    Delete(root);
   
}

int main()
{
    Tree* root = NULL;
    FILE* file = fopen("Text.txt","r");

    if (!file)
    {
        exit(1);
    }

    Task(file, root);
}

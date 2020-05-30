#include "invertedindex.h"
#include <QTextStream>
#include <QString>
#include <fstream>
#include <sstream>
#include <QDebug>
#include <QFile>
#include <QDir>
#include<string>

int fileNumber = 0;
extern QVector<QString> filesContent;

string InvertedIndex::search(string data)
{
    int depth = 0;
    node* temp = new node;
    temp = root;
    // Run the loop untill temp points to a NULL pointer
    while (temp != NULL)
    {
        depth++;
        if (temp->data == data)
        {
            set<string>::iterator it;
            string occurence = "This Word Occured in " + to_string(temp->filename.size()) + " files\n\n";
            occurence += "File Name\tFile Content\n\n";
            it = temp->filename.begin();
            while (it != temp->filename.end()) {
                occurence += *it + "\t" + filesContent[QString::fromStdString(*it).toInt()].toStdString() + "\n";
                it++;
            }
            temp = temp->left;
            return occurence;
        }
        // Shift pointer to left child.
        else if (temp->data > data)
            temp = temp->left;
        // Shift pointer to right child.
        else
            temp = temp->right;
    }
    return "Can't find word";
}
node* CreateNode(string data, string filenamee)
{
    node* newnode = new node;
    newnode->data = data;
    newnode->filename.insert(filenamee);
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}


node* InsertIntoTree(node* root, string data, string filename)
{
    // Create node using data from argument list.
    node* temp = CreateNode(data, filename);
    node* t = new node;
    t = root;

    // If root is null, assign it to the node created.
    if (root == NULL)
        root = temp;
    else
    {
        // Find the position for the new node to be inserted.
        while (t != NULL)
        {
            if (t->data < data)
            {
                if (t->right == NULL)
                {
                    // If current node is NULL then insert the node.
                    t->right = temp;
                    break;
                }
                // Shift pointer to the left.
                t = t->right;
            }

            else if (t->data > data)
            {
                if (t->left == NULL)
                {
                    // If current node is NULL then insert the node.
                    t->left = temp;
                    break;
                }
                // Shift pointer to the left.
                t = t->left;
            }
            else {

                t->filename.insert(filename);

                break;
            }
        }
    }
    return root;
}
void InvertedIndex::addFile(string file)
{
    vector<string> lines;
    string currentLine;
    for(unsigned int i = 0 ; i<(file.length()-1);i++)
    {
        if(file[i]==' ') {
            if(currentLine[currentLine.length() - 1] == '?')
                currentLine = currentLine.substr(0, currentLine.length() - 1);
            lines.push_back(currentLine);
            currentLine="";
        }
        else currentLine+=file[i];
    }
    lines.push_back(currentLine);
    string fileNumberStr= to_string(fileNumber);
    for(unsigned int i = 0 ; i<lines.size(); i++)
        {root = InsertIntoTree(root, lines[i], fileNumberStr);}
    fileNumber++;
}



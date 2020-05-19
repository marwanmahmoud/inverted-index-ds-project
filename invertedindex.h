#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include <set>

using namespace std;

struct node
{
    string data;
    set<string> filename;
    node* left;
    node* right;
};


class InvertedIndex
{
public:
    node* root = new node;

    void addFile(string filename);
    void show_files();
    string search(string word);


    InvertedIndex() {
        root = NULL;
    }
};
node* InsertIntoTree(node* root, string data, string filename);

node* CreateNode(string data, string filenamee);

#endif // INVERTEDINDEX_H

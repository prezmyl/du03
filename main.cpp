#include <fstream>
#include "HashTable.hpp"

using namespace std;

void readFile(const string &fileName, HashTable &ht,  int defValue);



int main()
{
    const int defValue = 1;
    HashTable ht;

    readFile("words.txt", ht, defValue);
    
    ht.Print();
    ht.Clear();

    return 0;
}






void readFile(const string &fileName, HashTable &ht,  int defValue)
{
    string token;

    ifstream fin(fileName);
    if (!fin.is_open())
    {   
        cerr << "file cannot be opened" << endl;
        return;
    }


    while (fin >> token)
    {
        ht.Insert(token, defValue);

    }

    fin.close();
}
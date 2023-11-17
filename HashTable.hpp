#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <iomanip>

using namespace std;

class HashTable{

    private:
        vector<list<map<string, int>>> table;
        size_t size;
        static size_t defSize;

        size_t Hash(string key) const;

    public:
        HashTable();
        HashTable(int size);
        void Insert(const string Key, const int Value);
        bool ContainsKey(const string Key)const;
        void Remove(const string Key);
        bool TryGetValue(const string Key, int& Value)const;
        int Count()const;
        int Size()const;
        double Alpha()const;
        void Clear();
        
        void Print();

};
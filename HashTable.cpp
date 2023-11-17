#include "HashTable.hpp"


size_t HashTable::defSize = 10019;

HashTable::HashTable() : size(defSize), table(defSize) {}

HashTable::HashTable(int size) : size(size), table(size) {}



size_t HashTable::Hash(string key) const
{
    size_t hash = 5381;

    for (auto &c : key)
    {
        hash = ((hash << 5) + hash) + c;
    }
    
    return hash % this->size;
}



void HashTable::Insert(const string Key, const int Value)
{
  
    //index
    size_t index = Hash(Key);    //index vectoru

    if (this->ContainsKey(Key))
    {   
        for (auto& map : table[index]) //element je map deli se pres list, kt. je dany vector.at(slot), coz obsahuje prvni list
        {
            auto pair = map.find(Key); // pair na map elemnt nalezeneho klice
            if (pair != map.end())
            {
                (pair->second)++;
            }
            
            
        }
 
    }
    else
    {
        table[index].push_back({{Key, Value}});
    }
    
}


void HashTable::Remove(const string Key)
{
    size_t index = Hash(Key); //slot
    
    if (this->ContainsKey(Key))
    {
        for (auto &map : this->table[index]) //element je map prochazi se pres listy<map<>>, kt. je dany vector.at(slot), coz obsahuje prvni list
        {
            auto pair = map.find(Key); // pair na map elemnt nalezeneho klice
            if (pair != map.end())
            {
                map.erase(pair);
            }
            
        }
    }
}




bool HashTable::ContainsKey(const string Key) const
{
    size_t index = Hash(Key); //slot

    for (auto &map : this->table[index]) //element je map prochazi se pres listy<map<>>, kt. je dany vector.at(slot), coz obsahuje prvni list
    {
        if (map.find(Key) != map.end())
        {
            return true;
        }
        
    }

    return false;

}



bool HashTable::TryGetValue(const string Key, int &Value) const
{
    size_t index = Hash(Key);

    for (auto &map : this->table[index])
    {
        auto pair = map.find(Key);
        if (pair != map.end())
        {
            Value = pair->second;
            return true;
        }
        
    }

    return false;
}



int HashTable::Count()const
{
    int count = 0;

    for( auto &&list : this->table){
        count += list.size();
    }

    return count;
}

int HashTable::Size() const
{
    return this->table.size();
    
}


double HashTable::Alpha() const
{
    return (Size() == 0) ? 0.0 : static_cast<double>(Count()) / Size();
}

void HashTable::Clear()
{
    this->table.clear();
    this->table.resize(this->size);
}



void HashTable::Print()
{
    for (auto &&list : table)
    {
        for (auto &map : list )
        {
            
            for (auto pair : map)
            {
                cout << "|"  << "Key: "<< setw(15)  << pair.first << " | " << "freq: " << setw(5) << pair.second << "|" <<endl;
            }
            
        }
        
        
    }
    
}

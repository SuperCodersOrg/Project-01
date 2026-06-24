#include <iostream>
#include <string>
#include <HashMap>

using namespace std;

struct IntHash
{
    size_t operator()(int key) const
    {
        return key * 31;
    }
};

struct CharHash
{
    size_t operator()(char c) const
    {
        return c;
    }
};

int main()
{
    cout << "===== TEST 1 : 1000 INSERTS =====\n";

    HashMap<int,int,IntHash> map;

    for(int i=0;i<1000;i++)
    {
        map.insert(i,i*10);
    }

    cout << "Size: " << map.size() << endl;
    cout << "Bucket Count: " << map.bucketCount() << endl;
    cout << "Load Factor: " << map.loadFactor() << endl;
    cout << "Collisions: " << map.collisions() << endl;

    cout << "\n===== TEST 2 : 1000 GETS =====\n";

    bool pass = true;

    for(int i=0;i<1000;i++)
    {
        int value;

        if(!map.get(i,value) || value!=i*10)
        {
            pass = false;
            cout << "Failed at key " << i << endl;
            break;
        }
    }

    cout << (pass ? "PASS" : "FAIL") << endl;

    cout << "\n===== TEST 3 : 1000 UPDATES =====\n";

    for(int i=0;i<1000;i++)
    {
        map.insert(i,i*100);
    }

    pass = true;

    for(int i=0;i<1000;i++)
    {
        int value;

        if(!map.get(i,value) || value!=i*100)
        {
            pass = false;
            cout << "Update failed at key " << i << endl;
            break;
        }
    }

    cout << (pass ? "PASS" : "FAIL") << endl;

    cout << "\n===== TEST 4 : 1000 REMOVES =====\n";

    for(int i=0;i<1000;i++)
    {
        map.remove(i);
    }

    cout << "Size after removals: "
         << map.size()
         << endl;

    cout << "Empty: "
         << map.isEmpty()
         << endl;

    cout << "\n===== TEST 5 : REHASHING =====\n";

    HashMap<int,int,IntHash> rehashMap(2);

    for(int i=0;i<500;i++)
    {
        rehashMap.insert(i,i);
    }

    cout << "Size: "
         << rehashMap.size()
         << endl;

    cout << "Bucket Count: "
         << rehashMap.bucketCount()
         << endl;

    pass = true;

    for(int i=0;i<500;i++)
    {
        int value;

        if(!rehashMap.get(i,value) || value!=i)
        {
            pass = false;
            cout << "Rehash failed at key "
                 << i
                 << endl;
            break;
        }
    }

    cout << (pass ? "PASS" : "FAIL") << endl;

    cout << "\n===== TEST 6 : COPY CONSTRUCTOR =====\n";

    HashMap<int,int,IntHash> copyMap(rehashMap);

    pass = true;

    for(int i=0;i<500;i++)
    {
        int value;

        if(!copyMap.get(i,value) || value!=i)
        {
            pass = false;
            break;
        }
    }

    cout << (pass ? "PASS" : "FAIL") << endl;

    copyMap.insert(9999,9999);

    cout << "Original Exists: "
         << rehashMap.exists(9999)
         << endl;

    cout << "Copy Exists: "
         << copyMap.exists(9999)
         << endl;

    cout << "\n===== TEST 7 : ASSIGNMENT OPERATOR =====\n";

    HashMap<int,int,IntHash> assignMap;

    assignMap = rehashMap;

    pass = true;

    for(int i=0;i<500;i++)
    {
        int value;

        if(!assignMap.get(i,value) || value!=i)
        {
            pass = false;
            break;
        }
    }

    cout << (pass ? "PASS" : "FAIL") << endl;

    assignMap.insert(8888,8888);

    cout << "Original Exists: "
         << rehashMap.exists(8888)
         << endl;

    cout << "Assigned Exists: "
         << assignMap.exists(8888)
         << endl;

    cout << "\n===== TEST 8 : STRING VALUES =====\n";

    HashMap<int,string,IntHash> students;

    students.insert(1,"Garv");
    students.insert(2,"Nilesh");
    students.insert(3,"Aman");

    string name;

    students.get(1,name);
    cout << name << endl;

    students.get(2,name);
    cout << name << endl;

    students.get(3,name);
    cout << name << endl;

    cout << "\n===== TEST 9 : CHAR KEYS =====\n";

    HashMap<char,string,CharHash> grades;

    grades.insert('A',"Excellent");
    grades.insert('B',"Good");
    grades.insert('C',"Average");

    grades.get('A',name);
    cout << name << endl;

    grades.get('B',name);
    cout << name << endl;

    grades.get('C',name);
    cout << name << endl;

    cout << "\n===== ALL TESTS COMPLETED =====\n";

    return 0;
}
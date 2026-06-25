#include <iostream>
#include <HashMap>

using namespace std;

int main()
{
    struct stud{
        string name;
        string rollno;
        stud(string name,string rollno):name(name),rollno(rollno){}
    bool operator==(const stud& other) const
    {
        return rollno == other.rollno;
    }
    };
stud garv("g","1");
stud gar("ga","2");
stud ga("gar","2");
HashMap<stud,int> map;
map.insert(garv,1);
map.insert(gar,2);
map.insert(ga,2);
map.debugPrint();
}
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
    struct StudHash
{
    size_t operator()(const stud& s) const
    {
        return DefaultHash<std::string>()(
            s.rollno
        );
    }
};
    stud grv("grv","101");
    stud gv("gv","102");
    stud v("v","103");
    stud g("g","104");
    HashMap<stud,int,StudHash> garv;
    garv.insert(g,1);
    garv.insert(gv,1);
    garv.insert(v,1);
    garv.insert(grv,1);
    garv.debugPrint();
    cout<<garv.collisions();
}
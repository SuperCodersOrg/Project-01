#include <DynamicArray>
#include <iostream>

using namespace std;

int main()
{
    DynamicArray<string> d;
    DynamicArray<string> e;
    cout<<d.size()<<" ";
    cout<<d.capacity();
    d.print();
    d.append("garv");
    d.append("garv1");
    d.append("garv2");
    d.append("garv3");
    d.append("garv4");
    d.append("garv5");
    d.print();
    cout<<d.size()<<" ";
    cout<<d.capacity();
    cout<<endl;
    e=d;
    e.print();
    DynamicArray<int> a;
    a.append(1);
    a.append(1);
    a.append(1);
    a.append(1);
    a.append(1);
    a.append(5);
    a.append(10);
    a.append(10);
    a.append(10000000);
    a.print();
}
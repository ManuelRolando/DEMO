#include<vector>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    vector<string>* v = new vector<string>;
    v->push_back("hello");
    v->push_back("glozanoa");
    vector<string>::iterator iter;
    for(iter = v->begin(); iter != v->end(); iter++)
    {
        cout << "size(" << *iter << ") : " << iter->size() << endl;
    }
}

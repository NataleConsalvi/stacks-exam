#include <iostream>
#include "NatsTasks.h"

using std::vector;

int main() {

    std::unordered_map <char, vector<char>> subtasks = {
        {'a',{'b','g'}},
        {'b',{'c','d','e'}},
        {'c',{'f'}},
        {'d',{'g'}},
        {'e',{}},
        {'f',{}},
        {'g',{}}
    };

    Stack stack = Stack();
    const char c = 'a';
    vector<char> task = stack.execute(c, subtasks);
    cout << "-----Task to do in order-------" << endl;
    cout << stack.vec2str(task) << endl;

}

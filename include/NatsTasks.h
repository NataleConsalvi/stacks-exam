#ifndef NATSTASKS_H
#define NATSTASKS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using std::unordered_map;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


class Stack{
    private:
        vector<char> tasks;
        int size;
    
    public:
        Stack(){
            this->tasks = vector<char> ();
            this->size = 0;
        }

        bool is_empty() const{
            if(this->size == 0){
                return true;
            }
            return false;
        }

        void push(const char& c){
            this->tasks.push_back(c);
            this->size++;
        }

        char pop(){
            char ret = this->tasks[size -1];
            this->tasks.pop_back();
            this->size--;
            return ret;
        }

        char get_tail(){
            return this->tasks[size-1];
        }

        string as_string() const{
            stringstream s;
            s << "  Stack: [";
            for(char now : this->tasks){
                s << now << ", ";
            }
            string ss = s.str();
            if(this->size > 0){
                ss.resize(ss.size() - 2);
            }
            ss += "]";
            return ss;
        }

        string vec2str(const vector<char>& vec) const{
            stringstream s;
            s << "[";
            for(char now : vec){
                s << now << ", ";
            }
            string ss = s.str();
            if(vec.size() > 0){
                ss.resize(ss.size() - 2);
            }
            ss += "]";
            return ss;
        }

        vector<char> execute(const char task, const unordered_map<char, vector<char>>& subtasks){

            vector<char> ret;
            this->push(task);
            while(this->size != 0){
                
                char doing = this->pop();
                ret.push_back(doing);
                vector<char> sub = subtasks.at(doing);
                cout << "Debug: doing task '" << doing << "' = " << vec2str(sub) << endl;

                for(int i = sub.size() - 1; i > -1; i--){
                    this->push(sub[i]);
                }
                cout << this->as_string() << endl;
            }
            return ret;
        }
        
};







#endif //NATSTASKS_H
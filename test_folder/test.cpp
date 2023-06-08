#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct my_string_compare {
    bool operator()(string str1, string str2) const {
        int n1 = str1.length(), n2 = str2.length();
 
        if (n1 < n2)
            return true;
        if (n2 < n1)
            return false;
    
        for (int i = 0; i < n1; i++)
            if (str1[i] < str2[i])
                return true;
            else if (str1[i] > str2[i])
                return false;
    
        return false;
    }
    bool operator()(int a, int b) const {
       return a<=b;
    }
};

template<typename T>
struct select_less {
    using type = std::less<T>;
};


template<typename T>
using my_less = typename select_less<T>::type;

int main(){
    // my_less<string> char_less;
    set<string> st;
    st.insert("XYZ");
    st.insert("ABCD");

    for(auto x:st){
        cout<<x<<endl;
    }

    // if (char_less("hi","ii")) {
    //      cout<<"Hello";
    // }

    // my_less<int> int_less;

    // // Same as std::less<int>
    // if (int_less(7, 9)) {
    //     // ...
    // }
}
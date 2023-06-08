// C++ program to illustrate the passing
// of functions as an object parameter
#include <functional>
#include <iostream>
using namespace std;

// Define add and multiply to
// return respective values
int add(int x, int y)
{
	return x - y;
}
int multiply(int x, int y)
{
	return x * y;
}

bool compare(string str1,string str2){
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

// Function that accepts an object of
// type std::function<> as a parameter
// as well
template<typename T1>
class A{
    public:
    int add(int x, int y)
    {
        return x + y;
    }
    int multiply(int x, int y)
    {
        return x * y;
    }
    bool isEqual(int x,int y){
       return x==y;
    }
    bool isEqual(float x,float y){
       return x==y;
    }
    bool isEqual(double x,double y){
       return x==y;
    }
    bool isEqual(string str1,string str2){
       int n1 = str1.length(), n2 = str2.length();
 
        if (n1 < n2 || n2 < n1)
            return false;
    
        for (int i = 0; i < n1; i++)
            if (str1[i] < str2[i])
                return false;
            else if (str1[i] > str2[i])
                return false;
    
        return true;
    }
    int invoke(T1 x, T1 y,
            function<bool(T1, T1)> func)
    {
        return func(x, y);
    }
};

// Driver code
int main()
{
	// Pass the required function as
	// parameter using its name
    A<string> obj;
	cout << obj.invoke("hi", "He",compare);


	return 0;
}

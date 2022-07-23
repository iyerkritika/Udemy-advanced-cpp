#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#include<ctype.h>

using namespace std;

vector<int> array;
void enterArray()
{
    signed char input;
    array.clear();
    //Size of Array is Max 30 min 5 only numbers
    //have to type q to finish
    while(1)
    {
        cout<<"Enter an element to put in the array. Q/q to quit, s, S to print array\n";
        cin>>input;
        if(isalpha(input))
        {
            if(input =='q' || input =='Q')
            {
                if(array.size()<5)
                {
                    throw string("Cant have array size less than 5\n");
                }
                return;
            }
            if(input =='s' || input =='S')
            {
//                if(array.size()<5)
//                {
//                    throw string("Cant have array size less than 5\n");
//                }
                for(int i =0; i < array.size();i++)
                {
                    cout<<array[i];
                }
                return;
            }
            throw input;
        }
        if((int)input<48)
        {
            throw ((int)input - 47);
        }
        if(array.size()==30)
        {
            throw string("Can't have array size greater than 30\n");
        }
        array.push_back(input-48);
    }
}

int main()
{
    try
    {
        enterArray();
    }
    catch (int e)
    {
        cout<<"Cant enter : "<<e<< " into the array";
    }
    catch(signed char e)
    {
        cout<<"cant have letters in the array like :" << e<<endl;
    }
    catch(string &e)
    {
        cout<<e;
    }
}

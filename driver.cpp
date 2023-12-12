#include "ass2.cpp"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    ExtendedArray obj(5);
    obj.appendElement(20);
    obj.appendElement(60);
    obj.appendElement(80);
    obj.appendElement(40);
    obj.rotate();
    return 0;
}
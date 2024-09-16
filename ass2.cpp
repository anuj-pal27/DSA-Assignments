#include "array structure.cpp"

class ExtendedArray : public array
{
public:
    ExtendedArray(int);
    int greatest();
    void sort();
    int smallest();
    int sum();
    int Average();
    void rotate();
};
ExtendedArray::ExtendedArray(int cap) : array(cap){};
void ExtendedArray::rotate(){
    int temp;
    for(int i=countElement()-1;i>0;i--){
        temp=getElementbyIndex(i);
        edit(i,getElementbyIndex(i-1));
        edit(i-1,temp);
    }
    for(int i=0;i<countElement();i++){
        cout<<" "<<getElementbyIndex(i);
    }
}
int ExtendedArray::greatest()
{
    int min;
    if (isEmpty())
    {
        cout << "Array is Empty";
        return -1;
    }
    min = getElementbyIndex(0);
    for (int i = 1; i < countElement(); i++)
    {
        if (min < getElementbyIndex(i))
            min = getElementbyIndex(i);
    }
    return min;
}

void ExtendedArray::sort()
{
    int var1, var2, temp;
    if (isEmpty())
    {
        cout << "Array is Empty";
    }
    for (int i = 0; i < countElement(); i++)
    {
        for (int j = i + 1; j < countElement(); j++)
        {
            if (getElementbyIndex(i) > getElementbyIndex(j))
            {
                temp = getElementbyIndex(i);
                edit(i, getElementbyIndex(j));
                edit(j, temp);
            }
        }
    }
    for (int i = 0; i < countElement(); i++)
    {
        cout << " " << getElementbyIndex(i);
    }
}

int ExtendedArray::smallest()
{
    int max;
    if (isEmpty())
    {
        cout << "Array is Empty";
        return -1;
    }
    max = getElementbyIndex(0);
    for (int i = 1; i < countElement(); i++)
    {
        if (max > getElementbyIndex(i))
            max = getElementbyIndex(i);
    }
    return max;
}
int ExtendedArray::sum()
{
    int sum = 0;
    for (int i = 0; i < countElement(); i++)
    {
        sum = sum + getElementbyIndex(i);
    }
    return sum;
}
int ExtendedArray::Average()
{
    int avg;
    avg = sum() / countElement();

    return avg;
}
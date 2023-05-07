#include <iostream>
using namespace std;


template <typename T>class data {
public:
    data() {
        number = 0;
        numbers = 10;
        temp = new T[10];
    }
    ~data() {
        delete temp;
    }
    int AddItem(T aData)
    {
        if(number <= numbers)
        {
            temp[number] = aData;
            number++;
        }
        else
        {
            numbers++;
            T* p = new T[numbers],*pr = temp;
            for(int i = 0;i<numbers-1;i++)
                p[i] = temp[i];
            p[number] = aData;
            number++;
            delete pr;
            temp = p;
        }
        return number-1;
    }
    bool RemoveAt(int index)
    {
        if(index >= number || index < 0)
            return false;
        else if(index == number-1)
        {
            number--;
            return true;
        }
        else
        {
            number--;
            for(int i = index;i<number;i++)
                temp[i] = temp[i+1];
            return true;
        }
    }
    void InsertItem(int index,T aData)
    {
        if(index >number || index < 0 || number >= numbers)
            cout<<"error"<<endl;
        else if(index == number)
        {
            temp[number] = aData;
            number++;
        }
        else
        {
            for(int i = number;i>index;i--)
                temp[i] = temp[i-1];
            temp[index] = aData;
            number++;
        }
    }
    void SelectSort()
    {
        T tt;
        int p;
        for(int j = 0;j<number;j++)
        {
            p = j;
            for(int k = j;k<number;k++)
            {
                if(temp[k] < temp[p])
                    p = k;
            }
            tt = temp[p];
            temp[p] = temp[j];
            temp[j] = tt;
        }
    }
    void show()
    {
        for(int i = 0;i<number;i++) {
            cout << temp[i];
            cout <<" ";
        }
        cout<<endl;
    }
private:
    int number, numbers;
    T *temp;
};

class Point{
public:
    Point()
    {
        x = y = 0.0;
    }

    Point& operator=(const Point& p)
    {
        if(this == &p)return *this;
        x = p.x;
        y = p.y;
        return *this;
    }
    bool operator < (const Point& p)
    {
        if(x > p.x && y > p.y)
            return false;
        else
            return true;
    }
    friend void operator<<(ostream& os, const Point& p);
    friend void operator>>(istream& os, Point& p);
private:
    float x,y;
};
void operator<<(ostream& os, const Point& p)
{
    cout<<"x="<<p.x<<" "<<"y="<<p.y;
}
void operator>>(istream& os, Point& p)
{
    cin>>p.x;
    cin>>p.y;
}


template <typename T>
void test(data<T> a)
{
    T t;
    for(int i = 0;i<10;i++)
    {
        cin>>t;
        a.AddItem(t);
    }
    a.show();
    a.RemoveAt(9);
    a.show();
    cout<<"input:";
    cin>>t;
    a.InsertItem(4,t);
    a.show();
    a.SelectSort();
    a.show();
}

int main() {

    data<int> a;
    test(a);
    data<float> b;
    test(b);

    data<string> c;
    test(c);
    data<Point> d;
    test(d);


    return 0;
}

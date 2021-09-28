#include <iostream>
using namespace std;
class Image {
int* img;
int ax, ay;
public:
    Image(int tax, int tay) :ax(tax), ay(tay) {
    img = new int[ax * ay]();}
    virtual ~Image() {
    delete[] img;
    }
    int get(int x, int y) {
    if (x >= ax || y >= ay || x < 0 || y < 0) {
        throw 1;
    }
    return img[y * ay + x];
    }
    int set(int x, int y, int color) {
        if (x >= ax || y >= ay || x < 0 || y < 0) {
    throw 1;
        }
    img[y * ay + x] = color;
    }
    void operator=(const Image& v) {
  delete[] this->img;
    this->ax = v.ax;
    this->ay = v.ay;
    img = new int[ax * ay];
    for (int i = 0; i < ax * ay; i++) {
    this->img[i] = v.img[i];
    }
    }
};
int main() {
    try
    {
    Image frst(2, 2);
    frst.set(0, 0, 1);
    frst.set(1, 0, 2);
    frst.set(0, 1, 3);
    frst.set(1, 1, 4);
    Image scnd(1, 1);
    scnd = frst;
    cout << scnd.get(0, 0) << endl;
    cout << scnd.get(1, 0) << endl;
    cout << scnd.get(0, 1) << endl;
    cout << scnd.get(1, 1) << endl;
    scnd.set(3, 3, 1);
    }
catch (int)
{
cout << "Out of range" << endl;
}
}
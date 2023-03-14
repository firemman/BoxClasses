#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int Random(int min, int max) {
    return min + rand() % (max - min);
}

class Box {
public:
    Box() {}
    Box(int a, int b) { this->a = a; this->b = b; }
    Box(int a, int b, int c) : Box(a, b) { this->c = c; }

    void setA(int a) { this->a = a; }
    void setB(int b) { this->b = b; }
    void setC(int c) { this->c = c; }

    int boxArea() { return a * b * c; }

    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }

    void setBox() {
        a = Random(1, 10);
        b = Random(1, 10);
        c = Random(1, 10);
    }

    void getInfo() {
        cout << "длина " << getA() << ", ширина " << getB() << ", высота " << getC() << ". Площадь = " << boxArea() << "; \n";
    }

protected:
    int a, b, c;
};

class FtBox : public Box {
public:
    FtBox() {}
    FtBox(int a, int b, int c) : Box(a, b) { this->c = 0; }
    
    void setBox() {
        a = Random(1, 10);
        b = Random(1, 10);
        c = 0;
    }

    void getInfo() {
        cout << "длина " << getA() << ", ширина " << getB() << ", высота " << getC() << ". Площадь = " << boxArea() << "; \n";
    }

    int boxArea() { return a * b; }
};

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    cout << "Введите количество коробок: ";
    int N;
    cin >> N;

    Box* arr = new Box[N];
    int ftCnt = Random(1, N);
    FtBox* arrFt = new FtBox[ftCnt];
    
    cout << "Нормальные коробки: \n";

    for (int i = 0; i < N; i++) {
        arr[i].setBox();
        cout << "Коробка " << i + 1 << ": ";
        arr[i].getInfo();
    }

    cout << "\nВ процессе транспортировки сплюснулось некоторое количество коробок: \n";

    for (int i = 0; i < ftCnt; i++) {
        arrFt[i].setBox();
        cout << "Коробка " << N + i + 1 << ": ";
        arrFt[i].getInfo();
    }

    Box maxBox = arr[0];
    int markMax = 0;
    cout << "\n";

    for (int i = 0; i < N; i++) {
        if (arr[i].getA() > maxBox.getA() && arr[i].getB() > maxBox.getB() && arr[i].getC() > maxBox.getC()) {
            maxBox = arr[i];
            markMax = i;
        }
    }

    cout << "Самая большая коробка под номером (" << markMax + 1 << "),\nЕё размеры: ";
    maxBox.getInfo();
}
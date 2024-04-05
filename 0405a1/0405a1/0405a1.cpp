#include <iostream>
using std::cout; // cout 사용시 std:: 생략 가능
using std::sin; // cin 사용시 std:: 생략 가능
class point {

private:
    int x, y;

public:
    point(int a, int b) : x(a), y(b)
    {
        //x = a; y = b; 위의 : x(a), y(b)을 이니셜라이저를 사용하여 생략 가능
    }
    double Dist(point p)
    {
        int dx = p.x - x;
        int dy = p.y - y;
        double d = sqrt(dx * dx + dy * dy);
        return d;
    }
    point operator+(point p) // retrun(p1 + p2)
    {
         int nx = x + p.x;
         int ny = y + p.y;
         point np(nx, ny);
         return np;
    }
    point Add(point p) // point operator+와 같은 함수
    {
        int nx = x + p.x;
        int ny = y + p.y;
        point np(nx, ny);
        return np;
    }
    void Info()
    {
        cout << "(" << x << "," << y << ")"; //(x,y) 출력
    }
};

int main()
{
    point p1(10, 10), p2(30, 30);

    cout << "p1";  p1.Info();
    cout << "과 p2"; p2.Info();
    cout << "의 거리는 " << p1.Dist(p2) << "입니다.\n";
    cout << "\np1 + p2는 p"; (p1 + p2).Info();
    cout << "\np2 + p1은 p"; (p2 + p1).Info();
    //(p1 + p2).Info(); operator+ 로 했을경우 아래와 같은{p1.Add(p2).Info();} 의미를 가진다.
    //p1.Add(p2).Info(); add 함수 사용
    //p2.x = 50; private에 x가 있어 접근할수 없기때문에 에러가 나온다.

}


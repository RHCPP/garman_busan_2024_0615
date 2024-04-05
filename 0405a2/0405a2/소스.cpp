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
    point operator++(int) // retrun p1++ 후행연산
    {
        point rp(x, y);

        x++;
        y++;

        return rp;
    }
    point operator++() // retrun p1++ 선행연산
    {
        x++;
        y++;

        return *this;
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
    cout << "\np1++의 결과는 p"; (p1++).Info(); // 후행연산으로 계산 전 값인 10,10이 출력
    cout << "\n++p1의 결과는 p"; (++p1).Info(); // 앞에 후행결산으로 11,11인 상태에서 선행결산으로 12,12가 되서 출력
   
}
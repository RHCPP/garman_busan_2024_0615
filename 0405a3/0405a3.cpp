//#define SQUARE(X) ((X)*(X)) // 대문자로 쓰는 일이 많다. 
                            //그리고 안전성을 위해 괄호()를 아끼지않고 전부 씌워준다. 이것이 매크로 함수이다.
//#define PI 3.14159265
//#define ABS(X) (((X)<0)? (-X) : (X))
// 여기까지가 C level의 단계 복잡한 것은 만들 수 없음. C++에선 탬플릿화를 사용

//int abs(int val)
//{
    //int ret = (val < 0) ? -val : val; //여기서 ?가 삼항 연산자이다
    //return ret;
    //if (val < 0) return -val;
    //return val; 위와 같은 함수임

//}
#include <iostream>
using std::cout; // cout 사용시 std:: 생략 가능
using std::cin; // cin 사용시 std:: 생략 가능
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

//area(int x1, int x2, int y1, int y2) // 면적계산(x1, y1),(x2,y2)
//{
//    return (x2 - x1) * (y2 - y1);
//}

template <typename T> // datatyoe에 독립적인 함수 정의
T area(T x1, T y1, T x2, T y2)
{
    return (x2 - x1) * (y2 - y1);
}
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

    cout << "\n면적계산(정수) (10, 10, 30, 30) = " << area(10, 10, 30, 30);
    cout << "\n면적계산(정수) (10, 10, 30, 30) = " << area(10.0, 10.0, 30.0, 30.0);
}
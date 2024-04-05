#include <iostream>
using std::cout; // cout ���� std:: ���� ����
using std::sin; // cin ���� std:: ���� ����
class point {

private:
    int x, y;

public:
    point(int a, int b) : x(a), y(b)
    {
        //x = a; y = b; ���� : x(a), y(b)�� �̴ϼȶ������� ����Ͽ� ���� ����
    }
    double Dist(point p)
    {
        int dx = p.x - x;
        int dy = p.y - y;
        double d = sqrt(dx * dx + dy * dy);
        return d;
    }
    point operator++(int) // retrun p1++ ���࿬��
    {
        point rp(x, y);

        x++;
        y++;

        return rp;
    }
    point operator++() // retrun p1++ ���࿬��
    {
        x++;
        y++;

        return *this;
    }
    void Info()
    {
        cout << "(" << x << "," << y << ")"; //(x,y) ���
    }
};

int main()
{
    point p1(10, 10), p2(30, 30);

    cout << "p1";  p1.Info();
    cout << "�� p2"; p2.Info();
    cout << "�� �Ÿ��� " << p1.Dist(p2) << "�Դϴ�.\n";
    cout << "\np1++�� ����� p"; (p1++).Info(); // ���࿬������ ��� �� ���� 10,10�� ���
    cout << "\n++p1�� ����� p"; (++p1).Info(); // �տ� ���������� 11,11�� ���¿��� ���������� 12,12�� �Ǽ� ���
   
}
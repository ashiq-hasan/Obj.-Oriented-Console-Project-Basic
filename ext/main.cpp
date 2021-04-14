#include <iostream>

using namespace std;
class Vector3d
{
private:
    static  const  unsigned  int dim = 3;
    double component [dim];
public:
    Vector3d ()
    {
        for (int i = 0; i<3;i++)
        {
            component[i] = 0.0;
        }
    }

    friend  Vector3d operator-(Vector3d& x)
    {
        for (int i = 0; i<3;i++)
        {
            x.component[i] = - x.component[i];
        }
    }

    friend  Vector3d operator-(const Vector3d& x, const Vector3d& y)
    {
        Vector3d diff;
        for (int i = 0; i<3;i++)
        {
            diff.component[i] = x.component[i] - y.component[i];
        }
        return diff;

    }

    friend istream& operator>>(istream& in, Vector3d& x)
    {
        for (int i = 0; i<3;i++)
        {
            in >> x.component[i];
        }
        return in;
    }

    friend  ostream& operator<<(ostream& out, Vector3d& x)
    {
        out<<endl;
        for (int i = 0; i<3;i++)
        {
            out<<x.component[i]<<endl;
        }
        return out;

    }
};

int main(void)
{
    Vector3d v1, v2, v3;
    cout<< "input v2: "<< endl;
    cin>> v2;
    v3 = -v2;
    cout<< " v1 = "<< v1<< endl;
    cout<< " v2 = "<< v2<< endl;
    cout<< " v3 = "<< v3<< endl;

    cout<<"v2 -v3 = "<< <<endl;
}
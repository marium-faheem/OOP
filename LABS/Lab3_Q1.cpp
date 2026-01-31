#include<iostream>
using namespace std;
class Copy{
    private:
        int *real;
        int *imag;
    public:
        Copy(int r, int i){
            real = new int;
            imag = new int;
            *real = r;
            *imag = i;
        }
        //copy contruct (deep)
        Copy(const Copy &obj){
            real = new int;
            imag = new int;
            *real = *(obj.real);
            *imag = *(obj.imag);
        }
        void display(){
            cout<<"Complex Number: "<<*real<<"+"<<*imag<<"i"<<endl;
        }
        ~Copy(){
            delete real;
            delete imag;
        }
};
int main(){
    Copy Complex1(3,4);
    Copy Complex2 = Complex1;

    cout<<"Object 1: ";
    Complex1.display();

    cout<<"Object 2(copied): ";
    Complex2.display();
    return 0;
}
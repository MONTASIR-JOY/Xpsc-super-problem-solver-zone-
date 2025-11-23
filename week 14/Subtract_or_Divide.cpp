#include<bits/stdc++.h>
using namespace std;
class Product{
    public:
    string name;
    double price;
    Product(string s="",double k=0) : name(s) , price(k) {}
    double operator + (const Product &a){
        double k;
        k = a.price + price;
        return k;
    }
    //virtual void calculate() = 0;
    //friend void display();
};
class Electronics : public Product{
    public:
    string type;
    Electronics(string s="",double k=0, string f="") : Product(s,k) , type(f) {}
    virtual void calculate(){
        price+=(price*0.15);
    }
    virtual void calculate()
    {
        price += (price * 0.15);
    }
    friend void display(Electronics &a){
        cout << a.name << "-> final price : " << a.price << endl;
    }
    friend void display(Electronics &a)
    {
        cout << a.name << ": " << a.price << endl;
    }
};
class Grocery : public Product{
    public:
    string type;
    Grocery(string s="",double k=0 , string f="") : Product(s,k) , type(f) {}
    virtual void calculate(){
        price+=(price*0.05);
    }
    friend void display(Grocery &a){
        cout << a.name << "-> final price : " << a.price << endl;
    }
};
template<class T>
T highest(vector<T> &v) {
    return *max_element(v.begin(), v.end());
}
template<class T>
T highest(vector<T>&v)
{
    return *max_element(v.begin(), v.end());
}
int main(){
    fstream file;
    fstream File;
    int n; cin >> n;
    vector<double>p;
    File.open("hehe1.txt",ios::in);
    file.open("hehe1.txt", ios::in);
    // for(int i = 0 ;i < n; i++){
    //     string s,k;
    //     double m;
    //     cin >> s >> m >> k;
    //     File << s << " " << m << " " << k << "\n"; 
    // }
    //File.seekg(0);
    vector<Product>v;
    vector<Electronics>v1;
    vector<Grocery>v2;
    string s,k;
    double m;
    while(File >> s >> m >> k){
        if(k=="Electronics"){
            Electronics fin(s,m,k);
            fin.calculate();
            v1.push_back(fin);
            p.push_back(fin.price);
        }
        else{
            Grocery fin(s,m,k);
            fin.calculate();
            v2.push_back(fin);
            p.push_back(fin.price);
        }
        Product fi(s,m);
        v.push_back(fi);
        //p.push_back(m);
    }
    double max_price = highest(p);
    double first_two = v[0] + v[1];
    File.close();
    File.open("NEW.txt",ios::out);
    for(auto c : v1){
        // cout << c.display() << endl;
        //Electronics siuu = c;
        display(c);
        File << c.name << " " << c.price << " " << c.type << "\n";
    }
    for(auto c : v2){
        display(c);
        File << c.name << " " << c.price << " " << c.type << "\n";
    }
    cout << max_price << endl << first_two << endl;
    return 0;
}
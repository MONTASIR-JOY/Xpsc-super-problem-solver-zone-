#include <bits/stdc++.h>
using namespace std;

//reza
class Product {
    int id, stock;
    string name;
    double price;

public:
    Product(int a=0,string n="",double b=0,int s=0)
        : id(a),name(n),price(b),stock(s){}

    ~Product() {}

    int getid()
    {
        return id;
    }
    string getname()
    {
        return name;
    }
    double getprice()
    {
        return price;
    }
    int getstock()
    {
        return stock;
    }

    void addstock(int a)
    {
        stock+=a;
    }
    void removestock(int a)
    {
        if (a<=stock)
            stock-=a;
    }

    void savefile(ofstream &fout)
    {
        fout<<id<<" "<<name<<" "<<price<<" "<<stock<<"\n";
    }

    void display()
    {
        cout<<"ID: "<<id<<", Name: "<<name<<", Price: "<<price<<", Stock: "<<stock<<endl;
    }

    friend Product loadOne(ifstream &fin);
    friend class Inventory;

    // operator+ - merge stocks when adding same product
    Product operator+(const Product &p)
    {
        Product temp;
        temp.id = id;
        temp.name = name;
        temp.price = price;
        temp.stock = stock + p.stock;
        return temp;
    }

    friend void showProductSummary(Product &p);
};

Product loadOne(ifstream &fin)
{
    int id, stock;
    string name;
    double price;
    if(fin>>id>>name>>price>>stock)
        return Product(id,name,price,stock);
    return Product();
}

void showProductSummary(Product &p)
{
    cout<<"[Product] "<<p.name<<", ID: "<<p.id<<", Stock: "<<p.stock<<endl;
}

class Inventory
{
    Product products[100];
    int co;
public:
    Inventory():co(0){}

    void addproduct(Product p)
    {
        if(co<100)
            products[co++]=p;
    }

    Product* findprod(int id)
    {
        for(int i=0;i<co;i++)
        {
            if(products[i].getid()==id)
                return &products[i];
        }
        return nullptr;
    }

    void saveprod()
    {
        ofstream fout("products.txt");
        for(int i=0;i<co;i++)
        {
            products[i].savefile(fout);
        }
    }

    void loadprod()
    {
        ifstream fin("products.txt");
        co=0;
        while(fin)
        {
            Product p=loadOne(fin);
            if(fin.eof())
                break;
            addproduct(p);
        }
    }

    void showproducts(bool showAll=false)
    {
        cout<<"\n--- List of Products ---\n";
        for(int j=0;j<co;j++)
        {
            if(!showAll && products[j].getstock()==0)
                continue;
            cout<<products[j].getid()<<" "<<products[j].getname()<<" $"<<products[j].getprice()
                 <<" Available: "<<(products[j].getstock()==0?"Out of Stock":to_string(products[j].getstock()))<<endl;
        }
    }

    void showAllProducts()
    {
        cout<<"\n--- All Products (Including Out of Stock) ---\n";
        for(int j=0;j<co;j++)
        {
            cout<<products[j].getid()<<" "<<products[j].getname()<<" $"<<products[j].getprice()
                 <<" Stock: "<<products[j].getstock()<<endl;
        }
    }
};

//shuvo
class Customer
{
    string name;
    int pin;
public:
    Customer(string n="",int p=0):name(n),pin(p){}
    string getName()
    {
        return name;
    }
    int getPin()
    {
        return pin;
    }
    void saveToFile(ofstream &fout)
    {
        fout<<name<<" "<<pin<<"\n";
    }

    static Customer loadOne(ifstream &fin)
    {
        string n;
        int p;
        return (fin >> n >> p) ? Customer(n,p) : Customer();
    }

    // operator== - verify customer credentials (name and pin match)
    bool operator==(const Customer &other)
    {
        return (name == other.name && pin == other.pin);
    }

    friend void showCustomer(Customer &c);
};

void showCustomer(Customer &c)
{
    cout<<"Customer: "<<c.name<<", PIN: "<<c.pin<<endl;
}

//joy
class CartItem
{
    string name;
    double price;
    int quantity;
public:
    CartItem():name(""),price(0),quantity(0){}

    CartItem(string n,double p,int q):name(n),price(p),quantity(q){}

    double getTotal()
    {
        return price*quantity;
    }
    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }
    int getQuantity()
    {
        return quantity;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    void show()
    {
        cout<<name<<"("<<quantity<<") - "<<price<<" each, Total: "<<getTotal()<<endl;
    }

    // operator+= - increase quantity when same item added again
    CartItem& operator+=(int qty)
    {
        quantity += qty;
        return *this;
    }
};

class Cart
{
    CartItem items[20];
    int count;
public:
    Cart():count(0){}

    void addItem(string n,double p,int q)
    {
        // Check if item already exists
        for(int i=0;i<count;i++)
        {
            if(items[i].getName()==n)
            {
                items[i] += q; // operator+= to add quantity
                return;
            }
        }
        // Add new item if not exists
        if(count<20)
            items[count++]=CartItem(n,p,q);
    }

    void show()
    {
        for(int i=0;i<count;i++)
        {
            items[i].show();
        }
    }

    int getCount()
    {
        return count;
    }

    CartItem* getItems()
    {
        return items;
    }

    friend void showCartSummary(Cart &c);
};

void showCartSummary(Cart &c)
{
    cout<<"[Cart Summary] Total items: "<<c.getCount()<<endl;
}

//samin
class Payment
{
    string customerName;
    double amount;
    string method;
public:
    Payment(string name="Guest",double amt=0.0):customerName(name),amount(amt),method("N/A"){}

    void setAmount(double amt)
    {
        amount = amt;
    }

    double getAmount()
    {
        return amount;
    }

    void payBkash(double amt,string mob)
    {
        amount=amt;
        method="Bkash";
        processPayment();
    }
    void payNagad(double amt,string mob)
    {
        amount=amt;
        method="Nagad";
        processPayment();
    }
    void payCard(double amt,string card,bool emi=false,int months=0)
    {
        amount=amt;
        method="Card";
        processPayment();
    }
    void processPayment()
    {
        cout<<"[Processing "<<method<<"] Amount: "<<amount<<" for "<<customerName<<endl;
    }

    // operator- - apply discount to payment amount
    Payment operator-(double discount)
    {
        Payment temp = *this;
        temp.amount = amount - discount;
        if(temp.amount < 0) temp.amount = 0;
        return temp;
    }

    friend void showPaymentInfo(Payment &p);
};

void showPaymentInfo(Payment &p)
{
    cout<<"[Payment Info] "<<p.customerName<<", Amount: "<<p.amount<<endl;
}

//fahad
class Order
{
    int orderId;
    string customerName;
    Cart cart;
    string status;
    double totalAmount;
public:
    Order(int id=0,string cname="",Cart c=Cart(),double amt=0):orderId(id),customerName(cname),cart(c),status("PENDING"),totalAmount(amt){}

    void setStatus(string s)
    {
        status=s;
    }

    int getId() { return orderId; }

    double getTotalAmount() { return totalAmount; }

    void saveToFile(const string &filename)
    {
        ofstream outFile(filename,ios::app);
        outFile<<"Order ID: "<<orderId<<"\nCustomer: "<<customerName<<"\nStatus: "<<status<<"\nTotal Amount: "<<totalAmount<<"\nItems:\n";
        for(int i=0;i<cart.getCount();i++)
        {
            CartItem it = cart.getItems()[i];
            outFile<<it.getName()<<"("<<it.getQuantity()<<") - "<<it.getPrice()<<" each, Total: "<<it.getTotal()<<"\n";
        }
        outFile<<"---\n";
    }

    // operator++ (prefix) - increment order status (PENDING -> PROCESSING -> SHIPPED -> DELIVERED)
    Order& operator++()
    {
        if(status == "PENDING")
            status = "PROCESSING";
        else if(status == "PROCESSING")
            status = "SHIPPED";
        else if(status == "SHIPPED")
            status = "DELIVERED";
        return *this;
    }

    friend void showOrderSummary(Order &o);
};

void showOrderSummary(Order &o)
{
    cout<<"[Order] ID: "<<o.orderId<<", Customer: "<<o.customerName<<", Status: "<<o.status<<endl;
}

//samad
class Admin
{
    string username,password;
    int loginAttempts;
public:
    Admin():username("admin"),password("Admin1234"),loginAttempts(0){}

    bool login()
    {
        string u,p;
        cout<<"Enter username: ";
        cin>>u;
        cout<<"Enter password: ";
        cin>>p;

        bool success = (u==username && p==password);
        if(!success)
            ++(*this); // operator++ to increment login attempts
        else
            loginAttempts = 0; // reset on successful login

        return success;
    }

    void change_user_pass()
    {
        cout<<"Enter new username: ";
        cin>>username;
        cout<<"Enter new password: ";
        cin>>password;
        cout<<"Username & password changed successfully\n";
    }

    int getLoginAttempts()
    {
        return loginAttempts;
    }

    // operator++ (prefix) - increment failed login attempts
    Admin& operator++()
    {
        loginAttempts++;
        return *this;
    }

    friend void showAdminInfo(Admin &a);
};

void showAdminInfo(Admin &a)
{
    cout<<"[Admin] "<<a.username<<", Failed attempts: "<<a.loginAttempts<<endl;
}



int main()
{
    Inventory store;
    store.loadprod();
    Admin admin;
    static int orderCounter = 1;

    // Store registered customers
    vector<Customer> registeredCustomers;

    while (true)
    {
        cout << "\n--- Digital Shop Menu ---\n";
        cout << "1. Customer\n2. Admin\n3. Exit\n";
        cout << "Enter your choice: ";
        int mainChoice;
        cin >> mainChoice;
        cin.ignore();

        if (mainChoice == 1)
        {
            char continueCustomer = 'y';
            while (continueCustomer == 'y' || continueCustomer == 'Y')
            {
                string cname;
                int pin;

                cout << "\n1. Register New Customer\n2. Login as Existing Customer\nChoice: ";
                int custChoice;
                cin >> custChoice;
                cin.ignore();

                Customer cust;
                bool isRegistered = false;

                if(custChoice == 1)
                {
                    cout << "Enter your name: ";
                    getline(cin, cname);
                    cout << "Create a PIN: ";
                    cin >> pin;
                    cin.ignore();
                    cust = Customer(cname, pin);
                    registeredCustomers.push_back(cust);
                    cout << "Registration successful!\n";
                    isRegistered = true;
                }
                else
                {
                    cout << "Enter your name: ";
                    getline(cin, cname);
                    cout << "Enter your PIN: ";
                    cin >> pin;
                    cin.ignore();

                    Customer loginAttempt(cname, pin);

                    // operator== - verify customer credentials
                    for(auto &reg : registeredCustomers)
                    {
                        if(reg == loginAttempt)
                        {
                            cust = reg;
                            isRegistered = true;
                            cout << "Login successful!\n";
                            break;
                        }
                    }

                    if(!isRegistered)
                    {
                        cout << "Invalid credentials! Please register first.\n";
                        continue;
                    }
                }

                Cart cart;

                char more = 'y';
                while (more == 'y' || more == 'Y')
                {
                    cout << "\nAvailable Products:\n";
                    store.showproducts();

                    int pid, qty;
                    cout << "\nEnter product ID to add to cart: ";
                    cin >> pid;
                    cin.ignore();

                    Product *p = store.findprod(pid);
                    if (p)
                    {
                        if (p->getstock() == 0)
                            cout << "Out of stock!\n";
                        else
                        {
                            cout << "Enter quantity: ";
                            cin >> qty;
                            cin.ignore();

                            if (qty <= p->getstock())
                            {
                                // operator+= (CartItem) - adds to existing item quantity if item already in cart
                                cart.addItem(p->getname(), p->getprice(), qty);
                                p->removestock(qty);
                                cout << qty << " " << p->getname() << "(s) added to cart.\n";
                            }
                            else
                                cout << "Not enough stock!\n";
                        }
                    }
                    else
                        cout << "Product not found!\n";

                    cout << "Add more products to cart? (y/n): ";
                    cin >> more;
                    cin.ignore();
                }

                cout << "\nYour cart:\n";
                cart.show();

                double totalAmount = 0;
                for (int i = 0; i < cart.getCount(); i++)
                    totalAmount += cart.getItems()[i].getTotal();

                cout << "\nTotal Amount: $" << totalAmount << endl;

                // Check if customer qualifies for discount
                char applyDiscount;
                cout << "Do you have a discount code? (y/n): ";
                cin >> applyDiscount;
                cin.ignore();

                Payment payment(cust.getName(), totalAmount);

                if(applyDiscount == 'y' || applyDiscount == 'Y')
                {
                    string code;
                    cout << "Enter discount code: ";
                    getline(cin, code);

                    if(code == "SAVE10")
                    {
                        // operator- (Payment) - apply 10% discount
                        payment = payment - (totalAmount * 0.10);
                        cout << "10% discount applied! New amount: $" << payment.getAmount() << endl;
                        totalAmount = payment.getAmount();
                    }
                    else if(code == "SAVE20")
                    {
                        // operator- (Payment) - apply 20% discount
                        payment = payment - (totalAmount * 0.20);
                        cout << "20% discount applied! New amount: $" << payment.getAmount() << endl;
                        totalAmount = payment.getAmount();
                    }
                    else
                    {
                        cout << "Invalid discount code!\n";
                    }
                }

                cout << "\nSelect payment method:\n1. Bkash\n2. Nagad\n3. Card\nChoice: ";
                int methodChoice;
                cin >> methodChoice;
                cin.ignore();

                if (methodChoice == 1)
                {
                    string mob;
                    cout << "Enter mobile number: ";
                    getline(cin, mob);
                    payment.payBkash(totalAmount, mob);
                }
                else if (methodChoice == 2)
                {
                    string mob;
                    cout << "Enter mobile number: ";
                    getline(cin, mob);
                    payment.payNagad(totalAmount, mob);
                }
                else if (methodChoice == 3)
                {
                    string card;
                    char emiChoice;
                    int months = 0;
                    cout << "Enter card number: ";
                    getline(cin, card);
                    cout << "Pay via EMI? (y/n): ";
                    cin >> emiChoice;
                    cin.ignore();
                    if (emiChoice == 'y')
                    {
                        cout << "Enter months: ";
                        cin >> months;
                        cin.ignore();
                        payment.payCard(totalAmount, card, true, months);
                    }
                    else
                        payment.payCard(totalAmount, card);
                }

                Order order(orderCounter++, cust.getName(), cart, totalAmount);

                // operator++ (Order) - move order through status progression
                ++order; // PENDING -> PROCESSING
                cout << "Order status updated: PROCESSING\n";

                order.setStatus("PAID");
                order.saveToFile("orders.txt");
                store.saveprod();

                cout << "\nThank you for shopping! Your order has been placed.\n";
                cout << "Continue as customer? (y/n): ";
                cin >> continueCustomer;
                cin.ignore();
            }
        }
        else if (mainChoice == 2)
        {
            // Check if too many failed attempts
            if(admin.getLoginAttempts() >= 3)
            {
                cout << "Too many failed login attempts! Admin access locked.\n";
                cout << "Please restart the program.\n";
                continue;
            }

            if (admin.login())
            {
                char continueAdmin = 'y';
                while (continueAdmin == 'y' || continueAdmin == 'Y')
                {
                    int adminChoice;
                    cout << "\n--- Admin Menu ---\n1. Change username/password\n2. Add new product\n3. Update product stock\n4. View all products\n5. Exit Admin\nEnter your choice: ";
                    cin >> adminChoice;
                    cin.ignore();

                    if (adminChoice == 1)
                        admin.change_user_pass();
                    else if (adminChoice == 2)
                    {
                        int id, stock;
                        string name;
                        double price;

                        cout << "Enter product ID: ";
                        cin >> id;
                        cin.ignore();
                        cout << "Enter product name: ";
                        getline(cin, name);
                        cout << "Enter product price: ";
                        cin >> price;
                        cout << "Enter product stock: ";
                        cin >> stock;
                        cin.ignore();

                        Product newProd(id, name, price, stock);
                        Product *existing = store.findprod(id);

                        if (existing)
                        {
                            cout << "Product already exists. Merging stock...\n";
                            // operator+ (Product) - merge stocks
                            *existing = *existing + newProd;
                        }
                        else
                        {
                            store.addproduct(newProd);
                            cout << "Product added successfully.\n";
                        }

                        store.saveprod();
                    }
                    else if (adminChoice == 3)
                    {
                        int id, qty;
                        cout << "Enter product ID to update stock: ";
                        cin >> id;
                        cin.ignore();
                        Product *p = store.findprod(id);
                        if (p)
                        {
                            cout << "Enter additional stock to add: ";
                            cin >> qty;
                            cin.ignore();
                            // operator+ (Product) - add stock
                            *p = *p + Product(p->getid(), p->getname(), p->getprice(), qty);
                            store.saveprod();
                            cout << "Stock updated successfully.\n";
                        }
                        else
                            cout << "Product not found!\n";
                    }
                    else if (adminChoice == 4)
                    {
                        store.showAllProducts();
                    }
                    else if (adminChoice == 5)
                        break;
                    else
                        cout << "Invalid choice!\n";

                    cout << "Continue as admin? (y/n): ";
                    cin >> continueAdmin;
                    cin.ignore();
                }
            }
            else
            {
                // operator++ (Admin) was called inside login() to increment attempts
                cout << "Wrong username or password! Attempts: " << admin.getLoginAttempts() << "/3\n";
            }
        }
        else if (mainChoice == 3)
        {
            cout << "Exiting... Goodbye!\n";
            break;
        }
        else
            cout << "Invalid choice! Try again!\n";
    }

    return 0;
}

#include <iostream>
#include <set>

class Employee
{
    public:
        explicit Employee (int id, std::string const& name): id_(id), name_(name) {}
        int getID () const { return id_;}
        std::string getName () const { return name_;}

    private:
        int id_;
        std::string name_;
};

class compareID
{
    public:
    using is_transparent = void ;
    bool operator() (Employee const& em1, Employee const& em2) const
    {
        return em1.getID () < em2.getID ();
    }

    bool operator() (int id, Employee const& em1) const
    {
        return id < em1.getID ();
    }

    bool operator() (Employee const& em1, int id) const
    {
        return em1.getID () < id;
    }
};

int main ()
{
    std::set<Employee, compareID> emps = { Employee(1, "john"), Employee(2, "ben") };

    std::cout << emps.find(2)->getName () << std::endl;
    return 0;
}

/*
 * To debug the construction of shared ptr references,
 * watch the memory address 8bytes before the
 * address of the managed object (works on gcc).
 * gdb will break as the ref count changes and the code
 * responsible for sp construction can be found
 * looking at the backtrace
 */
#include <iostream>
#include <vector>
#include <memory>
int main ()
{
    std::vector< std::shared_ptr<int> > myvec;

    myvec.reserve (10);

    int i = 0;
    std::shared_ptr<int> p = std::make_shared<int>(12);

    for ( unsigned int i = 0; i < 10 ; ++i)
    {
        myvec.push_back (p);
    }

    std::cout << p.use_count () << std::endl;
    return 0;
}

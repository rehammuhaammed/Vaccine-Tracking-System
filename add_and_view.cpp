#include <queue>
#include <iostream>
#include "User.h"
#include "admin.h"
using namespace std;

int main()
{
    User l1;   
    l1.add_record_writeFiles();
    l1.mainmenu();
    l1.add_record_readFiles();

    return 1;
    
}


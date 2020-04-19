#include <stdio.h>
#include <stdlib.h>

#include <iostream> // std::cout
#include <thread>   // std::thread

void thread_task() {
    std::cout << "hello thread" << std::endl;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{   
    std::cout << "before call thread" << std::endl;
    std::thread t(thread_task);
    std::cout << "after call thread" << std::endl;
    std::cout << "before call thread join" << std::endl;
    t.join();
    std::cout << "after call thread join" << std::endl;


    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> sptr1;
    {
        std::cout << sptr1.use_count() << std::endl;
        sptr1 = std::make_shared<int>(100);
        std::cout << *sptr1 << " " << sptr1.use_count() << std::endl;
        {
            std::shared_ptr<int> sptr2(sptr1);
            std::cout << *sptr1 << " " << sptr1.use_count() << std::endl;
            std::cout << *sptr2 << " " << sptr2.use_count() << std::endl;
        }
        std::cout << *sptr1 << " " << sptr1.use_count() << std::endl;
    }
    std::cout << sptr1.use_count() << std::endl;
    
    return 0;
}
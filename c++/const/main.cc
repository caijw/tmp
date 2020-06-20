#include <iostream>

class CTextBlock {
public:
    CTextBlock(char* pText)
    : pText(pText) {

    }
    char& operator[] (std::size_t position) const {
        return pText[position];
    }
    char* pText;
};


int main() {
    char text[6] = "hello";
    const CTextBlock cctb(text);
    char *pc = &cctb[0];
    *pc = 'J';
    std::cout << cctb.pText << std::endl;
    return 0;
}
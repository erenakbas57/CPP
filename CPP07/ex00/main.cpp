#include "whatever.hpp"

// int main()
// {
//     {
//         int a = 2;
//         int b = 3;
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         swap(a, b);
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         std::cout << "min(a, b) = " << min(a, b) << std::endl;
//         std::cout << "max(a, b) = " << max(a, b) << std::endl;
//     }
//     {
//         std::string a = "chaine1";
//         std::string b = "chaine2";
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         swap(a, b);
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         std::cout << "min(a, b) = " << min(a, b) << std::endl;
//         std::cout << "max(a, b) = " << max(a, b) << std::endl;
//     }
//     {
//         float a = 2.2f;
//         float b = 3.3f;
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         swap(a, b);
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         std::cout << "min(a, b) = " << min(a, b) << std::endl;
//         std::cout << "max(a, b) = " << max(a, b) << std::endl;
//     }
//     {
//         double a = 2.2;
//         double b = 3.3;
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         swap(a, b);
//         std::cout << "a = " << a << ", b = " << b << std::endl;
//         std::cout << "min(a, b) = " << min(a, b) << std::endl;
//         std::cout << "max(a, b) = " << max(a, b) << std::endl;
//     }
//     return 0;
// }


int main( void ) { 
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0; 
}
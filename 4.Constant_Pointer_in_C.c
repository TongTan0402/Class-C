
#include <stdio.h>
#include <stdlib.h>  
/*
 int * const     // không thể thay đổi địa trị được gán ban đầu
 const int * ptr // có thể trỏ đến địa chỉ khác, ngoài địa chỉ ban đầu

( int * const prt)
    - có thể thay đổi, đọc được giá trị của biến (hằng) và biến (thường)
    - không thể trỏ đến địa chỉ của biến khác.
(const int * ptr)
    - chị đọc không thể sửa một biến const hoặc biến thường
    - có thể trỏ đến một biến khác, không bị cố định
(int const * const ptr)
    - chỉ đọc không thể sửa một biến hằng, hoặc biến thường
    - chỉ được trỏ đến một địa chỉ khơi tạo, không được trỏ dến địa chỉ khác
1.( int * const) cách khai báo một con tro hằng: <data type> * const <pointer name> = <memory address>;
2.( int * const) lỗi khơi tạo con trỏ hằng, khi khơi tạo con trỏ hằng thì phải trỏ đến một biến hoặc một vùng nhớ cụ thể, nếu k sẽ báo lỗi ( int * const)
3.( int * const) lỗi khi đã trỏ đến một địa chỉ rồi thì k được thay đổi nữa ( int * const)
4.( int * const) một con trỏ hẳng vẫn có thể đọc và ghi giá trị trong vùng nhớ mà nó trỏ đến bình thưởng ( int * const)

5. không nên dùng một con trỏ thưởng trỏ đến một biến const, vì nó có thể thay đổi giá trị của biến const đó
6. nếu không dùng con trỏ thường để thay đổi giá trị. mà cố tình thay đổi giá trị biến đó sẽ bị lỗi

7. (const int *)các sử dụng đúng con trỏ hằng trỏ đến biến hằng 
8. (const int *)nếu cố tình sử dụng con trỏ hằng thay đổi 1 biến hằng thì sẽ tạo  ra lỗi
9. (const int *)con trỏ hằng vẫn có thể thay đổi được địa chỉ
10.(const int *) có thể trỏ đến nhièu biến hằng

11.(int const * const) có thể trỏ đến một biến hằng và lấy giá trị, và không được phép thay đổi giá trị
12.(int const * const) có thể trỏ đến một biến thường và lấy giá trị, và không được phép thay đổi giá trị
13.(int const * const) không thể thay đổi giá trị của biến hàng, và cũng không được phép trỏ đến biến khác
*/

#define test 1
    
    
#if test == 1
    int main()
    {
        int a = 10, b = 20;
        int * const ptr = &a;
        printf("data: %d\n", *ptr);
        return 0;
    }
#elif test == 2
    int main()
    {
        int a = 10, b = 20;
        int * const ptr;    
        ptr = &a;    // This is not allowed
        printf("%d", *ptr);
        return 0;
    }
#elif test == 3
    int main()
    {
        int a = 10, b = 20;
        int * const ptr = &a;
        ptr = &b;    // Cannot point to another variable now
        printf("%d", *ptr);
        return 0;
    }
#elif test == 4
    int main()
    {
        const int a = 10;
        int b = 30;

        int * const ptr1 = &a;
        int * const ptr2 = &b;
        printf("Value of 'a' before change = %d\n", a);
        printf("Address pointed to by ptr = %p\n\n", ptr1);
        *ptr1 = 50;  // This is allowed because only the pointer is constant and not the variable 'a'
        printf("Value of 'a' after change = %d\n", a);
        printf("Address pointed to by ptr = %p\n", ptr1);

        *ptr2 = 100;  // This is allowed because only the pointer is constant and not the variable 'a'
        printf("Value of 'a' after change = %d\n", b);
        printf("Address pointed to by ptr = %p\n", ptr2);

        return 0;
    }
#elif test == 5
    int main()
    {
        const int a = 10;
        int *ptr = &a;
        *ptr = 50;
        printf("Value of 'a' is %d", a);
        return 0;
    }
#elif test == 6
    int main()
    {
        const int a = 10;
        int *ptr = &a;
        a = 60;    // This is not allowed
        printf("%d",a);
        return 0;
    }
#elif test == 7
    int main()
    {
        // con trỏ vẫn có thể đọc đk, read-only
        const int a = 10;
        const int * ptr;    // Note that it is not necessary to initialise the pointer here at the time of declaration
        ptr = &a;    
        printf("%d", *ptr);
        return 0;
    }
#elif test == 8
    int main()
    {
        const int a = 10;
            int b = 50;
        const int * ptr1 = &a;
        const int * ptr2 = &b;
        *ptr1 = 50;    // This is not allowed because 'a' is const
        *ptr2 = 100;    // This is not allowed because 'a' is const
        printf("%d -- %d", *ptr1, *ptr2);
        return 0;
    }
#elif test == 9
    int main()
    {
        const int a = 10;
        const int * ptr = &a;
        int b = 100;
        ptr = &b;
        printf("%d", *ptr);
        return 0;
    }
#elif test == 10
    int main()
    {
        const int a = 10;
        const int b = 50;
        const int * ptr = &a;
        printf("Address stored in pointer before change : %d\n", ptr);
        printf("Value stored in that address before change : %d\n\n", *ptr);
        ptr = &b;
        printf("Address stored in pointer after change : %d\n", ptr);
        printf("Value stored in that address after change : %d\n", *ptr);
        return 0;
    }
#elif test == 11
    int main()
    {
        const int a = 10;
        int const * const ptr = &a;
        printf("%d", *ptr);
        return 0;
    }
#elif test == 12 
    int main()
    {
        int b = 50;
        int const * const ptr = &b;
        printf("%d", *ptr);
        return 0;
    }
#elif test == 13
    int main()
    {
        const int a = 10;
        int const * const ptr = &a;
        *ptr = 50;    // Cannot change value of constant variable
        const int b = 100;
        ptr = &b;    // Cannot reassign pointer to different address
        return 0;
    }
#endif

#include <stdio.h>
#include <inttypes.h>
#include "test.h"

int main() {

    fprintf(stdout, "Введите номер теста: \n"
                    "1) Обычное успешное выделение памяти.\n"
                    "2) Освобождение одного блока из нескольких выделенных.\n"
                    "3) Освобождение двух блоков из нескольких выделенных.\n"
                    "4) Память закончилась, новый регион памяти расширяет старый.\n"
                    "5) Память закончилась, старый регион памяти не расширить из-за другого выделенного диапазона адресов, новый регион выделяется в другом месте.\n");



    uint8_t input_value;
    scanf("%"SCNu8, &input_value);

    switch (input_value) {
        case 1:
            usual_test();
            break;
        case 2:
            free_test();
            break;
        case 3:
            free_test2();
            break;
        case 4:
            new_region_test();
            break;
        case 5:
            new_distant_region_test();
            break;
        default:
            fprintf(stderr, "Введите цифру от 1 до 5\n");
            break;
    }



    return 0;
}

Определение четности числа с использованием побитовых операций AND (&) и сдвига (<<>>) является более эффективным с точки зрения производительности.

bool isEven(int value)
{
      return value % 2 == 0;
}

Плюсы реализации на основе остатка от деления:
	Простота и понятность кода

Минусы реализации на основе остатка от деления:
	Медленнее, чем использование битовых операций

Microsoft (R) C/C++ Optimizing Compiler Version 19.39.33321 for x86

tv66 = -4
_value$ = 8
bool isEven(int) PROC
        push    ebp
        mov     ebp, esp
        push    ecx
        mov     eax, DWORD PTR _value$[ebp]
        and     eax, -2147483647
        jns     SHORT $LN5@isEven
        dec     eax
        or      eax, -2
        inc     eax
$LN5@isEven:
        test    eax, eax
        jne     SHORT $LN3@isEven
        mov     DWORD PTR tv66[ebp], 1
        jmp     SHORT $LN4@isEven
$LN3@isEven:
        mov     DWORD PTR tv66[ebp], 0
$LN4@isEven:
        movzx   eax, BYTE PTR tv66[ebp]
        mov     esp, ebp
        pop     ebp
        ret     0
bool isEven(int) ENDP                


bool isEven(int value)
{
      return (value >> 1) << 1 == value;
}

Во второй реализации число сдвигается на один бит вправо с помощью операции sar, затем снова сдвигается налево с помощью операции shl.
Затем происходит сравнение исходного числа с полученным результатом , и если они равны, то число четное и в переменной tv66 устанавливается значение 1, иначе значение 0.

Microsoft (R) C/C++ Optimizing Compiler Version 19.39.33321 for x86

tv66 = -4
_value$ = 8
bool isEven(int) PROC
        push    ebp
        mov     ebp, esp
        push    ecx
        mov     eax, DWORD PTR _value$[ebp]
        sar     eax, 1
        shl     eax, 1
        cmp     eax, DWORD PTR _value$[ebp]
        jne     SHORT $LN3@isEven
        mov     DWORD PTR tv66[ebp], 1
        jmp     SHORT $LN4@isEven
$LN3@isEven:
        mov     DWORD PTR tv66[ebp], 0
$LN4@isEven:
        movzx   eax, BYTE PTR tv66[ebp]
        mov     esp, ebp
        pop     ebp
        ret     0
bool isEven(int) ENDP 


bool isEven(int value)
{
      return (value & 1) == 0;
}

Плюсы реализации на основе битовой операции AND:
	Быстрее выполнение за счет использования битовых операций
Минусы реализации на основе битовой операции AND:
	Сложнее для понимания

Microsoft (R) C/C++ Optimizing Compiler Version 19.39.33321 for x86

tv66 = -4
_value$ = 8
bool isEven(int) PROC
        push    ebp
        mov     ebp, esp
        push    ecx
        mov     eax, DWORD PTR _value$[ebp]
        and     eax, 1
        jne     SHORT $LN3@isEven
        mov     DWORD PTR tv66[ebp], 1
        jmp     SHORT $LN4@isEven
$LN3@isEven:
        mov     DWORD PTR tv66[ebp], 0
$LN4@isEven:
        movzx   eax, BYTE PTR tv66[ebp]
        mov     esp, ebp
        pop     ebp
        ret     0
bool isEven(int) ENDP

Обе реализации эффективны, но первая реализация, которая использует сдвиги, требует больше операций (2 сдвига и 1 сравнение) по сравнению со второй реализацией, которая использует только побитовую операцию AND.

Compiler Explorer: https://compiler-explorer.com
#include <stdio.h>
#include <string.h>

#define SIZE 10   // حجم المخزن 

char buffer[SIZE];
int head = 0;   // مؤشر الكتابة
int tail = 0;   // مؤشر القراءة
int count = 0;  // عدد العناصر داخل المخزن

// دالة التهيئة — تعيد كل شيء للبداية
void init() {
    head = 0;
    tail = 0;
    count = 0;
}

// التحقق اذا كان المخزن ممتلئ
int isFull() {
    return count == SIZE;
}

// التحققق اذا كان المخزن فارغ
int isEmpty() {
    return count == 0;
}

// دالة لكتابة حرف داخل المخزن 
void write(char data) {

    if (isFull()) {
        printf("Buffer Overflow! Cannot write '%c'\n", data);
        return;
    }
    buffer[head] = data;
    head = (head + 1) % SIZE;
    count++;
}

// دالة لقراءة حرف من المخزن
char read() {

    if (isEmpty()) {
        printf("Buffer Underflow! Nothing to read.\n");
        return '\0';   // قيمة فارغة
    }
    char data = buffer[tail];
    tail = (tail + 1) % SIZE;
    count--;

    return data;
}

int main() {

    init();

    // مصفوفة لتخزين اسم المستخدم
    char name[100];

    // طلب الاسم من المستخدم
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Max size is : %d \n", SIZE);
    printf("phrase length is : %d\n", strlen(name));
    // اضافة اللاحقة المطلوبة إلى الاسم
    strcat(name, "CE-ESY");

    //كتابة كل حرف من الاسم داخل المخزن
    for (int i = 0; i < strlen(name); i++) {
        write(name[i]);
    }

    // قراءة الحروف من المخزن وطباعتها
    printf("Output: ");
    while (!isEmpty()) {
        char c = read();
        printf("%c", c);
    }

    // printf("\n");

    return 0;
}
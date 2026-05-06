#include <iostream>
#include <string>

using namespace std;

// Константа для максимального розміру масиву
const int N = 50;

// Оголошення функцій (прототипи), щоб main міг їх викликати
int input_int(string message);
void input_array(int arr[N], int &n);
void output_array(const int arr[N], int n);
void task_array_32();
void task_array_97();

// Головна функція з меню 
int main() {
    int choice;
    do {
        cout << "\n--- МЕНЮ ---" << endl;
        cout << "1. Завдання 1 (Array32)" << endl;
        cout << "2. Завдання 2 (Array97)" << endl;
        cout << "0. Вихід" << endl;
        choice = input_int("Ваш вибір: ");
        
        if (choice == 1) task_array_32();
        else if (choice == 2) task_array_97();
        
    } while (choice != 0);
    
    return 0;
}

// Функція для введення цілого числа (проста версія)
int input_int(string message) {
    int value;
    cout << message;
    cin >> value;
    return value;
}

// Введення масиву
void input_array(int arr[N], int &n) {
    n = input_int("Введіть кількість елементів (2-50): ");
    if (n > N) n = N;
    
    for (int i = 0; i < n; i++) {
        arr[i] = input_int("Елемент " + to_string(i + 1) + ": ");
    }
}

// Виведення масиву 
void output_array(const int arr[N], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ЗАВДАННЯ 1: Array32 (Більші за лівого сусіда, зворотний порядок)
void task_array_32() {
    cout << "\nВиконання Завдання 1 (Array32)" << endl;
    int arr[N], n;
    input_array(arr, n);
    
    cout << "Вихідний масив: ";
    output_array(arr, n);
    
    int count = 0;
    cout << "Номери елементів (у порядку зменшення): ";
    
    // Йдемо з кінця масиву до другого елемента (індекс 1)
    // Перший елемент (індекс 0) не має лівого сусіда, тому його не перевіряємо
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] > arr[i - 1]) {
            cout << i + 1 << " "; // Виводимо порядковий номер (індекс + 1)
            count++;
        }
    }
    
    if (count == 0) {
        cout << "таких елементів немає";
    }
    
    cout << "\nКількість таких елементів (K): " << count << endl;
}

// ЗАВДАННЯ 2: Array97 
// Видалити всі однакові елементи, залишивши їх останні входження
void task_array_97() {
    int arr[N];
    int n;
    input_array(arr, n);
    
    cout << "Масив до змін: ";
    output_array(arr, n);
    
    // Йдемо по масиву
    for (int i = 0; i < n; i++) {
        bool has_duplicate_later = false;
        
        // Перевіряємо, чи є таке ж число далі в масиві
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                has_duplicate_later = true;
                break;
            }
        }
        
        // Якщо таке число далі є, то поточне (arr[i]) треба видалити
        if (has_duplicate_later) {
            for (int k = i; k < n - 1; k++) {
                arr[k] = arr[k + 1];
            }
            n--; // Зменшуємо розмір
            i--; // Перевіряємо цей же індекс знову, бо там тепер нове число
        }
    }
    
    cout << "Масив після видалення дублікатів (залишено останні): ";
    output_array(arr, n);
}

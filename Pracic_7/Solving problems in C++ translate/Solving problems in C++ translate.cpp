// «Сокол Тысячелетия» имеет координаты местонахождения повстанцев в виде
//массива, где первая строка номера повстанцев, а следующие 3 строки –
//координаты планет, на которых находятся повстанцы.Чубака ввел данные
//местонахождения своего корабля.Ваша программа должна помочь рассчитать
//ему порядок перемещения корабля «Сокол Тысячелетия» чтобы забрать всех
//повстанцев себе на корабль.
//

#include <string>
#include <iostream>
#include <ctype.h>
#include <stdio.h>
using namespace std;
#include <cstdlib>
#include <ctime>

float dist(float  charr[], float parr[]) {
    return sqrt(pow(charr[0] - parr[0], 2) + pow(charr[1] - parr[1], 2) +
        pow(charr[2] - parr[2], 2));
}

int main() 
{
    float min_ = 0;
    float cor[3] ;
    const int ROWS = 4;
    const int COLS = 3;
    int index_ = 0;
    int index_2 = 0;
    int index_3 = 3;
    float arr[ROWS][COLS];
    setlocale(LC_ALL, "RU");
    printf("Введите координату x\n");
    cin >> cor[0];
    printf("Введите координату y\n");
    cin >> cor[1];
    printf("Введите координату z\n");
    cin >> cor[2];
    srand(time(0));  
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i > 0) {
                arr[i][j] = rand() % 21 - 10;
            }
            else {
                arr[i][j] = j+1;
            }
            cout << arr[i][j] << "\t"; 
        }
        cout << "\n";
    }
    cout << "\nРасстояния от заданной точки до первого повстанца:" << endl;
    for (int i = 0; i < COLS; i++) {
        float res = dist(cor, arr[i]);
        cout << "Точка " << i + 1 << ": " << res << endl;
        if (i == 0) {
            min_ = res;
            index_ = i + 1;
        }
        if (res < min_) {
            min_ = res;
            index_ = i+1;
        }
        cout << "Min " << ": " << min_ << " id: " << index_ << endl;
        cout << endl;
        cout << endl;
    }
    cout << "\nРасстояния до второй повстанца:" << endl;
    for (int i = 1; i <= COLS; i++) {
        if (i != index_) {
            float res = dist(cor, arr[i]);
            cout << "Точка " << i << ": " << res << endl;
            if ((i == 1) || (i == 2)) {
                min_ = res;
                index_2 = i;
            }
            if (res <= min_) {
                min_ = res;
                index_2 = i;
            }
            cout << "Min " << ": " << min_ << " id: " << index_2 << endl;
            cout << endl;
            cout << endl;
        }
    }
    for (int i = 1; i <= COLS; i++) {
        if (i != index_ && i != index_2) {
            index_3 = i;
        }      
    }
    cout << "Порядок сбора повстанцев. Первый: " << index_ << " Второй: " << index_2 << " Третий: " << index_3 << endl;
    return 0; 
    }   


//В необработанном тексте имеется информация о количестве магазинов «Ашан» в каждом городе.
// В тексте имеются и числовые данные, связанные со средним чеком покупателей в этих магазинах.Нужно написать программу,
//которая выведет на экран сколько магазинов в указанных городах.Склонение города не менять.Регулярные выражения не использовать.
//Ввод: В Москве 67 магазинов Ашан, при этом средний чек составляет 1123 рубля.Средний чек 982 рубля в Санкт--Петербурге 7 магазинов.


int main() {
	string str = "В Москве 67 магазинов Ашан, при этом средний чек составляет 1123 рубля."
					"Средний чек 982 рубля в Санкт--Петербурге 7 магазинов.\0";
	string prom;
	string stop_word = "Ашан,";
	setlocale(LC_ALL, "Ru");
	for (int i = 0;i < str.size();i++) {
		if (str[i] != ' ') {
			prom += str[i];
		}
		else {
			int s = prom.size();
			if ((s > 1) && isupper(static_cast<unsigned char>(prom[0])) && (prom != stop_word)) {
				cout << prom << ' ';
			}
			if (isdigit(prom[0]) && s < 3) {
				cout << prom;
				cout << '\n';
			}
			if (i != 0) {
				prom.clear();
			}
		}
	}
}

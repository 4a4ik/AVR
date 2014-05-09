#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
 
//TCCR0
#define CS0 0
#define CS1 1
#define CS2 2
#define TOIE0 0
 
// Частота МК 4 МГЦ
int clock = 0;
int move_x = 20;
int move_y = 20;
int clock2 = 0;
int manual = -1;
int pressed = -1;
int x_increase = 0, y_increase = 0;
 
ISR(TIMER0_OVF_vect) // Прерывание по переполнению таймера TNC0
{
  
  clock++; // Переменная для подсчёта частоты
  if (clock == move_y) // Каждые 1 - 2 мс обнуляем ножку
  {
  PORTC = PORTC ^ 0b00010000; // PD4
  }
  if (clock == move_x) // Подбиралось эксперементально min 14 max 32
  {
  PORTC = PORTC ^ 0b00100000; // PD5
  }
  
  if(clock >= 251) // Каждые 20 мс посылаем импульс
  {
  PORTC = 0b00110000;
  clock = 0;
  clock2++;
  }
  
  if( manual == -1 && clock == 0 ) // Если НЕ ручное управление
  {
  if(clock2 == 100) // Примерно каждые 2 секунды
  {
   move_x = 26;
   move_y = 17;
  }
  else if(clock2 == 200) // двигаем сервоприводами
  {
   move_x = 30;
   move_y = 20;
  }
  else if(clock2 == 300)
  {
   move_x = 20;
   move_y = 22;
  }
  
  else if(clock2 == 400)
  {
   move_x = 25;
   move_y = 21;
  }
  else if(clock2 >= 500)
  {
   move_x = 32;
   move_y = 19;
   clock2 = 0;
  }
 }
 
 if( manual == 1 && clock == 0 ) // Если ручное управление
 {
  if(clock2 >= 7) // Каждые 1/4 секунды крутим серву если нажата кнопка
  {
   if(x_increase == 1) move_x++;
   if(x_increase == -1) move_x--;
 
   if(y_increase == 1) move_y++;
   if(y_increase == -1) move_y--;
 
   x_increase = 0;
   y_increase = 0;
   clock2 = 0;
  }
 }
 
 if ((PIND & (1 << 0)) == 0 && pressed == -1)  // Если 1 вывод заземлили PIND == 0, нажали кнопку
 {
  _delay_ms(50); // Убираем дребезг контактов
  if ((PIND & (1 << 0)) == 0 && pressed == -1)
  {
   manual = -manual; // Меняем тип управления
   pressed = 1; // переменная для проверки нажатия
  }
 }
 if ((PIND & (1 << 0)) == 1  && pressed == 1) // Чтобы тип управления не менялся 100 раз
 {
  _delay_ms(50);
  if ((PIND & (1 << 0)) == 1 && pressed == 1) // Движение сервами
  {
   pressed = -1; // за 1 нажатие
  }
 }
 if ((PIND & (1 << 1)) == 0 && move_x < 32 )  // Остальные проверки кнопок
 {
  x_increase = 1;
 }
 if ((PIND & (1 << 2)) == 0 && move_x > 16) // Для движения сервами
 {
  x_increase = -1;
 }
 if ((PIND & (1 << 3)) == 0 && move_y < 32)
 {
  y_increase = 1;
 }
 if ((PIND & (1 << 4)) == 0 && move_y > 16)
 {
  y_increase = -1;
 }
}
 
 
int main()
{
 DDRC=0xFF; //выход
 DDRD=0x00; // вход
 PORTD=0b00011111; // ЛОГ 1 на выводы для кнопок
    // Настройка TIMER0
 TCCR0|=(0<<CS2)|(0<<CS1)|(1<<CS0);   // без предделителя
 TIMSK|=(1<<TOIE0);   // прерывание при переполнении таймера TNC0
 
 sei(); // Разрешаем прерывания
 
 while(1);
}

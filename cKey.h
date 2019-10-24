/*
 Класс работы с кнопками ПОУ
 Добавлен флаг работы кнопок IsStandBy
 IsStandBy = false :=> кнопки активны
 IsStandBy = true :=> кнопки игнорируются
 */
#ifndef C_KEY
#define C_KEY
 //========================================================================
 //---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
 //========================================================================
 
 //========================================================================
 //-------------------------------- КОНСТАНТЫ -----------------------------
 //========================================================================
 #define DELAY_KEYBOARD 50



 
 //========================================================================
 //--------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ -------------------------
 //========================================================================
 
class cKey{
 
 //------------------------------------------------------------------------
 // Атрибуты
 //------------------------------------------------------------------------

 
 char Name;               // Имя объекта
 int Line;			          // Линия ввода данных
 
 bool Current;		        // Текущее состояние кнопки
 bool Previous;		        // Предыдущее состояние кнопки
 
 long PreviousTime;       // Предыдущее значение миллисекундного таймера
 bool IsDebounce;         // Флаг процесса подавления дребезга
 
 
 public:

 bool IsEvent;            // Событие изменения состояния кнопки

 static bool IsStandBy;   // Флаг функционирования клавиатуры
 
 static int Dwell;        //Время ожидания для подавления дребезга
 static long CurrentTime; //Текущее значение миллисекундного таймера
 static int Code;         //Код операции
 
 
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------

 protected: 
 
 void eventGeneration();  // Генерация события
  
 public:
 
 static void getCurrentTime(); // Чтение текущего времени
 
 void operate();  // Реализация функциональности джойстика

 bool getValue(); // Чтение текущего значения
 
 void install(char nameX, int line);
 
 //------------------------------------------------------------------------
 // Конструкторы
 //------------------------------------------------------------------------
 cKey();
 
};//End of class cKey

 //========================================================================
 //--------------------------- РЕАЛИЗАЦИЯ МЕТОДОВ -------------------------
 //========================================================================

//
// Конструктор
//
cKey::cKey(
    )
{
  //...
} 

//
// Начальная установка
//
void cKey::install(
    char nameX,
    int line
  )
{
  this->Name = nameX;
  this->Line = line;
  
  this->Current = digitalRead(this->Line);
  this->Previous = this->Current;

  this->PreviousTime = millis();
  this->IsDebounce = false;
  /*
  String s = "";
  s += "Key ";
  s += this->Name;
  s += ", line: ";
  s += this->Line;
  
  Serial.println(s);
  */
}//End of void cKey::install

//
// Реализация функциональности
//
void cKey::operate()
{
  //
  // Чтение текущего состояния кнопки
  //
  this->Current = digitalRead(this->Line);
  // Фиксация момента изменения состояния кнопки
  if(this->Current != this->Previous)
  {
      this->Previous = this->Current;
      if(this->Current)this->eventGeneration();
  }
}//End of void cKey::operate()

//
// Генерация события
//
 void cKey::eventGeneration()
 {
    this->IsEvent = true;
    /*
    Serial.print("Key ");
    Serial.print(this->Name);
    if(this->Current) Serial.println(" released"); else  Serial.println(" pressed"); 
    */
 }

//
// Чтение текущего значения
//
 bool cKey::getValue()
 {
    return !this->Previous;
 }

 //
 // Чтение текущего времени
 //
 void cKey::getCurrentTime()
 {
    cKey::CurrentTime = millis();
 }
//========================================================================
//--------------------------- ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ----------------------
//========================================================================

bool cKey::IsStandBy = false;     //Кнопки активны
long cKey::CurrentTime;
int  cKey::Dwell = DELAY_KEYBOARD;// Задержка для подавления дребезга
int  cKey::Code = 0;              // Код операции в начальном положении


//--------------------------------------------------------------------------------
#endif

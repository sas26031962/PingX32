/*
 Класс, управляющий выбором IP-адреса
 */
#ifndef C_SELECTION
#define C_SELECTION
//========================================================================
//---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
//========================================================================
 
//========================================================================
//-------------------------------- КОНСТАНТЫ -----------------------------
//========================================================================
#define KEY_1 7   // UP
#define KEY_2 6   // DOWN
#define KEY_3 5   // SELECT
#define KEY_4 8   // RESTART

//========================================================================
//------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ И СТРУКТУР ----------------
//========================================================================

// Класс, управляющий выбором IP-адреса

class cSelection{

//Атрибуты
public:  
cKey Key1; 
cKey Key2;
cKey Key3;
cKey Key4;

static byte mac[6];   // mac адрес устройства
static byte ip100[4]; // ip адрес устройства для подсети 100
static byte ip0[4];   // ip адрес устройства для подсети 0
static byte ip1[4];   // ip адрес устройства для подсети 1
static byte ip101[4]; // ip адрес устройства для подсети 101
static byte ip102[4]; // ip адрес устройства для подсети 102

//Методы  

void install();
void releaseReset();
void selectRemoteIP();

//Конструктор

cSelection();

};//End of cSelection

//
// Реализации
//
cSelection::cSelection()
{
  //...
}

void cSelection::install()
{
  // Инициализация кнопок
  pinMode(KEY_1, INPUT_PULLUP);  
  pinMode(KEY_2, INPUT_PULLUP);  
  pinMode(KEY_3, INPUT_PULLUP);  
  pinMode(KEY_4, INPUT_PULLUP);  
  
  Key1.install('1', KEY_1);
  Key2.install('2', KEY_2);
  Key3.install('3', KEY_3);
  Key4.install('4', KEY_4);
}//End of cSelection::install()

void cSelection::releaseReset()
{
  Key4.operate();
  if(Key4.IsEvent)
  {
    void(* resetFunc)(void) = 0;
    resetFunc();
      
    Key4.IsEvent = false;
  }
}//End of cSelection::releaseReset()

//
// Выбор IP адреса
//
void cSelection::selectRemoteIP()
{
  //Ожидание нажатия кнопки ВВОД
  while(!cKey::IsStandBy)
  {
    // Функционирование кнопок
  
    Key1.operate();
    Key2.operate();
    Key3.operate();
    Key4.operate();

    unit::selectIPbyCode(cKey::Code);
    sDisplay::displaySelectIP();

    if(Key1.IsEvent)
    {
      cKey::Code++;
      if(cKey::Code > IP_ARRAY_LENGTH) cKey::Code = 0;

      Key1.IsEvent = false;
    }
    
    if(Key2.IsEvent)
    {
      cKey::Code--;
      if(cKey::Code < 0) cKey::Code = IP_ARRAY_LENGTH;
      
      Key2.IsEvent = false;
    }
    
    //
    // Завершение выбора и передача IP адреса 
    //
    if(Key3.IsEvent)
    {
      cKey::IsStandBy = true;
      Key3.IsEvent = false;
    
    }//End of if(Key3.IsEvent)
    //
    //Программный сброс контроллера
    //
    if(Key4.IsEvent)
    {
     
      void(* resetFunc)(void) = 0;
      resetFunc();
      
      Key4.IsEvent = false;
    }
  }//End of while(!cKey::IsStandBy)
  
  // Создание Ethernet-соединения

  if(unit::addrX[2] == 100) Ethernet.begin(cSelection::mac, cSelection::ip100);
  if(unit::addrX[2] == 101) Ethernet.begin(cSelection::mac, cSelection::ip101);
  if(unit::addrX[2] == 102) Ethernet.begin(cSelection::mac, cSelection::ip102);
  if(unit::addrX[2] == 1) Ethernet.begin(cSelection::mac, cSelection::ip1);
  if(unit::addrX[2] == 0) Ethernet.begin(cSelection::mac, cSelection::ip0);
  
}//End of void selectRemoteIP()

//========================================================================
//--------------------------- ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ----------------------
//========================================================================
byte cSelection::mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // MAC адрес устройства

byte cSelection::ip100[] = {192,168,100,102}; // ip адрес устройства
byte cSelection::ip0[] = {192,168,0,100};     // 
byte cSelection::ip1[] = {192,168,1,100};     // 
byte cSelection::ip101[] = {192,168,101,100}; // 
byte cSelection::ip102[] = {192,168,102,100}; // 

//--------------------------------------------------------------------------------
#endif

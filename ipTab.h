/*
 Структуры, описывающае проверяемые IP-адреса и названия устройств
 */
#ifndef IP_TAB
#define IP_TAB
 //========================================================================
 //---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
 //========================================================================
 
 //========================================================================
 //-------------------------------- КОНСТАНТЫ -----------------------------
 //========================================================================
#define IP_ARRAY_LENGTH 24  // Длина массива IP адресов
  
 //========================================================================
 //------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ И СТРУКТУР ----------------
 //========================================================================
//
// Структура "адрес + название"
//
struct unit{
  // Атрибуты
  int addr[4]; 
  String s;
  
  // Статические атрибуты (текущее значение параметров для загрузки)
  static byte addrX[4];
  static String uName;

  // Статические методы
  static void selectIPbyCode(int code);// Выбор адресу по коду
  static void getValueFromTab(unit Current);// Чтение значения из таблицы
  } type;

// Таблица ip адресов устройства
struct  ipTab {
  const int  count = IP_ARRAY_LENGTH;
  const unit addr0 = {{192, 168, 100, 100}, "Computer"};//компьютер
  const unit addr1 = {{192, 168, 100, 77}, "AimCommander"}; //прицел командира  
  const unit addr2 = {{192, 168, 100, 78}, "AimGunlayer"}; //прицел наводчика 
  const unit addr3 = {{192, 168, 100, 66}, "KUMZ"}; //КУМЗ 
  const unit addr4 = {{192, 168, 100, 67}, "KTN"}; //КТН 
  const unit addr5 = {{192, 168, 100, 16}, "Commander_TP"}; //АРМ командира 
  const unit addr6 = {{192, 168, 100, 32}, "Gunlayer_TP"}; //АРМ наводчика 
  const unit addr7 = {{192, 168, 100, 1}, "BCVS#1_TP"};  //БЦВС#1 TP
  const unit addr8 = {{192, 168, 100, 2}, "BCVS#2_TP"};  //БЦВС#2 TP
  const unit addr9 = {{192, 168, 100, 75}, "PKN"}; //Пульт КН 
  const unit addr10 = {{192, 168, 1, 4}, "SIPA"}; //СИПА 
  const unit addr11 = {{192,168,100,201}, "FCI_COM_TV"}; //Имитатор прицела командира, ТВ канал
  const unit addr12 = {{192,168,100,80}, "FCI_COM_TPV"}; //Имитатор прицела командира, ТПВ канал
  const unit addr13 = {{192,168,100,200}, "FCI_NAV_TV"}; //Имитатор прицела наводчика, ТВ канал
  const unit addr14 = {{192,168,100,78}, "FCI_NAV_TPV"}; //Имитатор прицела наводчика, ТПВ канал
  const unit addr15 = {{192,168,0,2}, "SWITCH_TOP"}; //Коммутатор башни
  const unit addr16 = {{192,168,0,3}, "SWITCH_BOTTOM"}; //Коммутатор шасси
  const unit addr17 = {{192,168,101,16}, "Commander_Fiber"}; //АРМ командира
  const unit addr18 = {{192,168,101,32}, "Gunlayer_Fiber"}; //АРМ наводчика 
  const unit addr19 = {{192,168,101,1}, "BCVS#1_Fiber"}; //БЦВС#1 Коммутатор
  const unit addr20 = {{192,168,100,69}, "SINSS"}; //СИНСС
  const unit addr21 = {{192,168,102,10}, "BCVS#1_Fiber2"}; //БЦВС#1 ТАС
  const unit addr22 = {{192,168,102,77}, "Aim_Com_Fiber"}; //Прицел командира оптика
  const unit addr23 = {{192,168,100,74}, "KBSE"}; //КБСЭ
}IP;

//
//Получения значения aadrX из таблицы ipTab
//
void unit::getValueFromTab(unit Current)
{
  unit::addrX[0] = Current.addr[0];
  unit::addrX[1] = Current.addr[1];
  unit::addrX[2] = Current.addr[2];
  unit::addrX[3] = Current.addr[3];
  unit::uName = Current.s;
}

void unit::selectIPbyCode(int code)
{
      //Выбор адреса удалённого устройства
      switch(code)
      {
        case 0:
          unit::getValueFromTab(IP.addr0);
        break;
    
        case 1:
          unit::getValueFromTab(IP.addr1);
        break;
    
        case 2:
          unit::getValueFromTab(IP.addr2);
        break;
    
        case 3:
          unit::getValueFromTab(IP.addr3);
        break;
    
        case 4:
          unit::getValueFromTab(IP.addr4);
        break;
    
        case 5:
          unit::getValueFromTab(IP.addr5);
        break;
    
        case 6:
          unit::getValueFromTab(IP.addr6);
        break;
    
        case 7:
          unit::getValueFromTab(IP.addr7);
        break;
    
        case 8:
          unit::getValueFromTab(IP.addr8);
        break;
    
        case 9:
          unit::getValueFromTab(IP.addr9);
        break;
    
        case 10:
          unit::getValueFromTab(IP.addr10);
        break;
    
        case 11:
          unit::getValueFromTab(IP.addr11);
        break;
    
        case 12:
          unit::getValueFromTab(IP.addr12);
        break;
    
        case 13:
          unit::getValueFromTab(IP.addr13);
        break;
    
        case 14:
          unit::getValueFromTab(IP.addr14);
        break;
    
        case 15:
          unit::getValueFromTab(IP.addr15);
        break;

        case 16:
          unit::getValueFromTab(IP.addr16);
        break;
    
        case 17:
          unit::getValueFromTab(IP.addr17);
        break;
    
        case 18:
          unit::getValueFromTab(IP.addr18);
        break;
    
         case 19:
          unit::getValueFromTab(IP.addr19);
        break;
    
         case 20:
          unit::getValueFromTab(IP.addr20);
        break;
    
         case 21:
          unit::getValueFromTab(IP.addr21);
        break;
         case 22:
          unit::getValueFromTab(IP.addr22);
        break;
         case 23:
          unit::getValueFromTab(IP.addr23);
        break;
    
       default:
          unit::addrX[0] = 192;
          unit::addrX[1] = 168;
          unit::addrX[2] = 100;
          unit::addrX[3] = 100;
          unit::uName = "Unknown node";
        break;
    
      }//End of switch(cKey::Code)
  
}//End of void selectIPbyCode()

//========================================================================
//--------------------------- ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ ----------------------
//========================================================================

byte unit::addrX[4] = {192, 168, 100, 100};
String unit::uName = "Unknown node";
  

//--------------------------------------------------------------------------------
#endif

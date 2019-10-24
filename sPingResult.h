/*
 Структура, описывающая параметры результата, 
 полученного при выполнении утилиты ping
 */
#ifndef PING_RESULT
#define PING_RESULT
//========================================================================
//---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
//========================================================================
 
//========================================================================
//-------------------------------- КОНСТАНТЫ -----------------------------
//========================================================================
  
//========================================================================
//------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ И СТРУКТУР ----------------
//========================================================================

//Структура, описывающая результат операции
struct {
  int t;//Время, прошедшее с начала операции
  int n;//Номер посылки
  int len;//Длина посылки
  int ttl;//Время жизни посылки
  bool statusX;//Признак завершения операции
  int addr[4];//IP адрес объекта
  int statusVal;//Статус завершения операции
  
  }PingResult;


//--------------------------------------------------------------------------------
#endif
